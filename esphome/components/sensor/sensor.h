#pragma once

#include "esphome/core/component.h"
#include "esphome/core/entity_base.h"
#include "esphome/core/helpers.h"
#include "esphome/core/log.h"
#include "esphome/components/sensor/filter.h"

#include <vector>
#include <memory>

namespace esphome {
namespace sensor {

#define LOG_SENSOR(prefix, type, obj) \
  if ((obj) != nullptr) { \
    ESP_LOGCONFIG(TAG, \
                  "%s%s '%s'\n" \
                  "%s  State Class: '%s'\n" \
                  "%s  Unit of Measurement: '%s'\n" \
                  "%s  Accuracy Decimals: %d", \
                  prefix, LOG_STR_LITERAL(type), (obj)->get_name().c_str(), prefix, \
                  state_class_to_string((obj)->get_state_class()).c_str(), prefix, \
                  (obj)->get_unit_of_measurement().c_str(), prefix, (obj)->get_accuracy_decimals()); \
    if (!(obj)->get_device_class().empty()) { \
      ESP_LOGCONFIG(TAG, "%s  Device Class: '%s'", prefix, (obj)->get_device_class().c_str()); \
    } \
    if (!(obj)->get_icon().empty()) { \
      ESP_LOGCONFIG(TAG, "%s  Icon: '%s'", prefix, (obj)->get_icon().c_str()); \
    } \
    if (!(obj)->unique_id().empty()) { \
      ESP_LOGV(TAG, "%s  Unique ID: '%s'", prefix, (obj)->unique_id().c_str()); \
    } \
    if ((obj)->get_force_update()) { \
      ESP_LOGV(TAG, "%s  Force Update: YES", prefix); \
    } \
  }

#define SUB_SENSOR(name) \
 protected: \
  sensor::Sensor *name##_sensor_{nullptr}; \
\
 public: \
  void set_##name##_sensor(sensor::Sensor *sensor) { this->name##_sensor_ = sensor; }

/**
 * Sensor state classes
 */
enum StateClass : uint8_t {
  STATE_CLASS_NONE = 0,
  STATE_CLASS_MEASUREMENT = 1,
  STATE_CLASS_TOTAL_INCREASING = 2,
  STATE_CLASS_TOTAL = 3,
};

std::string state_class_to_string(StateClass state_class);

/** Base-class for all sensors.
 *
 * A sensor has unit of measurement and can use publish_state to send out a new value with the specified accuracy.
 */
class Sensor : public EntityBase, public EntityBase_DeviceClass, public EntityBase_UnitOfMeasurement {
 public:
  explicit Sensor();

  /// Get the accuracy in decimals, using the manual override if set.
  int8_t get_accuracy_decimals();
  /// Manually set the accuracy in decimals.
  void set_accuracy_decimals(int8_t accuracy_decimals);

  /// Get the state class, using the manual override if set.
  StateClass get_state_class();
  /// Manually set the state class.
  void set_state_class(StateClass state_class);

  /**
   * Get whether force update mode is enabled.
   *
   * If the sensor is in force_update mode, the frontend is required to save all
   * state changes to the database when they are published, even if the state is the
   * same as before.
   */
  bool get_force_update() const { return sensor_flags_.force_update; }
  /// Set force update mode.
  void set_force_update(bool force_update) { sensor_flags_.force_update = force_update; }

  /// Add a filter to the filter chain. Will be appended to the back.
  void add_filter(Filter *filter);

  /** Add a list of vectors to the back of the filter chain.
   *
   * This may look like:
   *
   * sensor->add_filters({
   *   LambdaFilter([&](float value) -> optional<float> { return 42/value; }),
   *   OffsetFilter(1),
   *   SlidingWindowMovingAverageFilter(15, 15), // average over last 15 values
   * });
   */
  void add_filters(const std::vector<Filter *> &filters);

  /// Clear the filters and replace them by filters.
  void set_filters(const std::vector<Filter *> &filters);

  /// Clear the entire filter chain.
  void clear_filters();

  /// Getter-syntax for .state.
  float get_state() const;
  /// Getter-syntax for .raw_state
  float get_raw_state() const;

  /** Publish a new state to the front-end.
   *
   * First, the new state will be assigned to the raw_value. Then it's passed through all filters
   * until it finally lands in the .value member variable and a callback is issued.
   *
   * @param state The state as a floating point number.
   */
  void publish_state(float state);

  // ========== INTERNAL METHODS ==========
  // (In most use cases you won't need these)
  /// Add a callback that will be called every time a filtered value arrives.
  void add_on_state_callback(std::function<void(float)> &&callback);
  /// Add a callback that will be called every time the sensor sends a raw value.
  void add_on_raw_state_callback(std::function<void(float)> &&callback);

  /** This member variable stores the last state that has passed through all filters.
   *
   * On startup, when no state is available yet, this is NAN (not-a-number) and the validity
   * can be checked using has_state().
   *
   * This is exposed through a member variable for ease of use in esphome lambdas.
   */
  float state;

  /** This member variable stores the current raw state of the sensor, without any filters applied.
   *
   * Unlike .state,this will be updated immediately when publish_state is called.
   */
  float raw_state;

  /** Override this method to set the unique ID of this sensor.
   *
   * @deprecated Do not use for new sensors, a suitable unique ID is automatically generated (2023.4).
   */
  virtual std::string unique_id();

  void internal_send_state_to_frontend(float state);

 protected:
  std::unique_ptr<CallbackManager<void(float)>> raw_callback_;  ///< Storage for raw state callbacks (lazy allocated).
  CallbackManager<void(float)> callback_;                       ///< Storage for filtered state callbacks.

  Filter *filter_list_{nullptr};  ///< Store all active filters.

  // Group small members together to avoid padding
  int8_t accuracy_decimals_{-1};              ///< Accuracy in decimals (-1 = not set)
  StateClass state_class_{STATE_CLASS_NONE};  ///< State class (STATE_CLASS_NONE = not set)

  // Bit-packed flags for sensor-specific settings
  struct SensorFlags {
    uint8_t has_accuracy_override : 1;
    uint8_t has_state_class_override : 1;
    uint8_t force_update : 1;
    uint8_t reserved : 5;  // Reserved for future use
  } sensor_flags_{};
};

}  // namespace sensor
}  // namespace esphome
