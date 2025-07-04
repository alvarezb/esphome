import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    CONF_MAC_ADDRESS,
    KEY_CORE,
    KEY_FRAMEWORK_VERSION,
    KEY_TARGET_FRAMEWORK,
    KEY_TARGET_PLATFORM,
    PLATFORM_HOST,
)
from esphome.core import CORE

from .const import KEY_HOST

# force import gpio to register pin schema
from .gpio import host_pin_to_code  # noqa

CODEOWNERS = ["@esphome/core", "@clydebarrow"]
AUTO_LOAD = ["network", "preferences"]
IS_TARGET_PLATFORM = True


def set_core_data(config):
    CORE.data[KEY_HOST] = {}
    CORE.data[KEY_CORE][KEY_TARGET_PLATFORM] = PLATFORM_HOST
    CORE.data[KEY_CORE][KEY_TARGET_FRAMEWORK] = "host"
    CORE.data[KEY_CORE][KEY_FRAMEWORK_VERSION] = cv.Version(1, 0, 0)
    return config


CONFIG_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.Optional(CONF_MAC_ADDRESS, default="98:35:69:ab:f6:79"): cv.mac_address,
        }
    ),
    set_core_data,
)


async def to_code(config):
    cg.add_build_flag("-DUSE_HOST")
    cg.add_define("USE_ESPHOME_HOST_MAC_ADDRESS", config[CONF_MAC_ADDRESS].parts)
    cg.add_build_flag("-std=gnu++20")
    cg.add_define("ESPHOME_BOARD", "host")
    cg.add_platformio_option("platform", "platformio/native")
