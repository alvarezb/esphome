// This file was automatically generated with a tool.
// See script/api_protobuf/api_protobuf.py
#include "api_pb2.h"
#include "api_pb2_size.h"
#include "esphome/core/log.h"

#include <cinttypes>

namespace esphome {
namespace api {

#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::EntityCategory>(enums::EntityCategory value) {
  switch (value) {
    case enums::ENTITY_CATEGORY_NONE:
      return "ENTITY_CATEGORY_NONE";
    case enums::ENTITY_CATEGORY_CONFIG:
      return "ENTITY_CATEGORY_CONFIG";
    case enums::ENTITY_CATEGORY_DIAGNOSTIC:
      return "ENTITY_CATEGORY_DIAGNOSTIC";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::LegacyCoverState>(enums::LegacyCoverState value) {
  switch (value) {
    case enums::LEGACY_COVER_STATE_OPEN:
      return "LEGACY_COVER_STATE_OPEN";
    case enums::LEGACY_COVER_STATE_CLOSED:
      return "LEGACY_COVER_STATE_CLOSED";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::CoverOperation>(enums::CoverOperation value) {
  switch (value) {
    case enums::COVER_OPERATION_IDLE:
      return "COVER_OPERATION_IDLE";
    case enums::COVER_OPERATION_IS_OPENING:
      return "COVER_OPERATION_IS_OPENING";
    case enums::COVER_OPERATION_IS_CLOSING:
      return "COVER_OPERATION_IS_CLOSING";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::LegacyCoverCommand>(enums::LegacyCoverCommand value) {
  switch (value) {
    case enums::LEGACY_COVER_COMMAND_OPEN:
      return "LEGACY_COVER_COMMAND_OPEN";
    case enums::LEGACY_COVER_COMMAND_CLOSE:
      return "LEGACY_COVER_COMMAND_CLOSE";
    case enums::LEGACY_COVER_COMMAND_STOP:
      return "LEGACY_COVER_COMMAND_STOP";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::FanSpeed>(enums::FanSpeed value) {
  switch (value) {
    case enums::FAN_SPEED_LOW:
      return "FAN_SPEED_LOW";
    case enums::FAN_SPEED_MEDIUM:
      return "FAN_SPEED_MEDIUM";
    case enums::FAN_SPEED_HIGH:
      return "FAN_SPEED_HIGH";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::FanDirection>(enums::FanDirection value) {
  switch (value) {
    case enums::FAN_DIRECTION_FORWARD:
      return "FAN_DIRECTION_FORWARD";
    case enums::FAN_DIRECTION_REVERSE:
      return "FAN_DIRECTION_REVERSE";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ColorMode>(enums::ColorMode value) {
  switch (value) {
    case enums::COLOR_MODE_UNKNOWN:
      return "COLOR_MODE_UNKNOWN";
    case enums::COLOR_MODE_ON_OFF:
      return "COLOR_MODE_ON_OFF";
    case enums::COLOR_MODE_LEGACY_BRIGHTNESS:
      return "COLOR_MODE_LEGACY_BRIGHTNESS";
    case enums::COLOR_MODE_BRIGHTNESS:
      return "COLOR_MODE_BRIGHTNESS";
    case enums::COLOR_MODE_WHITE:
      return "COLOR_MODE_WHITE";
    case enums::COLOR_MODE_COLOR_TEMPERATURE:
      return "COLOR_MODE_COLOR_TEMPERATURE";
    case enums::COLOR_MODE_COLD_WARM_WHITE:
      return "COLOR_MODE_COLD_WARM_WHITE";
    case enums::COLOR_MODE_RGB:
      return "COLOR_MODE_RGB";
    case enums::COLOR_MODE_RGB_WHITE:
      return "COLOR_MODE_RGB_WHITE";
    case enums::COLOR_MODE_RGB_COLOR_TEMPERATURE:
      return "COLOR_MODE_RGB_COLOR_TEMPERATURE";
    case enums::COLOR_MODE_RGB_COLD_WARM_WHITE:
      return "COLOR_MODE_RGB_COLD_WARM_WHITE";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::SensorStateClass>(enums::SensorStateClass value) {
  switch (value) {
    case enums::STATE_CLASS_NONE:
      return "STATE_CLASS_NONE";
    case enums::STATE_CLASS_MEASUREMENT:
      return "STATE_CLASS_MEASUREMENT";
    case enums::STATE_CLASS_TOTAL_INCREASING:
      return "STATE_CLASS_TOTAL_INCREASING";
    case enums::STATE_CLASS_TOTAL:
      return "STATE_CLASS_TOTAL";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::SensorLastResetType>(enums::SensorLastResetType value) {
  switch (value) {
    case enums::LAST_RESET_NONE:
      return "LAST_RESET_NONE";
    case enums::LAST_RESET_NEVER:
      return "LAST_RESET_NEVER";
    case enums::LAST_RESET_AUTO:
      return "LAST_RESET_AUTO";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::LogLevel>(enums::LogLevel value) {
  switch (value) {
    case enums::LOG_LEVEL_NONE:
      return "LOG_LEVEL_NONE";
    case enums::LOG_LEVEL_ERROR:
      return "LOG_LEVEL_ERROR";
    case enums::LOG_LEVEL_WARN:
      return "LOG_LEVEL_WARN";
    case enums::LOG_LEVEL_INFO:
      return "LOG_LEVEL_INFO";
    case enums::LOG_LEVEL_CONFIG:
      return "LOG_LEVEL_CONFIG";
    case enums::LOG_LEVEL_DEBUG:
      return "LOG_LEVEL_DEBUG";
    case enums::LOG_LEVEL_VERBOSE:
      return "LOG_LEVEL_VERBOSE";
    case enums::LOG_LEVEL_VERY_VERBOSE:
      return "LOG_LEVEL_VERY_VERBOSE";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ServiceArgType>(enums::ServiceArgType value) {
  switch (value) {
    case enums::SERVICE_ARG_TYPE_BOOL:
      return "SERVICE_ARG_TYPE_BOOL";
    case enums::SERVICE_ARG_TYPE_INT:
      return "SERVICE_ARG_TYPE_INT";
    case enums::SERVICE_ARG_TYPE_FLOAT:
      return "SERVICE_ARG_TYPE_FLOAT";
    case enums::SERVICE_ARG_TYPE_STRING:
      return "SERVICE_ARG_TYPE_STRING";
    case enums::SERVICE_ARG_TYPE_BOOL_ARRAY:
      return "SERVICE_ARG_TYPE_BOOL_ARRAY";
    case enums::SERVICE_ARG_TYPE_INT_ARRAY:
      return "SERVICE_ARG_TYPE_INT_ARRAY";
    case enums::SERVICE_ARG_TYPE_FLOAT_ARRAY:
      return "SERVICE_ARG_TYPE_FLOAT_ARRAY";
    case enums::SERVICE_ARG_TYPE_STRING_ARRAY:
      return "SERVICE_ARG_TYPE_STRING_ARRAY";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ClimateMode>(enums::ClimateMode value) {
  switch (value) {
    case enums::CLIMATE_MODE_OFF:
      return "CLIMATE_MODE_OFF";
    case enums::CLIMATE_MODE_HEAT_COOL:
      return "CLIMATE_MODE_HEAT_COOL";
    case enums::CLIMATE_MODE_COOL:
      return "CLIMATE_MODE_COOL";
    case enums::CLIMATE_MODE_HEAT:
      return "CLIMATE_MODE_HEAT";
    case enums::CLIMATE_MODE_FAN_ONLY:
      return "CLIMATE_MODE_FAN_ONLY";
    case enums::CLIMATE_MODE_DRY:
      return "CLIMATE_MODE_DRY";
    case enums::CLIMATE_MODE_AUTO:
      return "CLIMATE_MODE_AUTO";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ClimateFanMode>(enums::ClimateFanMode value) {
  switch (value) {
    case enums::CLIMATE_FAN_ON:
      return "CLIMATE_FAN_ON";
    case enums::CLIMATE_FAN_OFF:
      return "CLIMATE_FAN_OFF";
    case enums::CLIMATE_FAN_AUTO:
      return "CLIMATE_FAN_AUTO";
    case enums::CLIMATE_FAN_LOW:
      return "CLIMATE_FAN_LOW";
    case enums::CLIMATE_FAN_MEDIUM:
      return "CLIMATE_FAN_MEDIUM";
    case enums::CLIMATE_FAN_HIGH:
      return "CLIMATE_FAN_HIGH";
    case enums::CLIMATE_FAN_MIDDLE:
      return "CLIMATE_FAN_MIDDLE";
    case enums::CLIMATE_FAN_FOCUS:
      return "CLIMATE_FAN_FOCUS";
    case enums::CLIMATE_FAN_DIFFUSE:
      return "CLIMATE_FAN_DIFFUSE";
    case enums::CLIMATE_FAN_QUIET:
      return "CLIMATE_FAN_QUIET";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ClimateSwingMode>(enums::ClimateSwingMode value) {
  switch (value) {
    case enums::CLIMATE_SWING_OFF:
      return "CLIMATE_SWING_OFF";
    case enums::CLIMATE_SWING_BOTH:
      return "CLIMATE_SWING_BOTH";
    case enums::CLIMATE_SWING_VERTICAL:
      return "CLIMATE_SWING_VERTICAL";
    case enums::CLIMATE_SWING_HORIZONTAL:
      return "CLIMATE_SWING_HORIZONTAL";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ClimateAction>(enums::ClimateAction value) {
  switch (value) {
    case enums::CLIMATE_ACTION_OFF:
      return "CLIMATE_ACTION_OFF";
    case enums::CLIMATE_ACTION_COOLING:
      return "CLIMATE_ACTION_COOLING";
    case enums::CLIMATE_ACTION_HEATING:
      return "CLIMATE_ACTION_HEATING";
    case enums::CLIMATE_ACTION_IDLE:
      return "CLIMATE_ACTION_IDLE";
    case enums::CLIMATE_ACTION_DRYING:
      return "CLIMATE_ACTION_DRYING";
    case enums::CLIMATE_ACTION_FAN:
      return "CLIMATE_ACTION_FAN";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ClimatePreset>(enums::ClimatePreset value) {
  switch (value) {
    case enums::CLIMATE_PRESET_NONE:
      return "CLIMATE_PRESET_NONE";
    case enums::CLIMATE_PRESET_HOME:
      return "CLIMATE_PRESET_HOME";
    case enums::CLIMATE_PRESET_AWAY:
      return "CLIMATE_PRESET_AWAY";
    case enums::CLIMATE_PRESET_BOOST:
      return "CLIMATE_PRESET_BOOST";
    case enums::CLIMATE_PRESET_COMFORT:
      return "CLIMATE_PRESET_COMFORT";
    case enums::CLIMATE_PRESET_ECO:
      return "CLIMATE_PRESET_ECO";
    case enums::CLIMATE_PRESET_SLEEP:
      return "CLIMATE_PRESET_SLEEP";
    case enums::CLIMATE_PRESET_ACTIVITY:
      return "CLIMATE_PRESET_ACTIVITY";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::NumberMode>(enums::NumberMode value) {
  switch (value) {
    case enums::NUMBER_MODE_AUTO:
      return "NUMBER_MODE_AUTO";
    case enums::NUMBER_MODE_BOX:
      return "NUMBER_MODE_BOX";
    case enums::NUMBER_MODE_SLIDER:
      return "NUMBER_MODE_SLIDER";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::LockState>(enums::LockState value) {
  switch (value) {
    case enums::LOCK_STATE_NONE:
      return "LOCK_STATE_NONE";
    case enums::LOCK_STATE_LOCKED:
      return "LOCK_STATE_LOCKED";
    case enums::LOCK_STATE_UNLOCKED:
      return "LOCK_STATE_UNLOCKED";
    case enums::LOCK_STATE_JAMMED:
      return "LOCK_STATE_JAMMED";
    case enums::LOCK_STATE_LOCKING:
      return "LOCK_STATE_LOCKING";
    case enums::LOCK_STATE_UNLOCKING:
      return "LOCK_STATE_UNLOCKING";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::LockCommand>(enums::LockCommand value) {
  switch (value) {
    case enums::LOCK_UNLOCK:
      return "LOCK_UNLOCK";
    case enums::LOCK_LOCK:
      return "LOCK_LOCK";
    case enums::LOCK_OPEN:
      return "LOCK_OPEN";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::MediaPlayerState>(enums::MediaPlayerState value) {
  switch (value) {
    case enums::MEDIA_PLAYER_STATE_NONE:
      return "MEDIA_PLAYER_STATE_NONE";
    case enums::MEDIA_PLAYER_STATE_IDLE:
      return "MEDIA_PLAYER_STATE_IDLE";
    case enums::MEDIA_PLAYER_STATE_PLAYING:
      return "MEDIA_PLAYER_STATE_PLAYING";
    case enums::MEDIA_PLAYER_STATE_PAUSED:
      return "MEDIA_PLAYER_STATE_PAUSED";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::MediaPlayerCommand>(enums::MediaPlayerCommand value) {
  switch (value) {
    case enums::MEDIA_PLAYER_COMMAND_PLAY:
      return "MEDIA_PLAYER_COMMAND_PLAY";
    case enums::MEDIA_PLAYER_COMMAND_PAUSE:
      return "MEDIA_PLAYER_COMMAND_PAUSE";
    case enums::MEDIA_PLAYER_COMMAND_STOP:
      return "MEDIA_PLAYER_COMMAND_STOP";
    case enums::MEDIA_PLAYER_COMMAND_MUTE:
      return "MEDIA_PLAYER_COMMAND_MUTE";
    case enums::MEDIA_PLAYER_COMMAND_UNMUTE:
      return "MEDIA_PLAYER_COMMAND_UNMUTE";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::MediaPlayerFormatPurpose>(enums::MediaPlayerFormatPurpose value) {
  switch (value) {
    case enums::MEDIA_PLAYER_FORMAT_PURPOSE_DEFAULT:
      return "MEDIA_PLAYER_FORMAT_PURPOSE_DEFAULT";
    case enums::MEDIA_PLAYER_FORMAT_PURPOSE_ANNOUNCEMENT:
      return "MEDIA_PLAYER_FORMAT_PURPOSE_ANNOUNCEMENT";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<>
const char *proto_enum_to_string<enums::BluetoothDeviceRequestType>(enums::BluetoothDeviceRequestType value) {
  switch (value) {
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT";
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_DISCONNECT:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_DISCONNECT";
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_PAIR:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_PAIR";
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_UNPAIR:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_UNPAIR";
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITH_CACHE:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITH_CACHE";
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITHOUT_CACHE:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITHOUT_CACHE";
    case enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CLEAR_CACHE:
      return "BLUETOOTH_DEVICE_REQUEST_TYPE_CLEAR_CACHE";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::BluetoothScannerState>(enums::BluetoothScannerState value) {
  switch (value) {
    case enums::BLUETOOTH_SCANNER_STATE_IDLE:
      return "BLUETOOTH_SCANNER_STATE_IDLE";
    case enums::BLUETOOTH_SCANNER_STATE_STARTING:
      return "BLUETOOTH_SCANNER_STATE_STARTING";
    case enums::BLUETOOTH_SCANNER_STATE_RUNNING:
      return "BLUETOOTH_SCANNER_STATE_RUNNING";
    case enums::BLUETOOTH_SCANNER_STATE_FAILED:
      return "BLUETOOTH_SCANNER_STATE_FAILED";
    case enums::BLUETOOTH_SCANNER_STATE_STOPPING:
      return "BLUETOOTH_SCANNER_STATE_STOPPING";
    case enums::BLUETOOTH_SCANNER_STATE_STOPPED:
      return "BLUETOOTH_SCANNER_STATE_STOPPED";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::BluetoothScannerMode>(enums::BluetoothScannerMode value) {
  switch (value) {
    case enums::BLUETOOTH_SCANNER_MODE_PASSIVE:
      return "BLUETOOTH_SCANNER_MODE_PASSIVE";
    case enums::BLUETOOTH_SCANNER_MODE_ACTIVE:
      return "BLUETOOTH_SCANNER_MODE_ACTIVE";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<>
const char *proto_enum_to_string<enums::VoiceAssistantSubscribeFlag>(enums::VoiceAssistantSubscribeFlag value) {
  switch (value) {
    case enums::VOICE_ASSISTANT_SUBSCRIBE_NONE:
      return "VOICE_ASSISTANT_SUBSCRIBE_NONE";
    case enums::VOICE_ASSISTANT_SUBSCRIBE_API_AUDIO:
      return "VOICE_ASSISTANT_SUBSCRIBE_API_AUDIO";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::VoiceAssistantRequestFlag>(enums::VoiceAssistantRequestFlag value) {
  switch (value) {
    case enums::VOICE_ASSISTANT_REQUEST_NONE:
      return "VOICE_ASSISTANT_REQUEST_NONE";
    case enums::VOICE_ASSISTANT_REQUEST_USE_VAD:
      return "VOICE_ASSISTANT_REQUEST_USE_VAD";
    case enums::VOICE_ASSISTANT_REQUEST_USE_WAKE_WORD:
      return "VOICE_ASSISTANT_REQUEST_USE_WAKE_WORD";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::VoiceAssistantEvent>(enums::VoiceAssistantEvent value) {
  switch (value) {
    case enums::VOICE_ASSISTANT_ERROR:
      return "VOICE_ASSISTANT_ERROR";
    case enums::VOICE_ASSISTANT_RUN_START:
      return "VOICE_ASSISTANT_RUN_START";
    case enums::VOICE_ASSISTANT_RUN_END:
      return "VOICE_ASSISTANT_RUN_END";
    case enums::VOICE_ASSISTANT_STT_START:
      return "VOICE_ASSISTANT_STT_START";
    case enums::VOICE_ASSISTANT_STT_END:
      return "VOICE_ASSISTANT_STT_END";
    case enums::VOICE_ASSISTANT_INTENT_START:
      return "VOICE_ASSISTANT_INTENT_START";
    case enums::VOICE_ASSISTANT_INTENT_END:
      return "VOICE_ASSISTANT_INTENT_END";
    case enums::VOICE_ASSISTANT_TTS_START:
      return "VOICE_ASSISTANT_TTS_START";
    case enums::VOICE_ASSISTANT_TTS_END:
      return "VOICE_ASSISTANT_TTS_END";
    case enums::VOICE_ASSISTANT_WAKE_WORD_START:
      return "VOICE_ASSISTANT_WAKE_WORD_START";
    case enums::VOICE_ASSISTANT_WAKE_WORD_END:
      return "VOICE_ASSISTANT_WAKE_WORD_END";
    case enums::VOICE_ASSISTANT_STT_VAD_START:
      return "VOICE_ASSISTANT_STT_VAD_START";
    case enums::VOICE_ASSISTANT_STT_VAD_END:
      return "VOICE_ASSISTANT_STT_VAD_END";
    case enums::VOICE_ASSISTANT_TTS_STREAM_START:
      return "VOICE_ASSISTANT_TTS_STREAM_START";
    case enums::VOICE_ASSISTANT_TTS_STREAM_END:
      return "VOICE_ASSISTANT_TTS_STREAM_END";
    case enums::VOICE_ASSISTANT_INTENT_PROGRESS:
      return "VOICE_ASSISTANT_INTENT_PROGRESS";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::VoiceAssistantTimerEvent>(enums::VoiceAssistantTimerEvent value) {
  switch (value) {
    case enums::VOICE_ASSISTANT_TIMER_STARTED:
      return "VOICE_ASSISTANT_TIMER_STARTED";
    case enums::VOICE_ASSISTANT_TIMER_UPDATED:
      return "VOICE_ASSISTANT_TIMER_UPDATED";
    case enums::VOICE_ASSISTANT_TIMER_CANCELLED:
      return "VOICE_ASSISTANT_TIMER_CANCELLED";
    case enums::VOICE_ASSISTANT_TIMER_FINISHED:
      return "VOICE_ASSISTANT_TIMER_FINISHED";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::AlarmControlPanelState>(enums::AlarmControlPanelState value) {
  switch (value) {
    case enums::ALARM_STATE_DISARMED:
      return "ALARM_STATE_DISARMED";
    case enums::ALARM_STATE_ARMED_HOME:
      return "ALARM_STATE_ARMED_HOME";
    case enums::ALARM_STATE_ARMED_AWAY:
      return "ALARM_STATE_ARMED_AWAY";
    case enums::ALARM_STATE_ARMED_NIGHT:
      return "ALARM_STATE_ARMED_NIGHT";
    case enums::ALARM_STATE_ARMED_VACATION:
      return "ALARM_STATE_ARMED_VACATION";
    case enums::ALARM_STATE_ARMED_CUSTOM_BYPASS:
      return "ALARM_STATE_ARMED_CUSTOM_BYPASS";
    case enums::ALARM_STATE_PENDING:
      return "ALARM_STATE_PENDING";
    case enums::ALARM_STATE_ARMING:
      return "ALARM_STATE_ARMING";
    case enums::ALARM_STATE_DISARMING:
      return "ALARM_STATE_DISARMING";
    case enums::ALARM_STATE_TRIGGERED:
      return "ALARM_STATE_TRIGGERED";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<>
const char *proto_enum_to_string<enums::AlarmControlPanelStateCommand>(enums::AlarmControlPanelStateCommand value) {
  switch (value) {
    case enums::ALARM_CONTROL_PANEL_DISARM:
      return "ALARM_CONTROL_PANEL_DISARM";
    case enums::ALARM_CONTROL_PANEL_ARM_AWAY:
      return "ALARM_CONTROL_PANEL_ARM_AWAY";
    case enums::ALARM_CONTROL_PANEL_ARM_HOME:
      return "ALARM_CONTROL_PANEL_ARM_HOME";
    case enums::ALARM_CONTROL_PANEL_ARM_NIGHT:
      return "ALARM_CONTROL_PANEL_ARM_NIGHT";
    case enums::ALARM_CONTROL_PANEL_ARM_VACATION:
      return "ALARM_CONTROL_PANEL_ARM_VACATION";
    case enums::ALARM_CONTROL_PANEL_ARM_CUSTOM_BYPASS:
      return "ALARM_CONTROL_PANEL_ARM_CUSTOM_BYPASS";
    case enums::ALARM_CONTROL_PANEL_TRIGGER:
      return "ALARM_CONTROL_PANEL_TRIGGER";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::TextMode>(enums::TextMode value) {
  switch (value) {
    case enums::TEXT_MODE_TEXT:
      return "TEXT_MODE_TEXT";
    case enums::TEXT_MODE_PASSWORD:
      return "TEXT_MODE_PASSWORD";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::ValveOperation>(enums::ValveOperation value) {
  switch (value) {
    case enums::VALVE_OPERATION_IDLE:
      return "VALVE_OPERATION_IDLE";
    case enums::VALVE_OPERATION_IS_OPENING:
      return "VALVE_OPERATION_IS_OPENING";
    case enums::VALVE_OPERATION_IS_CLOSING:
      return "VALVE_OPERATION_IS_CLOSING";
    default:
      return "UNKNOWN";
  }
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
template<> const char *proto_enum_to_string<enums::UpdateCommand>(enums::UpdateCommand value) {
  switch (value) {
    case enums::UPDATE_COMMAND_NONE:
      return "UPDATE_COMMAND_NONE";
    case enums::UPDATE_COMMAND_UPDATE:
      return "UPDATE_COMMAND_UPDATE";
    case enums::UPDATE_COMMAND_CHECK:
      return "UPDATE_COMMAND_CHECK";
    default:
      return "UNKNOWN";
  }
}
#endif

bool HelloRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->api_version_major = value.as_uint32();
      return true;
    }
    case 3: {
      this->api_version_minor = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool HelloRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->client_info = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void HelloRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->client_info);
  buffer.encode_uint32(2, this->api_version_major);
  buffer.encode_uint32(3, this->api_version_minor);
}
void HelloRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->client_info, false);
  ProtoSize::add_uint32_field(total_size, 1, this->api_version_major, false);
  ProtoSize::add_uint32_field(total_size, 1, this->api_version_minor, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void HelloRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("HelloRequest {\n");
  out.append("  client_info: ");
  out.append("'").append(this->client_info).append("'");
  out.append("\n");

  out.append("  api_version_major: ");
  sprintf(buffer, "%" PRIu32, this->api_version_major);
  out.append(buffer);
  out.append("\n");

  out.append("  api_version_minor: ");
  sprintf(buffer, "%" PRIu32, this->api_version_minor);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool HelloResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->api_version_major = value.as_uint32();
      return true;
    }
    case 2: {
      this->api_version_minor = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool HelloResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->server_info = value.as_string();
      return true;
    }
    case 4: {
      this->name = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void HelloResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->api_version_major);
  buffer.encode_uint32(2, this->api_version_minor);
  buffer.encode_string(3, this->server_info);
  buffer.encode_string(4, this->name);
}
void HelloResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->api_version_major, false);
  ProtoSize::add_uint32_field(total_size, 1, this->api_version_minor, false);
  ProtoSize::add_string_field(total_size, 1, this->server_info, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void HelloResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("HelloResponse {\n");
  out.append("  api_version_major: ");
  sprintf(buffer, "%" PRIu32, this->api_version_major);
  out.append(buffer);
  out.append("\n");

  out.append("  api_version_minor: ");
  sprintf(buffer, "%" PRIu32, this->api_version_minor);
  out.append(buffer);
  out.append("\n");

  out.append("  server_info: ");
  out.append("'").append(this->server_info).append("'");
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ConnectRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->password = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void ConnectRequest::encode(ProtoWriteBuffer buffer) const { buffer.encode_string(1, this->password); }
void ConnectRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->password, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ConnectRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ConnectRequest {\n");
  out.append("  password: ");
  out.append("'").append(this->password).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ConnectResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->invalid_password = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void ConnectResponse::encode(ProtoWriteBuffer buffer) const { buffer.encode_bool(1, this->invalid_password); }
void ConnectResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->invalid_password, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ConnectResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ConnectResponse {\n");
  out.append("  invalid_password: ");
  out.append(YESNO(this->invalid_password));
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void DisconnectRequest::dump_to(std::string &out) const { out.append("DisconnectRequest {}"); }
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void DisconnectResponse::dump_to(std::string &out) const { out.append("DisconnectResponse {}"); }
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void PingRequest::dump_to(std::string &out) const { out.append("PingRequest {}"); }
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void PingResponse::dump_to(std::string &out) const { out.append("PingResponse {}"); }
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void DeviceInfoRequest::dump_to(std::string &out) const { out.append("DeviceInfoRequest {}"); }
#endif
bool AreaInfo::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->area_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool AreaInfo::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->name = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void AreaInfo::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->area_id);
  buffer.encode_string(2, this->name);
}
void AreaInfo::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->area_id, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void AreaInfo::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("AreaInfo {\n");
  out.append("  area_id: ");
  sprintf(buffer, "%" PRIu32, this->area_id);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool DeviceInfo::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->device_id = value.as_uint32();
      return true;
    }
    case 3: {
      this->area_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool DeviceInfo::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->name = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void DeviceInfo::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->device_id);
  buffer.encode_string(2, this->name);
  buffer.encode_uint32(3, this->area_id);
}
void DeviceInfo::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_uint32_field(total_size, 1, this->area_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void DeviceInfo::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("DeviceInfo {\n");
  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  area_id: ");
  sprintf(buffer, "%" PRIu32, this->area_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool DeviceInfoResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->uses_password = value.as_bool();
      return true;
    }
    case 7: {
      this->has_deep_sleep = value.as_bool();
      return true;
    }
    case 10: {
      this->webserver_port = value.as_uint32();
      return true;
    }
    case 11: {
      this->legacy_bluetooth_proxy_version = value.as_uint32();
      return true;
    }
    case 15: {
      this->bluetooth_proxy_feature_flags = value.as_uint32();
      return true;
    }
    case 14: {
      this->legacy_voice_assistant_version = value.as_uint32();
      return true;
    }
    case 17: {
      this->voice_assistant_feature_flags = value.as_uint32();
      return true;
    }
    case 19: {
      this->api_encryption_supported = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool DeviceInfoResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->name = value.as_string();
      return true;
    }
    case 3: {
      this->mac_address = value.as_string();
      return true;
    }
    case 4: {
      this->esphome_version = value.as_string();
      return true;
    }
    case 5: {
      this->compilation_time = value.as_string();
      return true;
    }
    case 6: {
      this->model = value.as_string();
      return true;
    }
    case 8: {
      this->project_name = value.as_string();
      return true;
    }
    case 9: {
      this->project_version = value.as_string();
      return true;
    }
    case 12: {
      this->manufacturer = value.as_string();
      return true;
    }
    case 13: {
      this->friendly_name = value.as_string();
      return true;
    }
    case 16: {
      this->suggested_area = value.as_string();
      return true;
    }
    case 18: {
      this->bluetooth_mac_address = value.as_string();
      return true;
    }
    case 20: {
      this->devices.push_back(value.as_message<DeviceInfo>());
      return true;
    }
    case 21: {
      this->areas.push_back(value.as_message<AreaInfo>());
      return true;
    }
    case 22: {
      this->area = value.as_message<AreaInfo>();
      return true;
    }
    default:
      return false;
  }
}
void DeviceInfoResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_bool(1, this->uses_password);
  buffer.encode_string(2, this->name);
  buffer.encode_string(3, this->mac_address);
  buffer.encode_string(4, this->esphome_version);
  buffer.encode_string(5, this->compilation_time);
  buffer.encode_string(6, this->model);
  buffer.encode_bool(7, this->has_deep_sleep);
  buffer.encode_string(8, this->project_name);
  buffer.encode_string(9, this->project_version);
  buffer.encode_uint32(10, this->webserver_port);
  buffer.encode_uint32(11, this->legacy_bluetooth_proxy_version);
  buffer.encode_uint32(15, this->bluetooth_proxy_feature_flags);
  buffer.encode_string(12, this->manufacturer);
  buffer.encode_string(13, this->friendly_name);
  buffer.encode_uint32(14, this->legacy_voice_assistant_version);
  buffer.encode_uint32(17, this->voice_assistant_feature_flags);
  buffer.encode_string(16, this->suggested_area);
  buffer.encode_string(18, this->bluetooth_mac_address);
  buffer.encode_bool(19, this->api_encryption_supported);
  for (auto &it : this->devices) {
    buffer.encode_message<DeviceInfo>(20, it, true);
  }
  for (auto &it : this->areas) {
    buffer.encode_message<AreaInfo>(21, it, true);
  }
  buffer.encode_message<AreaInfo>(22, this->area);
}
void DeviceInfoResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->uses_password, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->mac_address, false);
  ProtoSize::add_string_field(total_size, 1, this->esphome_version, false);
  ProtoSize::add_string_field(total_size, 1, this->compilation_time, false);
  ProtoSize::add_string_field(total_size, 1, this->model, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_deep_sleep, false);
  ProtoSize::add_string_field(total_size, 1, this->project_name, false);
  ProtoSize::add_string_field(total_size, 1, this->project_version, false);
  ProtoSize::add_uint32_field(total_size, 1, this->webserver_port, false);
  ProtoSize::add_uint32_field(total_size, 1, this->legacy_bluetooth_proxy_version, false);
  ProtoSize::add_uint32_field(total_size, 1, this->bluetooth_proxy_feature_flags, false);
  ProtoSize::add_string_field(total_size, 1, this->manufacturer, false);
  ProtoSize::add_string_field(total_size, 1, this->friendly_name, false);
  ProtoSize::add_uint32_field(total_size, 1, this->legacy_voice_assistant_version, false);
  ProtoSize::add_uint32_field(total_size, 2, this->voice_assistant_feature_flags, false);
  ProtoSize::add_string_field(total_size, 2, this->suggested_area, false);
  ProtoSize::add_string_field(total_size, 2, this->bluetooth_mac_address, false);
  ProtoSize::add_bool_field(total_size, 2, this->api_encryption_supported, false);
  ProtoSize::add_repeated_message(total_size, 2, this->devices);
  ProtoSize::add_repeated_message(total_size, 2, this->areas);
  ProtoSize::add_message_object(total_size, 2, this->area, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void DeviceInfoResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("DeviceInfoResponse {\n");
  out.append("  uses_password: ");
  out.append(YESNO(this->uses_password));
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  mac_address: ");
  out.append("'").append(this->mac_address).append("'");
  out.append("\n");

  out.append("  esphome_version: ");
  out.append("'").append(this->esphome_version).append("'");
  out.append("\n");

  out.append("  compilation_time: ");
  out.append("'").append(this->compilation_time).append("'");
  out.append("\n");

  out.append("  model: ");
  out.append("'").append(this->model).append("'");
  out.append("\n");

  out.append("  has_deep_sleep: ");
  out.append(YESNO(this->has_deep_sleep));
  out.append("\n");

  out.append("  project_name: ");
  out.append("'").append(this->project_name).append("'");
  out.append("\n");

  out.append("  project_version: ");
  out.append("'").append(this->project_version).append("'");
  out.append("\n");

  out.append("  webserver_port: ");
  sprintf(buffer, "%" PRIu32, this->webserver_port);
  out.append(buffer);
  out.append("\n");

  out.append("  legacy_bluetooth_proxy_version: ");
  sprintf(buffer, "%" PRIu32, this->legacy_bluetooth_proxy_version);
  out.append(buffer);
  out.append("\n");

  out.append("  bluetooth_proxy_feature_flags: ");
  sprintf(buffer, "%" PRIu32, this->bluetooth_proxy_feature_flags);
  out.append(buffer);
  out.append("\n");

  out.append("  manufacturer: ");
  out.append("'").append(this->manufacturer).append("'");
  out.append("\n");

  out.append("  friendly_name: ");
  out.append("'").append(this->friendly_name).append("'");
  out.append("\n");

  out.append("  legacy_voice_assistant_version: ");
  sprintf(buffer, "%" PRIu32, this->legacy_voice_assistant_version);
  out.append(buffer);
  out.append("\n");

  out.append("  voice_assistant_feature_flags: ");
  sprintf(buffer, "%" PRIu32, this->voice_assistant_feature_flags);
  out.append(buffer);
  out.append("\n");

  out.append("  suggested_area: ");
  out.append("'").append(this->suggested_area).append("'");
  out.append("\n");

  out.append("  bluetooth_mac_address: ");
  out.append("'").append(this->bluetooth_mac_address).append("'");
  out.append("\n");

  out.append("  api_encryption_supported: ");
  out.append(YESNO(this->api_encryption_supported));
  out.append("\n");

  for (const auto &it : this->devices) {
    out.append("  devices: ");
    it.dump_to(out);
    out.append("\n");
  }

  for (const auto &it : this->areas) {
    out.append("  areas: ");
    it.dump_to(out);
    out.append("\n");
  }

  out.append("  area: ");
  this->area.dump_to(out);
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesRequest::dump_to(std::string &out) const { out.append("ListEntitiesRequest {}"); }
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesDoneResponse::dump_to(std::string &out) const { out.append("ListEntitiesDoneResponse {}"); }
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeStatesRequest::dump_to(std::string &out) const { out.append("SubscribeStatesRequest {}"); }
#endif
bool ListEntitiesBinarySensorResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->is_status_binary_sensor = value.as_bool();
      return true;
    }
    case 7: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 9: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 10: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesBinarySensorResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->device_class = value.as_string();
      return true;
    }
    case 8: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesBinarySensorResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesBinarySensorResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->device_class);
  buffer.encode_bool(6, this->is_status_binary_sensor);
  buffer.encode_bool(7, this->disabled_by_default);
  buffer.encode_string(8, this->icon);
  buffer.encode_enum<enums::EntityCategory>(9, this->entity_category);
  buffer.encode_uint32(10, this->device_id);
}
void ListEntitiesBinarySensorResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_bool_field(total_size, 1, this->is_status_binary_sensor, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesBinarySensorResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesBinarySensorResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  is_status_binary_sensor: ");
  out.append(YESNO(this->is_status_binary_sensor));
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BinarySensorStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_bool();
      return true;
    }
    case 3: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool BinarySensorStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void BinarySensorStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->state);
  buffer.encode_bool(3, this->missing_state);
}
void BinarySensorStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BinarySensorStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BinarySensorStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesCoverResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 5: {
      this->assumed_state = value.as_bool();
      return true;
    }
    case 6: {
      this->supports_position = value.as_bool();
      return true;
    }
    case 7: {
      this->supports_tilt = value.as_bool();
      return true;
    }
    case 9: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 11: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 12: {
      this->supports_stop = value.as_bool();
      return true;
    }
    case 13: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesCoverResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 8: {
      this->device_class = value.as_string();
      return true;
    }
    case 10: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesCoverResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesCoverResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_bool(5, this->assumed_state);
  buffer.encode_bool(6, this->supports_position);
  buffer.encode_bool(7, this->supports_tilt);
  buffer.encode_string(8, this->device_class);
  buffer.encode_bool(9, this->disabled_by_default);
  buffer.encode_string(10, this->icon);
  buffer.encode_enum<enums::EntityCategory>(11, this->entity_category);
  buffer.encode_bool(12, this->supports_stop);
  buffer.encode_uint32(13, this->device_id);
}
void ListEntitiesCoverResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_bool_field(total_size, 1, this->assumed_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_position, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_tilt, false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_stop, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesCoverResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesCoverResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  assumed_state: ");
  out.append(YESNO(this->assumed_state));
  out.append("\n");

  out.append("  supports_position: ");
  out.append(YESNO(this->supports_position));
  out.append("\n");

  out.append("  supports_tilt: ");
  out.append(YESNO(this->supports_tilt));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  supports_stop: ");
  out.append(YESNO(this->supports_stop));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool CoverStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->legacy_state = value.as_enum<enums::LegacyCoverState>();
      return true;
    }
    case 5: {
      this->current_operation = value.as_enum<enums::CoverOperation>();
      return true;
    }
    default:
      return false;
  }
}
bool CoverStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 3: {
      this->position = value.as_float();
      return true;
    }
    case 4: {
      this->tilt = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void CoverStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::LegacyCoverState>(2, this->legacy_state);
  buffer.encode_float(3, this->position);
  buffer.encode_float(4, this->tilt);
  buffer.encode_enum<enums::CoverOperation>(5, this->current_operation);
}
void CoverStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->legacy_state), false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->position != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->tilt != 0.0f, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->current_operation), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void CoverStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("CoverStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  legacy_state: ");
  out.append(proto_enum_to_string<enums::LegacyCoverState>(this->legacy_state));
  out.append("\n");

  out.append("  position: ");
  sprintf(buffer, "%g", this->position);
  out.append(buffer);
  out.append("\n");

  out.append("  tilt: ");
  sprintf(buffer, "%g", this->tilt);
  out.append(buffer);
  out.append("\n");

  out.append("  current_operation: ");
  out.append(proto_enum_to_string<enums::CoverOperation>(this->current_operation));
  out.append("\n");
  out.append("}");
}
#endif
bool CoverCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_legacy_command = value.as_bool();
      return true;
    }
    case 3: {
      this->legacy_command = value.as_enum<enums::LegacyCoverCommand>();
      return true;
    }
    case 4: {
      this->has_position = value.as_bool();
      return true;
    }
    case 6: {
      this->has_tilt = value.as_bool();
      return true;
    }
    case 8: {
      this->stop = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool CoverCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 5: {
      this->position = value.as_float();
      return true;
    }
    case 7: {
      this->tilt = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void CoverCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_legacy_command);
  buffer.encode_enum<enums::LegacyCoverCommand>(3, this->legacy_command);
  buffer.encode_bool(4, this->has_position);
  buffer.encode_float(5, this->position);
  buffer.encode_bool(6, this->has_tilt);
  buffer.encode_float(7, this->tilt);
  buffer.encode_bool(8, this->stop);
}
void CoverCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_legacy_command, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->legacy_command), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_position, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->position != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_tilt, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->tilt != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->stop, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void CoverCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("CoverCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_legacy_command: ");
  out.append(YESNO(this->has_legacy_command));
  out.append("\n");

  out.append("  legacy_command: ");
  out.append(proto_enum_to_string<enums::LegacyCoverCommand>(this->legacy_command));
  out.append("\n");

  out.append("  has_position: ");
  out.append(YESNO(this->has_position));
  out.append("\n");

  out.append("  position: ");
  sprintf(buffer, "%g", this->position);
  out.append(buffer);
  out.append("\n");

  out.append("  has_tilt: ");
  out.append(YESNO(this->has_tilt));
  out.append("\n");

  out.append("  tilt: ");
  sprintf(buffer, "%g", this->tilt);
  out.append(buffer);
  out.append("\n");

  out.append("  stop: ");
  out.append(YESNO(this->stop));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesFanResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 5: {
      this->supports_oscillation = value.as_bool();
      return true;
    }
    case 6: {
      this->supports_speed = value.as_bool();
      return true;
    }
    case 7: {
      this->supports_direction = value.as_bool();
      return true;
    }
    case 8: {
      this->supported_speed_count = value.as_int32();
      return true;
    }
    case 9: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 11: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 13: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesFanResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 10: {
      this->icon = value.as_string();
      return true;
    }
    case 12: {
      this->supported_preset_modes.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesFanResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesFanResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_bool(5, this->supports_oscillation);
  buffer.encode_bool(6, this->supports_speed);
  buffer.encode_bool(7, this->supports_direction);
  buffer.encode_int32(8, this->supported_speed_count);
  buffer.encode_bool(9, this->disabled_by_default);
  buffer.encode_string(10, this->icon);
  buffer.encode_enum<enums::EntityCategory>(11, this->entity_category);
  for (auto &it : this->supported_preset_modes) {
    buffer.encode_string(12, it, true);
  }
  buffer.encode_uint32(13, this->device_id);
}
void ListEntitiesFanResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_oscillation, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_speed, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_direction, false);
  ProtoSize::add_int32_field(total_size, 1, this->supported_speed_count, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  if (!this->supported_preset_modes.empty()) {
    for (const auto &it : this->supported_preset_modes) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesFanResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesFanResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  supports_oscillation: ");
  out.append(YESNO(this->supports_oscillation));
  out.append("\n");

  out.append("  supports_speed: ");
  out.append(YESNO(this->supports_speed));
  out.append("\n");

  out.append("  supports_direction: ");
  out.append(YESNO(this->supports_direction));
  out.append("\n");

  out.append("  supported_speed_count: ");
  sprintf(buffer, "%" PRId32, this->supported_speed_count);
  out.append(buffer);
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  for (const auto &it : this->supported_preset_modes) {
    out.append("  supported_preset_modes: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool FanStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_bool();
      return true;
    }
    case 3: {
      this->oscillating = value.as_bool();
      return true;
    }
    case 4: {
      this->speed = value.as_enum<enums::FanSpeed>();
      return true;
    }
    case 5: {
      this->direction = value.as_enum<enums::FanDirection>();
      return true;
    }
    case 6: {
      this->speed_level = value.as_int32();
      return true;
    }
    default:
      return false;
  }
}
bool FanStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 7: {
      this->preset_mode = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool FanStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void FanStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->state);
  buffer.encode_bool(3, this->oscillating);
  buffer.encode_enum<enums::FanSpeed>(4, this->speed);
  buffer.encode_enum<enums::FanDirection>(5, this->direction);
  buffer.encode_int32(6, this->speed_level);
  buffer.encode_string(7, this->preset_mode);
}
void FanStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->oscillating, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->speed), false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->direction), false);
  ProtoSize::add_int32_field(total_size, 1, this->speed_level, false);
  ProtoSize::add_string_field(total_size, 1, this->preset_mode, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void FanStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("FanStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");

  out.append("  oscillating: ");
  out.append(YESNO(this->oscillating));
  out.append("\n");

  out.append("  speed: ");
  out.append(proto_enum_to_string<enums::FanSpeed>(this->speed));
  out.append("\n");

  out.append("  direction: ");
  out.append(proto_enum_to_string<enums::FanDirection>(this->direction));
  out.append("\n");

  out.append("  speed_level: ");
  sprintf(buffer, "%" PRId32, this->speed_level);
  out.append(buffer);
  out.append("\n");

  out.append("  preset_mode: ");
  out.append("'").append(this->preset_mode).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool FanCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_state = value.as_bool();
      return true;
    }
    case 3: {
      this->state = value.as_bool();
      return true;
    }
    case 4: {
      this->has_speed = value.as_bool();
      return true;
    }
    case 5: {
      this->speed = value.as_enum<enums::FanSpeed>();
      return true;
    }
    case 6: {
      this->has_oscillating = value.as_bool();
      return true;
    }
    case 7: {
      this->oscillating = value.as_bool();
      return true;
    }
    case 8: {
      this->has_direction = value.as_bool();
      return true;
    }
    case 9: {
      this->direction = value.as_enum<enums::FanDirection>();
      return true;
    }
    case 10: {
      this->has_speed_level = value.as_bool();
      return true;
    }
    case 11: {
      this->speed_level = value.as_int32();
      return true;
    }
    case 12: {
      this->has_preset_mode = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool FanCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 13: {
      this->preset_mode = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool FanCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void FanCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_state);
  buffer.encode_bool(3, this->state);
  buffer.encode_bool(4, this->has_speed);
  buffer.encode_enum<enums::FanSpeed>(5, this->speed);
  buffer.encode_bool(6, this->has_oscillating);
  buffer.encode_bool(7, this->oscillating);
  buffer.encode_bool(8, this->has_direction);
  buffer.encode_enum<enums::FanDirection>(9, this->direction);
  buffer.encode_bool(10, this->has_speed_level);
  buffer.encode_int32(11, this->speed_level);
  buffer.encode_bool(12, this->has_preset_mode);
  buffer.encode_string(13, this->preset_mode);
}
void FanCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_speed, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->speed), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_oscillating, false);
  ProtoSize::add_bool_field(total_size, 1, this->oscillating, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_direction, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->direction), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_speed_level, false);
  ProtoSize::add_int32_field(total_size, 1, this->speed_level, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_preset_mode, false);
  ProtoSize::add_string_field(total_size, 1, this->preset_mode, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void FanCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("FanCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_state: ");
  out.append(YESNO(this->has_state));
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");

  out.append("  has_speed: ");
  out.append(YESNO(this->has_speed));
  out.append("\n");

  out.append("  speed: ");
  out.append(proto_enum_to_string<enums::FanSpeed>(this->speed));
  out.append("\n");

  out.append("  has_oscillating: ");
  out.append(YESNO(this->has_oscillating));
  out.append("\n");

  out.append("  oscillating: ");
  out.append(YESNO(this->oscillating));
  out.append("\n");

  out.append("  has_direction: ");
  out.append(YESNO(this->has_direction));
  out.append("\n");

  out.append("  direction: ");
  out.append(proto_enum_to_string<enums::FanDirection>(this->direction));
  out.append("\n");

  out.append("  has_speed_level: ");
  out.append(YESNO(this->has_speed_level));
  out.append("\n");

  out.append("  speed_level: ");
  sprintf(buffer, "%" PRId32, this->speed_level);
  out.append(buffer);
  out.append("\n");

  out.append("  has_preset_mode: ");
  out.append(YESNO(this->has_preset_mode));
  out.append("\n");

  out.append("  preset_mode: ");
  out.append("'").append(this->preset_mode).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesLightResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 12: {
      this->supported_color_modes.push_back(value.as_enum<enums::ColorMode>());
      return true;
    }
    case 5: {
      this->legacy_supports_brightness = value.as_bool();
      return true;
    }
    case 6: {
      this->legacy_supports_rgb = value.as_bool();
      return true;
    }
    case 7: {
      this->legacy_supports_white_value = value.as_bool();
      return true;
    }
    case 8: {
      this->legacy_supports_color_temperature = value.as_bool();
      return true;
    }
    case 13: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 15: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 16: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesLightResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 11: {
      this->effects.push_back(value.as_string());
      return true;
    }
    case 14: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesLightResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    case 9: {
      this->min_mireds = value.as_float();
      return true;
    }
    case 10: {
      this->max_mireds = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesLightResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  for (auto &it : this->supported_color_modes) {
    buffer.encode_enum<enums::ColorMode>(12, it, true);
  }
  buffer.encode_bool(5, this->legacy_supports_brightness);
  buffer.encode_bool(6, this->legacy_supports_rgb);
  buffer.encode_bool(7, this->legacy_supports_white_value);
  buffer.encode_bool(8, this->legacy_supports_color_temperature);
  buffer.encode_float(9, this->min_mireds);
  buffer.encode_float(10, this->max_mireds);
  for (auto &it : this->effects) {
    buffer.encode_string(11, it, true);
  }
  buffer.encode_bool(13, this->disabled_by_default);
  buffer.encode_string(14, this->icon);
  buffer.encode_enum<enums::EntityCategory>(15, this->entity_category);
  buffer.encode_uint32(16, this->device_id);
}
void ListEntitiesLightResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  if (!this->supported_color_modes.empty()) {
    for (const auto &it : this->supported_color_modes) {
      ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(it), true);
    }
  }
  ProtoSize::add_bool_field(total_size, 1, this->legacy_supports_brightness, false);
  ProtoSize::add_bool_field(total_size, 1, this->legacy_supports_rgb, false);
  ProtoSize::add_bool_field(total_size, 1, this->legacy_supports_white_value, false);
  ProtoSize::add_bool_field(total_size, 1, this->legacy_supports_color_temperature, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->min_mireds != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->max_mireds != 0.0f, false);
  if (!this->effects.empty()) {
    for (const auto &it : this->effects) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 2, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesLightResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesLightResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  for (const auto &it : this->supported_color_modes) {
    out.append("  supported_color_modes: ");
    out.append(proto_enum_to_string<enums::ColorMode>(it));
    out.append("\n");
  }

  out.append("  legacy_supports_brightness: ");
  out.append(YESNO(this->legacy_supports_brightness));
  out.append("\n");

  out.append("  legacy_supports_rgb: ");
  out.append(YESNO(this->legacy_supports_rgb));
  out.append("\n");

  out.append("  legacy_supports_white_value: ");
  out.append(YESNO(this->legacy_supports_white_value));
  out.append("\n");

  out.append("  legacy_supports_color_temperature: ");
  out.append(YESNO(this->legacy_supports_color_temperature));
  out.append("\n");

  out.append("  min_mireds: ");
  sprintf(buffer, "%g", this->min_mireds);
  out.append(buffer);
  out.append("\n");

  out.append("  max_mireds: ");
  sprintf(buffer, "%g", this->max_mireds);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->effects) {
    out.append("  effects: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool LightStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_bool();
      return true;
    }
    case 11: {
      this->color_mode = value.as_enum<enums::ColorMode>();
      return true;
    }
    default:
      return false;
  }
}
bool LightStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 9: {
      this->effect = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool LightStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 3: {
      this->brightness = value.as_float();
      return true;
    }
    case 10: {
      this->color_brightness = value.as_float();
      return true;
    }
    case 4: {
      this->red = value.as_float();
      return true;
    }
    case 5: {
      this->green = value.as_float();
      return true;
    }
    case 6: {
      this->blue = value.as_float();
      return true;
    }
    case 7: {
      this->white = value.as_float();
      return true;
    }
    case 8: {
      this->color_temperature = value.as_float();
      return true;
    }
    case 12: {
      this->cold_white = value.as_float();
      return true;
    }
    case 13: {
      this->warm_white = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void LightStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->state);
  buffer.encode_float(3, this->brightness);
  buffer.encode_enum<enums::ColorMode>(11, this->color_mode);
  buffer.encode_float(10, this->color_brightness);
  buffer.encode_float(4, this->red);
  buffer.encode_float(5, this->green);
  buffer.encode_float(6, this->blue);
  buffer.encode_float(7, this->white);
  buffer.encode_float(8, this->color_temperature);
  buffer.encode_float(12, this->cold_white);
  buffer.encode_float(13, this->warm_white);
  buffer.encode_string(9, this->effect);
}
void LightStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->brightness != 0.0f, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->color_mode), false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->color_brightness != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->red != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->green != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->blue != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->white != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->color_temperature != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->cold_white != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->warm_white != 0.0f, false);
  ProtoSize::add_string_field(total_size, 1, this->effect, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void LightStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("LightStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");

  out.append("  brightness: ");
  sprintf(buffer, "%g", this->brightness);
  out.append(buffer);
  out.append("\n");

  out.append("  color_mode: ");
  out.append(proto_enum_to_string<enums::ColorMode>(this->color_mode));
  out.append("\n");

  out.append("  color_brightness: ");
  sprintf(buffer, "%g", this->color_brightness);
  out.append(buffer);
  out.append("\n");

  out.append("  red: ");
  sprintf(buffer, "%g", this->red);
  out.append(buffer);
  out.append("\n");

  out.append("  green: ");
  sprintf(buffer, "%g", this->green);
  out.append(buffer);
  out.append("\n");

  out.append("  blue: ");
  sprintf(buffer, "%g", this->blue);
  out.append(buffer);
  out.append("\n");

  out.append("  white: ");
  sprintf(buffer, "%g", this->white);
  out.append(buffer);
  out.append("\n");

  out.append("  color_temperature: ");
  sprintf(buffer, "%g", this->color_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  cold_white: ");
  sprintf(buffer, "%g", this->cold_white);
  out.append(buffer);
  out.append("\n");

  out.append("  warm_white: ");
  sprintf(buffer, "%g", this->warm_white);
  out.append(buffer);
  out.append("\n");

  out.append("  effect: ");
  out.append("'").append(this->effect).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool LightCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_state = value.as_bool();
      return true;
    }
    case 3: {
      this->state = value.as_bool();
      return true;
    }
    case 4: {
      this->has_brightness = value.as_bool();
      return true;
    }
    case 22: {
      this->has_color_mode = value.as_bool();
      return true;
    }
    case 23: {
      this->color_mode = value.as_enum<enums::ColorMode>();
      return true;
    }
    case 20: {
      this->has_color_brightness = value.as_bool();
      return true;
    }
    case 6: {
      this->has_rgb = value.as_bool();
      return true;
    }
    case 10: {
      this->has_white = value.as_bool();
      return true;
    }
    case 12: {
      this->has_color_temperature = value.as_bool();
      return true;
    }
    case 24: {
      this->has_cold_white = value.as_bool();
      return true;
    }
    case 26: {
      this->has_warm_white = value.as_bool();
      return true;
    }
    case 14: {
      this->has_transition_length = value.as_bool();
      return true;
    }
    case 15: {
      this->transition_length = value.as_uint32();
      return true;
    }
    case 16: {
      this->has_flash_length = value.as_bool();
      return true;
    }
    case 17: {
      this->flash_length = value.as_uint32();
      return true;
    }
    case 18: {
      this->has_effect = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool LightCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 19: {
      this->effect = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool LightCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 5: {
      this->brightness = value.as_float();
      return true;
    }
    case 21: {
      this->color_brightness = value.as_float();
      return true;
    }
    case 7: {
      this->red = value.as_float();
      return true;
    }
    case 8: {
      this->green = value.as_float();
      return true;
    }
    case 9: {
      this->blue = value.as_float();
      return true;
    }
    case 11: {
      this->white = value.as_float();
      return true;
    }
    case 13: {
      this->color_temperature = value.as_float();
      return true;
    }
    case 25: {
      this->cold_white = value.as_float();
      return true;
    }
    case 27: {
      this->warm_white = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void LightCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_state);
  buffer.encode_bool(3, this->state);
  buffer.encode_bool(4, this->has_brightness);
  buffer.encode_float(5, this->brightness);
  buffer.encode_bool(22, this->has_color_mode);
  buffer.encode_enum<enums::ColorMode>(23, this->color_mode);
  buffer.encode_bool(20, this->has_color_brightness);
  buffer.encode_float(21, this->color_brightness);
  buffer.encode_bool(6, this->has_rgb);
  buffer.encode_float(7, this->red);
  buffer.encode_float(8, this->green);
  buffer.encode_float(9, this->blue);
  buffer.encode_bool(10, this->has_white);
  buffer.encode_float(11, this->white);
  buffer.encode_bool(12, this->has_color_temperature);
  buffer.encode_float(13, this->color_temperature);
  buffer.encode_bool(24, this->has_cold_white);
  buffer.encode_float(25, this->cold_white);
  buffer.encode_bool(26, this->has_warm_white);
  buffer.encode_float(27, this->warm_white);
  buffer.encode_bool(14, this->has_transition_length);
  buffer.encode_uint32(15, this->transition_length);
  buffer.encode_bool(16, this->has_flash_length);
  buffer.encode_uint32(17, this->flash_length);
  buffer.encode_bool(18, this->has_effect);
  buffer.encode_string(19, this->effect);
}
void LightCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_brightness, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->brightness != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_color_mode, false);
  ProtoSize::add_enum_field(total_size, 2, static_cast<uint32_t>(this->color_mode), false);
  ProtoSize::add_bool_field(total_size, 2, this->has_color_brightness, false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->color_brightness != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_rgb, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->red != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->green != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->blue != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_white, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->white != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_color_temperature, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->color_temperature != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_cold_white, false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->cold_white != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_warm_white, false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->warm_white != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_transition_length, false);
  ProtoSize::add_uint32_field(total_size, 1, this->transition_length, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_flash_length, false);
  ProtoSize::add_uint32_field(total_size, 2, this->flash_length, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_effect, false);
  ProtoSize::add_string_field(total_size, 2, this->effect, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void LightCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("LightCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_state: ");
  out.append(YESNO(this->has_state));
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");

  out.append("  has_brightness: ");
  out.append(YESNO(this->has_brightness));
  out.append("\n");

  out.append("  brightness: ");
  sprintf(buffer, "%g", this->brightness);
  out.append(buffer);
  out.append("\n");

  out.append("  has_color_mode: ");
  out.append(YESNO(this->has_color_mode));
  out.append("\n");

  out.append("  color_mode: ");
  out.append(proto_enum_to_string<enums::ColorMode>(this->color_mode));
  out.append("\n");

  out.append("  has_color_brightness: ");
  out.append(YESNO(this->has_color_brightness));
  out.append("\n");

  out.append("  color_brightness: ");
  sprintf(buffer, "%g", this->color_brightness);
  out.append(buffer);
  out.append("\n");

  out.append("  has_rgb: ");
  out.append(YESNO(this->has_rgb));
  out.append("\n");

  out.append("  red: ");
  sprintf(buffer, "%g", this->red);
  out.append(buffer);
  out.append("\n");

  out.append("  green: ");
  sprintf(buffer, "%g", this->green);
  out.append(buffer);
  out.append("\n");

  out.append("  blue: ");
  sprintf(buffer, "%g", this->blue);
  out.append(buffer);
  out.append("\n");

  out.append("  has_white: ");
  out.append(YESNO(this->has_white));
  out.append("\n");

  out.append("  white: ");
  sprintf(buffer, "%g", this->white);
  out.append(buffer);
  out.append("\n");

  out.append("  has_color_temperature: ");
  out.append(YESNO(this->has_color_temperature));
  out.append("\n");

  out.append("  color_temperature: ");
  sprintf(buffer, "%g", this->color_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  has_cold_white: ");
  out.append(YESNO(this->has_cold_white));
  out.append("\n");

  out.append("  cold_white: ");
  sprintf(buffer, "%g", this->cold_white);
  out.append(buffer);
  out.append("\n");

  out.append("  has_warm_white: ");
  out.append(YESNO(this->has_warm_white));
  out.append("\n");

  out.append("  warm_white: ");
  sprintf(buffer, "%g", this->warm_white);
  out.append(buffer);
  out.append("\n");

  out.append("  has_transition_length: ");
  out.append(YESNO(this->has_transition_length));
  out.append("\n");

  out.append("  transition_length: ");
  sprintf(buffer, "%" PRIu32, this->transition_length);
  out.append(buffer);
  out.append("\n");

  out.append("  has_flash_length: ");
  out.append(YESNO(this->has_flash_length));
  out.append("\n");

  out.append("  flash_length: ");
  sprintf(buffer, "%" PRIu32, this->flash_length);
  out.append(buffer);
  out.append("\n");

  out.append("  has_effect: ");
  out.append(YESNO(this->has_effect));
  out.append("\n");

  out.append("  effect: ");
  out.append("'").append(this->effect).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesSensorResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 7: {
      this->accuracy_decimals = value.as_int32();
      return true;
    }
    case 8: {
      this->force_update = value.as_bool();
      return true;
    }
    case 10: {
      this->state_class = value.as_enum<enums::SensorStateClass>();
      return true;
    }
    case 11: {
      this->legacy_last_reset_type = value.as_enum<enums::SensorLastResetType>();
      return true;
    }
    case 12: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 13: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 14: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSensorResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 6: {
      this->unit_of_measurement = value.as_string();
      return true;
    }
    case 9: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSensorResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesSensorResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_string(6, this->unit_of_measurement);
  buffer.encode_int32(7, this->accuracy_decimals);
  buffer.encode_bool(8, this->force_update);
  buffer.encode_string(9, this->device_class);
  buffer.encode_enum<enums::SensorStateClass>(10, this->state_class);
  buffer.encode_enum<enums::SensorLastResetType>(11, this->legacy_last_reset_type);
  buffer.encode_bool(12, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(13, this->entity_category);
  buffer.encode_uint32(14, this->device_id);
}
void ListEntitiesSensorResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_string_field(total_size, 1, this->unit_of_measurement, false);
  ProtoSize::add_int32_field(total_size, 1, this->accuracy_decimals, false);
  ProtoSize::add_bool_field(total_size, 1, this->force_update, false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->state_class), false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->legacy_last_reset_type), false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesSensorResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesSensorResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  unit_of_measurement: ");
  out.append("'").append(this->unit_of_measurement).append("'");
  out.append("\n");

  out.append("  accuracy_decimals: ");
  sprintf(buffer, "%" PRId32, this->accuracy_decimals);
  out.append(buffer);
  out.append("\n");

  out.append("  force_update: ");
  out.append(YESNO(this->force_update));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  state_class: ");
  out.append(proto_enum_to_string<enums::SensorStateClass>(this->state_class));
  out.append("\n");

  out.append("  legacy_last_reset_type: ");
  out.append(proto_enum_to_string<enums::SensorLastResetType>(this->legacy_last_reset_type));
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool SensorStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SensorStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 2: {
      this->state = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void SensorStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_float(2, this->state);
  buffer.encode_bool(3, this->missing_state);
}
void SensorStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->state != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SensorStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SensorStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  sprintf(buffer, "%g", this->state);
  out.append(buffer);
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesSwitchResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->assumed_state = value.as_bool();
      return true;
    }
    case 7: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 8: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 10: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSwitchResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 9: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSwitchResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesSwitchResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->assumed_state);
  buffer.encode_bool(7, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(8, this->entity_category);
  buffer.encode_string(9, this->device_class);
  buffer.encode_uint32(10, this->device_id);
}
void ListEntitiesSwitchResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->assumed_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesSwitchResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesSwitchResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  assumed_state: ");
  out.append(YESNO(this->assumed_state));
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool SwitchStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SwitchStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void SwitchStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->state);
}
void SwitchStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SwitchStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SwitchStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");
  out.append("}");
}
#endif
bool SwitchCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SwitchCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void SwitchCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->state);
}
void SwitchCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SwitchCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SwitchCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesTextSensorResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 9: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesTextSensorResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 8: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesTextSensorResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesTextSensorResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_string(8, this->device_class);
  buffer.encode_uint32(9, this->device_id);
}
void ListEntitiesTextSensorResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesTextSensorResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesTextSensorResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool TextSensorStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool TextSensorStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool TextSensorStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void TextSensorStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->state);
  buffer.encode_bool(3, this->missing_state);
}
void TextSensorStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void TextSensorStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("TextSensorStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append("'").append(this->state).append("'");
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");
  out.append("}");
}
#endif
bool SubscribeLogsRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->level = value.as_enum<enums::LogLevel>();
      return true;
    }
    case 2: {
      this->dump_config = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void SubscribeLogsRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_enum<enums::LogLevel>(1, this->level);
  buffer.encode_bool(2, this->dump_config);
}
void SubscribeLogsRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->level), false);
  ProtoSize::add_bool_field(total_size, 1, this->dump_config, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeLogsRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SubscribeLogsRequest {\n");
  out.append("  level: ");
  out.append(proto_enum_to_string<enums::LogLevel>(this->level));
  out.append("\n");

  out.append("  dump_config: ");
  out.append(YESNO(this->dump_config));
  out.append("\n");
  out.append("}");
}
#endif
bool SubscribeLogsResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->level = value.as_enum<enums::LogLevel>();
      return true;
    }
    case 4: {
      this->send_failed = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SubscribeLogsResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->message = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void SubscribeLogsResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_enum<enums::LogLevel>(1, this->level);
  buffer.encode_string(3, this->message);
  buffer.encode_bool(4, this->send_failed);
}
void SubscribeLogsResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->level), false);
  ProtoSize::add_string_field(total_size, 1, this->message, false);
  ProtoSize::add_bool_field(total_size, 1, this->send_failed, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeLogsResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SubscribeLogsResponse {\n");
  out.append("  level: ");
  out.append(proto_enum_to_string<enums::LogLevel>(this->level));
  out.append("\n");

  out.append("  message: ");
  out.append("'").append(this->message).append("'");
  out.append("\n");

  out.append("  send_failed: ");
  out.append(YESNO(this->send_failed));
  out.append("\n");
  out.append("}");
}
#endif
bool NoiseEncryptionSetKeyRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void NoiseEncryptionSetKeyRequest::encode(ProtoWriteBuffer buffer) const { buffer.encode_string(1, this->key); }
void NoiseEncryptionSetKeyRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->key, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void NoiseEncryptionSetKeyRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("NoiseEncryptionSetKeyRequest {\n");
  out.append("  key: ");
  out.append("'").append(this->key).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool NoiseEncryptionSetKeyResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->success = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void NoiseEncryptionSetKeyResponse::encode(ProtoWriteBuffer buffer) const { buffer.encode_bool(1, this->success); }
void NoiseEncryptionSetKeyResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->success, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void NoiseEncryptionSetKeyResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("NoiseEncryptionSetKeyResponse {\n");
  out.append("  success: ");
  out.append(YESNO(this->success));
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeHomeassistantServicesRequest::dump_to(std::string &out) const {
  out.append("SubscribeHomeassistantServicesRequest {}");
}
#endif
bool HomeassistantServiceMap::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_string();
      return true;
    }
    case 2: {
      this->value = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void HomeassistantServiceMap::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->key);
  buffer.encode_string(2, this->value);
}
void HomeassistantServiceMap::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->key, false);
  ProtoSize::add_string_field(total_size, 1, this->value, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void HomeassistantServiceMap::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("HomeassistantServiceMap {\n");
  out.append("  key: ");
  out.append("'").append(this->key).append("'");
  out.append("\n");

  out.append("  value: ");
  out.append("'").append(this->value).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool HomeassistantServiceResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 5: {
      this->is_event = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool HomeassistantServiceResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->service = value.as_string();
      return true;
    }
    case 2: {
      this->data.push_back(value.as_message<HomeassistantServiceMap>());
      return true;
    }
    case 3: {
      this->data_template.push_back(value.as_message<HomeassistantServiceMap>());
      return true;
    }
    case 4: {
      this->variables.push_back(value.as_message<HomeassistantServiceMap>());
      return true;
    }
    default:
      return false;
  }
}
void HomeassistantServiceResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->service);
  for (auto &it : this->data) {
    buffer.encode_message<HomeassistantServiceMap>(2, it, true);
  }
  for (auto &it : this->data_template) {
    buffer.encode_message<HomeassistantServiceMap>(3, it, true);
  }
  for (auto &it : this->variables) {
    buffer.encode_message<HomeassistantServiceMap>(4, it, true);
  }
  buffer.encode_bool(5, this->is_event);
}
void HomeassistantServiceResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->service, false);
  ProtoSize::add_repeated_message(total_size, 1, this->data);
  ProtoSize::add_repeated_message(total_size, 1, this->data_template);
  ProtoSize::add_repeated_message(total_size, 1, this->variables);
  ProtoSize::add_bool_field(total_size, 1, this->is_event, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void HomeassistantServiceResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("HomeassistantServiceResponse {\n");
  out.append("  service: ");
  out.append("'").append(this->service).append("'");
  out.append("\n");

  for (const auto &it : this->data) {
    out.append("  data: ");
    it.dump_to(out);
    out.append("\n");
  }

  for (const auto &it : this->data_template) {
    out.append("  data_template: ");
    it.dump_to(out);
    out.append("\n");
  }

  for (const auto &it : this->variables) {
    out.append("  variables: ");
    it.dump_to(out);
    out.append("\n");
  }

  out.append("  is_event: ");
  out.append(YESNO(this->is_event));
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeHomeAssistantStatesRequest::dump_to(std::string &out) const {
  out.append("SubscribeHomeAssistantStatesRequest {}");
}
#endif
bool SubscribeHomeAssistantStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->once = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SubscribeHomeAssistantStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->entity_id = value.as_string();
      return true;
    }
    case 2: {
      this->attribute = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void SubscribeHomeAssistantStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->entity_id);
  buffer.encode_string(2, this->attribute);
  buffer.encode_bool(3, this->once);
}
void SubscribeHomeAssistantStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->entity_id, false);
  ProtoSize::add_string_field(total_size, 1, this->attribute, false);
  ProtoSize::add_bool_field(total_size, 1, this->once, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeHomeAssistantStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SubscribeHomeAssistantStateResponse {\n");
  out.append("  entity_id: ");
  out.append("'").append(this->entity_id).append("'");
  out.append("\n");

  out.append("  attribute: ");
  out.append("'").append(this->attribute).append("'");
  out.append("\n");

  out.append("  once: ");
  out.append(YESNO(this->once));
  out.append("\n");
  out.append("}");
}
#endif
bool HomeAssistantStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->entity_id = value.as_string();
      return true;
    }
    case 2: {
      this->state = value.as_string();
      return true;
    }
    case 3: {
      this->attribute = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void HomeAssistantStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->entity_id);
  buffer.encode_string(2, this->state);
  buffer.encode_string(3, this->attribute);
}
void HomeAssistantStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->entity_id, false);
  ProtoSize::add_string_field(total_size, 1, this->state, false);
  ProtoSize::add_string_field(total_size, 1, this->attribute, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void HomeAssistantStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("HomeAssistantStateResponse {\n");
  out.append("  entity_id: ");
  out.append("'").append(this->entity_id).append("'");
  out.append("\n");

  out.append("  state: ");
  out.append("'").append(this->state).append("'");
  out.append("\n");

  out.append("  attribute: ");
  out.append("'").append(this->attribute).append("'");
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void GetTimeRequest::dump_to(std::string &out) const { out.append("GetTimeRequest {}"); }
#endif
bool GetTimeResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->epoch_seconds = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void GetTimeResponse::encode(ProtoWriteBuffer buffer) const { buffer.encode_fixed32(1, this->epoch_seconds); }
void GetTimeResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->epoch_seconds != 0, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void GetTimeResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("GetTimeResponse {\n");
  out.append("  epoch_seconds: ");
  sprintf(buffer, "%" PRIu32, this->epoch_seconds);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesServicesArgument::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->type = value.as_enum<enums::ServiceArgType>();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesServicesArgument::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->name = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesServicesArgument::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->name);
  buffer.encode_enum<enums::ServiceArgType>(2, this->type);
}
void ListEntitiesServicesArgument::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->type), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesServicesArgument::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesServicesArgument {\n");
  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  type: ");
  out.append(proto_enum_to_string<enums::ServiceArgType>(this->type));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesServicesResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->name = value.as_string();
      return true;
    }
    case 3: {
      this->args.push_back(value.as_message<ListEntitiesServicesArgument>());
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesServicesResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesServicesResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->name);
  buffer.encode_fixed32(2, this->key);
  for (auto &it : this->args) {
    buffer.encode_message<ListEntitiesServicesArgument>(3, it, true);
  }
}
void ListEntitiesServicesResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_repeated_message(total_size, 1, this->args);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesServicesResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesServicesResponse {\n");
  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->args) {
    out.append("  args: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool ExecuteServiceArgument::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->bool_ = value.as_bool();
      return true;
    }
    case 2: {
      this->legacy_int = value.as_int32();
      return true;
    }
    case 5: {
      this->int_ = value.as_sint32();
      return true;
    }
    case 6: {
      this->bool_array.push_back(value.as_bool());
      return true;
    }
    case 7: {
      this->int_array.push_back(value.as_sint32());
      return true;
    }
    default:
      return false;
  }
}
bool ExecuteServiceArgument::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 4: {
      this->string_ = value.as_string();
      return true;
    }
    case 9: {
      this->string_array.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
bool ExecuteServiceArgument::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 3: {
      this->float_ = value.as_float();
      return true;
    }
    case 8: {
      this->float_array.push_back(value.as_float());
      return true;
    }
    default:
      return false;
  }
}
void ExecuteServiceArgument::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_bool(1, this->bool_);
  buffer.encode_int32(2, this->legacy_int);
  buffer.encode_float(3, this->float_);
  buffer.encode_string(4, this->string_);
  buffer.encode_sint32(5, this->int_);
  for (auto it : this->bool_array) {
    buffer.encode_bool(6, it, true);
  }
  for (auto &it : this->int_array) {
    buffer.encode_sint32(7, it, true);
  }
  for (auto &it : this->float_array) {
    buffer.encode_float(8, it, true);
  }
  for (auto &it : this->string_array) {
    buffer.encode_string(9, it, true);
  }
}
void ExecuteServiceArgument::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->bool_, false);
  ProtoSize::add_int32_field(total_size, 1, this->legacy_int, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->float_ != 0.0f, false);
  ProtoSize::add_string_field(total_size, 1, this->string_, false);
  ProtoSize::add_sint32_field(total_size, 1, this->int_, false);
  if (!this->bool_array.empty()) {
    for (const auto it : this->bool_array) {
      ProtoSize::add_bool_field(total_size, 1, it, true);
    }
  }
  if (!this->int_array.empty()) {
    for (const auto &it : this->int_array) {
      ProtoSize::add_sint32_field(total_size, 1, it, true);
    }
  }
  if (!this->float_array.empty()) {
    for (const auto &it : this->float_array) {
      ProtoSize::add_fixed_field<4>(total_size, 1, it != 0.0f, true);
    }
  }
  if (!this->string_array.empty()) {
    for (const auto &it : this->string_array) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ExecuteServiceArgument::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ExecuteServiceArgument {\n");
  out.append("  bool_: ");
  out.append(YESNO(this->bool_));
  out.append("\n");

  out.append("  legacy_int: ");
  sprintf(buffer, "%" PRId32, this->legacy_int);
  out.append(buffer);
  out.append("\n");

  out.append("  float_: ");
  sprintf(buffer, "%g", this->float_);
  out.append(buffer);
  out.append("\n");

  out.append("  string_: ");
  out.append("'").append(this->string_).append("'");
  out.append("\n");

  out.append("  int_: ");
  sprintf(buffer, "%" PRId32, this->int_);
  out.append(buffer);
  out.append("\n");

  for (const auto it : this->bool_array) {
    out.append("  bool_array: ");
    out.append(YESNO(it));
    out.append("\n");
  }

  for (const auto &it : this->int_array) {
    out.append("  int_array: ");
    sprintf(buffer, "%" PRId32, it);
    out.append(buffer);
    out.append("\n");
  }

  for (const auto &it : this->float_array) {
    out.append("  float_array: ");
    sprintf(buffer, "%g", it);
    out.append(buffer);
    out.append("\n");
  }

  for (const auto &it : this->string_array) {
    out.append("  string_array: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }
  out.append("}");
}
#endif
bool ExecuteServiceRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->args.push_back(value.as_message<ExecuteServiceArgument>());
      return true;
    }
    default:
      return false;
  }
}
bool ExecuteServiceRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ExecuteServiceRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  for (auto &it : this->args) {
    buffer.encode_message<ExecuteServiceArgument>(2, it, true);
  }
}
void ExecuteServiceRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_repeated_message(total_size, 1, this->args);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ExecuteServiceRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ExecuteServiceRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->args) {
    out.append("  args: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool ListEntitiesCameraResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 5: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesCameraResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 6: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesCameraResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesCameraResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_bool(5, this->disabled_by_default);
  buffer.encode_string(6, this->icon);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_uint32(8, this->device_id);
}
void ListEntitiesCameraResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesCameraResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesCameraResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool CameraImageResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->done = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool CameraImageResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool CameraImageResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void CameraImageResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->data);
  buffer.encode_bool(3, this->done);
}
void CameraImageResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->data, false);
  ProtoSize::add_bool_field(total_size, 1, this->done, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void CameraImageResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("CameraImageResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");

  out.append("  done: ");
  out.append(YESNO(this->done));
  out.append("\n");
  out.append("}");
}
#endif
bool CameraImageRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->single = value.as_bool();
      return true;
    }
    case 2: {
      this->stream = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void CameraImageRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_bool(1, this->single);
  buffer.encode_bool(2, this->stream);
}
void CameraImageRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->single, false);
  ProtoSize::add_bool_field(total_size, 1, this->stream, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void CameraImageRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("CameraImageRequest {\n");
  out.append("  single: ");
  out.append(YESNO(this->single));
  out.append("\n");

  out.append("  stream: ");
  out.append(YESNO(this->stream));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesClimateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 5: {
      this->supports_current_temperature = value.as_bool();
      return true;
    }
    case 6: {
      this->supports_two_point_target_temperature = value.as_bool();
      return true;
    }
    case 7: {
      this->supported_modes.push_back(value.as_enum<enums::ClimateMode>());
      return true;
    }
    case 11: {
      this->legacy_supports_away = value.as_bool();
      return true;
    }
    case 12: {
      this->supports_action = value.as_bool();
      return true;
    }
    case 13: {
      this->supported_fan_modes.push_back(value.as_enum<enums::ClimateFanMode>());
      return true;
    }
    case 14: {
      this->supported_swing_modes.push_back(value.as_enum<enums::ClimateSwingMode>());
      return true;
    }
    case 16: {
      this->supported_presets.push_back(value.as_enum<enums::ClimatePreset>());
      return true;
    }
    case 18: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 20: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 22: {
      this->supports_current_humidity = value.as_bool();
      return true;
    }
    case 23: {
      this->supports_target_humidity = value.as_bool();
      return true;
    }
    case 26: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesClimateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 15: {
      this->supported_custom_fan_modes.push_back(value.as_string());
      return true;
    }
    case 17: {
      this->supported_custom_presets.push_back(value.as_string());
      return true;
    }
    case 19: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesClimateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    case 8: {
      this->visual_min_temperature = value.as_float();
      return true;
    }
    case 9: {
      this->visual_max_temperature = value.as_float();
      return true;
    }
    case 10: {
      this->visual_target_temperature_step = value.as_float();
      return true;
    }
    case 21: {
      this->visual_current_temperature_step = value.as_float();
      return true;
    }
    case 24: {
      this->visual_min_humidity = value.as_float();
      return true;
    }
    case 25: {
      this->visual_max_humidity = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesClimateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_bool(5, this->supports_current_temperature);
  buffer.encode_bool(6, this->supports_two_point_target_temperature);
  for (auto &it : this->supported_modes) {
    buffer.encode_enum<enums::ClimateMode>(7, it, true);
  }
  buffer.encode_float(8, this->visual_min_temperature);
  buffer.encode_float(9, this->visual_max_temperature);
  buffer.encode_float(10, this->visual_target_temperature_step);
  buffer.encode_bool(11, this->legacy_supports_away);
  buffer.encode_bool(12, this->supports_action);
  for (auto &it : this->supported_fan_modes) {
    buffer.encode_enum<enums::ClimateFanMode>(13, it, true);
  }
  for (auto &it : this->supported_swing_modes) {
    buffer.encode_enum<enums::ClimateSwingMode>(14, it, true);
  }
  for (auto &it : this->supported_custom_fan_modes) {
    buffer.encode_string(15, it, true);
  }
  for (auto &it : this->supported_presets) {
    buffer.encode_enum<enums::ClimatePreset>(16, it, true);
  }
  for (auto &it : this->supported_custom_presets) {
    buffer.encode_string(17, it, true);
  }
  buffer.encode_bool(18, this->disabled_by_default);
  buffer.encode_string(19, this->icon);
  buffer.encode_enum<enums::EntityCategory>(20, this->entity_category);
  buffer.encode_float(21, this->visual_current_temperature_step);
  buffer.encode_bool(22, this->supports_current_humidity);
  buffer.encode_bool(23, this->supports_target_humidity);
  buffer.encode_float(24, this->visual_min_humidity);
  buffer.encode_float(25, this->visual_max_humidity);
  buffer.encode_uint32(26, this->device_id);
}
void ListEntitiesClimateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_current_temperature, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_two_point_target_temperature, false);
  if (!this->supported_modes.empty()) {
    for (const auto &it : this->supported_modes) {
      ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(it), true);
    }
  }
  ProtoSize::add_fixed_field<4>(total_size, 1, this->visual_min_temperature != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->visual_max_temperature != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->visual_target_temperature_step != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->legacy_supports_away, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_action, false);
  if (!this->supported_fan_modes.empty()) {
    for (const auto &it : this->supported_fan_modes) {
      ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(it), true);
    }
  }
  if (!this->supported_swing_modes.empty()) {
    for (const auto &it : this->supported_swing_modes) {
      ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(it), true);
    }
  }
  if (!this->supported_custom_fan_modes.empty()) {
    for (const auto &it : this->supported_custom_fan_modes) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  if (!this->supported_presets.empty()) {
    for (const auto &it : this->supported_presets) {
      ProtoSize::add_enum_field(total_size, 2, static_cast<uint32_t>(it), true);
    }
  }
  if (!this->supported_custom_presets.empty()) {
    for (const auto &it : this->supported_custom_presets) {
      ProtoSize::add_string_field(total_size, 2, it, true);
    }
  }
  ProtoSize::add_bool_field(total_size, 2, this->disabled_by_default, false);
  ProtoSize::add_string_field(total_size, 2, this->icon, false);
  ProtoSize::add_enum_field(total_size, 2, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->visual_current_temperature_step != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 2, this->supports_current_humidity, false);
  ProtoSize::add_bool_field(total_size, 2, this->supports_target_humidity, false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->visual_min_humidity != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->visual_max_humidity != 0.0f, false);
  ProtoSize::add_uint32_field(total_size, 2, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesClimateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesClimateResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  supports_current_temperature: ");
  out.append(YESNO(this->supports_current_temperature));
  out.append("\n");

  out.append("  supports_two_point_target_temperature: ");
  out.append(YESNO(this->supports_two_point_target_temperature));
  out.append("\n");

  for (const auto &it : this->supported_modes) {
    out.append("  supported_modes: ");
    out.append(proto_enum_to_string<enums::ClimateMode>(it));
    out.append("\n");
  }

  out.append("  visual_min_temperature: ");
  sprintf(buffer, "%g", this->visual_min_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  visual_max_temperature: ");
  sprintf(buffer, "%g", this->visual_max_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  visual_target_temperature_step: ");
  sprintf(buffer, "%g", this->visual_target_temperature_step);
  out.append(buffer);
  out.append("\n");

  out.append("  legacy_supports_away: ");
  out.append(YESNO(this->legacy_supports_away));
  out.append("\n");

  out.append("  supports_action: ");
  out.append(YESNO(this->supports_action));
  out.append("\n");

  for (const auto &it : this->supported_fan_modes) {
    out.append("  supported_fan_modes: ");
    out.append(proto_enum_to_string<enums::ClimateFanMode>(it));
    out.append("\n");
  }

  for (const auto &it : this->supported_swing_modes) {
    out.append("  supported_swing_modes: ");
    out.append(proto_enum_to_string<enums::ClimateSwingMode>(it));
    out.append("\n");
  }

  for (const auto &it : this->supported_custom_fan_modes) {
    out.append("  supported_custom_fan_modes: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  for (const auto &it : this->supported_presets) {
    out.append("  supported_presets: ");
    out.append(proto_enum_to_string<enums::ClimatePreset>(it));
    out.append("\n");
  }

  for (const auto &it : this->supported_custom_presets) {
    out.append("  supported_custom_presets: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  visual_current_temperature_step: ");
  sprintf(buffer, "%g", this->visual_current_temperature_step);
  out.append(buffer);
  out.append("\n");

  out.append("  supports_current_humidity: ");
  out.append(YESNO(this->supports_current_humidity));
  out.append("\n");

  out.append("  supports_target_humidity: ");
  out.append(YESNO(this->supports_target_humidity));
  out.append("\n");

  out.append("  visual_min_humidity: ");
  sprintf(buffer, "%g", this->visual_min_humidity);
  out.append(buffer);
  out.append("\n");

  out.append("  visual_max_humidity: ");
  sprintf(buffer, "%g", this->visual_max_humidity);
  out.append(buffer);
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ClimateStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->mode = value.as_enum<enums::ClimateMode>();
      return true;
    }
    case 7: {
      this->unused_legacy_away = value.as_bool();
      return true;
    }
    case 8: {
      this->action = value.as_enum<enums::ClimateAction>();
      return true;
    }
    case 9: {
      this->fan_mode = value.as_enum<enums::ClimateFanMode>();
      return true;
    }
    case 10: {
      this->swing_mode = value.as_enum<enums::ClimateSwingMode>();
      return true;
    }
    case 12: {
      this->preset = value.as_enum<enums::ClimatePreset>();
      return true;
    }
    default:
      return false;
  }
}
bool ClimateStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 11: {
      this->custom_fan_mode = value.as_string();
      return true;
    }
    case 13: {
      this->custom_preset = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ClimateStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 3: {
      this->current_temperature = value.as_float();
      return true;
    }
    case 4: {
      this->target_temperature = value.as_float();
      return true;
    }
    case 5: {
      this->target_temperature_low = value.as_float();
      return true;
    }
    case 6: {
      this->target_temperature_high = value.as_float();
      return true;
    }
    case 14: {
      this->current_humidity = value.as_float();
      return true;
    }
    case 15: {
      this->target_humidity = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ClimateStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::ClimateMode>(2, this->mode);
  buffer.encode_float(3, this->current_temperature);
  buffer.encode_float(4, this->target_temperature);
  buffer.encode_float(5, this->target_temperature_low);
  buffer.encode_float(6, this->target_temperature_high);
  buffer.encode_bool(7, this->unused_legacy_away);
  buffer.encode_enum<enums::ClimateAction>(8, this->action);
  buffer.encode_enum<enums::ClimateFanMode>(9, this->fan_mode);
  buffer.encode_enum<enums::ClimateSwingMode>(10, this->swing_mode);
  buffer.encode_string(11, this->custom_fan_mode);
  buffer.encode_enum<enums::ClimatePreset>(12, this->preset);
  buffer.encode_string(13, this->custom_preset);
  buffer.encode_float(14, this->current_humidity);
  buffer.encode_float(15, this->target_humidity);
}
void ClimateStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->mode), false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->current_temperature != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_temperature != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_temperature_low != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_temperature_high != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->unused_legacy_away, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->action), false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->fan_mode), false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->swing_mode), false);
  ProtoSize::add_string_field(total_size, 1, this->custom_fan_mode, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->preset), false);
  ProtoSize::add_string_field(total_size, 1, this->custom_preset, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->current_humidity != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_humidity != 0.0f, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ClimateStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ClimateStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  mode: ");
  out.append(proto_enum_to_string<enums::ClimateMode>(this->mode));
  out.append("\n");

  out.append("  current_temperature: ");
  sprintf(buffer, "%g", this->current_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  target_temperature: ");
  sprintf(buffer, "%g", this->target_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  target_temperature_low: ");
  sprintf(buffer, "%g", this->target_temperature_low);
  out.append(buffer);
  out.append("\n");

  out.append("  target_temperature_high: ");
  sprintf(buffer, "%g", this->target_temperature_high);
  out.append(buffer);
  out.append("\n");

  out.append("  unused_legacy_away: ");
  out.append(YESNO(this->unused_legacy_away));
  out.append("\n");

  out.append("  action: ");
  out.append(proto_enum_to_string<enums::ClimateAction>(this->action));
  out.append("\n");

  out.append("  fan_mode: ");
  out.append(proto_enum_to_string<enums::ClimateFanMode>(this->fan_mode));
  out.append("\n");

  out.append("  swing_mode: ");
  out.append(proto_enum_to_string<enums::ClimateSwingMode>(this->swing_mode));
  out.append("\n");

  out.append("  custom_fan_mode: ");
  out.append("'").append(this->custom_fan_mode).append("'");
  out.append("\n");

  out.append("  preset: ");
  out.append(proto_enum_to_string<enums::ClimatePreset>(this->preset));
  out.append("\n");

  out.append("  custom_preset: ");
  out.append("'").append(this->custom_preset).append("'");
  out.append("\n");

  out.append("  current_humidity: ");
  sprintf(buffer, "%g", this->current_humidity);
  out.append(buffer);
  out.append("\n");

  out.append("  target_humidity: ");
  sprintf(buffer, "%g", this->target_humidity);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ClimateCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_mode = value.as_bool();
      return true;
    }
    case 3: {
      this->mode = value.as_enum<enums::ClimateMode>();
      return true;
    }
    case 4: {
      this->has_target_temperature = value.as_bool();
      return true;
    }
    case 6: {
      this->has_target_temperature_low = value.as_bool();
      return true;
    }
    case 8: {
      this->has_target_temperature_high = value.as_bool();
      return true;
    }
    case 10: {
      this->unused_has_legacy_away = value.as_bool();
      return true;
    }
    case 11: {
      this->unused_legacy_away = value.as_bool();
      return true;
    }
    case 12: {
      this->has_fan_mode = value.as_bool();
      return true;
    }
    case 13: {
      this->fan_mode = value.as_enum<enums::ClimateFanMode>();
      return true;
    }
    case 14: {
      this->has_swing_mode = value.as_bool();
      return true;
    }
    case 15: {
      this->swing_mode = value.as_enum<enums::ClimateSwingMode>();
      return true;
    }
    case 16: {
      this->has_custom_fan_mode = value.as_bool();
      return true;
    }
    case 18: {
      this->has_preset = value.as_bool();
      return true;
    }
    case 19: {
      this->preset = value.as_enum<enums::ClimatePreset>();
      return true;
    }
    case 20: {
      this->has_custom_preset = value.as_bool();
      return true;
    }
    case 22: {
      this->has_target_humidity = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool ClimateCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 17: {
      this->custom_fan_mode = value.as_string();
      return true;
    }
    case 21: {
      this->custom_preset = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ClimateCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 5: {
      this->target_temperature = value.as_float();
      return true;
    }
    case 7: {
      this->target_temperature_low = value.as_float();
      return true;
    }
    case 9: {
      this->target_temperature_high = value.as_float();
      return true;
    }
    case 23: {
      this->target_humidity = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ClimateCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_mode);
  buffer.encode_enum<enums::ClimateMode>(3, this->mode);
  buffer.encode_bool(4, this->has_target_temperature);
  buffer.encode_float(5, this->target_temperature);
  buffer.encode_bool(6, this->has_target_temperature_low);
  buffer.encode_float(7, this->target_temperature_low);
  buffer.encode_bool(8, this->has_target_temperature_high);
  buffer.encode_float(9, this->target_temperature_high);
  buffer.encode_bool(10, this->unused_has_legacy_away);
  buffer.encode_bool(11, this->unused_legacy_away);
  buffer.encode_bool(12, this->has_fan_mode);
  buffer.encode_enum<enums::ClimateFanMode>(13, this->fan_mode);
  buffer.encode_bool(14, this->has_swing_mode);
  buffer.encode_enum<enums::ClimateSwingMode>(15, this->swing_mode);
  buffer.encode_bool(16, this->has_custom_fan_mode);
  buffer.encode_string(17, this->custom_fan_mode);
  buffer.encode_bool(18, this->has_preset);
  buffer.encode_enum<enums::ClimatePreset>(19, this->preset);
  buffer.encode_bool(20, this->has_custom_preset);
  buffer.encode_string(21, this->custom_preset);
  buffer.encode_bool(22, this->has_target_humidity);
  buffer.encode_float(23, this->target_humidity);
}
void ClimateCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_mode, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->mode), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_target_temperature, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_temperature != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_target_temperature_low, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_temperature_low != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_target_temperature_high, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->target_temperature_high != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->unused_has_legacy_away, false);
  ProtoSize::add_bool_field(total_size, 1, this->unused_legacy_away, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_fan_mode, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->fan_mode), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_swing_mode, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->swing_mode), false);
  ProtoSize::add_bool_field(total_size, 2, this->has_custom_fan_mode, false);
  ProtoSize::add_string_field(total_size, 2, this->custom_fan_mode, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_preset, false);
  ProtoSize::add_enum_field(total_size, 2, static_cast<uint32_t>(this->preset), false);
  ProtoSize::add_bool_field(total_size, 2, this->has_custom_preset, false);
  ProtoSize::add_string_field(total_size, 2, this->custom_preset, false);
  ProtoSize::add_bool_field(total_size, 2, this->has_target_humidity, false);
  ProtoSize::add_fixed_field<4>(total_size, 2, this->target_humidity != 0.0f, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ClimateCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ClimateCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_mode: ");
  out.append(YESNO(this->has_mode));
  out.append("\n");

  out.append("  mode: ");
  out.append(proto_enum_to_string<enums::ClimateMode>(this->mode));
  out.append("\n");

  out.append("  has_target_temperature: ");
  out.append(YESNO(this->has_target_temperature));
  out.append("\n");

  out.append("  target_temperature: ");
  sprintf(buffer, "%g", this->target_temperature);
  out.append(buffer);
  out.append("\n");

  out.append("  has_target_temperature_low: ");
  out.append(YESNO(this->has_target_temperature_low));
  out.append("\n");

  out.append("  target_temperature_low: ");
  sprintf(buffer, "%g", this->target_temperature_low);
  out.append(buffer);
  out.append("\n");

  out.append("  has_target_temperature_high: ");
  out.append(YESNO(this->has_target_temperature_high));
  out.append("\n");

  out.append("  target_temperature_high: ");
  sprintf(buffer, "%g", this->target_temperature_high);
  out.append(buffer);
  out.append("\n");

  out.append("  unused_has_legacy_away: ");
  out.append(YESNO(this->unused_has_legacy_away));
  out.append("\n");

  out.append("  unused_legacy_away: ");
  out.append(YESNO(this->unused_legacy_away));
  out.append("\n");

  out.append("  has_fan_mode: ");
  out.append(YESNO(this->has_fan_mode));
  out.append("\n");

  out.append("  fan_mode: ");
  out.append(proto_enum_to_string<enums::ClimateFanMode>(this->fan_mode));
  out.append("\n");

  out.append("  has_swing_mode: ");
  out.append(YESNO(this->has_swing_mode));
  out.append("\n");

  out.append("  swing_mode: ");
  out.append(proto_enum_to_string<enums::ClimateSwingMode>(this->swing_mode));
  out.append("\n");

  out.append("  has_custom_fan_mode: ");
  out.append(YESNO(this->has_custom_fan_mode));
  out.append("\n");

  out.append("  custom_fan_mode: ");
  out.append("'").append(this->custom_fan_mode).append("'");
  out.append("\n");

  out.append("  has_preset: ");
  out.append(YESNO(this->has_preset));
  out.append("\n");

  out.append("  preset: ");
  out.append(proto_enum_to_string<enums::ClimatePreset>(this->preset));
  out.append("\n");

  out.append("  has_custom_preset: ");
  out.append(YESNO(this->has_custom_preset));
  out.append("\n");

  out.append("  custom_preset: ");
  out.append("'").append(this->custom_preset).append("'");
  out.append("\n");

  out.append("  has_target_humidity: ");
  out.append(YESNO(this->has_target_humidity));
  out.append("\n");

  out.append("  target_humidity: ");
  sprintf(buffer, "%g", this->target_humidity);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesNumberResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 9: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 10: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 12: {
      this->mode = value.as_enum<enums::NumberMode>();
      return true;
    }
    case 14: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesNumberResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 11: {
      this->unit_of_measurement = value.as_string();
      return true;
    }
    case 13: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesNumberResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    case 6: {
      this->min_value = value.as_float();
      return true;
    }
    case 7: {
      this->max_value = value.as_float();
      return true;
    }
    case 8: {
      this->step = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesNumberResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_float(6, this->min_value);
  buffer.encode_float(7, this->max_value);
  buffer.encode_float(8, this->step);
  buffer.encode_bool(9, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(10, this->entity_category);
  buffer.encode_string(11, this->unit_of_measurement);
  buffer.encode_enum<enums::NumberMode>(12, this->mode);
  buffer.encode_string(13, this->device_class);
  buffer.encode_uint32(14, this->device_id);
}
void ListEntitiesNumberResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->min_value != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->max_value != 0.0f, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->step != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->unit_of_measurement, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->mode), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesNumberResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesNumberResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  min_value: ");
  sprintf(buffer, "%g", this->min_value);
  out.append(buffer);
  out.append("\n");

  out.append("  max_value: ");
  sprintf(buffer, "%g", this->max_value);
  out.append(buffer);
  out.append("\n");

  out.append("  step: ");
  sprintf(buffer, "%g", this->step);
  out.append(buffer);
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  unit_of_measurement: ");
  out.append("'").append(this->unit_of_measurement).append("'");
  out.append("\n");

  out.append("  mode: ");
  out.append(proto_enum_to_string<enums::NumberMode>(this->mode));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool NumberStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool NumberStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 2: {
      this->state = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void NumberStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_float(2, this->state);
  buffer.encode_bool(3, this->missing_state);
}
void NumberStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->state != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void NumberStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("NumberStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  sprintf(buffer, "%g", this->state);
  out.append(buffer);
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");
  out.append("}");
}
#endif
bool NumberCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 2: {
      this->state = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void NumberCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_float(2, this->state);
}
void NumberCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->state != 0.0f, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void NumberCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("NumberCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  sprintf(buffer, "%g", this->state);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesSelectResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 7: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 8: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 9: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSelectResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 6: {
      this->options.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSelectResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesSelectResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  for (auto &it : this->options) {
    buffer.encode_string(6, it, true);
  }
  buffer.encode_bool(7, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(8, this->entity_category);
  buffer.encode_uint32(9, this->device_id);
}
void ListEntitiesSelectResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  if (!this->options.empty()) {
    for (const auto &it : this->options) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesSelectResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesSelectResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  for (const auto &it : this->options) {
    out.append("  options: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool SelectStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SelectStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool SelectStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void SelectStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->state);
  buffer.encode_bool(3, this->missing_state);
}
void SelectStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SelectStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SelectStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append("'").append(this->state).append("'");
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");
  out.append("}");
}
#endif
bool SelectCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool SelectCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void SelectCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->state);
}
void SelectCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SelectCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SelectCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append("'").append(this->state).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesSirenResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 8: {
      this->supports_duration = value.as_bool();
      return true;
    }
    case 9: {
      this->supports_volume = value.as_bool();
      return true;
    }
    case 10: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 11: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSirenResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 7: {
      this->tones.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesSirenResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesSirenResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  for (auto &it : this->tones) {
    buffer.encode_string(7, it, true);
  }
  buffer.encode_bool(8, this->supports_duration);
  buffer.encode_bool(9, this->supports_volume);
  buffer.encode_enum<enums::EntityCategory>(10, this->entity_category);
  buffer.encode_uint32(11, this->device_id);
}
void ListEntitiesSirenResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  if (!this->tones.empty()) {
    for (const auto &it : this->tones) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_bool_field(total_size, 1, this->supports_duration, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_volume, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesSirenResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesSirenResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  for (const auto &it : this->tones) {
    out.append("  tones: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  supports_duration: ");
  out.append(YESNO(this->supports_duration));
  out.append("\n");

  out.append("  supports_volume: ");
  out.append(YESNO(this->supports_volume));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool SirenStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SirenStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void SirenStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->state);
}
void SirenStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SirenStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SirenStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");
  out.append("}");
}
#endif
bool SirenCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_state = value.as_bool();
      return true;
    }
    case 3: {
      this->state = value.as_bool();
      return true;
    }
    case 4: {
      this->has_tone = value.as_bool();
      return true;
    }
    case 6: {
      this->has_duration = value.as_bool();
      return true;
    }
    case 7: {
      this->duration = value.as_uint32();
      return true;
    }
    case 8: {
      this->has_volume = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool SirenCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 5: {
      this->tone = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool SirenCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 9: {
      this->volume = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void SirenCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_state);
  buffer.encode_bool(3, this->state);
  buffer.encode_bool(4, this->has_tone);
  buffer.encode_string(5, this->tone);
  buffer.encode_bool(6, this->has_duration);
  buffer.encode_uint32(7, this->duration);
  buffer.encode_bool(8, this->has_volume);
  buffer.encode_float(9, this->volume);
}
void SirenCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_tone, false);
  ProtoSize::add_string_field(total_size, 1, this->tone, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_duration, false);
  ProtoSize::add_uint32_field(total_size, 1, this->duration, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_volume, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->volume != 0.0f, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SirenCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SirenCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_state: ");
  out.append(YESNO(this->has_state));
  out.append("\n");

  out.append("  state: ");
  out.append(YESNO(this->state));
  out.append("\n");

  out.append("  has_tone: ");
  out.append(YESNO(this->has_tone));
  out.append("\n");

  out.append("  tone: ");
  out.append("'").append(this->tone).append("'");
  out.append("\n");

  out.append("  has_duration: ");
  out.append(YESNO(this->has_duration));
  out.append("\n");

  out.append("  duration: ");
  sprintf(buffer, "%" PRIu32, this->duration);
  out.append(buffer);
  out.append("\n");

  out.append("  has_volume: ");
  out.append(YESNO(this->has_volume));
  out.append("\n");

  out.append("  volume: ");
  sprintf(buffer, "%g", this->volume);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesLockResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->assumed_state = value.as_bool();
      return true;
    }
    case 9: {
      this->supports_open = value.as_bool();
      return true;
    }
    case 10: {
      this->requires_code = value.as_bool();
      return true;
    }
    case 12: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesLockResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 11: {
      this->code_format = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesLockResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesLockResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_bool(8, this->assumed_state);
  buffer.encode_bool(9, this->supports_open);
  buffer.encode_bool(10, this->requires_code);
  buffer.encode_string(11, this->code_format);
  buffer.encode_uint32(12, this->device_id);
}
void ListEntitiesLockResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_bool_field(total_size, 1, this->assumed_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_open, false);
  ProtoSize::add_bool_field(total_size, 1, this->requires_code, false);
  ProtoSize::add_string_field(total_size, 1, this->code_format, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesLockResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesLockResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  assumed_state: ");
  out.append(YESNO(this->assumed_state));
  out.append("\n");

  out.append("  supports_open: ");
  out.append(YESNO(this->supports_open));
  out.append("\n");

  out.append("  requires_code: ");
  out.append(YESNO(this->requires_code));
  out.append("\n");

  out.append("  code_format: ");
  out.append("'").append(this->code_format).append("'");
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool LockStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_enum<enums::LockState>();
      return true;
    }
    default:
      return false;
  }
}
bool LockStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void LockStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::LockState>(2, this->state);
}
void LockStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->state), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void LockStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("LockStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(proto_enum_to_string<enums::LockState>(this->state));
  out.append("\n");
  out.append("}");
}
#endif
bool LockCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->command = value.as_enum<enums::LockCommand>();
      return true;
    }
    case 3: {
      this->has_code = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool LockCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 4: {
      this->code = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool LockCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void LockCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::LockCommand>(2, this->command);
  buffer.encode_bool(3, this->has_code);
  buffer.encode_string(4, this->code);
}
void LockCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->command), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_code, false);
  ProtoSize::add_string_field(total_size, 1, this->code, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void LockCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("LockCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  command: ");
  out.append(proto_enum_to_string<enums::LockCommand>(this->command));
  out.append("\n");

  out.append("  has_code: ");
  out.append(YESNO(this->has_code));
  out.append("\n");

  out.append("  code: ");
  out.append("'").append(this->code).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesButtonResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 9: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesButtonResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 8: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesButtonResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesButtonResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_string(8, this->device_class);
  buffer.encode_uint32(9, this->device_id);
}
void ListEntitiesButtonResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesButtonResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesButtonResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ButtonCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ButtonCommandRequest::encode(ProtoWriteBuffer buffer) const { buffer.encode_fixed32(1, this->key); }
void ButtonCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ButtonCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ButtonCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool MediaPlayerSupportedFormat::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->sample_rate = value.as_uint32();
      return true;
    }
    case 3: {
      this->num_channels = value.as_uint32();
      return true;
    }
    case 4: {
      this->purpose = value.as_enum<enums::MediaPlayerFormatPurpose>();
      return true;
    }
    case 5: {
      this->sample_bytes = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool MediaPlayerSupportedFormat::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->format = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void MediaPlayerSupportedFormat::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->format);
  buffer.encode_uint32(2, this->sample_rate);
  buffer.encode_uint32(3, this->num_channels);
  buffer.encode_enum<enums::MediaPlayerFormatPurpose>(4, this->purpose);
  buffer.encode_uint32(5, this->sample_bytes);
}
void MediaPlayerSupportedFormat::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->format, false);
  ProtoSize::add_uint32_field(total_size, 1, this->sample_rate, false);
  ProtoSize::add_uint32_field(total_size, 1, this->num_channels, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->purpose), false);
  ProtoSize::add_uint32_field(total_size, 1, this->sample_bytes, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void MediaPlayerSupportedFormat::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("MediaPlayerSupportedFormat {\n");
  out.append("  format: ");
  out.append("'").append(this->format).append("'");
  out.append("\n");

  out.append("  sample_rate: ");
  sprintf(buffer, "%" PRIu32, this->sample_rate);
  out.append(buffer);
  out.append("\n");

  out.append("  num_channels: ");
  sprintf(buffer, "%" PRIu32, this->num_channels);
  out.append(buffer);
  out.append("\n");

  out.append("  purpose: ");
  out.append(proto_enum_to_string<enums::MediaPlayerFormatPurpose>(this->purpose));
  out.append("\n");

  out.append("  sample_bytes: ");
  sprintf(buffer, "%" PRIu32, this->sample_bytes);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesMediaPlayerResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->supports_pause = value.as_bool();
      return true;
    }
    case 10: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesMediaPlayerResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 9: {
      this->supported_formats.push_back(value.as_message<MediaPlayerSupportedFormat>());
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesMediaPlayerResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesMediaPlayerResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_bool(8, this->supports_pause);
  for (auto &it : this->supported_formats) {
    buffer.encode_message<MediaPlayerSupportedFormat>(9, it, true);
  }
  buffer.encode_uint32(10, this->device_id);
}
void ListEntitiesMediaPlayerResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_pause, false);
  ProtoSize::add_repeated_message(total_size, 1, this->supported_formats);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesMediaPlayerResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesMediaPlayerResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  supports_pause: ");
  out.append(YESNO(this->supports_pause));
  out.append("\n");

  for (const auto &it : this->supported_formats) {
    out.append("  supported_formats: ");
    it.dump_to(out);
    out.append("\n");
  }

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool MediaPlayerStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_enum<enums::MediaPlayerState>();
      return true;
    }
    case 4: {
      this->muted = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool MediaPlayerStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 3: {
      this->volume = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void MediaPlayerStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::MediaPlayerState>(2, this->state);
  buffer.encode_float(3, this->volume);
  buffer.encode_bool(4, this->muted);
}
void MediaPlayerStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->state), false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->volume != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->muted, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void MediaPlayerStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("MediaPlayerStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(proto_enum_to_string<enums::MediaPlayerState>(this->state));
  out.append("\n");

  out.append("  volume: ");
  sprintf(buffer, "%g", this->volume);
  out.append(buffer);
  out.append("\n");

  out.append("  muted: ");
  out.append(YESNO(this->muted));
  out.append("\n");
  out.append("}");
}
#endif
bool MediaPlayerCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_command = value.as_bool();
      return true;
    }
    case 3: {
      this->command = value.as_enum<enums::MediaPlayerCommand>();
      return true;
    }
    case 4: {
      this->has_volume = value.as_bool();
      return true;
    }
    case 6: {
      this->has_media_url = value.as_bool();
      return true;
    }
    case 8: {
      this->has_announcement = value.as_bool();
      return true;
    }
    case 9: {
      this->announcement = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool MediaPlayerCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 7: {
      this->media_url = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool MediaPlayerCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 5: {
      this->volume = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void MediaPlayerCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_command);
  buffer.encode_enum<enums::MediaPlayerCommand>(3, this->command);
  buffer.encode_bool(4, this->has_volume);
  buffer.encode_float(5, this->volume);
  buffer.encode_bool(6, this->has_media_url);
  buffer.encode_string(7, this->media_url);
  buffer.encode_bool(8, this->has_announcement);
  buffer.encode_bool(9, this->announcement);
}
void MediaPlayerCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_command, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->command), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_volume, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->volume != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_media_url, false);
  ProtoSize::add_string_field(total_size, 1, this->media_url, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_announcement, false);
  ProtoSize::add_bool_field(total_size, 1, this->announcement, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void MediaPlayerCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("MediaPlayerCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_command: ");
  out.append(YESNO(this->has_command));
  out.append("\n");

  out.append("  command: ");
  out.append(proto_enum_to_string<enums::MediaPlayerCommand>(this->command));
  out.append("\n");

  out.append("  has_volume: ");
  out.append(YESNO(this->has_volume));
  out.append("\n");

  out.append("  volume: ");
  sprintf(buffer, "%g", this->volume);
  out.append(buffer);
  out.append("\n");

  out.append("  has_media_url: ");
  out.append(YESNO(this->has_media_url));
  out.append("\n");

  out.append("  media_url: ");
  out.append("'").append(this->media_url).append("'");
  out.append("\n");

  out.append("  has_announcement: ");
  out.append(YESNO(this->has_announcement));
  out.append("\n");

  out.append("  announcement: ");
  out.append(YESNO(this->announcement));
  out.append("\n");
  out.append("}");
}
#endif
bool SubscribeBluetoothLEAdvertisementsRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->flags = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void SubscribeBluetoothLEAdvertisementsRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->flags);
}
void SubscribeBluetoothLEAdvertisementsRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->flags, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeBluetoothLEAdvertisementsRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SubscribeBluetoothLEAdvertisementsRequest {\n");
  out.append("  flags: ");
  sprintf(buffer, "%" PRIu32, this->flags);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothServiceData::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->legacy_data.push_back(value.as_uint32());
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothServiceData::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->uuid = value.as_string();
      return true;
    }
    case 3: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothServiceData::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->uuid);
  for (auto &it : this->legacy_data) {
    buffer.encode_uint32(2, it, true);
  }
  buffer.encode_string(3, this->data);
}
void BluetoothServiceData::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->uuid, false);
  if (!this->legacy_data.empty()) {
    for (const auto &it : this->legacy_data) {
      ProtoSize::add_uint32_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_string_field(total_size, 1, this->data, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothServiceData::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothServiceData {\n");
  out.append("  uuid: ");
  out.append("'").append(this->uuid).append("'");
  out.append("\n");

  for (const auto &it : this->legacy_data) {
    out.append("  legacy_data: ");
    sprintf(buffer, "%" PRIu32, it);
    out.append(buffer);
    out.append("\n");
  }

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothLEAdvertisementResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 3: {
      this->rssi = value.as_sint32();
      return true;
    }
    case 7: {
      this->address_type = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothLEAdvertisementResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->service_uuids.push_back(value.as_string());
      return true;
    }
    case 5: {
      this->service_data.push_back(value.as_message<BluetoothServiceData>());
      return true;
    }
    case 6: {
      this->manufacturer_data.push_back(value.as_message<BluetoothServiceData>());
      return true;
    }
    default:
      return false;
  }
}
void BluetoothLEAdvertisementResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_string(2, this->name);
  buffer.encode_sint32(3, this->rssi);
  for (auto &it : this->service_uuids) {
    buffer.encode_string(4, it, true);
  }
  for (auto &it : this->service_data) {
    buffer.encode_message<BluetoothServiceData>(5, it, true);
  }
  for (auto &it : this->manufacturer_data) {
    buffer.encode_message<BluetoothServiceData>(6, it, true);
  }
  buffer.encode_uint32(7, this->address_type);
}
void BluetoothLEAdvertisementResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_sint32_field(total_size, 1, this->rssi, false);
  if (!this->service_uuids.empty()) {
    for (const auto &it : this->service_uuids) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_repeated_message(total_size, 1, this->service_data);
  ProtoSize::add_repeated_message(total_size, 1, this->manufacturer_data);
  ProtoSize::add_uint32_field(total_size, 1, this->address_type, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothLEAdvertisementResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothLEAdvertisementResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  rssi: ");
  sprintf(buffer, "%" PRId32, this->rssi);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->service_uuids) {
    out.append("  service_uuids: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  for (const auto &it : this->service_data) {
    out.append("  service_data: ");
    it.dump_to(out);
    out.append("\n");
  }

  for (const auto &it : this->manufacturer_data) {
    out.append("  manufacturer_data: ");
    it.dump_to(out);
    out.append("\n");
  }

  out.append("  address_type: ");
  sprintf(buffer, "%" PRIu32, this->address_type);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothLERawAdvertisement::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->rssi = value.as_sint32();
      return true;
    }
    case 3: {
      this->address_type = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothLERawAdvertisement::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 4: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothLERawAdvertisement::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_sint32(2, this->rssi);
  buffer.encode_uint32(3, this->address_type);
  buffer.encode_string(4, this->data);
}
void BluetoothLERawAdvertisement::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_sint32_field(total_size, 1, this->rssi, false);
  ProtoSize::add_uint32_field(total_size, 1, this->address_type, false);
  ProtoSize::add_string_field(total_size, 1, this->data, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothLERawAdvertisement::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothLERawAdvertisement {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  rssi: ");
  sprintf(buffer, "%" PRId32, this->rssi);
  out.append(buffer);
  out.append("\n");

  out.append("  address_type: ");
  sprintf(buffer, "%" PRIu32, this->address_type);
  out.append(buffer);
  out.append("\n");

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothLERawAdvertisementsResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->advertisements.push_back(value.as_message<BluetoothLERawAdvertisement>());
      return true;
    }
    default:
      return false;
  }
}
void BluetoothLERawAdvertisementsResponse::encode(ProtoWriteBuffer buffer) const {
  for (auto &it : this->advertisements) {
    buffer.encode_message<BluetoothLERawAdvertisement>(1, it, true);
  }
}
void BluetoothLERawAdvertisementsResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_repeated_message(total_size, 1, this->advertisements);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothLERawAdvertisementsResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothLERawAdvertisementsResponse {\n");
  for (const auto &it : this->advertisements) {
    out.append("  advertisements: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool BluetoothDeviceRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->request_type = value.as_enum<enums::BluetoothDeviceRequestType>();
      return true;
    }
    case 3: {
      this->has_address_type = value.as_bool();
      return true;
    }
    case 4: {
      this->address_type = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothDeviceRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_enum<enums::BluetoothDeviceRequestType>(2, this->request_type);
  buffer.encode_bool(3, this->has_address_type);
  buffer.encode_uint32(4, this->address_type);
}
void BluetoothDeviceRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->request_type), false);
  ProtoSize::add_bool_field(total_size, 1, this->has_address_type, false);
  ProtoSize::add_uint32_field(total_size, 1, this->address_type, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothDeviceRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothDeviceRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  request_type: ");
  out.append(proto_enum_to_string<enums::BluetoothDeviceRequestType>(this->request_type));
  out.append("\n");

  out.append("  has_address_type: ");
  out.append(YESNO(this->has_address_type));
  out.append("\n");

  out.append("  address_type: ");
  sprintf(buffer, "%" PRIu32, this->address_type);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothDeviceConnectionResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->connected = value.as_bool();
      return true;
    }
    case 3: {
      this->mtu = value.as_uint32();
      return true;
    }
    case 4: {
      this->error = value.as_int32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothDeviceConnectionResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_bool(2, this->connected);
  buffer.encode_uint32(3, this->mtu);
  buffer.encode_int32(4, this->error);
}
void BluetoothDeviceConnectionResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_bool_field(total_size, 1, this->connected, false);
  ProtoSize::add_uint32_field(total_size, 1, this->mtu, false);
  ProtoSize::add_int32_field(total_size, 1, this->error, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothDeviceConnectionResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothDeviceConnectionResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  connected: ");
  out.append(YESNO(this->connected));
  out.append("\n");

  out.append("  mtu: ");
  sprintf(buffer, "%" PRIu32, this->mtu);
  out.append(buffer);
  out.append("\n");

  out.append("  error: ");
  sprintf(buffer, "%" PRId32, this->error);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTGetServicesRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTGetServicesRequest::encode(ProtoWriteBuffer buffer) const { buffer.encode_uint64(1, this->address); }
void BluetoothGATTGetServicesRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTGetServicesRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTGetServicesRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTDescriptor::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->uuid.push_back(value.as_uint64());
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTDescriptor::encode(ProtoWriteBuffer buffer) const {
  for (auto &it : this->uuid) {
    buffer.encode_uint64(1, it, true);
  }
  buffer.encode_uint32(2, this->handle);
}
void BluetoothGATTDescriptor::calculate_size(uint32_t &total_size) const {
  if (!this->uuid.empty()) {
    for (const auto &it : this->uuid) {
      ProtoSize::add_uint64_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTDescriptor::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTDescriptor {\n");
  for (const auto &it : this->uuid) {
    out.append("  uuid: ");
    sprintf(buffer, "%llu", it);
    out.append(buffer);
    out.append("\n");
  }

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTCharacteristic::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->uuid.push_back(value.as_uint64());
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    case 3: {
      this->properties = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTCharacteristic::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 4: {
      this->descriptors.push_back(value.as_message<BluetoothGATTDescriptor>());
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTCharacteristic::encode(ProtoWriteBuffer buffer) const {
  for (auto &it : this->uuid) {
    buffer.encode_uint64(1, it, true);
  }
  buffer.encode_uint32(2, this->handle);
  buffer.encode_uint32(3, this->properties);
  for (auto &it : this->descriptors) {
    buffer.encode_message<BluetoothGATTDescriptor>(4, it, true);
  }
}
void BluetoothGATTCharacteristic::calculate_size(uint32_t &total_size) const {
  if (!this->uuid.empty()) {
    for (const auto &it : this->uuid) {
      ProtoSize::add_uint64_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_uint32_field(total_size, 1, this->properties, false);
  ProtoSize::add_repeated_message(total_size, 1, this->descriptors);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTCharacteristic::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTCharacteristic {\n");
  for (const auto &it : this->uuid) {
    out.append("  uuid: ");
    sprintf(buffer, "%llu", it);
    out.append(buffer);
    out.append("\n");
  }

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  properties: ");
  sprintf(buffer, "%" PRIu32, this->properties);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->descriptors) {
    out.append("  descriptors: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool BluetoothGATTService::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->uuid.push_back(value.as_uint64());
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTService::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->characteristics.push_back(value.as_message<BluetoothGATTCharacteristic>());
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTService::encode(ProtoWriteBuffer buffer) const {
  for (auto &it : this->uuid) {
    buffer.encode_uint64(1, it, true);
  }
  buffer.encode_uint32(2, this->handle);
  for (auto &it : this->characteristics) {
    buffer.encode_message<BluetoothGATTCharacteristic>(3, it, true);
  }
}
void BluetoothGATTService::calculate_size(uint32_t &total_size) const {
  if (!this->uuid.empty()) {
    for (const auto &it : this->uuid) {
      ProtoSize::add_uint64_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_repeated_message(total_size, 1, this->characteristics);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTService::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTService {\n");
  for (const auto &it : this->uuid) {
    out.append("  uuid: ");
    sprintf(buffer, "%llu", it);
    out.append(buffer);
    out.append("\n");
  }

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->characteristics) {
    out.append("  characteristics: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool BluetoothGATTGetServicesResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTGetServicesResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->services.push_back(value.as_message<BluetoothGATTService>());
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTGetServicesResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  for (auto &it : this->services) {
    buffer.encode_message<BluetoothGATTService>(2, it, true);
  }
}
void BluetoothGATTGetServicesResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_repeated_message(total_size, 1, this->services);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTGetServicesResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTGetServicesResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->services) {
    out.append("  services: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool BluetoothGATTGetServicesDoneResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTGetServicesDoneResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
}
void BluetoothGATTGetServicesDoneResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTGetServicesDoneResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTGetServicesDoneResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTReadRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTReadRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
}
void BluetoothGATTReadRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTReadRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTReadRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTReadResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTReadResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTReadResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
  buffer.encode_string(3, this->data);
}
void BluetoothGATTReadResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_string_field(total_size, 1, this->data, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTReadResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTReadResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTWriteRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    case 3: {
      this->response = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTWriteRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 4: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTWriteRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
  buffer.encode_bool(3, this->response);
  buffer.encode_string(4, this->data);
}
void BluetoothGATTWriteRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_bool_field(total_size, 1, this->response, false);
  ProtoSize::add_string_field(total_size, 1, this->data, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTWriteRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTWriteRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  response: ");
  out.append(YESNO(this->response));
  out.append("\n");

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTReadDescriptorRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTReadDescriptorRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
}
void BluetoothGATTReadDescriptorRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTReadDescriptorRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTReadDescriptorRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTWriteDescriptorRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTWriteDescriptorRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTWriteDescriptorRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
  buffer.encode_string(3, this->data);
}
void BluetoothGATTWriteDescriptorRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_string_field(total_size, 1, this->data, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTWriteDescriptorRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTWriteDescriptorRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTNotifyRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    case 3: {
      this->enable = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTNotifyRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
  buffer.encode_bool(3, this->enable);
}
void BluetoothGATTNotifyRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_bool_field(total_size, 1, this->enable, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTNotifyRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTNotifyRequest {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  enable: ");
  out.append(YESNO(this->enable));
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTNotifyDataResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool BluetoothGATTNotifyDataResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTNotifyDataResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
  buffer.encode_string(3, this->data);
}
void BluetoothGATTNotifyDataResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_string_field(total_size, 1, this->data, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTNotifyDataResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTNotifyDataResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeBluetoothConnectionsFreeRequest::dump_to(std::string &out) const {
  out.append("SubscribeBluetoothConnectionsFreeRequest {}");
}
#endif
bool BluetoothConnectionsFreeResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->free = value.as_uint32();
      return true;
    }
    case 2: {
      this->limit = value.as_uint32();
      return true;
    }
    case 3: {
      this->allocated.push_back(value.as_uint64());
      return true;
    }
    default:
      return false;
  }
}
void BluetoothConnectionsFreeResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->free);
  buffer.encode_uint32(2, this->limit);
  for (auto &it : this->allocated) {
    buffer.encode_uint64(3, it, true);
  }
}
void BluetoothConnectionsFreeResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->free, false);
  ProtoSize::add_uint32_field(total_size, 1, this->limit, false);
  if (!this->allocated.empty()) {
    for (const auto &it : this->allocated) {
      ProtoSize::add_uint64_field(total_size, 1, it, true);
    }
  }
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothConnectionsFreeResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothConnectionsFreeResponse {\n");
  out.append("  free: ");
  sprintf(buffer, "%" PRIu32, this->free);
  out.append(buffer);
  out.append("\n");

  out.append("  limit: ");
  sprintf(buffer, "%" PRIu32, this->limit);
  out.append(buffer);
  out.append("\n");

  for (const auto &it : this->allocated) {
    out.append("  allocated: ");
    sprintf(buffer, "%llu", it);
    out.append(buffer);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool BluetoothGATTErrorResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    case 3: {
      this->error = value.as_int32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTErrorResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
  buffer.encode_int32(3, this->error);
}
void BluetoothGATTErrorResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
  ProtoSize::add_int32_field(total_size, 1, this->error, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTErrorResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTErrorResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");

  out.append("  error: ");
  sprintf(buffer, "%" PRId32, this->error);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTWriteResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTWriteResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
}
void BluetoothGATTWriteResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTWriteResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTWriteResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothGATTNotifyResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->handle = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothGATTNotifyResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_uint32(2, this->handle);
}
void BluetoothGATTNotifyResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_uint32_field(total_size, 1, this->handle, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothGATTNotifyResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothGATTNotifyResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  handle: ");
  sprintf(buffer, "%" PRIu32, this->handle);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothDevicePairingResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->paired = value.as_bool();
      return true;
    }
    case 3: {
      this->error = value.as_int32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothDevicePairingResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_bool(2, this->paired);
  buffer.encode_int32(3, this->error);
}
void BluetoothDevicePairingResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_bool_field(total_size, 1, this->paired, false);
  ProtoSize::add_int32_field(total_size, 1, this->error, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothDevicePairingResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothDevicePairingResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  paired: ");
  out.append(YESNO(this->paired));
  out.append("\n");

  out.append("  error: ");
  sprintf(buffer, "%" PRId32, this->error);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothDeviceUnpairingResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->success = value.as_bool();
      return true;
    }
    case 3: {
      this->error = value.as_int32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothDeviceUnpairingResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_bool(2, this->success);
  buffer.encode_int32(3, this->error);
}
void BluetoothDeviceUnpairingResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_bool_field(total_size, 1, this->success, false);
  ProtoSize::add_int32_field(total_size, 1, this->error, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothDeviceUnpairingResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothDeviceUnpairingResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  success: ");
  out.append(YESNO(this->success));
  out.append("\n");

  out.append("  error: ");
  sprintf(buffer, "%" PRId32, this->error);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void UnsubscribeBluetoothLEAdvertisementsRequest::dump_to(std::string &out) const {
  out.append("UnsubscribeBluetoothLEAdvertisementsRequest {}");
}
#endif
bool BluetoothDeviceClearCacheResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->address = value.as_uint64();
      return true;
    }
    case 2: {
      this->success = value.as_bool();
      return true;
    }
    case 3: {
      this->error = value.as_int32();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothDeviceClearCacheResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint64(1, this->address);
  buffer.encode_bool(2, this->success);
  buffer.encode_int32(3, this->error);
}
void BluetoothDeviceClearCacheResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint64_field(total_size, 1, this->address, false);
  ProtoSize::add_bool_field(total_size, 1, this->success, false);
  ProtoSize::add_int32_field(total_size, 1, this->error, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothDeviceClearCacheResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothDeviceClearCacheResponse {\n");
  out.append("  address: ");
  sprintf(buffer, "%llu", this->address);
  out.append(buffer);
  out.append("\n");

  out.append("  success: ");
  out.append(YESNO(this->success));
  out.append("\n");

  out.append("  error: ");
  sprintf(buffer, "%" PRId32, this->error);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothScannerStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->state = value.as_enum<enums::BluetoothScannerState>();
      return true;
    }
    case 2: {
      this->mode = value.as_enum<enums::BluetoothScannerMode>();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothScannerStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_enum<enums::BluetoothScannerState>(1, this->state);
  buffer.encode_enum<enums::BluetoothScannerMode>(2, this->mode);
}
void BluetoothScannerStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->state), false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->mode), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothScannerStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothScannerStateResponse {\n");
  out.append("  state: ");
  out.append(proto_enum_to_string<enums::BluetoothScannerState>(this->state));
  out.append("\n");

  out.append("  mode: ");
  out.append(proto_enum_to_string<enums::BluetoothScannerMode>(this->mode));
  out.append("\n");
  out.append("}");
}
#endif
bool BluetoothScannerSetModeRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->mode = value.as_enum<enums::BluetoothScannerMode>();
      return true;
    }
    default:
      return false;
  }
}
void BluetoothScannerSetModeRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_enum<enums::BluetoothScannerMode>(1, this->mode);
}
void BluetoothScannerSetModeRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->mode), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void BluetoothScannerSetModeRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("BluetoothScannerSetModeRequest {\n");
  out.append("  mode: ");
  out.append(proto_enum_to_string<enums::BluetoothScannerMode>(this->mode));
  out.append("\n");
  out.append("}");
}
#endif
bool SubscribeVoiceAssistantRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->subscribe = value.as_bool();
      return true;
    }
    case 2: {
      this->flags = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
void SubscribeVoiceAssistantRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_bool(1, this->subscribe);
  buffer.encode_uint32(2, this->flags);
}
void SubscribeVoiceAssistantRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->subscribe, false);
  ProtoSize::add_uint32_field(total_size, 1, this->flags, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void SubscribeVoiceAssistantRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("SubscribeVoiceAssistantRequest {\n");
  out.append("  subscribe: ");
  out.append(YESNO(this->subscribe));
  out.append("\n");

  out.append("  flags: ");
  sprintf(buffer, "%" PRIu32, this->flags);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantAudioSettings::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->noise_suppression_level = value.as_uint32();
      return true;
    }
    case 2: {
      this->auto_gain = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantAudioSettings::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 3: {
      this->volume_multiplier = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantAudioSettings::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->noise_suppression_level);
  buffer.encode_uint32(2, this->auto_gain);
  buffer.encode_float(3, this->volume_multiplier);
}
void VoiceAssistantAudioSettings::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->noise_suppression_level, false);
  ProtoSize::add_uint32_field(total_size, 1, this->auto_gain, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->volume_multiplier != 0.0f, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantAudioSettings::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantAudioSettings {\n");
  out.append("  noise_suppression_level: ");
  sprintf(buffer, "%" PRIu32, this->noise_suppression_level);
  out.append(buffer);
  out.append("\n");

  out.append("  auto_gain: ");
  sprintf(buffer, "%" PRIu32, this->auto_gain);
  out.append(buffer);
  out.append("\n");

  out.append("  volume_multiplier: ");
  sprintf(buffer, "%g", this->volume_multiplier);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->start = value.as_bool();
      return true;
    }
    case 3: {
      this->flags = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->conversation_id = value.as_string();
      return true;
    }
    case 4: {
      this->audio_settings = value.as_message<VoiceAssistantAudioSettings>();
      return true;
    }
    case 5: {
      this->wake_word_phrase = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_bool(1, this->start);
  buffer.encode_string(2, this->conversation_id);
  buffer.encode_uint32(3, this->flags);
  buffer.encode_message<VoiceAssistantAudioSettings>(4, this->audio_settings);
  buffer.encode_string(5, this->wake_word_phrase);
}
void VoiceAssistantRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->start, false);
  ProtoSize::add_string_field(total_size, 1, this->conversation_id, false);
  ProtoSize::add_uint32_field(total_size, 1, this->flags, false);
  ProtoSize::add_message_object(total_size, 1, this->audio_settings, false);
  ProtoSize::add_string_field(total_size, 1, this->wake_word_phrase, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantRequest {\n");
  out.append("  start: ");
  out.append(YESNO(this->start));
  out.append("\n");

  out.append("  conversation_id: ");
  out.append("'").append(this->conversation_id).append("'");
  out.append("\n");

  out.append("  flags: ");
  sprintf(buffer, "%" PRIu32, this->flags);
  out.append(buffer);
  out.append("\n");

  out.append("  audio_settings: ");
  this->audio_settings.dump_to(out);
  out.append("\n");

  out.append("  wake_word_phrase: ");
  out.append("'").append(this->wake_word_phrase).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->port = value.as_uint32();
      return true;
    }
    case 2: {
      this->error = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_uint32(1, this->port);
  buffer.encode_bool(2, this->error);
}
void VoiceAssistantResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_uint32_field(total_size, 1, this->port, false);
  ProtoSize::add_bool_field(total_size, 1, this->error, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantResponse {\n");
  out.append("  port: ");
  sprintf(buffer, "%" PRIu32, this->port);
  out.append(buffer);
  out.append("\n");

  out.append("  error: ");
  out.append(YESNO(this->error));
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantEventData::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->name = value.as_string();
      return true;
    }
    case 2: {
      this->value = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantEventData::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->name);
  buffer.encode_string(2, this->value);
}
void VoiceAssistantEventData::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->value, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantEventData::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantEventData {\n");
  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  value: ");
  out.append("'").append(this->value).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantEventResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->event_type = value.as_enum<enums::VoiceAssistantEvent>();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantEventResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->data.push_back(value.as_message<VoiceAssistantEventData>());
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantEventResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_enum<enums::VoiceAssistantEvent>(1, this->event_type);
  for (auto &it : this->data) {
    buffer.encode_message<VoiceAssistantEventData>(2, it, true);
  }
}
void VoiceAssistantEventResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->event_type), false);
  ProtoSize::add_repeated_message(total_size, 1, this->data);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantEventResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantEventResponse {\n");
  out.append("  event_type: ");
  out.append(proto_enum_to_string<enums::VoiceAssistantEvent>(this->event_type));
  out.append("\n");

  for (const auto &it : this->data) {
    out.append("  data: ");
    it.dump_to(out);
    out.append("\n");
  }
  out.append("}");
}
#endif
bool VoiceAssistantAudio::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->end = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantAudio::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->data = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantAudio::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->data);
  buffer.encode_bool(2, this->end);
}
void VoiceAssistantAudio::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->data, false);
  ProtoSize::add_bool_field(total_size, 1, this->end, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantAudio::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantAudio {\n");
  out.append("  data: ");
  out.append("'").append(this->data).append("'");
  out.append("\n");

  out.append("  end: ");
  out.append(YESNO(this->end));
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantTimerEventResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->event_type = value.as_enum<enums::VoiceAssistantTimerEvent>();
      return true;
    }
    case 4: {
      this->total_seconds = value.as_uint32();
      return true;
    }
    case 5: {
      this->seconds_left = value.as_uint32();
      return true;
    }
    case 6: {
      this->is_active = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantTimerEventResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->timer_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantTimerEventResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_enum<enums::VoiceAssistantTimerEvent>(1, this->event_type);
  buffer.encode_string(2, this->timer_id);
  buffer.encode_string(3, this->name);
  buffer.encode_uint32(4, this->total_seconds);
  buffer.encode_uint32(5, this->seconds_left);
  buffer.encode_bool(6, this->is_active);
}
void VoiceAssistantTimerEventResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->event_type), false);
  ProtoSize::add_string_field(total_size, 1, this->timer_id, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_uint32_field(total_size, 1, this->total_seconds, false);
  ProtoSize::add_uint32_field(total_size, 1, this->seconds_left, false);
  ProtoSize::add_bool_field(total_size, 1, this->is_active, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantTimerEventResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantTimerEventResponse {\n");
  out.append("  event_type: ");
  out.append(proto_enum_to_string<enums::VoiceAssistantTimerEvent>(this->event_type));
  out.append("\n");

  out.append("  timer_id: ");
  out.append("'").append(this->timer_id).append("'");
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  total_seconds: ");
  sprintf(buffer, "%" PRIu32, this->total_seconds);
  out.append(buffer);
  out.append("\n");

  out.append("  seconds_left: ");
  sprintf(buffer, "%" PRIu32, this->seconds_left);
  out.append(buffer);
  out.append("\n");

  out.append("  is_active: ");
  out.append(YESNO(this->is_active));
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantAnnounceRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 4: {
      this->start_conversation = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantAnnounceRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->media_id = value.as_string();
      return true;
    }
    case 2: {
      this->text = value.as_string();
      return true;
    }
    case 3: {
      this->preannounce_media_id = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantAnnounceRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->media_id);
  buffer.encode_string(2, this->text);
  buffer.encode_string(3, this->preannounce_media_id);
  buffer.encode_bool(4, this->start_conversation);
}
void VoiceAssistantAnnounceRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->media_id, false);
  ProtoSize::add_string_field(total_size, 1, this->text, false);
  ProtoSize::add_string_field(total_size, 1, this->preannounce_media_id, false);
  ProtoSize::add_bool_field(total_size, 1, this->start_conversation, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantAnnounceRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantAnnounceRequest {\n");
  out.append("  media_id: ");
  out.append("'").append(this->media_id).append("'");
  out.append("\n");

  out.append("  text: ");
  out.append("'").append(this->text).append("'");
  out.append("\n");

  out.append("  preannounce_media_id: ");
  out.append("'").append(this->preannounce_media_id).append("'");
  out.append("\n");

  out.append("  start_conversation: ");
  out.append(YESNO(this->start_conversation));
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantAnnounceFinished::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 1: {
      this->success = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantAnnounceFinished::encode(ProtoWriteBuffer buffer) const { buffer.encode_bool(1, this->success); }
void VoiceAssistantAnnounceFinished::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_bool_field(total_size, 1, this->success, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantAnnounceFinished::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantAnnounceFinished {\n");
  out.append("  success: ");
  out.append(YESNO(this->success));
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantWakeWord::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->id = value.as_string();
      return true;
    }
    case 2: {
      this->wake_word = value.as_string();
      return true;
    }
    case 3: {
      this->trained_languages.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantWakeWord::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->id);
  buffer.encode_string(2, this->wake_word);
  for (auto &it : this->trained_languages) {
    buffer.encode_string(3, it, true);
  }
}
void VoiceAssistantWakeWord::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->id, false);
  ProtoSize::add_string_field(total_size, 1, this->wake_word, false);
  if (!this->trained_languages.empty()) {
    for (const auto &it : this->trained_languages) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantWakeWord::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantWakeWord {\n");
  out.append("  id: ");
  out.append("'").append(this->id).append("'");
  out.append("\n");

  out.append("  wake_word: ");
  out.append("'").append(this->wake_word).append("'");
  out.append("\n");

  for (const auto &it : this->trained_languages) {
    out.append("  trained_languages: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }
  out.append("}");
}
#endif
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantConfigurationRequest::dump_to(std::string &out) const {
  out.append("VoiceAssistantConfigurationRequest {}");
}
#endif
bool VoiceAssistantConfigurationResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->max_active_wake_words = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool VoiceAssistantConfigurationResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->available_wake_words.push_back(value.as_message<VoiceAssistantWakeWord>());
      return true;
    }
    case 2: {
      this->active_wake_words.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantConfigurationResponse::encode(ProtoWriteBuffer buffer) const {
  for (auto &it : this->available_wake_words) {
    buffer.encode_message<VoiceAssistantWakeWord>(1, it, true);
  }
  for (auto &it : this->active_wake_words) {
    buffer.encode_string(2, it, true);
  }
  buffer.encode_uint32(3, this->max_active_wake_words);
}
void VoiceAssistantConfigurationResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_repeated_message(total_size, 1, this->available_wake_words);
  if (!this->active_wake_words.empty()) {
    for (const auto &it : this->active_wake_words) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_uint32_field(total_size, 1, this->max_active_wake_words, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantConfigurationResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantConfigurationResponse {\n");
  for (const auto &it : this->available_wake_words) {
    out.append("  available_wake_words: ");
    it.dump_to(out);
    out.append("\n");
  }

  for (const auto &it : this->active_wake_words) {
    out.append("  active_wake_words: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  max_active_wake_words: ");
  sprintf(buffer, "%" PRIu32, this->max_active_wake_words);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool VoiceAssistantSetConfiguration::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->active_wake_words.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
void VoiceAssistantSetConfiguration::encode(ProtoWriteBuffer buffer) const {
  for (auto &it : this->active_wake_words) {
    buffer.encode_string(1, it, true);
  }
}
void VoiceAssistantSetConfiguration::calculate_size(uint32_t &total_size) const {
  if (!this->active_wake_words.empty()) {
    for (const auto &it : this->active_wake_words) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void VoiceAssistantSetConfiguration::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("VoiceAssistantSetConfiguration {\n");
  for (const auto &it : this->active_wake_words) {
    out.append("  active_wake_words: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }
  out.append("}");
}
#endif
bool ListEntitiesAlarmControlPanelResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->supported_features = value.as_uint32();
      return true;
    }
    case 9: {
      this->requires_code = value.as_bool();
      return true;
    }
    case 10: {
      this->requires_code_to_arm = value.as_bool();
      return true;
    }
    case 11: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesAlarmControlPanelResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesAlarmControlPanelResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesAlarmControlPanelResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_uint32(8, this->supported_features);
  buffer.encode_bool(9, this->requires_code);
  buffer.encode_bool(10, this->requires_code_to_arm);
  buffer.encode_uint32(11, this->device_id);
}
void ListEntitiesAlarmControlPanelResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->supported_features, false);
  ProtoSize::add_bool_field(total_size, 1, this->requires_code, false);
  ProtoSize::add_bool_field(total_size, 1, this->requires_code_to_arm, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesAlarmControlPanelResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesAlarmControlPanelResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  supported_features: ");
  sprintf(buffer, "%" PRIu32, this->supported_features);
  out.append(buffer);
  out.append("\n");

  out.append("  requires_code: ");
  out.append(YESNO(this->requires_code));
  out.append("\n");

  out.append("  requires_code_to_arm: ");
  out.append(YESNO(this->requires_code_to_arm));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool AlarmControlPanelStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_enum<enums::AlarmControlPanelState>();
      return true;
    }
    default:
      return false;
  }
}
bool AlarmControlPanelStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void AlarmControlPanelStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::AlarmControlPanelState>(2, this->state);
}
void AlarmControlPanelStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->state), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void AlarmControlPanelStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("AlarmControlPanelStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append(proto_enum_to_string<enums::AlarmControlPanelState>(this->state));
  out.append("\n");
  out.append("}");
}
#endif
bool AlarmControlPanelCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->command = value.as_enum<enums::AlarmControlPanelStateCommand>();
      return true;
    }
    default:
      return false;
  }
}
bool AlarmControlPanelCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 3: {
      this->code = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool AlarmControlPanelCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void AlarmControlPanelCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::AlarmControlPanelStateCommand>(2, this->command);
  buffer.encode_string(3, this->code);
}
void AlarmControlPanelCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->command), false);
  ProtoSize::add_string_field(total_size, 1, this->code, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void AlarmControlPanelCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("AlarmControlPanelCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  command: ");
  out.append(proto_enum_to_string<enums::AlarmControlPanelStateCommand>(this->command));
  out.append("\n");

  out.append("  code: ");
  out.append("'").append(this->code).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesTextResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->min_length = value.as_uint32();
      return true;
    }
    case 9: {
      this->max_length = value.as_uint32();
      return true;
    }
    case 11: {
      this->mode = value.as_enum<enums::TextMode>();
      return true;
    }
    case 12: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesTextResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 10: {
      this->pattern = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesTextResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesTextResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_uint32(8, this->min_length);
  buffer.encode_uint32(9, this->max_length);
  buffer.encode_string(10, this->pattern);
  buffer.encode_enum<enums::TextMode>(11, this->mode);
  buffer.encode_uint32(12, this->device_id);
}
void ListEntitiesTextResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->min_length, false);
  ProtoSize::add_uint32_field(total_size, 1, this->max_length, false);
  ProtoSize::add_string_field(total_size, 1, this->pattern, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->mode), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesTextResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesTextResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  min_length: ");
  sprintf(buffer, "%" PRIu32, this->min_length);
  out.append(buffer);
  out.append("\n");

  out.append("  max_length: ");
  sprintf(buffer, "%" PRIu32, this->max_length);
  out.append(buffer);
  out.append("\n");

  out.append("  pattern: ");
  out.append("'").append(this->pattern).append("'");
  out.append("\n");

  out.append("  mode: ");
  out.append(proto_enum_to_string<enums::TextMode>(this->mode));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool TextStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool TextStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool TextStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void TextStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->state);
  buffer.encode_bool(3, this->missing_state);
}
void TextStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->state, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void TextStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("TextStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append("'").append(this->state).append("'");
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");
  out.append("}");
}
#endif
bool TextCommandRequest::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->state = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool TextCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void TextCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->state);
}
void TextCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->state, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void TextCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("TextCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  state: ");
  out.append("'").append(this->state).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesDateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesDateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesDateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesDateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_uint32(8, this->device_id);
}
void ListEntitiesDateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesDateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesDateResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool DateStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->missing_state = value.as_bool();
      return true;
    }
    case 3: {
      this->year = value.as_uint32();
      return true;
    }
    case 4: {
      this->month = value.as_uint32();
      return true;
    }
    case 5: {
      this->day = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool DateStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void DateStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->missing_state);
  buffer.encode_uint32(3, this->year);
  buffer.encode_uint32(4, this->month);
  buffer.encode_uint32(5, this->day);
}
void DateStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
  ProtoSize::add_uint32_field(total_size, 1, this->year, false);
  ProtoSize::add_uint32_field(total_size, 1, this->month, false);
  ProtoSize::add_uint32_field(total_size, 1, this->day, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void DateStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("DateStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");

  out.append("  year: ");
  sprintf(buffer, "%" PRIu32, this->year);
  out.append(buffer);
  out.append("\n");

  out.append("  month: ");
  sprintf(buffer, "%" PRIu32, this->month);
  out.append(buffer);
  out.append("\n");

  out.append("  day: ");
  sprintf(buffer, "%" PRIu32, this->day);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool DateCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->year = value.as_uint32();
      return true;
    }
    case 3: {
      this->month = value.as_uint32();
      return true;
    }
    case 4: {
      this->day = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool DateCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void DateCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_uint32(2, this->year);
  buffer.encode_uint32(3, this->month);
  buffer.encode_uint32(4, this->day);
}
void DateCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_uint32_field(total_size, 1, this->year, false);
  ProtoSize::add_uint32_field(total_size, 1, this->month, false);
  ProtoSize::add_uint32_field(total_size, 1, this->day, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void DateCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("DateCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  year: ");
  sprintf(buffer, "%" PRIu32, this->year);
  out.append(buffer);
  out.append("\n");

  out.append("  month: ");
  sprintf(buffer, "%" PRIu32, this->month);
  out.append(buffer);
  out.append("\n");

  out.append("  day: ");
  sprintf(buffer, "%" PRIu32, this->day);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesTimeResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesTimeResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesTimeResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesTimeResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_uint32(8, this->device_id);
}
void ListEntitiesTimeResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesTimeResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesTimeResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool TimeStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->missing_state = value.as_bool();
      return true;
    }
    case 3: {
      this->hour = value.as_uint32();
      return true;
    }
    case 4: {
      this->minute = value.as_uint32();
      return true;
    }
    case 5: {
      this->second = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool TimeStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void TimeStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->missing_state);
  buffer.encode_uint32(3, this->hour);
  buffer.encode_uint32(4, this->minute);
  buffer.encode_uint32(5, this->second);
}
void TimeStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
  ProtoSize::add_uint32_field(total_size, 1, this->hour, false);
  ProtoSize::add_uint32_field(total_size, 1, this->minute, false);
  ProtoSize::add_uint32_field(total_size, 1, this->second, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void TimeStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("TimeStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");

  out.append("  hour: ");
  sprintf(buffer, "%" PRIu32, this->hour);
  out.append(buffer);
  out.append("\n");

  out.append("  minute: ");
  sprintf(buffer, "%" PRIu32, this->minute);
  out.append(buffer);
  out.append("\n");

  out.append("  second: ");
  sprintf(buffer, "%" PRIu32, this->second);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool TimeCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->hour = value.as_uint32();
      return true;
    }
    case 3: {
      this->minute = value.as_uint32();
      return true;
    }
    case 4: {
      this->second = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool TimeCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void TimeCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_uint32(2, this->hour);
  buffer.encode_uint32(3, this->minute);
  buffer.encode_uint32(4, this->second);
}
void TimeCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_uint32_field(total_size, 1, this->hour, false);
  ProtoSize::add_uint32_field(total_size, 1, this->minute, false);
  ProtoSize::add_uint32_field(total_size, 1, this->second, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void TimeCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("TimeCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  hour: ");
  sprintf(buffer, "%" PRIu32, this->hour);
  out.append(buffer);
  out.append("\n");

  out.append("  minute: ");
  sprintf(buffer, "%" PRIu32, this->minute);
  out.append(buffer);
  out.append("\n");

  out.append("  second: ");
  sprintf(buffer, "%" PRIu32, this->second);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesEventResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 10: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesEventResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 8: {
      this->device_class = value.as_string();
      return true;
    }
    case 9: {
      this->event_types.push_back(value.as_string());
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesEventResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesEventResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_string(8, this->device_class);
  for (auto &it : this->event_types) {
    buffer.encode_string(9, it, true);
  }
  buffer.encode_uint32(10, this->device_id);
}
void ListEntitiesEventResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  if (!this->event_types.empty()) {
    for (const auto &it : this->event_types) {
      ProtoSize::add_string_field(total_size, 1, it, true);
    }
  }
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesEventResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesEventResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  for (const auto &it : this->event_types) {
    out.append("  event_types: ");
    out.append("'").append(it).append("'");
    out.append("\n");
  }

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool EventResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 2: {
      this->event_type = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool EventResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void EventResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_string(2, this->event_type);
}
void EventResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->event_type, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void EventResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("EventResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  event_type: ");
  out.append("'").append(this->event_type).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesValveResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 9: {
      this->assumed_state = value.as_bool();
      return true;
    }
    case 10: {
      this->supports_position = value.as_bool();
      return true;
    }
    case 11: {
      this->supports_stop = value.as_bool();
      return true;
    }
    case 12: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesValveResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 8: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesValveResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesValveResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_string(8, this->device_class);
  buffer.encode_bool(9, this->assumed_state);
  buffer.encode_bool(10, this->supports_position);
  buffer.encode_bool(11, this->supports_stop);
  buffer.encode_uint32(12, this->device_id);
}
void ListEntitiesValveResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_bool_field(total_size, 1, this->assumed_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_position, false);
  ProtoSize::add_bool_field(total_size, 1, this->supports_stop, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesValveResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesValveResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  assumed_state: ");
  out.append(YESNO(this->assumed_state));
  out.append("\n");

  out.append("  supports_position: ");
  out.append(YESNO(this->supports_position));
  out.append("\n");

  out.append("  supports_stop: ");
  out.append(YESNO(this->supports_stop));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ValveStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 3: {
      this->current_operation = value.as_enum<enums::ValveOperation>();
      return true;
    }
    default:
      return false;
  }
}
bool ValveStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 2: {
      this->position = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ValveStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_float(2, this->position);
  buffer.encode_enum<enums::ValveOperation>(3, this->current_operation);
}
void ValveStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->position != 0.0f, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->current_operation), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ValveStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ValveStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  position: ");
  sprintf(buffer, "%g", this->position);
  out.append(buffer);
  out.append("\n");

  out.append("  current_operation: ");
  out.append(proto_enum_to_string<enums::ValveOperation>(this->current_operation));
  out.append("\n");
  out.append("}");
}
#endif
bool ValveCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->has_position = value.as_bool();
      return true;
    }
    case 4: {
      this->stop = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool ValveCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 3: {
      this->position = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void ValveCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->has_position);
  buffer.encode_float(3, this->position);
  buffer.encode_bool(4, this->stop);
}
void ValveCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_position, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->position != 0.0f, false);
  ProtoSize::add_bool_field(total_size, 1, this->stop, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ValveCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ValveCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  has_position: ");
  out.append(YESNO(this->has_position));
  out.append("\n");

  out.append("  position: ");
  sprintf(buffer, "%g", this->position);
  out.append(buffer);
  out.append("\n");

  out.append("  stop: ");
  out.append(YESNO(this->stop));
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesDateTimeResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 8: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesDateTimeResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesDateTimeResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesDateTimeResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_uint32(8, this->device_id);
}
void ListEntitiesDateTimeResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesDateTimeResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesDateTimeResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool DateTimeStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->missing_state = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool DateTimeStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 3: {
      this->epoch_seconds = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void DateTimeStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->missing_state);
  buffer.encode_fixed32(3, this->epoch_seconds);
}
void DateTimeStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->epoch_seconds != 0, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void DateTimeStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("DateTimeStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");

  out.append("  epoch_seconds: ");
  sprintf(buffer, "%" PRIu32, this->epoch_seconds);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool DateTimeCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 2: {
      this->epoch_seconds = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void DateTimeCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_fixed32(2, this->epoch_seconds);
}
void DateTimeCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->epoch_seconds != 0, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void DateTimeCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("DateTimeCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  epoch_seconds: ");
  sprintf(buffer, "%" PRIu32, this->epoch_seconds);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool ListEntitiesUpdateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 6: {
      this->disabled_by_default = value.as_bool();
      return true;
    }
    case 7: {
      this->entity_category = value.as_enum<enums::EntityCategory>();
      return true;
    }
    case 9: {
      this->device_id = value.as_uint32();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesUpdateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 1: {
      this->object_id = value.as_string();
      return true;
    }
    case 3: {
      this->name = value.as_string();
      return true;
    }
    case 4: {
      this->unique_id = value.as_string();
      return true;
    }
    case 5: {
      this->icon = value.as_string();
      return true;
    }
    case 8: {
      this->device_class = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool ListEntitiesUpdateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 2: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void ListEntitiesUpdateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_string(1, this->object_id);
  buffer.encode_fixed32(2, this->key);
  buffer.encode_string(3, this->name);
  buffer.encode_string(4, this->unique_id);
  buffer.encode_string(5, this->icon);
  buffer.encode_bool(6, this->disabled_by_default);
  buffer.encode_enum<enums::EntityCategory>(7, this->entity_category);
  buffer.encode_string(8, this->device_class);
  buffer.encode_uint32(9, this->device_id);
}
void ListEntitiesUpdateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_string_field(total_size, 1, this->object_id, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_string_field(total_size, 1, this->name, false);
  ProtoSize::add_string_field(total_size, 1, this->unique_id, false);
  ProtoSize::add_string_field(total_size, 1, this->icon, false);
  ProtoSize::add_bool_field(total_size, 1, this->disabled_by_default, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->entity_category), false);
  ProtoSize::add_string_field(total_size, 1, this->device_class, false);
  ProtoSize::add_uint32_field(total_size, 1, this->device_id, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void ListEntitiesUpdateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("ListEntitiesUpdateResponse {\n");
  out.append("  object_id: ");
  out.append("'").append(this->object_id).append("'");
  out.append("\n");

  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  name: ");
  out.append("'").append(this->name).append("'");
  out.append("\n");

  out.append("  unique_id: ");
  out.append("'").append(this->unique_id).append("'");
  out.append("\n");

  out.append("  icon: ");
  out.append("'").append(this->icon).append("'");
  out.append("\n");

  out.append("  disabled_by_default: ");
  out.append(YESNO(this->disabled_by_default));
  out.append("\n");

  out.append("  entity_category: ");
  out.append(proto_enum_to_string<enums::EntityCategory>(this->entity_category));
  out.append("\n");

  out.append("  device_class: ");
  out.append("'").append(this->device_class).append("'");
  out.append("\n");

  out.append("  device_id: ");
  sprintf(buffer, "%" PRIu32, this->device_id);
  out.append(buffer);
  out.append("\n");
  out.append("}");
}
#endif
bool UpdateStateResponse::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->missing_state = value.as_bool();
      return true;
    }
    case 3: {
      this->in_progress = value.as_bool();
      return true;
    }
    case 4: {
      this->has_progress = value.as_bool();
      return true;
    }
    default:
      return false;
  }
}
bool UpdateStateResponse::decode_length(uint32_t field_id, ProtoLengthDelimited value) {
  switch (field_id) {
    case 6: {
      this->current_version = value.as_string();
      return true;
    }
    case 7: {
      this->latest_version = value.as_string();
      return true;
    }
    case 8: {
      this->title = value.as_string();
      return true;
    }
    case 9: {
      this->release_summary = value.as_string();
      return true;
    }
    case 10: {
      this->release_url = value.as_string();
      return true;
    }
    default:
      return false;
  }
}
bool UpdateStateResponse::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    case 5: {
      this->progress = value.as_float();
      return true;
    }
    default:
      return false;
  }
}
void UpdateStateResponse::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_bool(2, this->missing_state);
  buffer.encode_bool(3, this->in_progress);
  buffer.encode_bool(4, this->has_progress);
  buffer.encode_float(5, this->progress);
  buffer.encode_string(6, this->current_version);
  buffer.encode_string(7, this->latest_version);
  buffer.encode_string(8, this->title);
  buffer.encode_string(9, this->release_summary);
  buffer.encode_string(10, this->release_url);
}
void UpdateStateResponse::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_bool_field(total_size, 1, this->missing_state, false);
  ProtoSize::add_bool_field(total_size, 1, this->in_progress, false);
  ProtoSize::add_bool_field(total_size, 1, this->has_progress, false);
  ProtoSize::add_fixed_field<4>(total_size, 1, this->progress != 0.0f, false);
  ProtoSize::add_string_field(total_size, 1, this->current_version, false);
  ProtoSize::add_string_field(total_size, 1, this->latest_version, false);
  ProtoSize::add_string_field(total_size, 1, this->title, false);
  ProtoSize::add_string_field(total_size, 1, this->release_summary, false);
  ProtoSize::add_string_field(total_size, 1, this->release_url, false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void UpdateStateResponse::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("UpdateStateResponse {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  missing_state: ");
  out.append(YESNO(this->missing_state));
  out.append("\n");

  out.append("  in_progress: ");
  out.append(YESNO(this->in_progress));
  out.append("\n");

  out.append("  has_progress: ");
  out.append(YESNO(this->has_progress));
  out.append("\n");

  out.append("  progress: ");
  sprintf(buffer, "%g", this->progress);
  out.append(buffer);
  out.append("\n");

  out.append("  current_version: ");
  out.append("'").append(this->current_version).append("'");
  out.append("\n");

  out.append("  latest_version: ");
  out.append("'").append(this->latest_version).append("'");
  out.append("\n");

  out.append("  title: ");
  out.append("'").append(this->title).append("'");
  out.append("\n");

  out.append("  release_summary: ");
  out.append("'").append(this->release_summary).append("'");
  out.append("\n");

  out.append("  release_url: ");
  out.append("'").append(this->release_url).append("'");
  out.append("\n");
  out.append("}");
}
#endif
bool UpdateCommandRequest::decode_varint(uint32_t field_id, ProtoVarInt value) {
  switch (field_id) {
    case 2: {
      this->command = value.as_enum<enums::UpdateCommand>();
      return true;
    }
    default:
      return false;
  }
}
bool UpdateCommandRequest::decode_32bit(uint32_t field_id, Proto32Bit value) {
  switch (field_id) {
    case 1: {
      this->key = value.as_fixed32();
      return true;
    }
    default:
      return false;
  }
}
void UpdateCommandRequest::encode(ProtoWriteBuffer buffer) const {
  buffer.encode_fixed32(1, this->key);
  buffer.encode_enum<enums::UpdateCommand>(2, this->command);
}
void UpdateCommandRequest::calculate_size(uint32_t &total_size) const {
  ProtoSize::add_fixed_field<4>(total_size, 1, this->key != 0, false);
  ProtoSize::add_enum_field(total_size, 1, static_cast<uint32_t>(this->command), false);
}
#ifdef HAS_PROTO_MESSAGE_DUMP
void UpdateCommandRequest::dump_to(std::string &out) const {
  __attribute__((unused)) char buffer[64];
  out.append("UpdateCommandRequest {\n");
  out.append("  key: ");
  sprintf(buffer, "%" PRIu32, this->key);
  out.append(buffer);
  out.append("\n");

  out.append("  command: ");
  out.append(proto_enum_to_string<enums::UpdateCommand>(this->command));
  out.append("\n");
  out.append("}");
}
#endif

}  // namespace api
}  // namespace esphome
