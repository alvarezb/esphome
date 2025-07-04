from string import ascii_letters, digits

import esphome.codegen as cg
from esphome.components import color
import esphome.config_validation as cv
from esphome.const import CONF_BACKGROUND_COLOR, CONF_FOREGROUND_COLOR, CONF_VISIBLE

from . import CONF_NEXTION_ID, Nextion

CONF_AUTO_WAKE_ON_TOUCH = "auto_wake_on_touch"
CONF_BACKGROUND_PRESSED_COLOR = "background_pressed_color"
CONF_COMMAND_SPACING = "command_spacing"
CONF_COMPONENT_NAME = "component_name"
CONF_EXIT_REPARSE_ON_START = "exit_reparse_on_start"
CONF_FONT_ID = "font_id"
CONF_FOREGROUND_PRESSED_COLOR = "foreground_pressed_color"
CONF_MAX_COMMANDS_PER_LOOP = "max_commands_per_loop"
CONF_MAX_QUEUE_SIZE = "max_queue_size"
CONF_ON_BUFFER_OVERFLOW = "on_buffer_overflow"
CONF_ON_PAGE = "on_page"
CONF_ON_SETUP = "on_setup"
CONF_ON_SLEEP = "on_sleep"
CONF_ON_WAKE = "on_wake"
CONF_PRECISION = "precision"
CONF_SKIP_CONNECTION_HANDSHAKE = "skip_connection_handshake"
CONF_START_UP_PAGE = "start_up_page"
CONF_TFT_URL = "tft_url"
CONF_TOUCH_SLEEP_TIMEOUT = "touch_sleep_timeout"
CONF_VARIABLE_NAME = "variable_name"
CONF_WAKE_UP_PAGE = "wake_up_page"
CONF_WAVE_CHANNEL_ID = "wave_channel_id"
CONF_WAVE_MAX_LENGTH = "wave_max_length"
CONF_WAVE_MAX_VALUE = "wave_max_value"
CONF_WAVEFORM_SEND_LAST_VALUE = "waveform_send_last_value"


def NextionName(value):
    valid_chars = f"{ascii_letters + digits + '_'}."
    if not isinstance(value, str) or len(value) > 29:
        raise cv.Invalid("Must be a string less than 29 characters")

    for char in value:
        if char not in valid_chars:
            raise cv.Invalid(
                f"Must only consist of upper/lowercase characters, numbers, the underscore '_', and the period '.'. The character '{char}' cannot be used."
            )

    return value


CONFIG_BASE_COMPONENT_SCHEMA = cv.Schema(
    {
        cv.GenerateID(CONF_NEXTION_ID): cv.use_id(Nextion),
        cv.Optional(CONF_BACKGROUND_COLOR): cv.use_id(color),
        cv.Optional(CONF_FOREGROUND_COLOR): cv.use_id(color),
        cv.Optional(CONF_VISIBLE, default=True): cv.boolean,
    }
)


CONFIG_TEXT_COMPONENT_SCHEMA = CONFIG_BASE_COMPONENT_SCHEMA.extend(
    cv.Schema(
        {
            cv.Required(CONF_COMPONENT_NAME): NextionName,
            cv.Optional(CONF_FONT_ID): cv.int_range(min=0, max=255),
        }
    )
)

CONFIG_BINARY_SENSOR_SCHEMA = CONFIG_BASE_COMPONENT_SCHEMA.extend(
    cv.Schema(
        {
            cv.Optional(CONF_COMPONENT_NAME): NextionName,
            cv.Optional(CONF_VARIABLE_NAME): NextionName,
        }
    )
)

CONFIG_SENSOR_COMPONENT_SCHEMA = CONFIG_BINARY_SENSOR_SCHEMA.extend(
    cv.Schema(
        {
            cv.Optional(CONF_FONT_ID): cv.int_range(min=0, max=255),
        }
    )
)


CONFIG_SWITCH_COMPONENT_SCHEMA = CONFIG_SENSOR_COMPONENT_SCHEMA.extend(
    cv.Schema(
        {
            cv.Optional(CONF_FOREGROUND_PRESSED_COLOR): cv.use_id(color),
            cv.Optional(CONF_BACKGROUND_PRESSED_COLOR): cv.use_id(color),
        }
    )
)


async def setup_component_core_(var, config, arg):
    if CONF_VARIABLE_NAME in config:
        cg.add(var.set_variable_name(config[CONF_VARIABLE_NAME]))
    elif CONF_COMPONENT_NAME in config:
        cg.add(
            var.set_variable_name(
                config[CONF_COMPONENT_NAME],
                config[CONF_COMPONENT_NAME] + arg,
            )
        )

    if CONF_BACKGROUND_COLOR in config:
        color_component = await cg.get_variable(config[CONF_BACKGROUND_COLOR])
        cg.add(var.set_background_color(color_component))

    if CONF_BACKGROUND_PRESSED_COLOR in config:
        color_component = await cg.get_variable(config[CONF_BACKGROUND_PRESSED_COLOR])
        cg.add(var.set_background_pressed_color(color_component))

    if CONF_FOREGROUND_COLOR in config:
        color_component = await cg.get_variable(config[CONF_FOREGROUND_COLOR])
        cg.add(var.set_foreground_color(color_component))

    if CONF_FOREGROUND_PRESSED_COLOR in config:
        color_component = await cg.get_variable(config[CONF_FOREGROUND_PRESSED_COLOR])
        cg.add(var.set_foreground_pressed_color(color_component))

    if CONF_FONT_ID in config:
        cg.add(var.set_font_id(config[CONF_FONT_ID]))

    if CONF_VISIBLE in config:
        cg.add(var.set_visible(config[CONF_VISIBLE]))
