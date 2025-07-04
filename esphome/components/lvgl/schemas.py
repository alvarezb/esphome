from esphome import config_validation as cv
from esphome.automation import Trigger, validate_automation
from esphome.components.time import RealTimeClock
from esphome.const import (
    CONF_ARGS,
    CONF_FORMAT,
    CONF_GROUP,
    CONF_ID,
    CONF_ON_BOOT,
    CONF_ON_VALUE,
    CONF_STATE,
    CONF_TEXT,
    CONF_TIME,
    CONF_TRIGGER_ID,
    CONF_TYPE,
    CONF_X,
    CONF_Y,
)
from esphome.core import TimePeriod
from esphome.core.config import StartupTrigger
from esphome.schema_extractors import SCHEMA_EXTRACT

from . import defines as df, lv_validation as lvalid
from .defines import CONF_TIME_FORMAT, LV_GRAD_DIR, TYPE_GRID
from .helpers import add_lv_use, requires_component, validate_printf
from .lv_validation import lv_color, lv_font, lv_gradient, lv_image, opacity
from .lvcode import LvglComponent, lv_event_t_ptr
from .types import (
    LVEncoderListener,
    LvType,
    WidgetType,
    lv_group_t,
    lv_obj_t,
    lv_pseudo_button_t,
    lv_style_t,
)

# this will be populated later, in __init__.py to avoid circular imports.
WIDGET_TYPES: dict = {}

TIME_TEXT_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_TIME_FORMAT): cv.string,
        cv.GenerateID(CONF_TIME): cv.templatable(cv.use_id(RealTimeClock)),
    }
)

PRINTF_TEXT_SCHEMA = cv.All(
    cv.Schema(
        {
            cv.Required(CONF_FORMAT): cv.string,
            cv.Optional(CONF_ARGS, default=list): cv.ensure_list(cv.lambda_),
        },
    ),
    validate_printf,
)


def _validate_text(value):
    """
    Do some sanity checking of the format to get better error messages
    than using cv.Any
    """
    if value is None:
        raise cv.Invalid("No text specified")
    if isinstance(value, dict):
        if CONF_TIME_FORMAT in value:
            return TIME_TEXT_SCHEMA(value)
        return PRINTF_TEXT_SCHEMA(value)

    return cv.templatable(cv.string)(value)


# A schema for text properties
TEXT_SCHEMA = cv.Schema(
    {
        cv.Optional(CONF_TEXT): _validate_text,
    }
)

LIST_ACTION_SCHEMA = cv.ensure_list(
    cv.maybe_simple_value(
        {
            cv.Required(CONF_ID): cv.use_id(lv_pseudo_button_t),
        },
        key=CONF_ID,
    )
)

PRESS_TIME = cv.All(
    lvalid.lv_milliseconds, cv.Range(max=TimePeriod(milliseconds=65535))
)

ENCODER_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.All(
            cv.declare_id(LVEncoderListener), requires_component("binary_sensor")
        ),
        cv.Optional(CONF_GROUP): cv.declare_id(lv_group_t),
        cv.Optional(df.CONF_INITIAL_FOCUS): cv.All(
            LIST_ACTION_SCHEMA, cv.Length(min=1, max=1)
        ),
        cv.Optional(df.CONF_LONG_PRESS_TIME, default="400ms"): PRESS_TIME,
        cv.Optional(df.CONF_LONG_PRESS_REPEAT_TIME, default="100ms"): PRESS_TIME,
    }
)

POINT_SCHEMA = cv.Schema(
    {
        cv.Required(CONF_X): cv.templatable(cv.int_),
        cv.Required(CONF_Y): cv.templatable(cv.int_),
    }
)


def point_schema(value):
    """
    A shorthand for a point in the form of x,y
    :param value: The value to check
    :return: The value as a tuple of x,y
    """
    if isinstance(value, dict):
        return POINT_SCHEMA(value)
    try:
        x, y = map(int, value.split(","))
        return {CONF_X: x, CONF_Y: y}
    except ValueError:
        pass
    # not raising this in the catch block because pylint doesn't like it
    raise cv.Invalid("Invalid point format, should be <x_int>, <y_int>")


# All LVGL styles and their validators
STYLE_PROPS = {
    "align": df.CHILD_ALIGNMENTS.one_of,
    "arc_opa": lvalid.opacity,
    "arc_color": lvalid.lv_color,
    "arc_rounded": lvalid.lv_bool,
    "arc_width": lvalid.lv_positive_int,
    "anim_time": lvalid.lv_milliseconds,
    "bg_color": lvalid.lv_color,
    "bg_grad": lv_gradient,
    "bg_grad_color": lvalid.lv_color,
    "bg_dither_mode": df.LvConstant("LV_DITHER_", "NONE", "ORDERED", "ERR_DIFF").one_of,
    "bg_grad_dir": LV_GRAD_DIR.one_of,
    "bg_grad_stop": lvalid.stop_value,
    "bg_image_opa": lvalid.opacity,
    "bg_image_recolor": lvalid.lv_color,
    "bg_image_recolor_opa": lvalid.opacity,
    "bg_image_src": lvalid.lv_image,
    "bg_image_tiled": lvalid.lv_bool,
    "bg_main_stop": lvalid.stop_value,
    "bg_opa": lvalid.opacity,
    "border_color": lvalid.lv_color,
    "border_opa": lvalid.opacity,
    "border_post": lvalid.lv_bool,
    "border_side": df.LvConstant(
        "LV_BORDER_SIDE_", "NONE", "TOP", "BOTTOM", "LEFT", "RIGHT", "INTERNAL"
    ).several_of,
    "border_width": lvalid.lv_positive_int,
    "clip_corner": lvalid.lv_bool,
    "color_filter_opa": lvalid.opacity,
    "height": lvalid.size,
    "image_recolor": lvalid.lv_color,
    "image_recolor_opa": lvalid.opacity,
    "line_width": lvalid.lv_positive_int,
    "line_dash_width": lvalid.lv_positive_int,
    "line_dash_gap": lvalid.lv_positive_int,
    "line_rounded": lvalid.lv_bool,
    "line_color": lvalid.lv_color,
    "opa": lvalid.opacity,
    "opa_layered": lvalid.opacity,
    "outline_color": lvalid.lv_color,
    "outline_opa": lvalid.opacity,
    "outline_pad": lvalid.padding,
    "outline_width": lvalid.pixels,
    "pad_all": lvalid.padding,
    "pad_bottom": lvalid.padding,
    "pad_left": lvalid.padding,
    "pad_right": lvalid.padding,
    "pad_top": lvalid.padding,
    "shadow_color": lvalid.lv_color,
    "shadow_ofs_x": lvalid.lv_int,
    "shadow_ofs_y": lvalid.lv_int,
    "shadow_opa": lvalid.opacity,
    "shadow_spread": lvalid.lv_int,
    "shadow_width": lvalid.lv_positive_int,
    "text_align": df.LvConstant(
        "LV_TEXT_ALIGN_", "LEFT", "CENTER", "RIGHT", "AUTO"
    ).one_of,
    "text_color": lvalid.lv_color,
    "text_decor": df.LvConstant(
        "LV_TEXT_DECOR_", "NONE", "UNDERLINE", "STRIKETHROUGH"
    ).several_of,
    "text_font": lv_font,
    "text_letter_space": lvalid.lv_positive_int,
    "text_line_space": lvalid.lv_positive_int,
    "text_opa": lvalid.opacity,
    "transform_angle": lvalid.lv_angle,
    "transform_height": lvalid.pixels_or_percent,
    "transform_pivot_x": lvalid.pixels_or_percent,
    "transform_pivot_y": lvalid.pixels_or_percent,
    "transform_zoom": lvalid.zoom,
    "translate_x": lvalid.pixels_or_percent,
    "translate_y": lvalid.pixels_or_percent,
    "max_height": lvalid.pixels_or_percent,
    "max_width": lvalid.pixels_or_percent,
    "min_height": lvalid.pixels_or_percent,
    "min_width": lvalid.pixels_or_percent,
    "radius": lvalid.lv_fraction,
    "width": lvalid.size,
    "x": lvalid.pixels_or_percent,
    "y": lvalid.pixels_or_percent,
}

STYLE_REMAP = {
    "bg_image_opa": "bg_img_opa",
    "bg_image_recolor": "bg_img_recolor",
    "bg_image_recolor_opa": "bg_img_recolor_opa",
    "bg_image_src": "bg_img_src",
    "bg_image_tiled": "bg_img_tiled",
    "image_recolor": "img_recolor",
    "image_recolor_opa": "img_recolor_opa",
}

cell_alignments = df.LV_CELL_ALIGNMENTS.one_of
grid_alignments = df.LV_GRID_ALIGNMENTS.one_of
flex_alignments = df.LV_FLEX_ALIGNMENTS.one_of

# Complete object style schema
STYLE_SCHEMA = cv.Schema({cv.Optional(k): v for k, v in STYLE_PROPS.items()}).extend(
    {
        cv.Optional(df.CONF_STYLES): cv.ensure_list(cv.use_id(lv_style_t)),
        cv.Optional(df.CONF_SCROLLBAR_MODE): df.LvConstant(
            "LV_SCROLLBAR_MODE_", "OFF", "ON", "ACTIVE", "AUTO"
        ).one_of,
    }
)

# Also allow widget specific properties for use in style definitions
FULL_STYLE_SCHEMA = STYLE_SCHEMA.extend(
    {
        cv.Optional(df.CONF_GRID_CELL_X_ALIGN): grid_alignments,
        cv.Optional(df.CONF_GRID_CELL_Y_ALIGN): grid_alignments,
        cv.Optional(df.CONF_PAD_ROW): lvalid.padding,
        cv.Optional(df.CONF_PAD_COLUMN): lvalid.padding,
    }
)

# Object states. Top level properties apply to MAIN
STATE_SCHEMA = cv.Schema(
    {cv.Optional(state): STYLE_SCHEMA for state in df.STATES}
).extend(STYLE_SCHEMA)
# Setting object states
SET_STATE_SCHEMA = cv.Schema(
    {cv.Optional(state): lvalid.lv_bool for state in df.STATES}
)
# Setting object flags
FLAG_SCHEMA = cv.Schema({cv.Optional(flag): lvalid.lv_bool for flag in df.OBJ_FLAGS})
FLAG_LIST = cv.ensure_list(df.LvConstant("LV_OBJ_FLAG_", *df.OBJ_FLAGS).one_of)


def part_schema(parts):
    """
    Generate a schema for the various parts (e.g. main:, indicator:) of a widget type
    :param parts:  The parts to include
    :return: The schema
    """
    return (
        cv.Schema({cv.Optional(part): STATE_SCHEMA for part in parts})
        .extend(STATE_SCHEMA)
        .extend(FLAG_SCHEMA)
    )


def automation_schema(typ: LvType):
    events = df.LV_EVENT_TRIGGERS + df.SWIPE_TRIGGERS
    if typ.has_on_value:
        events = events + (CONF_ON_VALUE,)
    args = typ.get_arg_type() if isinstance(typ, LvType) else []
    args.append(lv_event_t_ptr)
    return cv.Schema(
        {
            cv.Optional(event): validate_automation(
                {
                    cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(
                        Trigger.template(*args)
                    ),
                }
            )
            for event in events
        }
    ).extend(
        {
            cv.Optional(CONF_ON_BOOT): validate_automation(
                {cv.GenerateID(CONF_TRIGGER_ID): cv.declare_id(StartupTrigger)}
            )
        }
    )


def base_update_schema(widget_type, parts):
    """
    Create a schema for updating a widgets style properties, states and flags
    :param widget_type: The type of the ID
    :param parts:  The allowable parts to specify
    :return:
    """
    return part_schema(parts).extend(
        {
            cv.Required(CONF_ID): cv.ensure_list(
                cv.maybe_simple_value(
                    {
                        cv.Required(CONF_ID): cv.use_id(widget_type),
                    },
                    key=CONF_ID,
                )
            ),
            cv.Optional(CONF_STATE): SET_STATE_SCHEMA,
        }
    )


def create_modify_schema(widget_type):
    return base_update_schema(widget_type.w_type, widget_type.parts).extend(
        widget_type.modify_schema
    )


def obj_schema(widget_type: WidgetType):
    """
    Create a schema for a widget type itself i.e. no allowance for children
    :param widget_type:
    :return:
    """
    return (
        part_schema(widget_type.parts)
        .extend(LAYOUT_SCHEMA)
        .extend(ALIGN_TO_SCHEMA)
        .extend(automation_schema(widget_type.w_type))
        .extend(
            cv.Schema(
                {
                    cv.Optional(CONF_STATE): SET_STATE_SCHEMA,
                    cv.Optional(CONF_GROUP): cv.use_id(lv_group_t),
                }
            )
        )
    )


def _validate_grid_layout(config):
    layout = config[df.CONF_LAYOUT]
    rows = len(layout[df.CONF_GRID_ROWS])
    columns = len(layout[df.CONF_GRID_COLUMNS])
    used_cells = [[None] * columns for _ in range(rows)]
    for index, widget in enumerate(config[df.CONF_WIDGETS]):
        _, w = next(iter(widget.items()))
        if (df.CONF_GRID_CELL_COLUMN_POS in w) != (df.CONF_GRID_CELL_ROW_POS in w):
            # pylint: disable=raise-missing-from
            raise cv.Invalid(
                "Both row and column positions must be specified, or both omitted",
                [df.CONF_WIDGETS, index],
            )
        if df.CONF_GRID_CELL_ROW_POS in w:
            row = w[df.CONF_GRID_CELL_ROW_POS]
            column = w[df.CONF_GRID_CELL_COLUMN_POS]
        else:
            try:
                row, column = next(
                    (r_idx, c_idx)
                    for r_idx, row in enumerate(used_cells)
                    for c_idx, value in enumerate(row)
                    if value is None
                )
            except StopIteration:
                # pylint: disable=raise-missing-from
                raise cv.Invalid(
                    "No free cells available in grid layout", [df.CONF_WIDGETS, index]
                )
            w[df.CONF_GRID_CELL_ROW_POS] = row
            w[df.CONF_GRID_CELL_COLUMN_POS] = column

        for i in range(w[df.CONF_GRID_CELL_ROW_SPAN]):
            for j in range(w[df.CONF_GRID_CELL_COLUMN_SPAN]):
                if row + i >= rows or column + j >= columns:
                    # pylint: disable=raise-missing-from
                    raise cv.Invalid(
                        f"Cell at {row}/{column} span {w[df.CONF_GRID_CELL_ROW_SPAN]}x{w[df.CONF_GRID_CELL_COLUMN_SPAN]} "
                        f"exceeds grid size {rows}x{columns}",
                        [df.CONF_WIDGETS, index],
                    )
                if used_cells[row + i][column + j] is not None:
                    # pylint: disable=raise-missing-from
                    raise cv.Invalid(
                        f"Cell span {row + i}/{column + j} already occupied by widget at index {used_cells[row + i][column + j]}",
                        [df.CONF_WIDGETS, index],
                    )
                used_cells[row + i][column + j] = index

    return config


LAYOUT_SCHEMAS = {}
LAYOUT_VALIDATORS = {TYPE_GRID: _validate_grid_layout}

ALIGN_TO_SCHEMA = {
    cv.Optional(df.CONF_ALIGN_TO): cv.Schema(
        {
            cv.Required(CONF_ID): cv.use_id(lv_obj_t),
            cv.Required(df.CONF_ALIGN): df.ALIGN_ALIGNMENTS.one_of,
            cv.Optional(CONF_X, default=0): lvalid.pixels_or_percent,
            cv.Optional(CONF_Y, default=0): lvalid.pixels_or_percent,
        }
    )
}


def grid_free_space(value):
    value = cv.Upper(value)
    if value.startswith("FR(") and value.endswith(")"):
        value = value.removesuffix(")").removeprefix("FR(")
        return f"LV_GRID_FR({cv.positive_int(value)})"
    raise cv.Invalid("must be a size in pixels, CONTENT or FR(nn)")


grid_spec = cv.Any(
    lvalid.size, df.LvConstant("LV_GRID_", "CONTENT").one_of, grid_free_space
)

LAYOUT_SCHEMA = {
    cv.Optional(df.CONF_LAYOUT): cv.typed_schema(
        {
            df.TYPE_GRID: {
                cv.Required(df.CONF_GRID_ROWS): [grid_spec],
                cv.Required(df.CONF_GRID_COLUMNS): [grid_spec],
                cv.Optional(df.CONF_GRID_COLUMN_ALIGN): grid_alignments,
                cv.Optional(df.CONF_GRID_ROW_ALIGN): grid_alignments,
                cv.Optional(df.CONF_PAD_ROW): lvalid.padding,
                cv.Optional(df.CONF_PAD_COLUMN): lvalid.padding,
            },
            df.TYPE_FLEX: {
                cv.Optional(
                    df.CONF_FLEX_FLOW, default="row_wrap"
                ): df.FLEX_FLOWS.one_of,
                cv.Optional(df.CONF_FLEX_ALIGN_MAIN, default="start"): flex_alignments,
                cv.Optional(df.CONF_FLEX_ALIGN_CROSS, default="start"): flex_alignments,
                cv.Optional(df.CONF_FLEX_ALIGN_TRACK, default="start"): flex_alignments,
                cv.Optional(df.CONF_PAD_ROW): lvalid.padding,
                cv.Optional(df.CONF_PAD_COLUMN): lvalid.padding,
            },
        },
        lower=True,
    )
}

GRID_CELL_SCHEMA = {
    cv.Optional(df.CONF_GRID_CELL_ROW_POS): cv.positive_int,
    cv.Optional(df.CONF_GRID_CELL_COLUMN_POS): cv.positive_int,
    cv.Optional(df.CONF_GRID_CELL_ROW_SPAN, default=1): cv.positive_int,
    cv.Optional(df.CONF_GRID_CELL_COLUMN_SPAN, default=1): cv.positive_int,
    cv.Optional(df.CONF_GRID_CELL_X_ALIGN): grid_alignments,
    cv.Optional(df.CONF_GRID_CELL_Y_ALIGN): grid_alignments,
}

FLEX_OBJ_SCHEMA = {
    cv.Optional(df.CONF_FLEX_GROW): cv.int_,
}

DISP_BG_SCHEMA = cv.Schema(
    {
        cv.Optional(df.CONF_DISP_BG_IMAGE): cv.Any(
            cv.one_of("none", lower=True), lv_image
        ),
        cv.Optional(df.CONF_DISP_BG_COLOR): lv_color,
        cv.Optional(df.CONF_DISP_BG_OPA): opacity,
    }
)

# A style schema that can include text
STYLED_TEXT_SCHEMA = cv.maybe_simple_value(
    STYLE_SCHEMA.extend(TEXT_SCHEMA), key=CONF_TEXT
)

# For use by platform components
LVGL_SCHEMA = cv.Schema(
    {
        cv.GenerateID(df.CONF_LVGL_ID): cv.use_id(LvglComponent),
    }
)

ALL_STYLES = {
    **STYLE_PROPS,
    **GRID_CELL_SCHEMA,
    **FLEX_OBJ_SCHEMA,
    cv.Optional(df.CONF_PAD_ROW): lvalid.padding,
    cv.Optional(df.CONF_PAD_COLUMN): lvalid.padding,
}


def container_validator(schema, widget_type: WidgetType):
    """
    Create a validator for a container given the widget type
    :param schema: Base schema to extend
    :param widget_type:
    :return:
    """

    def validator(value):
        if w_sch := widget_type.schema:
            if isinstance(w_sch, dict):
                w_sch = cv.Schema(w_sch)
            # order is important here to preserve extras
            result = w_sch.extend(schema)
        else:
            result = schema
        ltype = df.TYPE_NONE
        if value and (layout := value.get(df.CONF_LAYOUT)):
            if not isinstance(layout, dict):
                raise cv.Invalid("Layout value must be a dict")
            ltype = layout.get(CONF_TYPE)
            if not ltype:
                raise (cv.Invalid("Layout schema requires type:"))
            add_lv_use(ltype)
        if value == SCHEMA_EXTRACT:
            return result
        result = result.extend(
            LAYOUT_SCHEMAS.get(ltype.lower(), LAYOUT_SCHEMAS[df.TYPE_NONE])
        )
        value = result(value)
        if layout_validator := LAYOUT_VALIDATORS.get(ltype):
            value = layout_validator(value)
        return value

    return validator


def container_schema(widget_type: WidgetType, extras=None):
    """
    Create a schema for a container widget of a given type. All obj properties are available, plus
    the extras passed in, plus any defined for the specific widget being specified.
    :param widget_type:     The widget type, e.g. "img"
    :param extras:  Additional options to be made available, e.g. layout properties for children
    :return: The schema for this type of widget.
    """
    schema = obj_schema(widget_type).extend(
        {cv.GenerateID(): cv.declare_id(widget_type.w_type)}
    )
    if extras:
        schema = schema.extend(extras)
    # Delayed evaluation for recursion
    return container_validator(schema, widget_type)


def widget_schema(widget_type: WidgetType, extras=None):
    """
    Create a schema for a given widget type
    :param widget_type: The name of the widget
    :param extras:
    :return:
    """
    validator = container_schema(widget_type, extras=extras)
    if required := widget_type.required_component:
        validator = cv.All(validator, requires_component(required))
    return cv.Exclusive(widget_type.name, df.CONF_WIDGETS), validator


# All widget schemas must be defined before this is called.


def any_widget_schema(extras=None):
    """
    Generate schemas for all possible LVGL widgets. This is what implements the ability to have a list of any kind of
    widget under the widgets: key.

    :param extras: Additional schema to be applied to each generated one
    :return:
    """
    return cv.Any(dict(widget_schema(wt, extras) for wt in WIDGET_TYPES.values()))
