from esphome import automation
from esphome.automation import maybe_simple_id
import esphome.codegen as cg
from esphome.components import mqtt, web_server
import esphome.config_validation as cv
from esphome.const import (
    CONF_DEVICE_CLASS,
    CONF_ENTITY_CATEGORY,
    CONF_ICON,
    CONF_ID,
    CONF_MQTT_ID,
    CONF_ON_PRESS,
    CONF_TRIGGER_ID,
    CONF_WEB_SERVER,
    DEVICE_CLASS_EMPTY,
    DEVICE_CLASS_IDENTIFY,
    DEVICE_CLASS_RESTART,
    DEVICE_CLASS_UPDATE,
)
from esphome.core import CORE, coroutine_with_priority
from esphome.core.entity_helpers import entity_duplicate_validator, setup_entity
from esphome.cpp_generator import MockObjClass

CODEOWNERS = ["@esphome/core"]
IS_PLATFORM_COMPONENT = True

DEVICE_CLASSES = [
    DEVICE_CLASS_EMPTY,
    DEVICE_CLASS_IDENTIFY,
    DEVICE_CLASS_RESTART,
    DEVICE_CLASS_UPDATE,
]

button_ns = cg.esphome_ns.namespace("button")
Button = button_ns.class_("Button", cg.EntityBase)
ButtonPtr = Button.operator("ptr")

PressAction = button_ns.class_("PressAction", automation.Action)

ButtonPressTrigger = button_ns.class_(
    "ButtonPressTrigger", automation.Trigger.template()
)

validate_device_class = cv.one_of(*DEVICE_CLASSES, lower=True, space="_")


_BUTTON_SCHEMA = (
    cv.ENTITY_BASE_SCHEMA.extend(web_server.WEBSERVER_SORTING_SCHEMA)
    .extend(cv.MQTT_COMMAND_COMPONENT_SCHEMA)
    .extend(
        {
            cv.OnlyWith(CONF_MQTT_ID, "mqtt"): cv.declare_id(mqtt.MQTTButtonComponent),
            cv.Optional(CONF_DEVICE_CLASS): validate_device_class,
            cv.Optional(CONF_ON_PRESS): automation.validate_automation(
                {
                    cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(ButtonPressTrigger),
                }
            ),
        }
    )
)


_BUTTON_SCHEMA.add_extra(entity_duplicate_validator("button"))


def button_schema(
    class_: MockObjClass,
    *,
    icon: str = cv.UNDEFINED,
    entity_category: str = cv.UNDEFINED,
    device_class: str = cv.UNDEFINED,
) -> cv.Schema:
    schema = {cv.GenerateID(): cv.declare_id(class_)}

    for key, default, validator in [
        (CONF_ICON, icon, cv.icon),
        (CONF_ENTITY_CATEGORY, entity_category, cv.entity_category),
        (CONF_DEVICE_CLASS, device_class, validate_device_class),
    ]:
        if default is not cv.UNDEFINED:
            schema[cv.Optional(key, default=default)] = validator

    return _BUTTON_SCHEMA.extend(schema)


# Remove before 2025.11.0
BUTTON_SCHEMA = button_schema(Button)
BUTTON_SCHEMA.add_extra(cv.deprecated_schema_constant("button"))


async def setup_button_core_(var, config):
    await setup_entity(var, config, "button")

    for conf in config.get(CONF_ON_PRESS, []):
        trigger = cg.new_Pvariable(conf[CONF_TRIGGER_ID], var)
        await automation.build_automation(trigger, [], conf)

    if device_class := config.get(CONF_DEVICE_CLASS):
        cg.add(var.set_device_class(device_class))

    if mqtt_id := config.get(CONF_MQTT_ID):
        mqtt_ = cg.new_Pvariable(mqtt_id, var)
        await mqtt.register_mqtt_component(mqtt_, config)

    if web_server_config := config.get(CONF_WEB_SERVER):
        await web_server.add_entity_config(var, web_server_config)


async def register_button(var, config):
    if not CORE.has_id(config[CONF_ID]):
        var = cg.Pvariable(config[CONF_ID], var)
    cg.add(cg.App.register_button(var))
    CORE.register_platform_component("button", var)
    await setup_button_core_(var, config)


async def new_button(config, *args):
    var = cg.new_Pvariable(config[CONF_ID], *args)
    await register_button(var, config)
    return var


BUTTON_PRESS_SCHEMA = maybe_simple_id(
    {
        cv.Required(CONF_ID): cv.use_id(Button),
    }
)


@automation.register_action("button.press", PressAction, BUTTON_PRESS_SCHEMA)
async def button_press_to_code(config, action_id, template_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    return cg.new_Pvariable(action_id, template_arg, paren)


@coroutine_with_priority(100.0)
async def to_code(config):
    cg.add_global(button_ns.using)
    cg.add_define("USE_BUTTON")
