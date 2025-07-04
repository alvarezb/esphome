import codecs
from contextlib import suppress
import ipaddress
import logging
import os
from pathlib import Path
import platform
import re
import tempfile
from urllib.parse import urlparse

_LOGGER = logging.getLogger(__name__)

IS_MACOS = platform.system() == "Darwin"
IS_WINDOWS = platform.system() == "Windows"
IS_LINUX = platform.system() == "Linux"


def ensure_unique_string(preferred_string, current_strings):
    test_string = preferred_string
    current_strings_set = set(current_strings)

    tries = 1

    while test_string in current_strings_set:
        tries += 1
        test_string = f"{preferred_string}_{tries}"

    return test_string


def fnv1a_32bit_hash(string: str) -> int:
    """FNV-1a 32-bit hash function.

    Note: This uses 32-bit hash instead of 64-bit for several reasons:
    1. ESPHome targets 32-bit microcontrollers with limited RAM (often <320KB)
    2. Using 64-bit hashes would double the RAM usage for storing IDs
    3. 64-bit operations are slower on 32-bit processors

    While there's a ~50% collision probability at ~77,000 unique IDs,
    ESPHome validates for collisions at compile time, preventing any
    runtime issues. In practice, most ESPHome installations only have
    a handful of area_ids and device_ids (typically <10 areas and <100
    devices), making collisions virtually impossible.
    """
    hash_value = 2166136261
    for char in string:
        hash_value ^= ord(char)
        hash_value = (hash_value * 16777619) & 0xFFFFFFFF
    return hash_value


def strip_accents(value: str) -> str:
    """Remove accents from a string."""
    import unicodedata

    return "".join(
        c
        for c in unicodedata.normalize("NFD", str(value))
        if unicodedata.category(c) != "Mn"
    )


def slugify(value: str) -> str:
    """Convert a string to a valid C++ identifier slug."""
    from esphome.const import ALLOWED_NAME_CHARS

    value = (
        strip_accents(value)
        .lower()
        .replace(" ", "_")
        .replace("-", "_")
        .replace("__", "_")
        .strip("_")
    )
    return "".join(c for c in value if c in ALLOWED_NAME_CHARS)


def indent_all_but_first_and_last(text, padding="  "):
    lines = text.splitlines(True)
    if len(lines) <= 2:
        return text
    return lines[0] + "".join(padding + line for line in lines[1:-1]) + lines[-1]


def indent_list(text, padding="  "):
    return [padding + line for line in text.splitlines()]


def indent(text, padding="  "):
    return "\n".join(indent_list(text, padding))


# From https://stackoverflow.com/a/14945195/8924614
def cpp_string_escape(string, encoding="utf-8"):
    def _should_escape(byte: int) -> bool:
        if not 32 <= byte < 127:
            return True
        if byte in (ord("\\"), ord('"')):
            return True
        return False

    if isinstance(string, str):
        string = string.encode(encoding)
    result = ""
    for character in string:
        if _should_escape(character):
            result += f"\\{character:03o}"
        else:
            result += chr(character)
    return f'"{result}"'


def run_system_command(*args):
    import subprocess

    with subprocess.Popen(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE) as p:
        stdout, stderr = p.communicate()
        rc = p.returncode
        return rc, stdout, stderr


def mkdir_p(path):
    if not path:
        # Empty path - means create current dir
        return
    try:
        os.makedirs(path)
    except OSError as err:
        import errno

        if err.errno == errno.EEXIST and os.path.isdir(path):
            pass
        else:
            from esphome.core import EsphomeError

            raise EsphomeError(f"Error creating directories {path}: {err}") from err


def is_ip_address(host):
    try:
        ipaddress.ip_address(host)
        return True
    except ValueError:
        return False


def _resolve_with_zeroconf(host):
    from esphome.core import EsphomeError
    from esphome.zeroconf import EsphomeZeroconf

    try:
        zc = EsphomeZeroconf()
    except Exception as err:
        raise EsphomeError(
            "Cannot start mDNS sockets, is this a docker container without "
            "host network mode?"
        ) from err
    try:
        info = zc.resolve_host(f"{host}.")
    except Exception as err:
        raise EsphomeError(f"Error resolving mDNS hostname: {err}") from err
    finally:
        zc.close()
    if info is None:
        raise EsphomeError(
            "Error resolving address with mDNS: Did not respond. "
            "Maybe the device is offline."
        )
    return info


def addr_preference_(res):
    # Trivial alternative to RFC6724 sorting. Put sane IPv6 first, then
    # Legacy IP, then IPv6 link-local addresses without an actual link.
    sa = res[4]
    ip = ipaddress.ip_address(sa[0])
    if ip.version == 4:
        return 2
    if ip.is_link_local and sa[3] == 0:
        return 3
    return 1


def resolve_ip_address(host, port):
    import socket

    from esphome.core import EsphomeError

    # There are five cases here. The host argument could be one of:
    #  • a *list* of IP addresses discovered by MQTT,
    #  • a single IP address specified by the user,
    #  • a .local hostname to be resolved by mDNS,
    #  • a normal hostname to be resolved in DNS, or
    #  • A URL from which we should extract the hostname.
    #
    # In each of the first three cases, we end up with IP addresses in
    # string form which need to be converted to a 5-tuple to be used
    # for the socket connection attempt. The easiest way to construct
    # those is to pass the IP address string to getaddrinfo(). Which,
    # coincidentally, is how we do hostname lookups in the other cases
    # too. So first build a list which contains either IP addresses or
    # a single hostname, then call getaddrinfo() on each element of
    # that list.

    errs = []
    if isinstance(host, list):
        addr_list = host
    elif is_ip_address(host):
        addr_list = [host]
    else:
        url = urlparse(host)
        if url.scheme != "":
            host = url.hostname

        addr_list = []
        if host.endswith(".local"):
            try:
                _LOGGER.info("Resolving IP address of %s in mDNS", host)
                addr_list = _resolve_with_zeroconf(host)
            except EsphomeError as err:
                errs.append(str(err))

        # If not mDNS, or if mDNS failed, use normal DNS
        if not addr_list:
            addr_list = [host]

    # Now we have a list containing either IP addresses or a hostname
    res = []
    for addr in addr_list:
        if not is_ip_address(addr):
            _LOGGER.info("Resolving IP address of %s", host)
        try:
            r = socket.getaddrinfo(addr, port, proto=socket.IPPROTO_TCP)
        except OSError as err:
            errs.append(str(err))
            raise EsphomeError(
                f"Error resolving IP address: {', '.join(errs)}"
            ) from err

        res = res + r

    # Zeroconf tends to give us link-local IPv6 addresses without specifying
    # the link. Put those last in the list to be attempted.
    res.sort(key=addr_preference_)
    return res


def sort_ip_addresses(address_list: list[str]) -> list[str]:
    """Takes a list of IP addresses in string form, e.g. from mDNS or MQTT,
    and sorts them into the best order to actually try connecting to them.

    This is roughly based on RFC6724 but a lot simpler: First we choose
    IPv6 addresses, then Legacy IP addresses, and lowest priority is
    link-local IPv6 addresses that don't have a link specified (which
    are useless, but mDNS does provide them in that form). Addresses
    which cannot be parsed are silently dropped.
    """
    import socket

    # First "resolve" all the IP addresses to getaddrinfo() tuples of the form
    # (family, type, proto, canonname, sockaddr)
    res: list[
        tuple[
            int,
            int,
            int,
            str | None,
            tuple[str, int] | tuple[str, int, int, int],
        ]
    ] = []
    for addr in address_list:
        # This should always work as these are supposed to be IP addresses
        try:
            res += socket.getaddrinfo(
                addr, 0, proto=socket.IPPROTO_TCP, flags=socket.AI_NUMERICHOST
            )
        except OSError:
            _LOGGER.info("Failed to parse IP address '%s'", addr)

    # Now use that information to sort them.
    res.sort(key=addr_preference_)

    # Finally, turn the getaddrinfo() tuples back into plain hostnames.
    return [socket.getnameinfo(r[4], socket.NI_NUMERICHOST)[0] for r in res]


def get_bool_env(var, default=False):
    value = os.getenv(var, default)
    if isinstance(value, str):
        value = value.lower()
        if value in ["1", "true"]:
            return True
        if value in ["0", "false"]:
            return False
    return bool(value)


def get_str_env(var, default=None):
    return str(os.getenv(var, default))


def get_int_env(var, default=0):
    return int(os.getenv(var, default))


def is_ha_addon():
    return get_bool_env("ESPHOME_IS_HA_ADDON")


def walk_files(path):
    for root, _, files in os.walk(path):
        for name in files:
            yield os.path.join(root, name)


def read_file(path):
    try:
        with codecs.open(path, "r", encoding="utf-8") as f_handle:
            return f_handle.read()
    except OSError as err:
        from esphome.core import EsphomeError

        raise EsphomeError(f"Error reading file {path}: {err}") from err
    except UnicodeDecodeError as err:
        from esphome.core import EsphomeError

        raise EsphomeError(f"Error reading file {path}: {err}") from err


def _write_file(path: Path | str, text: str | bytes):
    """Atomically writes `text` to the given path.

    Automatically creates all parent directories.
    """
    if not isinstance(path, Path):
        path = Path(path)
    data = text
    if isinstance(text, str):
        data = text.encode()

    directory = path.parent
    directory.mkdir(exist_ok=True, parents=True)

    tmp_path = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="wb", dir=directory, delete=False
        ) as f_handle:
            tmp_path = f_handle.name
            f_handle.write(data)
        # Newer tempfile implementations create the file with mode 0o600
        os.chmod(tmp_path, 0o644)
        # If destination exists, will be overwritten
        os.replace(tmp_path, path)
    finally:
        if tmp_path is not None and os.path.exists(tmp_path):
            try:
                os.remove(tmp_path)
            except OSError as err:
                _LOGGER.error("Write file cleanup failed: %s", err)


def write_file(path: Path | str, text: str):
    try:
        _write_file(path, text)
    except OSError as err:
        from esphome.core import EsphomeError

        raise EsphomeError(f"Could not write file at {path}") from err


def write_file_if_changed(path: Path | str, text: str) -> bool:
    """Write text to the given path, but not if the contents match already.

    Returns true if the file was changed.
    """
    if not isinstance(path, Path):
        path = Path(path)

    src_content = None
    if path.is_file():
        src_content = read_file(path)
    if src_content == text:
        return False
    write_file(path, text)
    return True


def copy_file_if_changed(src: os.PathLike, dst: os.PathLike) -> None:
    import shutil

    if file_compare(src, dst):
        return
    mkdir_p(os.path.dirname(dst))
    try:
        shutil.copyfile(src, dst)
    except OSError as err:
        if isinstance(err, PermissionError):
            # Older esphome versions copied over the src file permissions too.
            # So when the dst file had 444 permissions, the dst file would have those
            # too and subsequent writes would fail

            # -> delete file (it would be overwritten anyway), and try again
            # if that fails, use normal error handler
            with suppress(OSError):
                os.unlink(dst)
                shutil.copyfile(src, dst)
                return

        from esphome.core import EsphomeError

        raise EsphomeError(f"Error copying file {src} to {dst}: {err}") from err


def list_starts_with(list_, sub):
    return len(sub) <= len(list_) and all(list_[i] == x for i, x in enumerate(sub))


def file_compare(path1: os.PathLike, path2: os.PathLike) -> bool:
    """Return True if the files path1 and path2 have the same contents."""
    import stat

    try:
        stat1, stat2 = os.stat(path1), os.stat(path2)
    except OSError:
        # File doesn't exist or another error -> not equal
        return False

    if (
        stat.S_IFMT(stat1.st_mode) != stat.S_IFREG
        or stat.S_IFMT(stat2.st_mode) != stat.S_IFREG
    ):
        # At least one of them is not a regular file (or does not exist)
        return False
    if stat1.st_size != stat2.st_size:
        # Different sizes
        return False

    bufsize = 8 * 1024
    # Read files in blocks until a mismatch is found
    with open(path1, "rb") as fh1, open(path2, "rb") as fh2:
        while True:
            blob1, blob2 = fh1.read(bufsize), fh2.read(bufsize)
            if blob1 != blob2:
                # Different content
                return False
            if not blob1:
                # Reached end
                return True


# A dict of types that need to be converted to heaptypes before a class can be added
# to the object
_TYPE_OVERLOADS = {
    int: type("EInt", (int,), {}),
    float: type("EFloat", (float,), {}),
    str: type("EStr", (str,), {}),
    dict: type("EDict", (dict,), {}),
    list: type("EList", (list,), {}),
}

# cache created classes here
_CLASS_LOOKUP = {}


def add_class_to_obj(value, cls):
    """Add a class to a python type.

    This function modifies value so that it has cls as a basetype.
    The value itself may be modified by this action! You must use the return
    value of this function however, since some types need to be copied first (heaptypes).
    """
    if isinstance(value, cls):
        # If already is instance, do not add
        return value

    try:
        orig_cls = value.__class__
        key = (orig_cls, cls)
        new_cls = _CLASS_LOOKUP.get(key)
        if new_cls is None:
            new_cls = orig_cls.__class__(orig_cls.__name__, (orig_cls, cls), {})
            _CLASS_LOOKUP[key] = new_cls
        value.__class__ = new_cls
        return value
    except TypeError:
        # Non heap type, look in overloads dict
        for type_, func in _TYPE_OVERLOADS.items():
            # Use type() here, we only need to trigger if it's the exact type,
            # as otherwise we don't need to overload the class
            if type(value) is type_:  # pylint: disable=unidiomatic-typecheck
                return add_class_to_obj(func(value), cls)
        raise


def snake_case(value):
    """Same behaviour as `helpers.cpp` method `str_snake_case`."""
    return value.replace(" ", "_").lower()


_DISALLOWED_CHARS = re.compile(r"[^a-zA-Z0-9-_]")


def sanitize(value):
    """Same behaviour as `helpers.cpp` method `str_sanitize`."""
    return _DISALLOWED_CHARS.sub("_", value)
