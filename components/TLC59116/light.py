import esphome.config_validation as cv
import esphome.codegen as cg
from esphome.components import light, output
from esphome.const import CONF_OUTPUT_ID, CONF_OUTPUT

TLC59116_ns = cg.esphome_ns.namespace("TLC59116")
TLC59116 = TLC59116_ns.class_("TLC59116Output", light.LightOutput)

CONFIG_SCHEMA = light.BRIGHTNESS_ONLY_LIGHT_SCHEMA.extend(
    {
        cv.GenerateID(CONF_OUTPUT_ID): cv.declare_id(TLC59116),
        cv.Required(CONF_OUTPUT): cv.use_id(output.FloatOutput),
    }
)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_OUTPUT_ID])
    await light.register_light(var, config)

    out = await cg.get_variable(config[CONF_OUTPUT])
    cg.add(var.set_output(out))