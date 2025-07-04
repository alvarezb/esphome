# PYTHON_ARGCOMPLETE_OK
import argparse
from datetime import datetime
import functools
import importlib
import logging
import os
import re
import sys
import time

import argcomplete

from esphome import const, writer, yaml_util
import esphome.codegen as cg
from esphome.config import iter_component_configs, read_config, strip_default_ids
from esphome.const import (
    ALLOWED_NAME_CHARS,
    CONF_BAUD_RATE,
    CONF_BROKER,
    CONF_DEASSERT_RTS_DTR,
    CONF_DISABLED,
    CONF_ESPHOME,
    CONF_LEVEL,
    CONF_LOG_TOPIC,
    CONF_LOGGER,
    CONF_MDNS,
    CONF_MQTT,
    CONF_NAME,
    CONF_OTA,
    CONF_PASSWORD,
    CONF_PLATFORM,
    CONF_PLATFORMIO_OPTIONS,
    CONF_PORT,
    CONF_SUBSTITUTIONS,
    CONF_TOPIC,
    PLATFORM_BK72XX,
    PLATFORM_ESP32,
    PLATFORM_ESP8266,
    PLATFORM_RP2040,
    PLATFORM_RTL87XX,
    SECRETS_FILES,
)
from esphome.core import CORE, EsphomeError, coroutine
from esphome.helpers import get_bool_env, indent, is_ip_address
from esphome.log import AnsiFore, color, setup_log
from esphome.util import (
    get_serial_ports,
    list_yaml_files,
    run_external_command,
    run_external_process,
    safe_print,
)

_LOGGER = logging.getLogger(__name__)


def choose_prompt(options, purpose: str = None):
    if not options:
        raise EsphomeError(
            "Found no valid options for upload/logging, please make sure relevant "
            "sections (ota, api, mqtt, ...) are in your configuration and/or the "
            "device is plugged in."
        )

    if len(options) == 1:
        return options[0][1]

    safe_print(
        f"Found multiple options{f' for {purpose}' if purpose else ''}, please choose one:"
    )
    for i, (desc, _) in enumerate(options):
        safe_print(f"  [{i + 1}] {desc}")

    while True:
        opt = input("(number): ")
        if opt in options:
            opt = options.index(opt)
            break
        try:
            opt = int(opt)
            if opt < 1 or opt > len(options):
                raise ValueError
            break
        except ValueError:
            safe_print(color(AnsiFore.RED, f"Invalid option: '{opt}'"))
    return options[opt - 1][1]


def choose_upload_log_host(
    default, check_default, show_ota, show_mqtt, show_api, purpose: str = None
):
    options = []
    for port in get_serial_ports():
        options.append((f"{port.path} ({port.description})", port.path))
    if default == "SERIAL":
        return choose_prompt(options, purpose=purpose)
    if (show_ota and "ota" in CORE.config) or (show_api and "api" in CORE.config):
        options.append((f"Over The Air ({CORE.address})", CORE.address))
        if default == "OTA":
            return CORE.address
    if (
        show_mqtt
        and (mqtt_config := CORE.config.get(CONF_MQTT))
        and mqtt_logging_enabled(mqtt_config)
    ):
        options.append((f"MQTT ({mqtt_config[CONF_BROKER]})", "MQTT"))
        if default == "OTA":
            return "MQTT"
    if default is not None:
        return default
    if check_default is not None and check_default in [opt[1] for opt in options]:
        return check_default
    return choose_prompt(options, purpose=purpose)


def mqtt_logging_enabled(mqtt_config):
    log_topic = mqtt_config[CONF_LOG_TOPIC]
    if log_topic is None:
        return False
    if CONF_TOPIC not in log_topic:
        return False
    if log_topic.get(CONF_LEVEL, None) == "NONE":
        return False
    return True


def get_port_type(port):
    if port.startswith("/") or port.startswith("COM"):
        return "SERIAL"
    if port == "MQTT":
        return "MQTT"
    return "NETWORK"


def run_miniterm(config, port, args):
    from aioesphomeapi import LogParser
    import serial

    from esphome import platformio_api

    if CONF_LOGGER not in config:
        _LOGGER.info("Logger is not enabled. Not starting UART logs.")
        return 1
    baud_rate = config["logger"][CONF_BAUD_RATE]
    if baud_rate == 0:
        _LOGGER.info("UART logging is disabled (baud_rate=0). Not starting UART logs.")
        return 1
    _LOGGER.info("Starting log output from %s with baud rate %s", port, baud_rate)

    backtrace_state = False
    ser = serial.Serial()
    ser.baudrate = baud_rate
    ser.port = port

    # We can't set to False by default since it leads to toggling and hence
    # ESP32 resets on some platforms.
    if config["logger"][CONF_DEASSERT_RTS_DTR] or args.reset:
        ser.dtr = False
        ser.rts = False

    parser = LogParser()
    tries = 0
    while tries < 5:
        try:
            with ser:
                while True:
                    try:
                        raw = ser.readline()
                    except serial.SerialException:
                        _LOGGER.error("Serial port closed!")
                        return 0
                    line = (
                        raw.replace(b"\r", b"")
                        .replace(b"\n", b"")
                        .decode("utf8", "backslashreplace")
                    )
                    time_str = datetime.now().time().strftime("[%H:%M:%S]")
                    safe_print(parser.parse_line(line, time_str))

                    backtrace_state = platformio_api.process_stacktrace(
                        config, line, backtrace_state=backtrace_state
                    )
        except serial.SerialException:
            tries += 1
            time.sleep(1)
    if tries >= 5:
        _LOGGER.error("Could not connect to serial port %s", port)
        return 1

    return 0


def wrap_to_code(name, comp):
    coro = coroutine(comp.to_code)

    @functools.wraps(comp.to_code)
    async def wrapped(conf):
        cg.add(cg.LineComment(f"{name}:"))
        if comp.config_schema is not None:
            conf_str = yaml_util.dump(conf)
            conf_str = conf_str.replace("//", "")
            # remove tailing \ to avoid multi-line comment warning
            conf_str = conf_str.replace("\\\n", "\n")
            cg.add(cg.LineComment(indent(conf_str)))
        await coro(conf)

    if hasattr(coro, "priority"):
        wrapped.priority = coro.priority
    return wrapped


def write_cpp(config):
    generate_cpp_contents(config)
    return write_cpp_file()


def generate_cpp_contents(config):
    _LOGGER.info("Generating C++ source...")

    for name, component, conf in iter_component_configs(CORE.config):
        if component.to_code is not None:
            coro = wrap_to_code(name, component)
            CORE.add_job(coro, conf)

    CORE.flush_tasks()


def write_cpp_file():
    writer.write_platformio_project()

    code_s = indent(CORE.cpp_main_section)
    writer.write_cpp(code_s)
    return 0


def compile_program(args, config):
    from esphome import platformio_api

    _LOGGER.info("Compiling app...")
    rc = platformio_api.run_compile(config, CORE.verbose)
    if rc != 0:
        return rc
    idedata = platformio_api.get_idedata(config)
    return 0 if idedata is not None else 1


def upload_using_esptool(config, port, file, speed):
    from esphome import platformio_api

    first_baudrate = speed or config[CONF_ESPHOME][CONF_PLATFORMIO_OPTIONS].get(
        "upload_speed", os.getenv("ESPHOME_UPLOAD_SPEED", "460800")
    )

    if file is not None:
        flash_images = [platformio_api.FlashImage(path=file, offset="0x0")]
    else:
        idedata = platformio_api.get_idedata(config)

        firmware_offset = "0x10000" if CORE.is_esp32 else "0x0"
        flash_images = [
            platformio_api.FlashImage(
                path=idedata.firmware_bin_path, offset=firmware_offset
            ),
            *idedata.extra_flash_images,
        ]

    mcu = "esp8266"
    if CORE.is_esp32:
        from esphome.components.esp32 import get_esp32_variant

        mcu = get_esp32_variant().lower()

    def run_esptool(baud_rate):
        cmd = [
            "esptool.py",
            "--before",
            "default_reset",
            "--after",
            "hard_reset",
            "--baud",
            str(baud_rate),
            "--port",
            port,
            "--chip",
            mcu,
            "write_flash",
            "-z",
            "--flash_size",
            "detect",
        ]
        for img in flash_images:
            cmd += [img.offset, img.path]

        if os.environ.get("ESPHOME_USE_SUBPROCESS") is None:
            import esptool

            return run_external_command(esptool.main, *cmd)  # pylint: disable=no-member

        return run_external_process(*cmd)

    rc = run_esptool(first_baudrate)
    if rc == 0 or first_baudrate == 115200:
        return rc
    # Try with 115200 baud rate, with some serial chips the faster baud rates do not work well
    _LOGGER.info(
        "Upload with baud rate %s failed. Trying again with baud rate 115200.",
        first_baudrate,
    )
    return run_esptool(115200)


def upload_using_platformio(config, port):
    from esphome import platformio_api

    upload_args = ["-t", "upload", "-t", "nobuild"]
    if port is not None:
        upload_args += ["--upload-port", port]
    return platformio_api.run_platformio_cli_run(config, CORE.verbose, *upload_args)


def check_permissions(port):
    if os.name == "posix" and get_port_type(port) == "SERIAL":
        # Check if we can open selected serial port
        if not os.access(port, os.F_OK):
            raise EsphomeError(
                "The selected serial port does not exist. To resolve this issue, "
                "check that the device is connected to this computer with a USB cable and that "
                "the USB cable can be used for data and is not a power-only cable."
            )
        if not (os.access(port, os.R_OK | os.W_OK)):
            raise EsphomeError(
                "You do not have read or write permission on the selected serial port. "
                "To resolve this issue, you can add your user to the dialout group "
                f"by running the following command: sudo usermod -a -G dialout {os.getlogin()}. "
                "You will need to log out & back in or reboot to activate the new group access."
            )


def upload_program(config, args, host):
    try:
        module = importlib.import_module("esphome.components." + CORE.target_platform)
        if getattr(module, "upload_program")(config, args, host):
            return 0
    except AttributeError:
        pass

    if get_port_type(host) == "SERIAL":
        check_permissions(host)
        if CORE.target_platform in (PLATFORM_ESP32, PLATFORM_ESP8266):
            file = getattr(args, "file", None)
            return upload_using_esptool(config, host, file, args.upload_speed)

        if CORE.target_platform in (PLATFORM_RP2040):
            return upload_using_platformio(config, args.device)

        if CORE.target_platform in (PLATFORM_BK72XX, PLATFORM_RTL87XX):
            return upload_using_platformio(config, host)

        return 1  # Unknown target platform

    ota_conf = {}
    for ota_item in config.get(CONF_OTA, []):
        if ota_item[CONF_PLATFORM] == CONF_ESPHOME:
            ota_conf = ota_item
            break

    if not ota_conf:
        raise EsphomeError(
            f"Cannot upload Over the Air as the {CONF_OTA} configuration is not present or does not include {CONF_PLATFORM}: {CONF_ESPHOME}"
        )

    from esphome import espota2

    remote_port = int(ota_conf[CONF_PORT])
    password = ota_conf.get(CONF_PASSWORD, "")

    if (
        CONF_MQTT in config  # pylint: disable=too-many-boolean-expressions
        and (not args.device or args.device in ("MQTT", "OTA"))
        and (
            ((config[CONF_MDNS][CONF_DISABLED]) and not is_ip_address(CORE.address))
            or get_port_type(host) == "MQTT"
        )
    ):
        from esphome import mqtt

        host = mqtt.get_esphome_device_ip(
            config, args.username, args.password, args.client_id
        )

    if getattr(args, "file", None) is not None:
        return espota2.run_ota(host, remote_port, password, args.file)

    return espota2.run_ota(host, remote_port, password, CORE.firmware_bin)


def show_logs(config, args, port):
    if "logger" not in config:
        raise EsphomeError("Logger is not configured!")
    if get_port_type(port) == "SERIAL":
        check_permissions(port)
        return run_miniterm(config, port, args)
    if get_port_type(port) == "NETWORK" and "api" in config:
        if config[CONF_MDNS][CONF_DISABLED] and CONF_MQTT in config:
            from esphome import mqtt

            port = mqtt.get_esphome_device_ip(
                config, args.username, args.password, args.client_id
            )[0]

        from esphome.components.api.client import run_logs

        return run_logs(config, port)
    if get_port_type(port) == "MQTT" and "mqtt" in config:
        from esphome import mqtt

        return mqtt.show_logs(
            config, args.topic, args.username, args.password, args.client_id
        )

    raise EsphomeError("No remote or local logging method configured (api/mqtt/logger)")


def clean_mqtt(config, args):
    from esphome import mqtt

    return mqtt.clear_topic(
        config, args.topic, args.username, args.password, args.client_id
    )


def command_wizard(args):
    from esphome import wizard

    return wizard.wizard(args.configuration)


def command_config(args, config):
    if not CORE.verbose:
        config = strip_default_ids(config)
    output = yaml_util.dump(config, args.show_secrets)
    # add the console decoration so the front-end can hide the secrets
    if not args.show_secrets:
        output = re.sub(
            r"(password|key|psk|ssid)\: (.+)", r"\1: \\033[5m\2\\033[6m", output
        )
    if not CORE.quiet:
        safe_print(output)
    _LOGGER.info("Configuration is valid!")
    return 0


def command_vscode(args):
    from esphome import vscode

    logging.disable(logging.INFO)
    logging.disable(logging.WARNING)
    vscode.read_config(args)


def command_compile(args, config):
    exit_code = write_cpp(config)
    if exit_code != 0:
        return exit_code
    if args.only_generate:
        _LOGGER.info("Successfully generated source code.")
        return 0
    exit_code = compile_program(args, config)
    if exit_code != 0:
        return exit_code
    _LOGGER.info("Successfully compiled program.")
    return 0


def command_upload(args, config):
    port = choose_upload_log_host(
        default=args.device,
        check_default=None,
        show_ota=True,
        show_mqtt=False,
        show_api=False,
        purpose="uploading",
    )
    exit_code = upload_program(config, args, port)
    if exit_code != 0:
        return exit_code
    _LOGGER.info("Successfully uploaded program.")
    return 0


def command_discover(args, config):
    if "mqtt" in config:
        from esphome import mqtt

        return mqtt.show_discover(config, args.username, args.password, args.client_id)

    raise EsphomeError("No discover method configured (mqtt)")


def command_logs(args, config):
    port = choose_upload_log_host(
        default=args.device,
        check_default=None,
        show_ota=False,
        show_mqtt=True,
        show_api=True,
        purpose="logging",
    )
    return show_logs(config, args, port)


def command_run(args, config):
    exit_code = write_cpp(config)
    if exit_code != 0:
        return exit_code
    exit_code = compile_program(args, config)
    if exit_code != 0:
        return exit_code
    _LOGGER.info("Successfully compiled program.")
    if CORE.is_host:
        from esphome.platformio_api import get_idedata

        idedata = get_idedata(config)
        if idedata is None:
            return 1
        program_path = idedata.raw["prog_path"]
        return run_external_process(program_path)

    port = choose_upload_log_host(
        default=args.device,
        check_default=None,
        show_ota=True,
        show_mqtt=False,
        show_api=True,
        purpose="uploading",
    )
    exit_code = upload_program(config, args, port)
    if exit_code != 0:
        return exit_code
    _LOGGER.info("Successfully uploaded program.")
    if args.no_logs:
        return 0
    port = choose_upload_log_host(
        default=args.device,
        check_default=port,
        show_ota=False,
        show_mqtt=True,
        show_api=True,
        purpose="logging",
    )
    return show_logs(config, args, port)


def command_clean_mqtt(args, config):
    return clean_mqtt(config, args)


def command_mqtt_fingerprint(args, config):
    from esphome import mqtt

    return mqtt.get_fingerprint(config)


def command_version(args):
    safe_print(f"Version: {const.__version__}")
    return 0


def command_clean(args, config):
    try:
        writer.clean_build()
    except OSError as err:
        _LOGGER.error("Error deleting build files: %s", err)
        return 1
    _LOGGER.info("Done!")
    return 0


def command_dashboard(args):
    from esphome.dashboard import dashboard

    return dashboard.start_dashboard(args)


def command_update_all(args):
    import click

    success = {}
    files = list_yaml_files(args.configuration)
    twidth = 60

    def print_bar(middle_text):
        middle_text = f" {middle_text} "
        width = len(click.unstyle(middle_text))
        half_line = "=" * ((twidth - width) // 2)
        safe_print(f"{half_line}{middle_text}{half_line}")

    for f in files:
        safe_print(f"Updating {color(AnsiFore.CYAN, f)}")
        safe_print("-" * twidth)
        safe_print()
        if CORE.dashboard:
            rc = run_external_process(
                "esphome", "--dashboard", "run", f, "--no-logs", "--device", "OTA"
            )
        else:
            rc = run_external_process(
                "esphome", "run", f, "--no-logs", "--device", "OTA"
            )
        if rc == 0:
            print_bar(f"[{color(AnsiFore.BOLD_GREEN, 'SUCCESS')}] {f}")
            success[f] = True
        else:
            print_bar(f"[{color(AnsiFore.BOLD_RED, 'ERROR')}] {f}")
            success[f] = False

        safe_print()
        safe_print()
        safe_print()

    print_bar(f"[{color(AnsiFore.BOLD_WHITE, 'SUMMARY')}]")
    failed = 0
    for f in files:
        if success[f]:
            safe_print(f"  - {f}: {color(AnsiFore.GREEN, 'SUCCESS')}")
        else:
            safe_print(f"  - {f}: {color(AnsiFore.BOLD_RED, 'FAILED')}")
            failed += 1
    return failed


def command_idedata(args, config):
    import json

    from esphome import platformio_api

    logging.disable(logging.INFO)
    logging.disable(logging.WARNING)

    idedata = platformio_api.get_idedata(config)
    if idedata is None:
        return 1

    print(json.dumps(idedata.raw, indent=2) + "\n")
    return 0


def command_rename(args, config):
    for c in args.name:
        if c not in ALLOWED_NAME_CHARS:
            print(
                color(
                    AnsiFore.BOLD_RED,
                    f"'{c}' is an invalid character for names. Valid characters are: "
                    f"{ALLOWED_NAME_CHARS} (lowercase, no spaces)",
                )
            )
            return 1
    # Load existing yaml file
    with open(CORE.config_path, mode="r+", encoding="utf-8") as raw_file:
        raw_contents = raw_file.read()

    yaml = yaml_util.load_yaml(CORE.config_path)
    if CONF_ESPHOME not in yaml or CONF_NAME not in yaml[CONF_ESPHOME]:
        print(
            color(
                AnsiFore.BOLD_RED, "Complex YAML files cannot be automatically renamed."
            )
        )
        return 1
    old_name = yaml[CONF_ESPHOME][CONF_NAME]
    match = re.match(r"^\$\{?([a-zA-Z0-9_]+)\}?$", old_name)
    if match is None:
        new_raw = re.sub(
            rf"name:\s+[\"']?{old_name}[\"']?",
            f'name: "{args.name}"',
            raw_contents,
        )
    else:
        old_name = yaml[CONF_SUBSTITUTIONS][match.group(1)]
        if (
            len(
                re.findall(
                    rf"^\s+{match.group(1)}:\s+[\"']?{old_name}[\"']?",
                    raw_contents,
                    flags=re.MULTILINE,
                )
            )
            > 1
        ):
            print(color(AnsiFore.BOLD_RED, "Too many matches in YAML to safely rename"))
            return 1

        new_raw = re.sub(
            rf"^(\s+{match.group(1)}):\s+[\"']?{old_name}[\"']?",
            f'\\1: "{args.name}"',
            raw_contents,
            flags=re.MULTILINE,
        )

    new_path = os.path.join(CORE.config_dir, args.name + ".yaml")
    print(
        f"Updating {color(AnsiFore.CYAN, CORE.config_path)} to {color(AnsiFore.CYAN, new_path)}"
    )
    print()

    with open(new_path, mode="w", encoding="utf-8") as new_file:
        new_file.write(new_raw)

    rc = run_external_process("esphome", "config", new_path)
    if rc != 0:
        print(color(AnsiFore.BOLD_RED, "Rename failed. Reverting changes."))
        os.remove(new_path)
        return 1

    cli_args = [
        "run",
        new_path,
        "--no-logs",
        "--device",
        CORE.address,
    ]

    if args.dashboard:
        cli_args.insert(0, "--dashboard")

    try:
        rc = run_external_process("esphome", *cli_args)
    except KeyboardInterrupt:
        rc = 1
    if rc != 0:
        os.remove(new_path)
        return 1

    if CORE.config_path != new_path:
        os.remove(CORE.config_path)

    print(color(AnsiFore.BOLD_GREEN, "SUCCESS"))
    print()
    return 0


PRE_CONFIG_ACTIONS = {
    "wizard": command_wizard,
    "version": command_version,
    "dashboard": command_dashboard,
    "vscode": command_vscode,
    "update-all": command_update_all,
}

POST_CONFIG_ACTIONS = {
    "config": command_config,
    "compile": command_compile,
    "upload": command_upload,
    "logs": command_logs,
    "run": command_run,
    "clean-mqtt": command_clean_mqtt,
    "mqtt-fingerprint": command_mqtt_fingerprint,
    "clean": command_clean,
    "idedata": command_idedata,
    "rename": command_rename,
    "discover": command_discover,
}


def parse_args(argv):
    options_parser = argparse.ArgumentParser(add_help=False)
    options_parser.add_argument(
        "-v",
        "--verbose",
        help="Enable verbose ESPHome logs.",
        action="store_true",
        default=get_bool_env("ESPHOME_VERBOSE"),
    )
    options_parser.add_argument(
        "-q", "--quiet", help="Disable all ESPHome logs.", action="store_true"
    )
    options_parser.add_argument(
        "-l",
        "--log-level",
        help="Set the log level.",
        default=os.getenv("ESPHOME_LOG_LEVEL", "INFO"),
        action="store",
        choices=["DEBUG", "INFO", "WARNING", "ERROR", "CRITICAL"],
    )
    options_parser.add_argument(
        "--dashboard", help=argparse.SUPPRESS, action="store_true"
    )
    options_parser.add_argument(
        "-s",
        "--substitution",
        nargs=2,
        action="append",
        help="Add a substitution",
        metavar=("key", "value"),
    )

    parser = argparse.ArgumentParser(
        description=f"ESPHome {const.__version__}", parents=[options_parser]
    )

    parser.add_argument(
        "--version",
        action="version",
        version=f"Version: {const.__version__}",
        help="Print the ESPHome version and exit.",
    )

    mqtt_options = argparse.ArgumentParser(add_help=False)
    mqtt_options.add_argument("--topic", help="Manually set the MQTT topic.")
    mqtt_options.add_argument("--username", help="Manually set the MQTT username.")
    mqtt_options.add_argument("--password", help="Manually set the MQTT password.")
    mqtt_options.add_argument("--client-id", help="Manually set the MQTT client id.")

    subparsers = parser.add_subparsers(
        help="Command to run:", dest="command", metavar="command"
    )
    subparsers.required = True

    parser_config = subparsers.add_parser(
        "config", help="Validate the configuration and spit it out."
    )
    parser_config.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )
    parser_config.add_argument(
        "--show-secrets", help="Show secrets in output.", action="store_true"
    )

    parser_compile = subparsers.add_parser(
        "compile", help="Read the configuration and compile a program."
    )
    parser_compile.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )
    parser_compile.add_argument(
        "--only-generate",
        help="Only generate source code, do not compile.",
        action="store_true",
    )

    parser_upload = subparsers.add_parser(
        "upload",
        help="Validate the configuration and upload the latest binary.",
        parents=[mqtt_options],
    )
    parser_upload.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )
    parser_upload.add_argument(
        "--device",
        help="Manually specify the serial port/address to use, for example /dev/ttyUSB0.",
    )
    parser_upload.add_argument(
        "--upload_speed",
        help="Override the default or configured upload speed.",
    )
    parser_upload.add_argument(
        "--file",
        help="Manually specify the binary file to upload.",
    )

    parser_logs = subparsers.add_parser(
        "logs",
        help="Validate the configuration and show all logs.",
        aliases=["log"],
        parents=[mqtt_options],
    )
    parser_logs.add_argument(
        "configuration", help="Your YAML configuration file.", nargs=1
    )
    parser_logs.add_argument(
        "--device",
        help="Manually specify the serial port/address to use, for example /dev/ttyUSB0.",
    )
    parser_logs.add_argument(
        "--reset",
        "-r",
        action="store_true",
        help="Reset the device before starting serial logs.",
        default=os.getenv("ESPHOME_SERIAL_LOGGING_RESET"),
    )

    parser_discover = subparsers.add_parser(
        "discover",
        help="Validate the configuration and show all discovered devices.",
        parents=[mqtt_options],
    )
    parser_discover.add_argument(
        "configuration", help="Your YAML configuration file.", nargs=1
    )

    parser_run = subparsers.add_parser(
        "run",
        help="Validate the configuration, create a binary, upload it, and start logs.",
        parents=[mqtt_options],
    )
    parser_run.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )
    parser_run.add_argument(
        "--device",
        help="Manually specify the serial port/address to use, for example /dev/ttyUSB0.",
    )
    parser_run.add_argument(
        "--upload_speed",
        help="Override the default or configured upload speed.",
    )
    parser_run.add_argument(
        "--no-logs", help="Disable starting logs.", action="store_true"
    )
    parser_run.add_argument(
        "--reset",
        "-r",
        action="store_true",
        help="Reset the device before starting serial logs.",
        default=os.getenv("ESPHOME_SERIAL_LOGGING_RESET"),
    )

    parser_clean = subparsers.add_parser(
        "clean-mqtt",
        help="Helper to clear retained messages from an MQTT topic.",
        parents=[mqtt_options],
    )
    parser_clean.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )

    parser_wizard = subparsers.add_parser(
        "wizard",
        help="A helpful setup wizard that will guide you through setting up ESPHome.",
    )
    parser_wizard.add_argument("configuration", help="Your YAML configuration file.")

    parser_fingerprint = subparsers.add_parser(
        "mqtt-fingerprint", help="Get the SSL fingerprint from a MQTT broker."
    )
    parser_fingerprint.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )

    subparsers.add_parser("version", help="Print the ESPHome version and exit.")

    parser_clean = subparsers.add_parser(
        "clean", help="Delete all temporary build files."
    )
    parser_clean.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs="+"
    )

    parser_dashboard = subparsers.add_parser(
        "dashboard", help="Create a simple web server for a dashboard."
    )
    parser_dashboard.add_argument(
        "configuration", help="Your YAML configuration file directory."
    )
    parser_dashboard.add_argument(
        "--port",
        help="The HTTP port to open connections on. Defaults to 6052.",
        type=int,
        default=6052,
    )
    parser_dashboard.add_argument(
        "--address",
        help="The address to bind to.",
        type=str,
        default="0.0.0.0",
    )
    parser_dashboard.add_argument(
        "--username",
        help="The optional username to require for authentication.",
        type=str,
        default="",
    )
    parser_dashboard.add_argument(
        "--password",
        help="The optional password to require for authentication.",
        type=str,
        default="",
    )
    parser_dashboard.add_argument(
        "--open-ui", help="Open the dashboard UI in a browser.", action="store_true"
    )
    parser_dashboard.add_argument(
        "--ha-addon", help=argparse.SUPPRESS, action="store_true"
    )
    parser_dashboard.add_argument(
        "--socket", help="Make the dashboard serve under a unix socket", type=str
    )

    parser_vscode = subparsers.add_parser("vscode")
    parser_vscode.add_argument("configuration", help="Your YAML configuration file.")
    parser_vscode.add_argument("--ace", action="store_true")

    parser_update = subparsers.add_parser("update-all")
    parser_update.add_argument(
        "configuration", help="Your YAML configuration file directories.", nargs="+"
    )

    parser_idedata = subparsers.add_parser("idedata")
    parser_idedata.add_argument(
        "configuration", help="Your YAML configuration file(s).", nargs=1
    )

    parser_rename = subparsers.add_parser(
        "rename",
        help="Rename a device in YAML, compile the binary and upload it.",
    )
    parser_rename.add_argument(
        "configuration", help="Your YAML configuration file.", nargs=1
    )
    parser_rename.add_argument("name", help="The new name for the device.", type=str)

    # Keep backward compatibility with the old command line format of
    # esphome <config> <command>.
    #
    # Unfortunately this can't be done by adding another configuration argument to the
    # main config parser, as argparse is greedy when parsing arguments, so in regular
    # usage it'll eat the command as the configuration argument and error out out
    # because it can't parse the configuration as a command.
    #
    # Instead, if parsing using the current format fails, construct an ad-hoc parser
    # that doesn't actually process the arguments, but parses them enough to let us
    # figure out if the old format is used. In that case, swap the command and
    # configuration in the arguments and retry with the normal parser (and raise
    # a deprecation warning).
    arguments = argv[1:]

    argcomplete.autocomplete(parser)
    return parser.parse_args(arguments)


def run_esphome(argv):
    args = parse_args(argv)
    CORE.dashboard = args.dashboard

    # Override log level if verbose is set
    if args.verbose:
        args.log_level = "DEBUG"
    elif args.quiet:
        args.log_level = "CRITICAL"

    setup_log(
        log_level=args.log_level,
        # Show timestamp for dashboard access logs
        include_timestamp=args.command == "dashboard",
    )

    if args.command in PRE_CONFIG_ACTIONS:
        try:
            return PRE_CONFIG_ACTIONS[args.command](args)
        except EsphomeError as e:
            _LOGGER.error(e, exc_info=args.verbose)
            return 1

    _LOGGER.info("ESPHome %s", const.__version__)

    for conf_path in args.configuration:
        if any(os.path.basename(conf_path) == x for x in SECRETS_FILES):
            _LOGGER.warning("Skipping secrets file %s", conf_path)
            continue

        CORE.config_path = conf_path
        CORE.dashboard = args.dashboard

        config = read_config(dict(args.substitution) if args.substitution else {})
        if config is None:
            return 2
        CORE.config = config

        if args.command not in POST_CONFIG_ACTIONS:
            safe_print(f"Unknown command {args.command}")

        try:
            rc = POST_CONFIG_ACTIONS[args.command](args, config)
        except EsphomeError as e:
            _LOGGER.error(e, exc_info=args.verbose)
            return 1
        if rc != 0:
            return rc

        CORE.reset()
    return 0


def main():
    try:
        return run_esphome(sys.argv)
    except EsphomeError as e:
        _LOGGER.error(e)
        return 1
    except KeyboardInterrupt:
        return 1


if __name__ == "__main__":
    sys.exit(main())
