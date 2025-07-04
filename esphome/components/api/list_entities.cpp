#include "list_entities.h"
#ifdef USE_API
#include "api_connection.h"
#include "esphome/core/application.h"
#include "esphome/core/log.h"
#include "esphome/core/util.h"

namespace esphome {
namespace api {

#ifdef USE_BINARY_SENSOR
bool ListEntitiesIterator::on_binary_sensor(binary_sensor::BinarySensor *binary_sensor) {
  this->client_->send_binary_sensor_info(binary_sensor);
  return true;
}
#endif
#ifdef USE_COVER
bool ListEntitiesIterator::on_cover(cover::Cover *cover) {
  this->client_->send_cover_info(cover);
  return true;
}
#endif
#ifdef USE_FAN
bool ListEntitiesIterator::on_fan(fan::Fan *fan) {
  this->client_->send_fan_info(fan);
  return true;
}
#endif
#ifdef USE_LIGHT
bool ListEntitiesIterator::on_light(light::LightState *light) {
  this->client_->send_light_info(light);
  return true;
}
#endif
#ifdef USE_SENSOR
bool ListEntitiesIterator::on_sensor(sensor::Sensor *sensor) {
  this->client_->send_sensor_info(sensor);
  return true;
}
#endif
#ifdef USE_SWITCH
bool ListEntitiesIterator::on_switch(switch_::Switch *a_switch) {
  this->client_->send_switch_info(a_switch);
  return true;
}
#endif
#ifdef USE_BUTTON
bool ListEntitiesIterator::on_button(button::Button *button) {
  this->client_->send_button_info(button);
  return true;
}
#endif
#ifdef USE_TEXT_SENSOR
bool ListEntitiesIterator::on_text_sensor(text_sensor::TextSensor *text_sensor) {
  this->client_->send_text_sensor_info(text_sensor);
  return true;
}
#endif
#ifdef USE_LOCK
bool ListEntitiesIterator::on_lock(lock::Lock *a_lock) {
  this->client_->send_lock_info(a_lock);
  return true;
}
#endif
#ifdef USE_VALVE
bool ListEntitiesIterator::on_valve(valve::Valve *valve) {
  this->client_->send_valve_info(valve);
  return true;
}
#endif

bool ListEntitiesIterator::on_end() { return this->client_->send_list_info_done(); }
ListEntitiesIterator::ListEntitiesIterator(APIConnection *client) : client_(client) {}
bool ListEntitiesIterator::on_service(UserServiceDescriptor *service) {
  auto resp = service->encode_list_service_response();
  return this->client_->send_message(resp);
}

#ifdef USE_ESP32_CAMERA
bool ListEntitiesIterator::on_camera(esp32_camera::ESP32Camera *camera) {
  this->client_->send_camera_info(camera);
  return true;
}
#endif

#ifdef USE_CLIMATE
bool ListEntitiesIterator::on_climate(climate::Climate *climate) {
  this->client_->send_climate_info(climate);
  return true;
}
#endif

#ifdef USE_NUMBER
bool ListEntitiesIterator::on_number(number::Number *number) {
  this->client_->send_number_info(number);
  return true;
}
#endif

#ifdef USE_DATETIME_DATE
bool ListEntitiesIterator::on_date(datetime::DateEntity *date) {
  this->client_->send_date_info(date);
  return true;
}
#endif

#ifdef USE_DATETIME_TIME
bool ListEntitiesIterator::on_time(datetime::TimeEntity *time) {
  this->client_->send_time_info(time);
  return true;
}
#endif

#ifdef USE_DATETIME_DATETIME
bool ListEntitiesIterator::on_datetime(datetime::DateTimeEntity *datetime) {
  this->client_->send_datetime_info(datetime);
  return true;
}
#endif

#ifdef USE_TEXT
bool ListEntitiesIterator::on_text(text::Text *text) {
  this->client_->send_text_info(text);
  return true;
}
#endif

#ifdef USE_SELECT
bool ListEntitiesIterator::on_select(select::Select *select) {
  this->client_->send_select_info(select);
  return true;
}
#endif

#ifdef USE_MEDIA_PLAYER
bool ListEntitiesIterator::on_media_player(media_player::MediaPlayer *media_player) {
  this->client_->send_media_player_info(media_player);
  return true;
}
#endif
#ifdef USE_ALARM_CONTROL_PANEL
bool ListEntitiesIterator::on_alarm_control_panel(alarm_control_panel::AlarmControlPanel *a_alarm_control_panel) {
  this->client_->send_alarm_control_panel_info(a_alarm_control_panel);
  return true;
}
#endif
#ifdef USE_EVENT
bool ListEntitiesIterator::on_event(event::Event *event) {
  this->client_->send_event_info(event);
  return true;
}
#endif
#ifdef USE_UPDATE
bool ListEntitiesIterator::on_update(update::UpdateEntity *update) {
  this->client_->send_update_info(update);
  return true;
}
#endif

}  // namespace api
}  // namespace esphome
#endif
