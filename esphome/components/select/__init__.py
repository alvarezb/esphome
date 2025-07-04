from esphome import automation
import esphome.codegen as cg
from esphome.components import mqtt, web_server
import esphome.config_validation as cv
from esphome.const import (
    CONF_CYCLE,
    CONF_ENTITY_CATEGORY,
    CONF_ICON,
    CONF_ID,
    CONF_INDEX,
    CONF_MODE,
    CONF_MQTT_ID,
    CONF_ON_VALUE,
    CONF_OPERATION,
    CONF_OPTION,
    CONF_TRIGGER_ID,
    CONF_WEB_SERVER,
)
from esphome.core import CORE, coroutine_with_priority
from esphome.core.entity_helpers import entity_duplicate_validator, setup_entity
from esphome.cpp_generator import MockObjClass

CODEOWNERS = ["@esphome/core"]
IS_PLATFORM_COMPONENT = True

select_ns = cg.esphome_ns.namespace("select")
Select = select_ns.class_("Select", cg.EntityBase)
SelectPtr = Select.operator("ptr")

# Triggers
SelectStateTrigger = select_ns.class_(
    "SelectStateTrigger",
    automation.Trigger.template(cg.std_string, cg.size_t),
)

# Actions
SelectSetAction = select_ns.class_("SelectSetAction", automation.Action)
SelectSetIndexAction = select_ns.class_("SelectSetIndexAction", automation.Action)
SelectOperationAction = select_ns.class_("SelectOperationAction", automation.Action)

# Enums
SelectOperation = select_ns.enum("SelectOperation")
SELECT_OPERATION_OPTIONS = {
    "NEXT": SelectOperation.SELECT_OP_NEXT,
    "PREVIOUS": SelectOperation.SELECT_OP_PREVIOUS,
    "FIRST": SelectOperation.SELECT_OP_FIRST,
    "LAST": SelectOperation.SELECT_OP_LAST,
}


_SELECT_SCHEMA = (
    cv.ENTITY_BASE_SCHEMA.extend(web_server.WEBSERVER_SORTING_SCHEMA)
    .extend(cv.MQTT_COMMAND_COMPONENT_SCHEMA)
    .extend(
        {
            cv.OnlyWith(CONF_MQTT_ID, "mqtt"): cv.declare_id(mqtt.MQTTSelectComponent),
            cv.GenerateID(): cv.declare_id(Select),
            cv.Optional(CONF_ON_VALUE): automation.validate_automation(
                {
                    cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(SelectStateTrigger),
                }
            ),
        }
    )
)


_SELECT_SCHEMA.add_extra(entity_duplicate_validator("select"))


def select_schema(
    class_: MockObjClass,
    *,
    entity_category: str = cv.UNDEFINED,
    icon: str = cv.UNDEFINED,
):
    schema = {cv.GenerateID(): cv.declare_id(class_)}

    for key, default, validator in [
        (CONF_ENTITY_CATEGORY, entity_category, cv.entity_category),
        (CONF_ICON, icon, cv.icon),
    ]:
        if default is not cv.UNDEFINED:
            schema[cv.Optional(key, default=default)] = validator

    return _SELECT_SCHEMA.extend(schema)


# Remove before 2025.11.0
SELECT_SCHEMA = select_schema(Select)
SELECT_SCHEMA.add_extra(cv.deprecated_schema_constant("select"))


async def setup_select_core_(var, config, *, options: list[str]):
    await setup_entity(var, config, "select")

    cg.add(var.traits.set_options(options))

    for conf in config.get(CONF_ON_VALUE, []):
        trigger = cg.new_Pvariable(conf[CONF_TRIGGER_ID], var)
        await automation.build_automation(
            trigger, [(cg.std_string, "x"), (cg.size_t, "i")], conf
        )

    if (mqtt_id := config.get(CONF_MQTT_ID)) is not None:
        mqtt_ = cg.new_Pvariable(mqtt_id, var)
        await mqtt.register_mqtt_component(mqtt_, config)

    if web_server_config := config.get(CONF_WEB_SERVER):
        await web_server.add_entity_config(var, web_server_config)


async def register_select(var, config, *, options: list[str]):
    if not CORE.has_id(config[CONF_ID]):
        var = cg.Pvariable(config[CONF_ID], var)
    cg.add(cg.App.register_select(var))
    CORE.register_platform_component("select", var)
    await setup_select_core_(var, config, options=options)


async def new_select(config, *, options: list[str]):
    var = cg.new_Pvariable(config[CONF_ID])
    await register_select(var, config, options=options)
    return var


@coroutine_with_priority(100.0)
async def to_code(config):
    cg.add_define("USE_SELECT")
    cg.add_global(select_ns.using)


OPERATION_BASE_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_ID): cv.use_id(Select),
    }
)


@automation.register_action(
    "select.set",
    SelectSetAction,
    OPERATION_BASE_SCHEMA.extend(
        {
            cv.Required(CONF_OPTION): cv.templatable(cv.string_strict),
        }
    ),
)
async def select_set_to_code(config, action_id, template_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    var = cg.new_Pvariable(action_id, template_arg, paren)
    template_ = await cg.templatable(config[CONF_OPTION], args, cg.std_string)
    cg.add(var.set_option(template_))
    return var


@automation.register_action(
    "select.set_index",
    SelectSetIndexAction,
    OPERATION_BASE_SCHEMA.extend(
        {
            cv.Required(CONF_INDEX): cv.templatable(cv.positive_int),
        }
    ),
)
async def select_set_index_to_code(config, action_id, template_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    var = cg.new_Pvariable(action_id, template_arg, paren)
    template_ = await cg.templatable(config[CONF_INDEX], args, cg.size_t)
    cg.add(var.set_index(template_))
    return var


@automation.register_action(
    "select.operation",
    SelectOperationAction,
    OPERATION_BASE_SCHEMA.extend(
        {
            cv.Required(CONF_OPERATION): cv.templatable(
                cv.enum(SELECT_OPERATION_OPTIONS, upper=True)
            ),
            cv.Optional(CONF_CYCLE, default=True): cv.templatable(cv.boolean),
        }
    ),
)
@automation.register_action(
    "select.next",
    SelectOperationAction,
    automation.maybe_simple_id(
        OPERATION_BASE_SCHEMA.extend(
            {
                cv.Optional(CONF_MODE, default="NEXT"): cv.one_of("NEXT", upper=True),
                cv.Optional(CONF_CYCLE, default=True): cv.boolean,
            }
        )
    ),
)
@automation.register_action(
    "select.previous",
    SelectOperationAction,
    automation.maybe_simple_id(
        OPERATION_BASE_SCHEMA.extend(
            {
                cv.Optional(CONF_MODE, default="PREVIOUS"): cv.one_of(
                    "PREVIOUS", upper=True
                ),
                cv.Optional(CONF_CYCLE, default=True): cv.boolean,
            }
        )
    ),
)
@automation.register_action(
    "select.first",
    SelectOperationAction,
    automation.maybe_simple_id(
        OPERATION_BASE_SCHEMA.extend(
            {
                cv.Optional(CONF_MODE, default="FIRST"): cv.one_of("FIRST", upper=True),
            }
        )
    ),
)
@automation.register_action(
    "select.last",
    SelectOperationAction,
    automation.maybe_simple_id(
        OPERATION_BASE_SCHEMA.extend(
            {
                cv.Optional(CONF_MODE, default="LAST"): cv.one_of("LAST", upper=True),
            }
        )
    ),
)
async def select_operation_to_code(config, action_id, template_arg, args):
    paren = await cg.get_variable(config[CONF_ID])
    var = cg.new_Pvariable(action_id, template_arg, paren)
    if (operation := config.get(CONF_OPERATION)) is not None:
        op_ = await cg.templatable(operation, args, SelectOperation)
        cg.add(var.set_operation(op_))
        if (cycle := config.get(CONF_CYCLE)) is not None:
            template_ = await cg.templatable(cycle, args, bool)
            cg.add(var.set_cycle(template_))
    if (mode := config.get(CONF_MODE)) is not None:
        cg.add(var.set_operation(SELECT_OPERATION_OPTIONS[mode]))
        if (cycle := config.get(CONF_CYCLE)) is not None:
            cg.add(var.set_cycle(cycle))
    return var
