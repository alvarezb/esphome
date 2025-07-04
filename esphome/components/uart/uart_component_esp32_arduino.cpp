#ifdef USE_ESP32_FRAMEWORK_ARDUINO
#include "uart_component_esp32_arduino.h"
#include "esphome/core/application.h"
#include "esphome/core/defines.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"

#ifdef USE_LOGGER
#include "esphome/components/logger/logger.h"
#endif

namespace esphome {
namespace uart {
static const char *const TAG = "uart.arduino_esp32";

static const uint32_t UART_PARITY_EVEN = 0 << 0;
static const uint32_t UART_PARITY_ODD = 1 << 0;
static const uint32_t UART_PARITY_ENABLE = 1 << 1;
static const uint32_t UART_NB_BIT_5 = 0 << 2;
static const uint32_t UART_NB_BIT_6 = 1 << 2;
static const uint32_t UART_NB_BIT_7 = 2 << 2;
static const uint32_t UART_NB_BIT_8 = 3 << 2;
static const uint32_t UART_NB_STOP_BIT_1 = 1 << 4;
static const uint32_t UART_NB_STOP_BIT_2 = 3 << 4;
static const uint32_t UART_TICK_APB_CLOCK = 1 << 27;

uint32_t ESP32ArduinoUARTComponent::get_config() {
  uint32_t config = 0;

  /*
   * All bits numbers below come from
   * framework-arduinoespressif32/cores/esp32/esp32-hal-uart.h
   * And more specifically conf0 union in uart_dev_t.
   *
   * Below is bit used from conf0 union.
   * <name>:<bits position>  <values>
   * parity:0                0:even 1:odd
   * parity_en:1             Set this bit to enable uart parity check.
   * bit_num:2-4             0:5bits 1:6bits 2:7bits 3:8bits
   * stop_bit_num:4-6        stop bit. 1:1bit  2:1.5bits  3:2bits
   * tick_ref_always_on:27   select the clock.1：apb clock：ref_tick
   */

  if (this->parity_ == UART_CONFIG_PARITY_EVEN) {
    config |= UART_PARITY_EVEN | UART_PARITY_ENABLE;
  } else if (this->parity_ == UART_CONFIG_PARITY_ODD) {
    config |= UART_PARITY_ODD | UART_PARITY_ENABLE;
  }

  switch (this->data_bits_) {
    case 5:
      config |= UART_NB_BIT_5;
      break;
    case 6:
      config |= UART_NB_BIT_6;
      break;
    case 7:
      config |= UART_NB_BIT_7;
      break;
    case 8:
      config |= UART_NB_BIT_8;
      break;
  }

  if (this->stop_bits_ == 1) {
    config |= UART_NB_STOP_BIT_1;
  } else {
    config |= UART_NB_STOP_BIT_2;
  }

  config |= UART_TICK_APB_CLOCK;

  return config;
}

void ESP32ArduinoUARTComponent::setup() {
  ESP_LOGCONFIG(TAG, "Running setup");
  // Use Arduino HardwareSerial UARTs if all used pins match the ones
  // preconfigured by the platform. For example if RX disabled but TX pin
  // is 1 we still want to use Serial.
  bool is_default_tx, is_default_rx;
#ifdef CONFIG_IDF_TARGET_ESP32C3
  is_default_tx = tx_pin_ == nullptr || tx_pin_->get_pin() == 21;
  is_default_rx = rx_pin_ == nullptr || rx_pin_->get_pin() == 20;
#else
  is_default_tx = tx_pin_ == nullptr || tx_pin_->get_pin() == 1;
  is_default_rx = rx_pin_ == nullptr || rx_pin_->get_pin() == 3;
#endif
  static uint8_t next_uart_num = 0;
  if (is_default_tx && is_default_rx && next_uart_num == 0) {
#if ARDUINO_USB_CDC_ON_BOOT
    this->hw_serial_ = &Serial0;
#else
    this->hw_serial_ = &Serial;
#endif
    next_uart_num++;
  } else {
#ifdef USE_LOGGER
    bool logger_uses_hardware_uart = true;

#ifdef USE_LOGGER_USB_CDC
    if (logger::global_logger->get_uart() == logger::UART_SELECTION_USB_CDC) {
      // this is not a hardware UART, ignore it
      logger_uses_hardware_uart = false;
    }
#endif  // USE_LOGGER_USB_CDC

#ifdef USE_LOGGER_USB_SERIAL_JTAG
    if (logger::global_logger->get_uart() == logger::UART_SELECTION_USB_SERIAL_JTAG) {
      // this is not a hardware UART, ignore it
      logger_uses_hardware_uart = false;
    }
#endif  // USE_LOGGER_USB_SERIAL_JTAG

    if (logger_uses_hardware_uart && logger::global_logger->get_baud_rate() > 0 &&
        logger::global_logger->get_uart() == next_uart_num) {
      next_uart_num++;
    }
#endif  // USE_LOGGER

    if (next_uart_num >= SOC_UART_NUM) {
      ESP_LOGW(TAG, "Maximum number of UART components created already.");
      this->mark_failed();
      return;
    }

    this->number_ = next_uart_num;
    this->hw_serial_ = new HardwareSerial(next_uart_num++);  // NOLINT(cppcoreguidelines-owning-memory)
  }

  this->load_settings(false);
}

void ESP32ArduinoUARTComponent::load_settings(bool dump_config) {
  int8_t tx = this->tx_pin_ != nullptr ? this->tx_pin_->get_pin() : -1;
  int8_t rx = this->rx_pin_ != nullptr ? this->rx_pin_->get_pin() : -1;
  bool invert = false;
  if (tx_pin_ != nullptr && tx_pin_->is_inverted())
    invert = true;
  if (rx_pin_ != nullptr && rx_pin_->is_inverted())
    invert = true;
  this->hw_serial_->setRxBufferSize(this->rx_buffer_size_);
  this->hw_serial_->begin(this->baud_rate_, get_config(), rx, tx, invert);
  if (dump_config) {
    ESP_LOGCONFIG(TAG, "UART %u was reloaded.", this->number_);
    this->dump_config();
  }
}

void ESP32ArduinoUARTComponent::dump_config() {
  ESP_LOGCONFIG(TAG, "UART Bus %d:", this->number_);
  LOG_PIN("  TX Pin: ", tx_pin_);
  LOG_PIN("  RX Pin: ", rx_pin_);
  if (this->rx_pin_ != nullptr) {
    ESP_LOGCONFIG(TAG, "  RX Buffer Size: %u", this->rx_buffer_size_);
  }
  ESP_LOGCONFIG(TAG,
                "  Baud Rate: %u baud\n"
                "  Data Bits: %u\n"
                "  Parity: %s\n"
                "  Stop bits: %u",
                this->baud_rate_, this->data_bits_, LOG_STR_ARG(parity_to_str(this->parity_)), this->stop_bits_);
  this->check_logger_conflict();
}

void ESP32ArduinoUARTComponent::write_array(const uint8_t *data, size_t len) {
  this->hw_serial_->write(data, len);
#ifdef USE_UART_DEBUGGER
  for (size_t i = 0; i < len; i++) {
    this->debug_callback_.call(UART_DIRECTION_TX, data[i]);
  }
#endif
}

bool ESP32ArduinoUARTComponent::peek_byte(uint8_t *data) {
  if (!this->check_read_timeout_())
    return false;
  *data = this->hw_serial_->peek();
  return true;
}

bool ESP32ArduinoUARTComponent::read_array(uint8_t *data, size_t len) {
  if (!this->check_read_timeout_(len))
    return false;
  this->hw_serial_->readBytes(data, len);
#ifdef USE_UART_DEBUGGER
  for (size_t i = 0; i < len; i++) {
    this->debug_callback_.call(UART_DIRECTION_RX, data[i]);
  }
#endif
  return true;
}

int ESP32ArduinoUARTComponent::available() { return this->hw_serial_->available(); }
void ESP32ArduinoUARTComponent::flush() {
  ESP_LOGVV(TAG, "    Flushing");
  this->hw_serial_->flush();
}

void ESP32ArduinoUARTComponent::check_logger_conflict() {
#ifdef USE_LOGGER
  if (this->hw_serial_ == nullptr || logger::global_logger->get_baud_rate() == 0) {
    return;
  }

  if (this->hw_serial_ == logger::global_logger->get_hw_serial()) {
    ESP_LOGW(TAG, "  You're using the same serial port for logging and the UART component. Please "
                  "disable logging over the serial port by setting logger->baud_rate to 0.");
  }
#endif
}

}  // namespace uart
}  // namespace esphome
#endif  // USE_ESP32_FRAMEWORK_ARDUINO
