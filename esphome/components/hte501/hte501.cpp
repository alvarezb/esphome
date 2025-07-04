#include "hte501.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

namespace esphome {
namespace hte501 {

static const char *const TAG = "hte501";

void HTE501Component::setup() {
  ESP_LOGCONFIG(TAG, "Running setup");
  uint8_t address[] = {0x70, 0x29};
  this->write(address, 2, false);
  uint8_t identification[9];
  this->read(identification, 9);
  if (identification[8] != calc_crc8_(identification, 0, 7)) {
    this->error_code_ = CRC_CHECK_FAILED;
    this->mark_failed();
    return;
  }
  ESP_LOGV(TAG, "    Serial Number: 0x%s", format_hex(identification + 0, 7).c_str());
}

void HTE501Component::dump_config() {
  ESP_LOGCONFIG(TAG, "HTE501:");
  LOG_I2C_DEVICE(this);
  switch (this->error_code_) {
    case COMMUNICATION_FAILED:
      ESP_LOGE(TAG, ESP_LOG_MSG_COMM_FAIL);
      break;
    case CRC_CHECK_FAILED:
      ESP_LOGE(TAG, "The crc check failed");
      break;
    case NONE:
    default:
      break;
  }
  LOG_UPDATE_INTERVAL(this);
  LOG_SENSOR("  ", "Temperature", this->temperature_sensor_);
  LOG_SENSOR("  ", "Humidity", this->humidity_sensor_);
}

float HTE501Component::get_setup_priority() const { return setup_priority::DATA; }
void HTE501Component::update() {
  uint8_t address_1[] = {0x2C, 0x1B};
  this->write(address_1, 2, true);
  this->set_timeout(50, [this]() {
    uint8_t i2c_response[6];
    this->read(i2c_response, 6);
    if (i2c_response[2] != calc_crc8_(i2c_response, 0, 1) && i2c_response[5] != calc_crc8_(i2c_response, 3, 4)) {
      this->error_code_ = CRC_CHECK_FAILED;
      this->status_set_warning();
      return;
    }
    float temperature = (float) encode_uint16(i2c_response[0], i2c_response[1]);
    if (temperature > 55536) {
      temperature = (temperature - 65536) / 100;
    } else {
      temperature = temperature / 100;
    }
    float humidity = ((float) encode_uint16(i2c_response[3], i2c_response[4])) / 100.0f;

    ESP_LOGD(TAG, "Got temperature=%.2f°C humidity=%.2f%%", temperature, humidity);
    if (this->temperature_sensor_ != nullptr)
      this->temperature_sensor_->publish_state(temperature);
    if (this->humidity_sensor_ != nullptr)
      this->humidity_sensor_->publish_state(humidity);
    this->status_clear_warning();
  });
}

unsigned char HTE501Component::calc_crc8_(const unsigned char buf[], unsigned char from, unsigned char to) {
  unsigned char crc_val = 0xFF;
  unsigned char i = 0;
  unsigned char j = 0;
  for (i = from; i <= to; i++) {
    int cur_val = buf[i];
    for (j = 0; j < 8; j++) {
      if (((crc_val ^ cur_val) & 0x80) != 0)  // If MSBs are not equal
      {
        crc_val = ((crc_val << 1) ^ 0x31);
      } else {
        crc_val = (crc_val << 1);
      }
      cur_val = cur_val << 1;
    }
  }
  return crc_val;
}
}  // namespace hte501
}  // namespace esphome
