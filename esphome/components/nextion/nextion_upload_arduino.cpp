#include "nextion.h"

#ifdef USE_NEXTION_TFT_UPLOAD
#ifdef USE_ARDUINO

#include <cinttypes>
#include "esphome/components/network/util.h"
#include "esphome/core/application.h"
#include "esphome/core/defines.h"
#include "esphome/core/log.h"
#include "esphome/core/util.h"

#ifdef USE_ESP32
#include <esp_heap_caps.h>
#endif

namespace esphome {
namespace nextion {
static const char *const TAG = "nextion.upload.arduino";

// Followed guide
// https://unofficialnextion.com/t/nextion-upload-protocol-v1-2-the-fast-one/1044/2

inline uint32_t Nextion::get_free_heap_() {
#if defined(USE_ESP32)
  return heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
#elif defined(USE_ESP8266)
  return EspClass::getFreeHeap();
#endif  // USE_ESP32 vs USE_ESP8266
}

int Nextion::upload_by_chunks_(HTTPClient &http_client, uint32_t &range_start) {
  uint32_t range_size = this->tft_size_ - range_start;
  ESP_LOGV(TAG, "Heap: %" PRIu32, this->get_free_heap_());
  uint32_t range_end = ((upload_first_chunk_sent_ or this->tft_size_ < 4096) ? this->tft_size_ : 4096) - 1;
  ESP_LOGD(TAG, "Range start: %" PRIu32, range_start);
  if (range_size <= 0 or range_end <= range_start) {
    ESP_LOGD(TAG, "Range end: %" PRIu32, range_end);
    ESP_LOGD(TAG, "Range size: %" PRIu32, range_size);
    ESP_LOGE(TAG, "Invalid range");
    return -1;
  }

  char range_header[32];
  sprintf(range_header, "bytes=%" PRIu32 "-%" PRIu32, range_start, range_end);
  ESP_LOGV(TAG, "Range: %s", range_header);
  http_client.addHeader("Range", range_header);
  int code = http_client.GET();
  if (code != HTTP_CODE_OK and code != HTTP_CODE_PARTIAL_CONTENT) {
    ESP_LOGW(TAG, "HTTP failed: %s", HTTPClient::errorToString(code).c_str());
    return -1;
  }

  // Allocate the buffer dynamically
  RAMAllocator<uint8_t> allocator;
  uint8_t *buffer = allocator.allocate(4096);
  if (!buffer) {
    ESP_LOGE(TAG, "Buffer alloc failed");
    return -1;
  }

  std::string recv_string;
  while (true) {
    App.feed_wdt();
    const uint16_t buffer_size =
        this->content_length_ < 4096 ? this->content_length_ : 4096;  // Limits buffer to the remaining data
    ESP_LOGV(TAG, "Fetch %" PRIu16 " bytes", buffer_size);
    uint16_t read_len = 0;
    int partial_read_len = 0;
    const uint32_t start_time = App.get_loop_component_start_time();
    while (read_len < buffer_size && App.get_loop_component_start_time() - start_time < 5000) {
      if (http_client.getStreamPtr()->available() > 0) {
        partial_read_len =
            http_client.getStreamPtr()->readBytes(reinterpret_cast<char *>(buffer) + read_len, buffer_size - read_len);
        read_len += partial_read_len;
        if (partial_read_len > 0) {
          App.feed_wdt();
          delay(2);
        }
      }
    }
    if (read_len != buffer_size) {
      // Did not receive the full package within the timeout period
      ESP_LOGE(TAG, "Read failed: %" PRIu16 "/%" PRIu16 " bytes", read_len, buffer_size);
      // Deallocate buffer
      allocator.deallocate(buffer, 4096);
      buffer = nullptr;
      return -1;
    }
    ESP_LOGV(TAG, "Fetched %d bytes", read_len);
    if (read_len > 0) {
      recv_string.clear();
      this->write_array(buffer, buffer_size);
      App.feed_wdt();
      this->recv_ret_string_(recv_string, upload_first_chunk_sent_ ? 500 : 5000, true);
      this->content_length_ -= read_len;
      const float upload_percentage = 100.0f * (this->tft_size_ - this->content_length_) / this->tft_size_;
#if defined(USE_ESP32) && defined(USE_PSRAM)
      ESP_LOGD(TAG, "Upload: %0.2f%% (%" PRIu32 " left, heap: %" PRIu32 "+%" PRIu32 ")", upload_percentage,
               this->content_length_, static_cast<uint32_t>(heap_caps_get_free_size(MALLOC_CAP_INTERNAL)),
               static_cast<uint32_t>(heap_caps_get_free_size(MALLOC_CAP_SPIRAM)));
#else
      ESP_LOGD(TAG, "Upload: %0.2f%% (%" PRIu32 " left, heap: %" PRIu32 ")", upload_percentage, this->content_length_,
               this->get_free_heap_());
#endif
      upload_first_chunk_sent_ = true;
      if (recv_string[0] == 0x08 && recv_string.size() == 5) {  // handle partial upload request
        ESP_LOGD(TAG, "Recv: [%s]",
                 format_hex_pretty(reinterpret_cast<const uint8_t *>(recv_string.data()), recv_string.size()).c_str());
        uint32_t result = 0;
        for (int j = 0; j < 4; ++j) {
          result += static_cast<uint8_t>(recv_string[j + 1]) << (8 * j);
        }
        if (result > 0) {
          ESP_LOGI(TAG, "New range: %" PRIu32, result);
          this->content_length_ = this->tft_size_ - result;
          range_start = result;
        } else {
          range_start = range_end + 1;
        }
        // Deallocate buffer
        allocator.deallocate(buffer, 4096);
        buffer = nullptr;
        return range_end + 1;
      } else if (recv_string[0] != 0x05 and recv_string[0] != 0x08) {  // 0x05 == "ok"
        ESP_LOGE(TAG, "Invalid response: [%s]",
                 format_hex_pretty(reinterpret_cast<const uint8_t *>(recv_string.data()), recv_string.size()).c_str());
        // Deallocate buffer
        allocator.deallocate(buffer, 4096);
        buffer = nullptr;
        return -1;
      }

      recv_string.clear();
    } else if (read_len == 0) {
      ESP_LOGV(TAG, "HTTP end");
      break;  // Exit the loop if there is no more data to read
    } else {
      ESP_LOGE(TAG, "HTTP read failed: %d", read_len);
      break;  // Exit the loop on error
    }
  }
  range_start = range_end + 1;
  // Deallocate buffer
  allocator.deallocate(buffer, 4096);
  buffer = nullptr;
  return range_end + 1;
}

bool Nextion::upload_tft(uint32_t baud_rate, bool exit_reparse) {
  ESP_LOGD(TAG, "TFT upload requested");
  ESP_LOGD(TAG, "Exit reparse: %s", YESNO(exit_reparse));
  ESP_LOGD(TAG, "URL: %s", this->tft_url_.c_str());

  if (this->is_updating_) {
    ESP_LOGW(TAG, "Upload in progress");
    return false;
  }

  if (!network::is_connected()) {
    ESP_LOGE(TAG, "No network");
    return false;
  }

  this->is_updating_ = true;

  if (exit_reparse) {
    ESP_LOGD(TAG, "Exit reparse mode");
    if (!this->set_protocol_reparse_mode(false)) {
      ESP_LOGW(TAG, "Exit reparse failed");
      return false;
    }
  }

  // Check if baud rate is supported
  this->original_baud_rate_ = this->parent_->get_baud_rate();
  static const std::vector<uint32_t> SUPPORTED_BAUD_RATES = {2400,   4800,   9600,   19200,  31250,  38400, 57600,
                                                             115200, 230400, 250000, 256000, 512000, 921600};
  if (std::find(SUPPORTED_BAUD_RATES.begin(), SUPPORTED_BAUD_RATES.end(), baud_rate) == SUPPORTED_BAUD_RATES.end()) {
    baud_rate = this->original_baud_rate_;
  }
  ESP_LOGD(TAG, "Baud rate: %" PRIu32, baud_rate);

  // Define the configuration for the HTTP client
  ESP_LOGV(TAG, "Init HTTP client");
  ESP_LOGV(TAG, "Heap: %" PRIu32, this->get_free_heap_());
  HTTPClient http_client;
  http_client.setTimeout(15000);  // Yes 15 seconds.... Helps 8266s along

  bool begin_status = false;
#ifdef USE_ESP32
  begin_status = http_client.begin(this->tft_url_.c_str());
#endif
#ifdef USE_ESP8266
#if USE_ARDUINO_VERSION_CODE >= VERSION_CODE(2, 7, 0)
  http_client.setFollowRedirects(HTTPC_STRICT_FOLLOW_REDIRECTS);
#elif USE_ARDUINO_VERSION_CODE >= VERSION_CODE(2, 6, 0)
  http_client.setFollowRedirects(true);
#endif
#if USE_ARDUINO_VERSION_CODE >= VERSION_CODE(2, 6, 0)
  http_client.setRedirectLimit(3);
#endif
  begin_status = http_client.begin(*this->get_wifi_client_(), this->tft_url_.c_str());
#endif  // USE_ESP8266
  if (!begin_status) {
    this->is_updating_ = false;
    ESP_LOGD(TAG, "Connection failed");
    return false;
  } else {
    ESP_LOGD(TAG, "Connected");
  }
  http_client.addHeader("Range", "bytes=0-255");
  const char *header_names[] = {"Content-Range"};
  http_client.collectHeaders(header_names, 1);
  ESP_LOGD(TAG, "URL: %s", this->tft_url_.c_str());
  http_client.setReuse(true);
  // try up to 5 times. DNS sometimes needs a second try or so
  int tries = 1;
  int code = http_client.GET();
  delay(100);  // NOLINT

  App.feed_wdt();
  while (code != 200 && code != 206 && tries <= 5) {
    ESP_LOGW(TAG, "HTTP fail: URL: %s; Error: %s, retry %d/5", this->tft_url_.c_str(),
             HTTPClient::errorToString(code).c_str(), tries);

    delay(250);  // NOLINT
    App.feed_wdt();
    code = http_client.GET();
    ++tries;
  }

  if (code != 200 and code != 206) {
    return this->upload_end_(false);
  }

  String content_range_string = http_client.header("Content-Range");
  content_range_string.remove(0, 12);
  this->tft_size_ = content_range_string.toInt();

  ESP_LOGD(TAG, "TFT size: %zu bytes", this->tft_size_);
  if (this->tft_size_ < 4096) {
    ESP_LOGE(TAG, "Size check failed");
    ESP_LOGD(TAG, "Close HTTP");
    http_client.end();
    ESP_LOGV(TAG, "Connection closed");
    return this->upload_end_(false);
  } else {
    ESP_LOGV(TAG, "Size check OK");
  }
  this->content_length_ = this->tft_size_;

  ESP_LOGD(TAG, "Uploading");

  // The Nextion will ignore the upload command if it is sleeping
  ESP_LOGV(TAG, "Wake-up");
  this->ignore_is_setup_ = true;
  this->send_command_("sleep=0");
  this->send_command_("dim=100");
  delay(250);  // NOLINT
  ESP_LOGV(TAG, "Heap: %" PRIu32, this->get_free_heap_());

  App.feed_wdt();
  char command[128];
  // Tells the Nextion the content length of the tft file and baud rate it will be sent at
  // Once the Nextion accepts the command it will wait until the file is successfully uploaded
  // If it fails for any reason a power cycle of the display will be needed
  sprintf(command, "whmi-wris %d,%d,1", this->content_length_, baud_rate);

  // Clear serial receive buffer
  ESP_LOGV(TAG, "Clear RX buffer");
  this->reset_(false);
  delay(250);  // NOLINT
  ESP_LOGV(TAG, "Heap: %" PRIu32, this->get_free_heap_());

  ESP_LOGV(TAG, "Upload cmd: %s", command);
  this->send_command_(command);

  if (baud_rate != this->original_baud_rate_) {
    ESP_LOGD(TAG, "Baud: %" PRIu32 "->%" PRIu32, this->original_baud_rate_, baud_rate);
    this->parent_->set_baud_rate(baud_rate);
    this->parent_->load_settings();
  }

  App.feed_wdt();

  std::string response;
  ESP_LOGV(TAG, "Wait upload resp");
  this->recv_ret_string_(response, 5000, true);  // This can take some time to return

  // The Nextion display will, if it's ready to accept data, send a 0x05 byte.
  ESP_LOGD(TAG, "Upload resp: [%s] %zu B",
           format_hex_pretty(reinterpret_cast<const uint8_t *>(response.data()), response.size()).c_str(),
           response.length());
  ESP_LOGV(TAG, "Heap: %" PRIu32, this->get_free_heap_());

  if (response.find(0x05) != std::string::npos) {
    ESP_LOGV(TAG, "Upload prep done");
  } else {
    ESP_LOGE(TAG, "Prep failed %d '%s'", response[0], response.c_str());
    ESP_LOGD(TAG, "Close HTTP");
    http_client.end();
    ESP_LOGV(TAG, "Connection closed");
    return this->upload_end_(false);
  }

  ESP_LOGD(TAG, "Upload TFT:");
  ESP_LOGD(TAG, "  URL:  %s", this->tft_url_.c_str());
  ESP_LOGD(TAG, "  Size: %d bytes", this->content_length_);
  ESP_LOGD(TAG, "  Heap: %" PRIu32, this->get_free_heap_());

  // Proceed with the content download as before

  ESP_LOGV(TAG, "Start chunk transfer");

  uint32_t position = 0;
  while (this->content_length_ > 0) {
    int upload_result = upload_by_chunks_(http_client, position);
    if (upload_result < 0) {
      ESP_LOGE(TAG, "Upload error");
      ESP_LOGD(TAG, "Close HTTP");
      http_client.end();
      ESP_LOGV(TAG, "Connection closed");
      return this->upload_end_(false);
    }
    App.feed_wdt();
    ESP_LOGV(TAG, "Heap: %" PRIu32 " left: %" PRIu32, this->get_free_heap_(), this->content_length_);
  }

  ESP_LOGD(TAG, "Upload complete");

  ESP_LOGV(TAG, "Close HTTP");
  http_client.end();
  ESP_LOGV(TAG, "Connection closed");
  return upload_end_(true);
}

#ifdef USE_ESP8266
WiFiClient *Nextion::get_wifi_client_() {
  if (this->tft_url_.compare(0, 6, "https:") == 0) {
    if (this->wifi_client_secure_ == nullptr) {
      // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
      this->wifi_client_secure_ = new BearSSL::WiFiClientSecure();
      this->wifi_client_secure_->setInsecure();
      this->wifi_client_secure_->setBufferSizes(512, 512);
    }
    return this->wifi_client_secure_;
  }

  if (this->wifi_client_ == nullptr) {
    // NOLINTNEXTLINE(cppcoreguidelines-owning-memory)
    this->wifi_client_ = new WiFiClient();
  }
  return this->wifi_client_;
}
#endif  // USE_ESP8266

}  // namespace nextion
}  // namespace esphome

#endif  // USE_ARDUINO
#endif  // USE_NEXTION_TFT_UPLOAD
