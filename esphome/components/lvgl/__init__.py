import logging

from esphome.automation import build_automation, register_action, validate_automation
import esphome.codegen as cg
from esphome.components.const import CONF_DRAW_ROUNDING
from esphome.components.display import Display
import esphome.config_validation as cv
from esphome.const import (
    CONF_AUTO_CLEAR_ENABLED,
    CONF_BUFFER_SIZE,
    CONF_GROUP,
    CONF_ID,
    CONF_LAMBDA,
    CONF_ON_BOOT,
    CONF_ON_IDLE,
    CONF_PAGES,
    CONF_TIMEOUT,
    CONF_TRIGGER_ID,
    CONF_TYPE,
)
from esphome.core import CORE, ID, Lambda
from esphome.cpp_generator import MockObj
from esphome.final_validate import full_config
from esphome.helpers import write_file_if_changed

from . import defines as df, helpers, lv_validation as lvalid
from .automation import disp_update, focused_widgets, refreshed_widgets, update_to_code
from .defines import add_define
from .encoders import (
    ENCODERS_CONFIG,
    encoders_to_code,
    get_default_group,
    initial_focus_to_code,
)
from .gradient import GRADIENT_SCHEMA, gradients_to_code
from .hello_world import get_hello_world
from .keypads import KEYPADS_CONFIG, keypads_to_code
from .lv_validation import lv_bool, lv_images_used
from .lvcode import LvContext, LvglComponent, lvgl_static
from .schemas import (
    DISP_BG_SCHEMA,
    FLEX_OBJ_SCHEMA,
    FULL_STYLE_SCHEMA,
    GRID_CELL_SCHEMA,
    LAYOUT_SCHEMAS,
    WIDGET_TYPES,
    any_widget_schema,
    container_schema,
    create_modify_schema,
    obj_schema,
)
from .styles import add_top_layer, styles_to_code, theme_to_code
from .touchscreens import touchscreen_schema, touchscreens_to_code
from .trigger import add_on_boot_triggers, generate_triggers
from .types import (
    FontEngine,
    IdleTrigger,
    ObjUpdateAction,
    PauseTrigger,
    lv_font_t,
    lv_group_t,
    lv_style_t,
    lvgl_ns,
)
from .widgets import (
    LvScrActType,
    Widget,
    add_widgets,
    get_scr_act,
    set_obj_properties,
    styles_used,
)
from .widgets.animimg import animimg_spec
from .widgets.arc import arc_spec
from .widgets.button import button_spec
from .widgets.buttonmatrix import buttonmatrix_spec
from .widgets.canvas import canvas_spec
from .widgets.checkbox import checkbox_spec
from .widgets.dropdown import dropdown_spec
from .widgets.img import img_spec
from .widgets.keyboard import keyboard_spec
from .widgets.label import label_spec
from .widgets.led import led_spec
from .widgets.line import line_spec
from .widgets.lv_bar import bar_spec
from .widgets.meter import meter_spec
from .widgets.msgbox import MSGBOX_SCHEMA, msgboxes_to_code
from .widgets.obj import obj_spec
from .widgets.page import add_pages, generate_page_triggers, page_spec
from .widgets.qrcode import qr_code_spec
from .widgets.roller import roller_spec
from .widgets.slider import slider_spec
from .widgets.spinbox import spinbox_spec
from .widgets.spinner import spinner_spec
from .widgets.switch import switch_spec
from .widgets.tabview import tabview_spec
from .widgets.textarea import textarea_spec
from .widgets.tileview import tileview_spec

DOMAIN = "lvgl"
DEPENDENCIES = ["display"]
AUTO_LOAD = ["key_provider"]
CODEOWNERS = ["@clydebarrow"]
LOGGER = logging.getLogger(__name__)

for w_type in (
    label_spec,
    obj_spec,
    button_spec,
    bar_spec,
    slider_spec,
    arc_spec,
    line_spec,
    spinner_spec,
    led_spec,
    animimg_spec,
    checkbox_spec,
    img_spec,
    switch_spec,
    tabview_spec,
    buttonmatrix_spec,
    meter_spec,
    dropdown_spec,
    roller_spec,
    textarea_spec,
    spinbox_spec,
    keyboard_spec,
    tileview_spec,
    qr_code_spec,
    canvas_spec,
):
    WIDGET_TYPES[w_type.name] = w_type

WIDGET_SCHEMA = any_widget_schema()

LAYOUT_SCHEMAS[df.TYPE_GRID] = {
    cv.Optional(df.CONF_WIDGETS): cv.ensure_list(any_widget_schema(GRID_CELL_SCHEMA))
}
LAYOUT_SCHEMAS[df.TYPE_FLEX] = {
    cv.Optional(df.CONF_WIDGETS): cv.ensure_list(any_widget_schema(FLEX_OBJ_SCHEMA))
}
LAYOUT_SCHEMAS[df.TYPE_NONE] = {
    cv.Optional(df.CONF_WIDGETS): cv.ensure_list(any_widget_schema())
}
for w_type in WIDGET_TYPES.values():
    register_action(
        f"lvgl.{w_type.name}.update",
        ObjUpdateAction,
        create_modify_schema(w_type),
    )(update_to_code)


def as_macro(macro, value):
    if value is None:
        return f"#define {macro}"
    return f"#define {macro} {value}"


LV_CONF_FILENAME = "lv_conf.h"
LV_CONF_H_FORMAT = """\
#pragma once
{}
"""


def generate_lv_conf_h():
    definitions = [as_macro(m, v) for m, v in df.lv_defines.items()]
    definitions.sort()
    return LV_CONF_H_FORMAT.format("\n".join(definitions))


def multi_conf_validate(configs: list[dict]):
    displays = [config[df.CONF_DISPLAYS] for config in configs]
    # flatten the display list
    display_list = [disp for disps in displays for disp in disps]
    if len(display_list) != len(set(display_list)):
        raise cv.Invalid("A display ID may be used in only one LVGL instance")
    for config in configs:
        for item in (df.CONF_ENCODERS, df.CONF_KEYPADS):
            for enc in config.get(item, ()):
                if CONF_GROUP not in enc:
                    raise cv.Invalid(
                        f"'{item}' must have an explicit group set when using multiple LVGL instances"
                    )
    base_config = configs[0]
    for config in configs[1:]:
        for item in (
            df.CONF_LOG_LEVEL,
            df.CONF_COLOR_DEPTH,
            df.CONF_BYTE_ORDER,
            df.CONF_TRANSPARENCY_KEY,
        ):
            if base_config[item] != config[item]:
                raise cv.Invalid(
                    f"Config item '{item}' must be the same for all LVGL instances"
                )


def final_validation(configs):
    if len(configs) != 1:
        multi_conf_validate(configs)
    global_config = full_config.get()
    for config in configs:
        if pages := config.get(CONF_PAGES):
            if all(p[df.CONF_SKIP] for p in pages):
                raise cv.Invalid("At least one page must not be skipped")
        for display_id in config[df.CONF_DISPLAYS]:
            path = global_config.get_path_for_id(display_id)[:-1]
            display = global_config.get_config_for_path(path)
            if CONF_LAMBDA in display or CONF_PAGES in display:
                raise cv.Invalid(
                    "Using lambda: or pages: in display config is not compatible with LVGL"
                )
            if display.get(CONF_AUTO_CLEAR_ENABLED) is True:
                raise cv.Invalid(
                    "Using auto_clear_enabled: true in display config not compatible with LVGL"
                )
            if draw_rounding := display.get(CONF_DRAW_ROUNDING):
                config[CONF_DRAW_ROUNDING] = max(
                    draw_rounding, config[CONF_DRAW_ROUNDING]
                )
        buffer_frac = config[CONF_BUFFER_SIZE]
        if CORE.is_esp32 and buffer_frac > 0.5 and "psram" not in global_config:
            LOGGER.warning("buffer_size: may need to be reduced without PSRAM")
        for image_id in lv_images_used:
            path = global_config.get_path_for_id(image_id)[:-1]
            image_conf = global_config.get_config_for_path(path)
            if image_conf[CONF_TYPE] in ("RGBA", "RGB24"):
                raise cv.Invalid(
                    "Using RGBA or RGB24 in image config not compatible with LVGL", path
                )
        for w in focused_widgets:
            path = global_config.get_path_for_id(w)
            widget_conf = global_config.get_config_for_path(path[:-1])
            if (
                df.CONF_ADJUSTABLE in widget_conf
                and not widget_conf[df.CONF_ADJUSTABLE]
            ):
                raise cv.Invalid(
                    "A non adjustable arc may not be focused",
                    path,
                )
        for w in refreshed_widgets:
            path = global_config.get_path_for_id(w)
            widget_conf = global_config.get_config_for_path(path[:-1])
            if not any(isinstance(v, Lambda) for v in widget_conf.values()):
                raise cv.Invalid(
                    f"Widget '{w}' does not have any templated properties to refresh",
                )


async def to_code(configs):
    config_0 = configs[0]
    # Global configuration
    cg.add_library("lvgl/lvgl", "8.4.0")
    cg.add_define("USE_LVGL")
    # suppress default enabling of extra widgets
    add_define("_LV_KCONFIG_PRESENT")
    # Always enable - lots of things use it.
    add_define("LV_DRAW_COMPLEX", "1")
    add_define("LV_TICK_CUSTOM", "1")
    add_define("LV_TICK_CUSTOM_INCLUDE", '"esphome/components/lvgl/lvgl_hal.h"')
    add_define("LV_TICK_CUSTOM_SYS_TIME_EXPR", "(lv_millis())")
    add_define("LV_MEM_CUSTOM", "1")
    add_define("LV_MEM_CUSTOM_ALLOC", "lv_custom_mem_alloc")
    add_define("LV_MEM_CUSTOM_FREE", "lv_custom_mem_free")
    add_define("LV_MEM_CUSTOM_REALLOC", "lv_custom_mem_realloc")
    add_define("LV_MEM_CUSTOM_INCLUDE", '"esphome/components/lvgl/lvgl_hal.h"')

    add_define(
        "LV_LOG_LEVEL",
        f"LV_LOG_LEVEL_{df.LV_LOG_LEVELS[config_0[df.CONF_LOG_LEVEL]]}",
    )
    cg.add_define(
        "LVGL_LOG_LEVEL",
        cg.RawExpression(f"ESPHOME_LOG_LEVEL_{config_0[df.CONF_LOG_LEVEL]}"),
    )
    add_define("LV_COLOR_DEPTH", config_0[df.CONF_COLOR_DEPTH])
    for font in helpers.lv_fonts_used:
        add_define(f"LV_FONT_{font.upper()}")

    if config_0[df.CONF_COLOR_DEPTH] == 16:
        add_define(
            "LV_COLOR_16_SWAP",
            "1" if config_0[df.CONF_BYTE_ORDER] == "big_endian" else "0",
        )
    add_define(
        "LV_COLOR_CHROMA_KEY",
        await lvalid.lv_color.process(config_0[df.CONF_TRANSPARENCY_KEY]),
    )
    cg.add_build_flag("-Isrc")

    cg.add_global(lvgl_ns.using)
    for font in helpers.esphome_fonts_used:
        await cg.get_variable(font)
        cg.new_Pvariable(ID(f"{font}_engine", True, type=FontEngine), MockObj(font))
    default_font = config_0[df.CONF_DEFAULT_FONT]
    if not lvalid.is_lv_font(default_font):
        add_define(
            "LV_FONT_CUSTOM_DECLARE", f"LV_FONT_DECLARE(*{df.DEFAULT_ESPHOME_FONT})"
        )
        globfont_id = ID(
            df.DEFAULT_ESPHOME_FONT,
            True,
            type=lv_font_t.operator("ptr").operator("const"),
        )
        cg.new_variable(
            globfont_id, MockObj(await lvalid.lv_font.process(default_font))
        )
        add_define("LV_FONT_DEFAULT", df.DEFAULT_ESPHOME_FONT)
    else:
        add_define("LV_FONT_DEFAULT", await lvalid.lv_font.process(default_font))
    cg.add(lvgl_static.esphome_lvgl_init())
    default_group = get_default_group(config_0)

    for config in configs:
        frac = config[CONF_BUFFER_SIZE]
        if frac >= 0.75:
            frac = 1
        elif frac >= 0.375:
            frac = 2
        elif frac > 0.19:
            frac = 4
        elif frac != 0:
            frac = 8
        displays = [
            await cg.get_variable(display) for display in config[df.CONF_DISPLAYS]
        ]
        lv_component = cg.new_Pvariable(
            config[CONF_ID],
            displays,
            frac,
            config[df.CONF_FULL_REFRESH],
            config[CONF_DRAW_ROUNDING],
            config[df.CONF_RESUME_ON_INPUT],
        )
        await cg.register_component(lv_component, config)
        Widget.create(config[CONF_ID], lv_component, LvScrActType(), config)

        lv_scr_act = get_scr_act(lv_component)
        async with LvContext():
            await touchscreens_to_code(lv_component, config)
            await encoders_to_code(lv_component, config, default_group)
            await keypads_to_code(lv_component, config, default_group)
            await theme_to_code(config)
            await gradients_to_code(config)
            await styles_to_code(config)
            await set_obj_properties(lv_scr_act, config)
            await add_widgets(lv_scr_act, config)
            await add_pages(lv_component, config)
            await add_top_layer(lv_component, config)
            await msgboxes_to_code(lv_component, config)
            await disp_update(lv_component.get_disp(), config)
    # Set this directly since we are limited in how many methods can be added to the Widget class.
    Widget.widgets_completed = True
    async with LvContext():
        await generate_triggers()
        for config in configs:
            lv_component = await cg.get_variable(config[CONF_ID])
            await generate_page_triggers(config)
            await initial_focus_to_code(config)
            for conf in config.get(CONF_ON_IDLE, ()):
                templ = await cg.templatable(conf[CONF_TIMEOUT], [], cg.uint32)
                idle_trigger = cg.new_Pvariable(
                    conf[CONF_TRIGGER_ID], lv_component, templ
                )
                await build_automation(idle_trigger, [], conf)
            for conf in config.get(df.CONF_ON_PAUSE, ()):
                pause_trigger = cg.new_Pvariable(
                    conf[CONF_TRIGGER_ID], lv_component, True
                )
                await build_automation(pause_trigger, [], conf)
            for conf in config.get(df.CONF_ON_RESUME, ()):
                resume_trigger = cg.new_Pvariable(
                    conf[CONF_TRIGGER_ID], lv_component, False
                )
                await build_automation(resume_trigger, [], conf)
            await add_on_boot_triggers(config.get(CONF_ON_BOOT, ()))

    # This must be done after all widgets are created
    for comp in helpers.lvgl_components_required:
        cg.add_define(f"USE_LVGL_{comp.upper()}")
    if "transform_angle" in styles_used:
        add_define("LV_COLOR_SCREEN_TRANSP", "1")
    for use in helpers.lv_uses:
        add_define(f"LV_USE_{use.upper()}")
        cg.add_define(f"USE_LVGL_{use.upper()}")
    lv_conf_h_file = CORE.relative_src_path(LV_CONF_FILENAME)
    write_file_if_changed(lv_conf_h_file, generate_lv_conf_h())
    cg.add_build_flag("-DLV_CONF_H=1")
    cg.add_build_flag(f'-DLV_CONF_PATH="{LV_CONF_FILENAME}"')


def display_schema(config):
    value = cv.ensure_list(cv.use_id(Display))(config)
    value = value or [cv.use_id(Display)(config)]
    if len(set(value)) != len(value):
        raise cv.Invalid("Display IDs must be unique")
    return value


def add_hello_world(config):
    if df.CONF_WIDGETS not in config and CONF_PAGES not in config:
        LOGGER.info("No pages or widgets configured, creating default hello_world page")
        config[df.CONF_WIDGETS] = cv.ensure_list(WIDGET_SCHEMA)(get_hello_world())
    return config


FINAL_VALIDATE_SCHEMA = final_validation

LVGL_SCHEMA = cv.All(
    container_schema(
        obj_spec,
        cv.polling_component_schema("1s")
        .extend(
            {
                cv.GenerateID(CONF_ID): cv.declare_id(LvglComponent),
                cv.GenerateID(df.CONF_DISPLAYS): display_schema,
                cv.Optional(df.CONF_COLOR_DEPTH, default=16): cv.one_of(16),
                cv.Optional(
                    df.CONF_DEFAULT_FONT, default="montserrat_14"
                ): lvalid.lv_font,
                cv.Optional(df.CONF_FULL_REFRESH, default=False): cv.boolean,
                cv.Optional(CONF_DRAW_ROUNDING, default=2): cv.positive_int,
                cv.Optional(CONF_BUFFER_SIZE, default=0): cv.percentage,
                cv.Optional(df.CONF_LOG_LEVEL, default="WARN"): cv.one_of(
                    *df.LV_LOG_LEVELS, upper=True
                ),
                cv.Optional(df.CONF_BYTE_ORDER, default="big_endian"): cv.one_of(
                    "big_endian", "little_endian"
                ),
                cv.Optional(df.CONF_STYLE_DEFINITIONS): cv.ensure_list(
                    cv.Schema({cv.Required(CONF_ID): cv.declare_id(lv_style_t)}).extend(
                        FULL_STYLE_SCHEMA
                    )
                ),
                cv.Optional(CONF_ON_IDLE): validate_automation(
                    {
                        cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(IdleTrigger),
                        cv.Required(CONF_TIMEOUT): cv.templatable(
                            cv.positive_time_period_milliseconds
                        ),
                    }
                ),
                cv.Optional(df.CONF_ON_PAUSE): validate_automation(
                    {
                        cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(PauseTrigger),
                    }
                ),
                cv.Optional(df.CONF_ON_RESUME): validate_automation(
                    {
                        cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(PauseTrigger),
                    }
                ),
                cv.Exclusive(df.CONF_WIDGETS, CONF_PAGES): cv.ensure_list(
                    WIDGET_SCHEMA
                ),
                cv.Exclusive(CONF_PAGES, CONF_PAGES): cv.ensure_list(
                    container_schema(page_spec)
                ),
                cv.Optional(df.CONF_MSGBOXES): cv.ensure_list(MSGBOX_SCHEMA),
                cv.Optional(df.CONF_PAGE_WRAP, default=True): lv_bool,
                cv.Optional(df.CONF_TOP_LAYER): container_schema(obj_spec),
                cv.Optional(
                    df.CONF_TRANSPARENCY_KEY, default=0x000400
                ): lvalid.lv_color,
                cv.Optional(df.CONF_THEME): cv.Schema(
                    {
                        cv.Optional(name): obj_schema(w).extend(FULL_STYLE_SCHEMA)
                        for name, w in WIDGET_TYPES.items()
                    }
                ),
                cv.Optional(df.CONF_GRADIENTS): GRADIENT_SCHEMA,
                cv.Optional(df.CONF_TOUCHSCREENS, default=None): touchscreen_schema,
                cv.Optional(df.CONF_ENCODERS, default=None): ENCODERS_CONFIG,
                cv.Optional(df.CONF_KEYPADS, default=None): KEYPADS_CONFIG,
                cv.GenerateID(df.CONF_DEFAULT_GROUP): cv.declare_id(lv_group_t),
                cv.Optional(df.CONF_RESUME_ON_INPUT, default=True): cv.boolean,
            }
        )
        .extend(DISP_BG_SCHEMA),
    ),
    cv.has_at_most_one_key(CONF_PAGES, df.CONF_LAYOUT),
    add_hello_world,
)


def lvgl_config_schema(config):
    """
    Can't use cv.ensure_list here because it converts an empty config to an empty list,
    rather than a default config.
    """
    if not config or isinstance(config, dict):
        return [LVGL_SCHEMA(config)]
    return cv.Schema([LVGL_SCHEMA])(config)


CONFIG_SCHEMA = lvgl_config_schema
