#include "bluetooth_proxy.h"

#include "esphome/core/log.h"
#include "esphome/core/macros.h"
#include "esphome/core/application.h"

#ifdef USE_ESP32

namespace esphome {
namespace bluetooth_proxy {

static const char *const TAG = "bluetooth_proxy";
static const int DONE_SENDING_SERVICES = -2;

std::vector<uint64_t> get_128bit_uuid_vec(esp_bt_uuid_t uuid_source) {
  esp_bt_uuid_t uuid = espbt::ESPBTUUID::from_uuid(uuid_source).as_128bit().get_uuid();
  return std::vector<uint64_t>{((uint64_t) uuid.uuid.uuid128[15] << 56) | ((uint64_t) uuid.uuid.uuid128[14] << 48) |
                                   ((uint64_t) uuid.uuid.uuid128[13] << 40) | ((uint64_t) uuid.uuid.uuid128[12] << 32) |
                                   ((uint64_t) uuid.uuid.uuid128[11] << 24) | ((uint64_t) uuid.uuid.uuid128[10] << 16) |
                                   ((uint64_t) uuid.uuid.uuid128[9] << 8) | ((uint64_t) uuid.uuid.uuid128[8]),
                               ((uint64_t) uuid.uuid.uuid128[7] << 56) | ((uint64_t) uuid.uuid.uuid128[6] << 48) |
                                   ((uint64_t) uuid.uuid.uuid128[5] << 40) | ((uint64_t) uuid.uuid.uuid128[4] << 32) |
                                   ((uint64_t) uuid.uuid.uuid128[3] << 24) | ((uint64_t) uuid.uuid.uuid128[2] << 16) |
                                   ((uint64_t) uuid.uuid.uuid128[1] << 8) | ((uint64_t) uuid.uuid.uuid128[0])};
}

BluetoothProxy::BluetoothProxy() { global_bluetooth_proxy = this; }

void BluetoothProxy::setup() {
  this->parent_->add_scanner_state_callback([this](esp32_ble_tracker::ScannerState state) {
    if (this->api_connection_ != nullptr) {
      this->send_bluetooth_scanner_state_(state);
    }
  });
}

void BluetoothProxy::send_bluetooth_scanner_state_(esp32_ble_tracker::ScannerState state) {
  api::BluetoothScannerStateResponse resp;
  resp.state = static_cast<api::enums::BluetoothScannerState>(state);
  resp.mode = this->parent_->get_scan_active() ? api::enums::BluetoothScannerMode::BLUETOOTH_SCANNER_MODE_ACTIVE
                                               : api::enums::BluetoothScannerMode::BLUETOOTH_SCANNER_MODE_PASSIVE;
  this->api_connection_->send_message(resp);
}

bool BluetoothProxy::parse_device(const esp32_ble_tracker::ESPBTDevice &device) {
  if (!api::global_api_server->is_connected() || this->api_connection_ == nullptr || this->raw_advertisements_)
    return false;

  ESP_LOGV(TAG, "Proxying packet from %s - %s. RSSI: %d dB", device.get_name().c_str(), device.address_str().c_str(),
           device.get_rssi());
  this->send_api_packet_(device);
  return true;
}

static constexpr size_t FLUSH_BATCH_SIZE = 8;
static std::vector<api::BluetoothLERawAdvertisement> &get_batch_buffer() {
  static std::vector<api::BluetoothLERawAdvertisement> batch_buffer;
  return batch_buffer;
}

bool BluetoothProxy::parse_devices(const esp32_ble::BLEScanResult *scan_results, size_t count) {
  if (!api::global_api_server->is_connected() || this->api_connection_ == nullptr || !this->raw_advertisements_)
    return false;

  // Get the batch buffer reference
  auto &batch_buffer = get_batch_buffer();

  // Reserve additional capacity if needed
  size_t new_size = batch_buffer.size() + count;
  if (batch_buffer.capacity() < new_size) {
    batch_buffer.reserve(new_size);
  }

  // Add new advertisements to the batch buffer
  for (size_t i = 0; i < count; i++) {
    auto &result = scan_results[i];
    uint8_t length = result.adv_data_len + result.scan_rsp_len;

    batch_buffer.emplace_back();
    auto &adv = batch_buffer.back();
    adv.address = esp32_ble::ble_addr_to_uint64(result.bda);
    adv.rssi = result.rssi;
    adv.address_type = result.ble_addr_type;
    adv.data.assign(&result.ble_adv[0], &result.ble_adv[length]);

    ESP_LOGV(TAG, "Queuing raw packet from %02X:%02X:%02X:%02X:%02X:%02X, length %d. RSSI: %d dB", result.bda[0],
             result.bda[1], result.bda[2], result.bda[3], result.bda[4], result.bda[5], length, result.rssi);
  }

  // Only send if we've accumulated a good batch size to maximize batching efficiency
  // https://github.com/esphome/backlog/issues/21
  if (batch_buffer.size() >= FLUSH_BATCH_SIZE) {
    this->flush_pending_advertisements();
  }

  return true;
}

void BluetoothProxy::flush_pending_advertisements() {
  auto &batch_buffer = get_batch_buffer();
  if (batch_buffer.empty() || !api::global_api_server->is_connected() || this->api_connection_ == nullptr)
    return;

  api::BluetoothLERawAdvertisementsResponse resp;
  resp.advertisements.swap(batch_buffer);
  this->api_connection_->send_message(resp);
}

void BluetoothProxy::send_api_packet_(const esp32_ble_tracker::ESPBTDevice &device) {
  api::BluetoothLEAdvertisementResponse resp;
  resp.address = device.address_uint64();
  resp.address_type = device.get_address_type();
  if (!device.get_name().empty())
    resp.name = device.get_name();
  resp.rssi = device.get_rssi();

  // Pre-allocate vectors based on known sizes
  auto service_uuids = device.get_service_uuids();
  resp.service_uuids.reserve(service_uuids.size());
  for (auto &uuid : service_uuids) {
    resp.service_uuids.emplace_back(uuid.to_string());
  }

  // Pre-allocate service data vector
  auto service_datas = device.get_service_datas();
  resp.service_data.reserve(service_datas.size());
  for (auto &data : service_datas) {
    resp.service_data.emplace_back();
    auto &service_data = resp.service_data.back();
    service_data.uuid = data.uuid.to_string();
    service_data.data.assign(data.data.begin(), data.data.end());
  }

  // Pre-allocate manufacturer data vector
  auto manufacturer_datas = device.get_manufacturer_datas();
  resp.manufacturer_data.reserve(manufacturer_datas.size());
  for (auto &data : manufacturer_datas) {
    resp.manufacturer_data.emplace_back();
    auto &manufacturer_data = resp.manufacturer_data.back();
    manufacturer_data.uuid = data.uuid.to_string();
    manufacturer_data.data.assign(data.data.begin(), data.data.end());
  }

  this->api_connection_->send_message(resp);
}

void BluetoothProxy::dump_config() {
  ESP_LOGCONFIG(TAG, "Bluetooth Proxy:");
  ESP_LOGCONFIG(TAG,
                "  Active: %s\n"
                "  Connections: %d\n"
                "  Raw advertisements: %s",
                YESNO(this->active_), this->connections_.size(), YESNO(this->raw_advertisements_));
}

int BluetoothProxy::get_bluetooth_connections_free() {
  int free = 0;
  for (auto *connection : this->connections_) {
    if (connection->address_ == 0) {
      free++;
      ESP_LOGV(TAG, "[%d] Free connection", connection->get_connection_index());
    } else {
      ESP_LOGV(TAG, "[%d] Used connection by [%s]", connection->get_connection_index(),
               connection->address_str().c_str());
    }
  }
  return free;
}

void BluetoothProxy::loop() {
  if (!api::global_api_server->is_connected() || this->api_connection_ == nullptr) {
    for (auto *connection : this->connections_) {
      if (connection->get_address() != 0) {
        connection->disconnect();
      }
    }
    return;
  }

  // Flush any pending BLE advertisements that have been accumulated but not yet sent
  if (this->raw_advertisements_) {
    static uint32_t last_flush_time = 0;
    uint32_t now = App.get_loop_component_start_time();

    // Flush accumulated advertisements every 100ms
    if (now - last_flush_time >= 100) {
      this->flush_pending_advertisements();
      last_flush_time = now;
    }
  }
  for (auto *connection : this->connections_) {
    if (connection->send_service_ == connection->service_count_) {
      connection->send_service_ = DONE_SENDING_SERVICES;
      this->send_gatt_services_done(connection->get_address());
      if (connection->connection_type_ == espbt::ConnectionType::V3_WITH_CACHE ||
          connection->connection_type_ == espbt::ConnectionType::V3_WITHOUT_CACHE) {
        connection->release_services();
      }
    } else if (connection->send_service_ >= 0) {
      esp_gattc_service_elem_t service_result;
      uint16_t service_count = 1;
      esp_gatt_status_t service_status =
          esp_ble_gattc_get_service(connection->get_gattc_if(), connection->get_conn_id(), nullptr, &service_result,
                                    &service_count, connection->send_service_);
      connection->send_service_++;
      if (service_status != ESP_GATT_OK) {
        ESP_LOGE(TAG, "[%d] [%s] esp_ble_gattc_get_service error at offset=%d, status=%d",
                 connection->get_connection_index(), connection->address_str().c_str(), connection->send_service_ - 1,
                 service_status);
        continue;
      }
      if (service_count == 0) {
        ESP_LOGE(TAG, "[%d] [%s] esp_ble_gattc_get_service missing, service_count=%d",
                 connection->get_connection_index(), connection->address_str().c_str(), service_count);
        continue;
      }
      api::BluetoothGATTGetServicesResponse resp;
      resp.address = connection->get_address();
      resp.services.reserve(1);  // Always one service per response in this implementation
      api::BluetoothGATTService service_resp;
      service_resp.uuid = get_128bit_uuid_vec(service_result.uuid);
      service_resp.handle = service_result.start_handle;
      uint16_t char_offset = 0;
      esp_gattc_char_elem_t char_result;
      // Get the number of characteristics directly with one call
      uint16_t total_char_count = 0;
      esp_gatt_status_t char_count_status = esp_ble_gattc_get_attr_count(
          connection->get_gattc_if(), connection->get_conn_id(), ESP_GATT_DB_CHARACTERISTIC,
          service_result.start_handle, service_result.end_handle, 0, &total_char_count);

      if (char_count_status == ESP_GATT_OK && total_char_count > 0) {
        // Only reserve if we successfully got a count
        service_resp.characteristics.reserve(total_char_count);
      } else if (char_count_status != ESP_GATT_OK) {
        ESP_LOGW(TAG, "[%d] [%s] Error getting characteristic count, status=%d", connection->get_connection_index(),
                 connection->address_str().c_str(), char_count_status);
      }

      // Now process characteristics
      while (true) {  // characteristics
        uint16_t char_count = 1;
        esp_gatt_status_t char_status = esp_ble_gattc_get_all_char(
            connection->get_gattc_if(), connection->get_conn_id(), service_result.start_handle,
            service_result.end_handle, &char_result, &char_count, char_offset);
        if (char_status == ESP_GATT_INVALID_OFFSET || char_status == ESP_GATT_NOT_FOUND) {
          break;
        }
        if (char_status != ESP_GATT_OK) {
          ESP_LOGE(TAG, "[%d] [%s] esp_ble_gattc_get_all_char error, status=%d", connection->get_connection_index(),
                   connection->address_str().c_str(), char_status);
          break;
        }
        if (char_count == 0) {
          break;
        }
        api::BluetoothGATTCharacteristic characteristic_resp;
        characteristic_resp.uuid = get_128bit_uuid_vec(char_result.uuid);
        characteristic_resp.handle = char_result.char_handle;
        characteristic_resp.properties = char_result.properties;
        char_offset++;

        // Get the number of descriptors directly with one call
        uint16_t total_desc_count = 0;
        esp_gatt_status_t desc_count_status =
            esp_ble_gattc_get_attr_count(connection->get_gattc_if(), connection->get_conn_id(), ESP_GATT_DB_DESCRIPTOR,
                                         char_result.char_handle, service_result.end_handle, 0, &total_desc_count);

        if (desc_count_status == ESP_GATT_OK && total_desc_count > 0) {
          // Only reserve if we successfully got a count
          characteristic_resp.descriptors.reserve(total_desc_count);
        } else if (desc_count_status != ESP_GATT_OK) {
          ESP_LOGW(TAG, "[%d] [%s] Error getting descriptor count for char handle %d, status=%d",
                   connection->get_connection_index(), connection->address_str().c_str(), char_result.char_handle,
                   desc_count_status);
        }

        // Now process descriptors
        uint16_t desc_offset = 0;
        esp_gattc_descr_elem_t desc_result;
        while (true) {  // descriptors
          uint16_t desc_count = 1;
          esp_gatt_status_t desc_status =
              esp_ble_gattc_get_all_descr(connection->get_gattc_if(), connection->get_conn_id(),
                                          char_result.char_handle, &desc_result, &desc_count, desc_offset);
          if (desc_status == ESP_GATT_INVALID_OFFSET || desc_status == ESP_GATT_NOT_FOUND) {
            break;
          }
          if (desc_status != ESP_GATT_OK) {
            ESP_LOGE(TAG, "[%d] [%s] esp_ble_gattc_get_all_descr error, status=%d", connection->get_connection_index(),
                     connection->address_str().c_str(), desc_status);
            break;
          }
          if (desc_count == 0) {
            break;
          }
          api::BluetoothGATTDescriptor descriptor_resp;
          descriptor_resp.uuid = get_128bit_uuid_vec(desc_result.uuid);
          descriptor_resp.handle = desc_result.handle;
          characteristic_resp.descriptors.push_back(std::move(descriptor_resp));
          desc_offset++;
        }
        service_resp.characteristics.push_back(std::move(characteristic_resp));
      }
      resp.services.push_back(std::move(service_resp));
      this->api_connection_->send_message(resp);
    }
  }
}

esp32_ble_tracker::AdvertisementParserType BluetoothProxy::get_advertisement_parser_type() {
  if (this->raw_advertisements_)
    return esp32_ble_tracker::AdvertisementParserType::RAW_ADVERTISEMENTS;
  return esp32_ble_tracker::AdvertisementParserType::PARSED_ADVERTISEMENTS;
}

BluetoothConnection *BluetoothProxy::get_connection_(uint64_t address, bool reserve) {
  for (auto *connection : this->connections_) {
    if (connection->get_address() == address)
      return connection;
  }

  if (!reserve)
    return nullptr;

  for (auto *connection : this->connections_) {
    if (connection->get_address() == 0) {
      connection->send_service_ = DONE_SENDING_SERVICES;
      connection->set_address(address);
      // All connections must start at INIT
      // We only set the state if we allocate the connection
      // to avoid a race where multiple connection attempts
      // are made.
      connection->set_state(espbt::ClientState::INIT);
      return connection;
    }
  }

  return nullptr;
}

void BluetoothProxy::bluetooth_device_request(const api::BluetoothDeviceRequest &msg) {
  switch (msg.request_type) {
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITH_CACHE:
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITHOUT_CACHE:
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT: {
      auto *connection = this->get_connection_(msg.address, true);
      if (connection == nullptr) {
        ESP_LOGW(TAG, "No free connections available");
        this->send_device_connection(msg.address, false);
        return;
      }
      if (connection->state() == espbt::ClientState::CONNECTED ||
          connection->state() == espbt::ClientState::ESTABLISHED) {
        ESP_LOGW(TAG, "[%d] [%s] Connection already established", connection->get_connection_index(),
                 connection->address_str().c_str());
        this->send_device_connection(msg.address, true);
        this->send_connections_free();
        return;
      } else if (connection->state() == espbt::ClientState::SEARCHING) {
        ESP_LOGW(TAG, "[%d] [%s] Connection request ignored, already searching for device",
                 connection->get_connection_index(), connection->address_str().c_str());
        return;
      } else if (connection->state() == espbt::ClientState::DISCOVERED) {
        ESP_LOGW(TAG, "[%d] [%s] Connection request ignored, device already discovered",
                 connection->get_connection_index(), connection->address_str().c_str());
        return;
      } else if (connection->state() == espbt::ClientState::READY_TO_CONNECT) {
        ESP_LOGW(TAG, "[%d] [%s] Connection request ignored, waiting in line to connect",
                 connection->get_connection_index(), connection->address_str().c_str());
        return;
      } else if (connection->state() == espbt::ClientState::CONNECTING) {
        if (connection->disconnect_pending()) {
          ESP_LOGW(TAG, "[%d] [%s] Connection request while pending disconnect, cancelling pending disconnect",
                   connection->get_connection_index(), connection->address_str().c_str());
          connection->cancel_pending_disconnect();
          return;
        }
        ESP_LOGW(TAG, "[%d] [%s] Connection request ignored, already connecting", connection->get_connection_index(),
                 connection->address_str().c_str());
        return;
      } else if (connection->state() == espbt::ClientState::DISCONNECTING) {
        ESP_LOGW(TAG, "[%d] [%s] Connection request ignored, device is disconnecting",
                 connection->get_connection_index(), connection->address_str().c_str());
        return;
      } else if (connection->state() != espbt::ClientState::INIT) {
        ESP_LOGW(TAG, "[%d] [%s] Connection already in progress", connection->get_connection_index(),
                 connection->address_str().c_str());
        return;
      }
      if (msg.request_type == api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITH_CACHE) {
        connection->set_connection_type(espbt::ConnectionType::V3_WITH_CACHE);
        ESP_LOGI(TAG, "[%d] [%s] Connecting v3 with cache", connection->get_connection_index(),
                 connection->address_str().c_str());
      } else if (msg.request_type == api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CONNECT_V3_WITHOUT_CACHE) {
        connection->set_connection_type(espbt::ConnectionType::V3_WITHOUT_CACHE);
        ESP_LOGI(TAG, "[%d] [%s] Connecting v3 without cache", connection->get_connection_index(),
                 connection->address_str().c_str());
      } else {
        connection->set_connection_type(espbt::ConnectionType::V1);
        ESP_LOGI(TAG, "[%d] [%s] Connecting v1", connection->get_connection_index(), connection->address_str().c_str());
      }
      if (msg.has_address_type) {
        uint64_to_bd_addr(msg.address, connection->remote_bda_);
        connection->set_remote_addr_type(static_cast<esp_ble_addr_type_t>(msg.address_type));
        connection->set_state(espbt::ClientState::DISCOVERED);
      } else {
        connection->set_state(espbt::ClientState::SEARCHING);
      }
      this->send_connections_free();
      break;
    }
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_DISCONNECT: {
      auto *connection = this->get_connection_(msg.address, false);
      if (connection == nullptr) {
        this->send_device_connection(msg.address, false);
        this->send_connections_free();
        return;
      }
      if (connection->state() != espbt::ClientState::IDLE) {
        connection->disconnect();
      } else {
        connection->set_address(0);
        this->send_device_connection(msg.address, false);
        this->send_connections_free();
      }
      break;
    }
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_PAIR: {
      auto *connection = this->get_connection_(msg.address, false);
      if (connection != nullptr) {
        if (!connection->is_paired()) {
          auto err = connection->pair();
          if (err != ESP_OK) {
            this->send_device_pairing(msg.address, false, err);
          }
        } else {
          this->send_device_pairing(msg.address, true);
        }
      }
      break;
    }
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_UNPAIR: {
      esp_bd_addr_t address;
      uint64_to_bd_addr(msg.address, address);
      esp_err_t ret = esp_ble_remove_bond_device(address);
      this->send_device_pairing(msg.address, ret == ESP_OK, ret);
      break;
    }
    case api::enums::BLUETOOTH_DEVICE_REQUEST_TYPE_CLEAR_CACHE: {
      esp_bd_addr_t address;
      uint64_to_bd_addr(msg.address, address);
      esp_err_t ret = esp_ble_gattc_cache_clean(address);
      api::BluetoothDeviceClearCacheResponse call;
      call.address = msg.address;
      call.success = ret == ESP_OK;
      call.error = ret;

      this->api_connection_->send_message(call);

      break;
    }
  }
}

void BluetoothProxy::bluetooth_gatt_read(const api::BluetoothGATTReadRequest &msg) {
  auto *connection = this->get_connection_(msg.address, false);
  if (connection == nullptr) {
    ESP_LOGW(TAG, "Cannot read GATT characteristic, not connected");
    this->send_gatt_error(msg.address, msg.handle, ESP_GATT_NOT_CONNECTED);
    return;
  }

  auto err = connection->read_characteristic(msg.handle);
  if (err != ESP_OK) {
    this->send_gatt_error(msg.address, msg.handle, err);
  }
}

void BluetoothProxy::bluetooth_gatt_write(const api::BluetoothGATTWriteRequest &msg) {
  auto *connection = this->get_connection_(msg.address, false);
  if (connection == nullptr) {
    ESP_LOGW(TAG, "Cannot write GATT characteristic, not connected");
    this->send_gatt_error(msg.address, msg.handle, ESP_GATT_NOT_CONNECTED);
    return;
  }

  auto err = connection->write_characteristic(msg.handle, msg.data, msg.response);
  if (err != ESP_OK) {
    this->send_gatt_error(msg.address, msg.handle, err);
  }
}

void BluetoothProxy::bluetooth_gatt_read_descriptor(const api::BluetoothGATTReadDescriptorRequest &msg) {
  auto *connection = this->get_connection_(msg.address, false);
  if (connection == nullptr) {
    ESP_LOGW(TAG, "Cannot read GATT descriptor, not connected");
    this->send_gatt_error(msg.address, msg.handle, ESP_GATT_NOT_CONNECTED);
    return;
  }

  auto err = connection->read_descriptor(msg.handle);
  if (err != ESP_OK) {
    this->send_gatt_error(msg.address, msg.handle, err);
  }
}

void BluetoothProxy::bluetooth_gatt_write_descriptor(const api::BluetoothGATTWriteDescriptorRequest &msg) {
  auto *connection = this->get_connection_(msg.address, false);
  if (connection == nullptr) {
    ESP_LOGW(TAG, "Cannot write GATT descriptor, not connected");
    this->send_gatt_error(msg.address, msg.handle, ESP_GATT_NOT_CONNECTED);
    return;
  }

  auto err = connection->write_descriptor(msg.handle, msg.data, true);
  if (err != ESP_OK) {
    this->send_gatt_error(msg.address, msg.handle, err);
  }
}

void BluetoothProxy::bluetooth_gatt_send_services(const api::BluetoothGATTGetServicesRequest &msg) {
  auto *connection = this->get_connection_(msg.address, false);
  if (connection == nullptr || !connection->connected()) {
    ESP_LOGW(TAG, "Cannot get GATT services, not connected");
    this->send_gatt_error(msg.address, 0, ESP_GATT_NOT_CONNECTED);
    return;
  }
  if (!connection->service_count_) {
    ESP_LOGW(TAG, "[%d] [%s] No GATT services found", connection->connection_index_, connection->address_str().c_str());
    this->send_gatt_services_done(msg.address);
    return;
  }
  if (connection->send_service_ ==
      DONE_SENDING_SERVICES)  // Only start sending services if we're not already sending them
    connection->send_service_ = 0;
}

void BluetoothProxy::bluetooth_gatt_notify(const api::BluetoothGATTNotifyRequest &msg) {
  auto *connection = this->get_connection_(msg.address, false);
  if (connection == nullptr) {
    ESP_LOGW(TAG, "Cannot notify GATT characteristic, not connected");
    this->send_gatt_error(msg.address, msg.handle, ESP_GATT_NOT_CONNECTED);
    return;
  }

  auto err = connection->notify_characteristic(msg.handle, msg.enable);
  if (err != ESP_OK) {
    this->send_gatt_error(msg.address, msg.handle, err);
  }
}

void BluetoothProxy::subscribe_api_connection(api::APIConnection *api_connection, uint32_t flags) {
  if (this->api_connection_ != nullptr) {
    ESP_LOGE(TAG, "Only one API subscription is allowed at a time");
    return;
  }
  this->api_connection_ = api_connection;
  this->raw_advertisements_ = flags & BluetoothProxySubscriptionFlag::SUBSCRIPTION_RAW_ADVERTISEMENTS;
  this->parent_->recalculate_advertisement_parser_types();

  this->send_bluetooth_scanner_state_(this->parent_->get_scanner_state());
}

void BluetoothProxy::unsubscribe_api_connection(api::APIConnection *api_connection) {
  if (this->api_connection_ != api_connection) {
    ESP_LOGV(TAG, "API connection is not subscribed");
    return;
  }
  this->api_connection_ = nullptr;
  this->raw_advertisements_ = false;
  this->parent_->recalculate_advertisement_parser_types();
}

void BluetoothProxy::send_device_connection(uint64_t address, bool connected, uint16_t mtu, esp_err_t error) {
  if (this->api_connection_ == nullptr)
    return;
  api::BluetoothDeviceConnectionResponse call;
  call.address = address;
  call.connected = connected;
  call.mtu = mtu;
  call.error = error;
  this->api_connection_->send_message(call);
}
void BluetoothProxy::send_connections_free() {
  if (this->api_connection_ == nullptr)
    return;
  api::BluetoothConnectionsFreeResponse call;
  call.free = this->get_bluetooth_connections_free();
  call.limit = this->get_bluetooth_connections_limit();
  for (auto *connection : this->connections_) {
    if (connection->address_ != 0) {
      call.allocated.push_back(connection->address_);
    }
  }
  this->api_connection_->send_message(call);
}

void BluetoothProxy::send_gatt_services_done(uint64_t address) {
  if (this->api_connection_ == nullptr)
    return;
  api::BluetoothGATTGetServicesDoneResponse call;
  call.address = address;
  this->api_connection_->send_message(call);
}

void BluetoothProxy::send_gatt_error(uint64_t address, uint16_t handle, esp_err_t error) {
  if (this->api_connection_ == nullptr)
    return;
  api::BluetoothGATTErrorResponse call;
  call.address = address;
  call.handle = handle;
  call.error = error;
  this->api_connection_->send_message(call);
}

void BluetoothProxy::send_device_pairing(uint64_t address, bool paired, esp_err_t error) {
  api::BluetoothDevicePairingResponse call;
  call.address = address;
  call.paired = paired;
  call.error = error;

  this->api_connection_->send_message(call);
}

void BluetoothProxy::send_device_unpairing(uint64_t address, bool success, esp_err_t error) {
  api::BluetoothDeviceUnpairingResponse call;
  call.address = address;
  call.success = success;
  call.error = error;

  this->api_connection_->send_message(call);
}

void BluetoothProxy::bluetooth_scanner_set_mode(bool active) {
  if (this->parent_->get_scan_active() == active) {
    return;
  }
  ESP_LOGD(TAG, "Setting scanner mode to %s", active ? "active" : "passive");
  this->parent_->set_scan_active(active);
  this->parent_->stop_scan();
  this->parent_->set_scan_continuous(
      true);  // Set this to true to automatically start scanning again when it has cleaned up.
}

BluetoothProxy *global_bluetooth_proxy = nullptr;  // NOLINT(cppcoreguidelines-avoid-non-const-global-variables)

}  // namespace bluetooth_proxy
}  // namespace esphome

#endif  // USE_ESP32
