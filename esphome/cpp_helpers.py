import logging

from esphome.const import (
    CONF_SAFE_MODE,
    CONF_SETUP_PRIORITY,
    CONF_TYPE_ID,
    CONF_UPDATE_INTERVAL,
    KEY_PAST_SAFE_MODE,
)
from esphome.core import CORE, ID, coroutine
from esphome.coroutine import FakeAwaitable
from esphome.cpp_generator import add, get_variable
from esphome.cpp_types import App
from esphome.types import ConfigFragmentType, ConfigType
from esphome.util import Registry, RegistryEntry

_LOGGER = logging.getLogger(__name__)


async def gpio_pin_expression(conf):
    """Generate an expression for the given pin option.

    This is a coroutine, you must await it with a 'await' expression!
    """
    if conf is None:
        return None
    from esphome import pins

    for key, (func, _, _) in pins.PIN_SCHEMA_REGISTRY.items():
        if key in conf:
            return await coroutine(func)(conf)
    return await coroutine(pins.PIN_SCHEMA_REGISTRY[CORE.target_platform][0])(conf)


async def register_component(var, config):
    """Register the given obj as a component.

    This is a coroutine, you must await it with a 'await' expression!

    :param var: The variable representing the component.
    :param config: The configuration for the component.
    """
    import inspect

    id_ = str(var.base)
    if id_ not in CORE.component_ids:
        raise ValueError(
            f"Component ID {id_} was not declared to inherit from Component, or was registered twice. Please create a bug report with your configuration."
        )
    CORE.component_ids.remove(id_)
    if CONF_SETUP_PRIORITY in config:
        add(var.set_setup_priority(config[CONF_SETUP_PRIORITY]))
    if CONF_UPDATE_INTERVAL in config:
        add(var.set_update_interval(config[CONF_UPDATE_INTERVAL]))

    # Set component source by inspecting the stack and getting the callee module
    # https://stackoverflow.com/a/1095621
    name = None
    try:
        for frm in inspect.stack()[1:]:
            mod = inspect.getmodule(frm[0])
            if mod is None:
                continue
            name = mod.__name__
            if name.startswith("esphome.components."):
                name = name[len("esphome.components.") :]
                break
            if name == "esphome.automation":
                name = "automation"
                # continue looking further up in stack in case we find a better one
            if name == "esphome.coroutine":
                # Only works for async-await coroutine syntax
                break
    except (KeyError, AttributeError, IndexError) as e:
        _LOGGER.warning(
            "Error while finding name of component, please report this", exc_info=e
        )
    if name is not None:
        add(var.set_component_source(name))

    add(App.register_component(var))
    return var


async def register_parented(var, value):
    if isinstance(value, ID):
        paren = await get_variable(value)
    else:
        paren = value
    add(var.set_parent(paren))


def extract_registry_entry_config(
    registry: Registry,
    full_config: ConfigType,
) -> tuple[RegistryEntry, ConfigFragmentType]:
    key, config = next((k, v) for k, v in full_config.items() if k in registry)
    return registry[key], config


async def build_registry_entry(registry, full_config):
    registry_entry, config = extract_registry_entry_config(registry, full_config)
    type_id = full_config[CONF_TYPE_ID]
    builder = registry_entry.coroutine_fun
    return await builder(config, type_id)


async def build_registry_list(registry, config):
    actions = []
    for conf in config:
        action = await build_registry_entry(registry, conf)
        actions.append(action)
    return actions


async def past_safe_mode():
    if CONF_SAFE_MODE not in CORE.config:
        return

    def _safe_mode_generator():
        while True:
            if CORE.data.get(CONF_SAFE_MODE, {}).get(KEY_PAST_SAFE_MODE, False):
                return
            yield

    return await FakeAwaitable(_safe_mode_generator())
