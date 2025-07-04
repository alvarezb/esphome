# Dummy integration to allow relying on AsyncTCP
import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import (
    PLATFORM_BK72XX,
    PLATFORM_ESP32,
    PLATFORM_ESP8266,
    PLATFORM_RTL87XX,
)
from esphome.core import CORE, coroutine_with_priority

CODEOWNERS = ["@OttoWinter"]

CONFIG_SCHEMA = cv.All(
    cv.Schema({}),
    cv.only_with_arduino,
    cv.only_on([PLATFORM_ESP32, PLATFORM_ESP8266, PLATFORM_BK72XX, PLATFORM_RTL87XX]),
)


@coroutine_with_priority(200.0)
async def to_code(config):
    if CORE.is_esp32 or CORE.is_libretiny:
        # https://github.com/ESP32Async/AsyncTCP
        cg.add_library("ESP32Async/AsyncTCP", "3.4.4")
    elif CORE.is_esp8266:
        # https://github.com/ESP32Async/ESPAsyncTCP
        cg.add_library("ESP32Async/ESPAsyncTCP", "2.0.0")
