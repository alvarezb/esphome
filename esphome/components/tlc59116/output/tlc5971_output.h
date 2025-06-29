#pragma once

#include "esphome/core/helpers.h"

#include "esphome/components/output/float_output.h"

#include "../tlc59116.h"

namespace esphome {
namespace tlc59116 {

class TLC59116Channel : public output::FloatOutput, public Parented<TLC59116> {
 public:
  void set_channel(uint8_t channel) { this->channel_ = channel; }

 protected:
  void write_state(float state) override;
  uint8_t channel_;
};

}  // namespace tlc59116
}  // namespace esphome
