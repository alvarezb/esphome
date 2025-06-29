#include "tlc59116_output.h"

namespace esphome {
namespace tlc59116 {

void TLC59116Channel::write_state(float state) {
  auto amount = static_cast<uint16_t>(state * 0xffff);
  this->parent_->set_channel_value(this->channel_, amount);
}

}  // namespace tlc59116
}  // namespace esphome
