#pragma once

#include <cmath>
#include <cstdint>
#include <functional>
#include <string>

#include "esphome/core/optional.h"

namespace esphome {

/** Default setup priorities for components of different types.
 *
 * Components should return one of these setup priorities in get_setup_priority.
 */
namespace setup_priority {

/// For communication buses like i2c/spi
extern const float BUS;
/// For components that represent GPIO pins like PCF8573
extern const float IO;
/// For components that deal with hardware and are very important like GPIO switch
extern const float HARDWARE;
/// For components that import data from directly connected sensors like DHT.
extern const float DATA;
/// Alias for DATA (here for compatibility reasons)
extern const float HARDWARE_LATE;
/// For components that use data from sensors like displays
extern const float PROCESSOR;
extern const float BLUETOOTH;
extern const float AFTER_BLUETOOTH;
extern const float WIFI;
extern const float ETHERNET;
/// For components that should be initialized after WiFi and before API is connected.
extern const float BEFORE_CONNECTION;
/// For components that should be initialized after WiFi is connected.
extern const float AFTER_WIFI;
/// For components that should be initialized after a data connection (API/MQTT) is connected.
extern const float AFTER_CONNECTION;
/// For components that should be initialized at the very end of the setup process.
extern const float LATE;

}  // namespace setup_priority

static const uint32_t SCHEDULER_DONT_RUN = 4294967295UL;

#define LOG_UPDATE_INTERVAL(this) \
  if (this->get_update_interval() == SCHEDULER_DONT_RUN) { \
    ESP_LOGCONFIG(TAG, "  Update Interval: never"); \
  } else if (this->get_update_interval() < 100) { \
    ESP_LOGCONFIG(TAG, "  Update Interval: %.3fs", this->get_update_interval() / 1000.0f); \
  } else { \
    ESP_LOGCONFIG(TAG, "  Update Interval: %.1fs", this->get_update_interval() / 1000.0f); \
  }

extern const uint8_t COMPONENT_STATE_MASK;
extern const uint8_t COMPONENT_STATE_CONSTRUCTION;
extern const uint8_t COMPONENT_STATE_SETUP;
extern const uint8_t COMPONENT_STATE_LOOP;
extern const uint8_t COMPONENT_STATE_FAILED;
extern const uint8_t COMPONENT_STATE_LOOP_DONE;
extern const uint8_t STATUS_LED_MASK;
extern const uint8_t STATUS_LED_OK;
extern const uint8_t STATUS_LED_WARNING;
extern const uint8_t STATUS_LED_ERROR;

enum class RetryResult { DONE, RETRY };

extern const uint16_t WARN_IF_BLOCKING_OVER_MS;

class Component {
 public:
  /** Where the component's initialization should happen.
   *
   * Analogous to Arduino's setup(). This method is guaranteed to only be called once.
   * Defaults to doing nothing.
   */
  virtual void setup();

  /** This method will be called repeatedly.
   *
   * Analogous to Arduino's loop(). setup() is guaranteed to be called before this.
   * Defaults to doing nothing.
   */
  virtual void loop();

  virtual void dump_config();

  /** priority of setup(). higher -> executed earlier
   *
   * Defaults to setup_priority::DATA, i.e. 600.
   *
   * @return The setup priority of this component
   */
  virtual float get_setup_priority() const;

  float get_actual_setup_priority() const;

  void set_setup_priority(float priority);

  /** priority of loop(). higher -> executed earlier
   *
   * Defaults to 0.
   *
   * @return The loop priority of this component
   */
  virtual float get_loop_priority() const;

  void call();

  virtual void on_shutdown() {}
  virtual void on_safe_shutdown() {}

  /** Called during teardown to allow component to gracefully finish operations.
   *
   * @return true if teardown is complete, false if more time is needed
   */
  virtual bool teardown() { return true; }

  /** Called after teardown is complete to power down hardware.
   *
   * This is called after all components have finished their teardown process,
   * making it safe to power down hardware like ethernet PHY.
   */
  virtual void on_powerdown() {}

  uint8_t get_component_state() const;

  /** Reset this component back to the construction state to allow setup to run again.
   *
   * This can be used by components that have recoverable failures to attempt setup again.
   */
  void reset_to_construction_state();

  /** Check if this component has completed setup and is in the loop state.
   *
   * @return True if in loop state, false otherwise.
   */
  bool is_in_loop_state() const;

  /** Mark this component as failed. Any future timeouts/intervals/setup/loop will no longer be called.
   *
   * This might be useful if a component wants to indicate that a connection to its peripheral failed.
   * For example, i2c based components can check if the remote device is responding and otherwise
   * mark the component as failed. Eventually this will also enable smart status LEDs.
   */
  virtual void mark_failed();

  void mark_failed(const char *message) {
    this->status_set_error(message);
    this->mark_failed();
  }

  /** Disable this component's loop. The loop() method will no longer be called.
   *
   * This is useful for components that only need to run for a certain period of time
   * or when inactive, saving CPU cycles.
   *
   * @note Components should call this->disable_loop() on themselves, not on other components.
   *       This ensures the component's state is properly updated along with the loop partition.
   */
  void disable_loop();

  /** Enable this component's loop. The loop() method will be called normally.
   *
   * This is useful for components that transition between active and inactive states
   * and need to re-enable their loop() method when becoming active again.
   *
   * @note Components should call this->enable_loop() on themselves, not on other components.
   *       This ensures the component's state is properly updated along with the loop partition.
   */
  void enable_loop();

  /** Thread and ISR-safe version of enable_loop() that can be called from any context.
   *
   * This method defers the actual enable via enable_pending_loops_ to the main loop,
   * making it safe to call from ISR handlers, timer callbacks, other threads,
   * or any interrupt context.
   *
   * @note The actual loop enabling will happen on the next main loop iteration.
   * @note Only one pending enable request is tracked per component.
   * @note There is no disable_loop_soon_any_context() on purpose - it would race
   *       against enable calls and synchronization would get too complex
   *       to provide a safe version that would work for each component.
   *
   *       Use disable_loop() from the main thread only.
   *
   *       If you need to disable the loop from ISR, carefully implement
   *       it in the component itself, with an ISR safe approach, and call
   *       disable_loop() in its next ::loop() iteration. Implementations
   *       will need to carefully consider all possible race conditions.
   */
  void enable_loop_soon_any_context();

  bool is_failed() const;

  bool is_ready() const;

  virtual bool can_proceed();

  bool status_has_warning() const;

  bool status_has_error() const;

  void status_set_warning(const char *message = "unspecified");

  void status_set_error(const char *message = "unspecified");

  void status_clear_warning();

  void status_clear_error();

  void status_momentary_warning(const std::string &name, uint32_t length = 5000);

  void status_momentary_error(const std::string &name, uint32_t length = 5000);

  bool has_overridden_loop() const;

  /** Set where this component was loaded from for some debug messages.
   *
   * This is set by the ESPHome core, and should not be called manually.
   */
  void set_component_source(const char *source) { component_source_ = source; }
  /** Get the integration where this component was declared as a string.
   *
   * Returns "<unknown>" if source not set
   */
  const char *get_component_source() const;

  bool should_warn_of_blocking(uint32_t blocking_time);

 protected:
  friend class Application;

  virtual void call_loop();
  virtual void call_setup();
  virtual void call_dump_config();

  /** Set an interval function with a unique name. Empty name means no cancelling possible.
   *
   * This will call f every interval ms. Can be cancelled via CancelInterval().
   * Similar to javascript's setInterval().
   *
   * IMPORTANT NOTE:
   * The only guarantee offered by this call is that the callback will be called no *earlier* than
   * the specified interval after the previous call. Any given interval may be longer due to
   * other components blocking the loop() call.
   *
   * So do not rely on this having correct timing. If you need exact timing please
   * use hardware timers.
   *
   * Note also that the first call to f will not happen immediately, but after a random delay. This is
   * intended to prevent many interval functions from being called at the same time.
   *
   * @param name The identifier for this interval function.
   * @param interval The interval in ms.
   * @param f The function (or lambda) that should be called
   *
   * @see cancel_interval()
   */
  void set_interval(const std::string &name, uint32_t interval, std::function<void()> &&f);  // NOLINT

  void set_interval(uint32_t interval, std::function<void()> &&f);  // NOLINT

  /** Cancel an interval function.
   *
   * @param name The identifier for this interval function.
   * @return Whether an interval functions was deleted.
   */
  bool cancel_interval(const std::string &name);  // NOLINT

  /** Set an retry function with a unique name. Empty name means no cancelling possible.
   *
   * This will call the retry function f on the next scheduler loop. f should return RetryResult::DONE if
   * it is successful and no repeat is required. Otherwise, returning RetryResult::RETRY will call f
   * again in the future.
   *
   * The first retry of f happens after `initial_wait_time` milliseconds. The delay between retries is
   * increased by multiplying by `backoff_increase_factor` each time. If no backoff_increase_factor is
   * supplied (default = 1.0), the wait time will stay constant.
   *
   * The retry function f needs to accept a single argument: the number of attempts remaining. On the
   * final retry of f, this value will be 0.
   *
   * This retry function can also be cancelled by name via cancel_retry().
   *
   * IMPORTANT: Do not rely on this having correct timing. This is only called from
   * loop() and therefore can be significantly delayed.
   *
   * REMARK: It is an error to supply a negative or zero `backoff_increase_factor`, and 1.0 will be used instead.
   *
   * REMARK: The interval between retries is stored into a `uint32_t`, so this doesn't behave correctly
   * if `initial_wait_time * (backoff_increase_factor ** (max_attempts - 2))` overflows.
   *
   * @param name The identifier for this retry function.
   * @param initial_wait_time The time in ms before f is called again
   * @param max_attempts The maximum number of executions
   * @param f The function (or lambda) that should be called
   * @param backoff_increase_factor time between retries is multiplied by this factor on every retry after the first
   * @see cancel_retry()
   */
  void set_retry(const std::string &name, uint32_t initial_wait_time, uint8_t max_attempts,       // NOLINT
                 std::function<RetryResult(uint8_t)> &&f, float backoff_increase_factor = 1.0f);  // NOLINT

  void set_retry(uint32_t initial_wait_time, uint8_t max_attempts, std::function<RetryResult(uint8_t)> &&f,  // NOLINT
                 float backoff_increase_factor = 1.0f);                                                      // NOLINT

  /** Cancel a retry function.
   *
   * @param name The identifier for this retry function.
   * @return Whether a retry function was deleted.
   */
  bool cancel_retry(const std::string &name);  // NOLINT

  /** Set a timeout function with a unique name.
   *
   * Similar to javascript's setTimeout(). Empty name means no cancelling possible.
   *
   * IMPORTANT: Do not rely on this having correct timing. This is only called from
   * loop() and therefore can be significantly delay. If you need exact timing please
   * use hardware timers.
   *
   * @param name The identifier for this timeout function.
   * @param timeout The timeout in ms.
   * @param f The function (or lambda) that should be called
   *
   * @see cancel_timeout()
   */
  void set_timeout(const std::string &name, uint32_t timeout, std::function<void()> &&f);  // NOLINT

  void set_timeout(uint32_t timeout, std::function<void()> &&f);  // NOLINT

  /** Cancel a timeout function.
   *
   * @param name The identifier for this timeout function.
   * @return Whether a timeout functions was deleted.
   */
  bool cancel_timeout(const std::string &name);  // NOLINT

  /** Defer a callback to the next loop() call.
   *
   * If name is specified and a defer() object with the same name exists, the old one is first removed.
   *
   * @param name The name of the defer function.
   * @param f The callback.
   */
  void defer(const std::string &name, std::function<void()> &&f);  // NOLINT

  /// Defer a callback to the next loop() call.
  void defer(std::function<void()> &&f);  // NOLINT

  /// Cancel a defer callback using the specified name, name must not be empty.
  bool cancel_defer(const std::string &name);  // NOLINT

  // Ordered for optimal packing on 32-bit systems
  float setup_priority_override_{NAN};
  const char *component_source_{nullptr};
  const char *error_message_{nullptr};
  uint16_t warn_if_blocking_over_{WARN_IF_BLOCKING_OVER_MS};  ///< Warn if blocked for this many ms (max 65.5s)
  /// State of this component - each bit has a purpose:
  /// Bits 0-1: Component state (0x00=CONSTRUCTION, 0x01=SETUP, 0x02=LOOP, 0x03=FAILED)
  /// Bit 2: STATUS_LED_WARNING
  /// Bit 3: STATUS_LED_ERROR
  /// Bits 4-7: Unused - reserved for future expansion (50% of the bits are free)
  uint8_t component_state_{0x00};
  volatile bool pending_enable_loop_{false};  ///< ISR-safe flag for enable_loop_soon_any_context
};

/** This class simplifies creating components that periodically check a state.
 *
 * You basically just need to implement the update() function, it will be called every update_interval ms
 * after startup. Note that this class cannot guarantee a correct timing, as it's not using timers, just
 * a software polling feature with set_interval() from Component.
 */
class PollingComponent : public Component {
 public:
  PollingComponent() : PollingComponent(0) {}

  /** Initialize this polling component with the given update interval in ms.
   *
   * @param update_interval The update interval in ms.
   */
  explicit PollingComponent(uint32_t update_interval);

  /** Manually set the update interval in ms for this polling object.
   *
   * Override this if you want to do some validation for the update interval.
   *
   * @param update_interval The update interval in ms.
   */
  virtual void set_update_interval(uint32_t update_interval);

  // ========== OVERRIDE METHODS ==========
  // (You'll only need this when creating your own custom sensor)
  virtual void update() = 0;

  // ========== INTERNAL METHODS ==========
  // (In most use cases you won't need these)
  void call_setup() override;

  /// Get the update interval in ms of this sensor
  virtual uint32_t get_update_interval() const;

  // Start the poller, used for component.suspend
  void start_poller();

  // Stop the poller, used for component.suspend
  void stop_poller();

 protected:
  uint32_t update_interval_;
};

class WarnIfComponentBlockingGuard {
 public:
  WarnIfComponentBlockingGuard(Component *component, uint32_t start_time);

  // Finish the timing operation and return the current time
  uint32_t finish();

  ~WarnIfComponentBlockingGuard();

 protected:
  uint32_t started_;
  Component *component_;
};

}  // namespace esphome
