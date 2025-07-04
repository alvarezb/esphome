#pragma once

#include "esphome/core/defines.h"
#ifdef USE_BINARY_SENSOR
#include "esphome/components/binary_sensor/binary_sensor.h"
#endif
#ifdef USE_FAN
#include "esphome/components/fan/fan_state.h"
#endif
#ifdef USE_LIGHT
#include "esphome/components/light/light_state.h"
#endif
#ifdef USE_COVER
#include "esphome/components/cover/cover.h"
#endif
#ifdef USE_SENSOR
#include "esphome/components/sensor/sensor.h"
#endif
#ifdef USE_TEXT_SENSOR
#include "esphome/components/text_sensor/text_sensor.h"
#endif
#ifdef USE_SWITCH
#include "esphome/components/switch/switch.h"
#endif
#ifdef USE_BUTTON
#include "esphome/components/button/button.h"
#endif
#ifdef USE_CLIMATE
#include "esphome/components/climate/climate.h"
#endif
#ifdef USE_NUMBER
#include "esphome/components/number/number.h"
#endif
#ifdef USE_DATETIME_DATE
#include "esphome/components/datetime/date_entity.h"
#endif
#ifdef USE_DATETIME_TIME
#include "esphome/components/datetime/time_entity.h"
#endif
#ifdef USE_DATETIME_DATETIME
#include "esphome/components/datetime/datetime_entity.h"
#endif
#ifdef USE_TEXT
#include "esphome/components/text/text.h"
#endif
#ifdef USE_SELECT
#include "esphome/components/select/select.h"
#endif
#ifdef USE_LOCK
#include "esphome/components/lock/lock.h"
#endif
#ifdef USE_VALVE
#include "esphome/components/valve/valve.h"
#endif
#ifdef USE_MEDIA_PLAYER
#include "esphome/components/media_player/media_player.h"
#endif
#ifdef USE_ALARM_CONTROL_PANEL
#include "esphome/components/alarm_control_panel/alarm_control_panel.h"
#endif
#ifdef USE_EVENT
#include "esphome/components/event/event.h"
#endif
#ifdef USE_UPDATE
#include "esphome/components/update/update_entity.h"
#endif

namespace esphome {

class Controller {
 public:
  void setup_controller(bool include_internal = false);
#ifdef USE_BINARY_SENSOR
  virtual void on_binary_sensor_update(binary_sensor::BinarySensor *obj){};
#endif
#ifdef USE_FAN
  virtual void on_fan_update(fan::Fan *obj){};
#endif
#ifdef USE_LIGHT
  virtual void on_light_update(light::LightState *obj){};
#endif
#ifdef USE_SENSOR
  virtual void on_sensor_update(sensor::Sensor *obj, float state){};
#endif
#ifdef USE_SWITCH
  virtual void on_switch_update(switch_::Switch *obj, bool state){};
#endif
#ifdef USE_COVER
  virtual void on_cover_update(cover::Cover *obj){};
#endif
#ifdef USE_TEXT_SENSOR
  virtual void on_text_sensor_update(text_sensor::TextSensor *obj, const std::string &state){};
#endif
#ifdef USE_CLIMATE
  virtual void on_climate_update(climate::Climate *obj){};
#endif
#ifdef USE_NUMBER
  virtual void on_number_update(number::Number *obj, float state){};
#endif
#ifdef USE_DATETIME_DATE
  virtual void on_date_update(datetime::DateEntity *obj){};
#endif
#ifdef USE_DATETIME_TIME
  virtual void on_time_update(datetime::TimeEntity *obj){};
#endif
#ifdef USE_DATETIME_DATETIME
  virtual void on_datetime_update(datetime::DateTimeEntity *obj){};
#endif
#ifdef USE_TEXT
  virtual void on_text_update(text::Text *obj, const std::string &state){};
#endif
#ifdef USE_SELECT
  virtual void on_select_update(select::Select *obj, const std::string &state, size_t index){};
#endif
#ifdef USE_LOCK
  virtual void on_lock_update(lock::Lock *obj){};
#endif
#ifdef USE_VALVE
  virtual void on_valve_update(valve::Valve *obj){};
#endif
#ifdef USE_MEDIA_PLAYER
  virtual void on_media_player_update(media_player::MediaPlayer *obj){};
#endif
#ifdef USE_ALARM_CONTROL_PANEL
  virtual void on_alarm_control_panel_update(alarm_control_panel::AlarmControlPanel *obj){};
#endif
#ifdef USE_EVENT
  virtual void on_event(event::Event *obj, const std::string &event_type){};
#endif
#ifdef USE_UPDATE
  virtual void on_update(update::UpdateEntity *obj){};
#endif
};

}  // namespace esphome
