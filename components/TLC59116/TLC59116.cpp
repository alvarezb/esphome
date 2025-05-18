/*
 * Copyright (c) 2014, Majenko Technologies
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 * 
 *  1. Redistributions of source code must retain the above copyright notice, 
 *     this list of conditions and the following disclaimer.
 * 
 *  2. Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 * 
 *  3. Neither the name of Majenko Technologies nor the names of its contributors may be used
 *     to endorse or promote products derived from this software without 
 *     specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE 
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, 
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include "TLC59116.h"
#include "esphome/core/log.h"

namespace esphome {
namespace TLC59116 {

static const char *TAG = "alvarezb.TLC59116";


static inline void wiresend(unsigned char x) {
#if ARDUINO >= 100
    Wire.write((unsigned char)x);
#else
    Wire.send(x);
#endif
}

static inline unsigned char wirerecv(void) {
#if ARDUINO >= 100
    return Wire.read();
#else
    return Wire.receive();
#endif
}

void TLC59116Output::begin() {
    if (begun_ == false) {
        Wire.begin();
        writeRegister(TLC59116_MODE1, 0x01);
        delay(1);
        writeRegister(TLC59116_MODE2, 0x00);
        writeRegister(TLC59116_LEDOUT0, 0b10101010);
        writeRegister(TLC59116_LEDOUT1, 0b10101010);
        writeRegister(TLC59116_LEDOUT2, 0b10101010);
        writeRegister(TLC59116_LEDOUT3, 0b10101010);
        analogWrite(0, 0);
        analogWrite(1, 0);
        analogWrite(2, 0);
        analogWrite(3, 0);
        analogWrite(4, 0);
        analogWrite(5, 0);
        analogWrite(6, 0);
        analogWrite(7, 0);
        analogWrite(8, 0);
        analogWrite(9, 0);
        analogWrite(10, 0);
        analogWrite(11, 0);
        analogWrite(12, 0);
        analogWrite(13, 0);
        analogWrite(14, 0);
        analogWrite(15, 0);
    }
    begun_ = 1;
}


void TLC59116Output::writeRegister(uint8_t reg, uint8_t val) {
    Wire.beginTransmission(TLC59116_BASEADDR | (addr_ & 0x0F));
    wiresend(reg);
    wiresend(val);
    Wire.endTransmission();
}

void TLC59116Output::analogWrite(uint8_t chan, uint8_t b) {
    writeRegister(TLC59116_PWM0 + (chan & 0x0F), b);
}

/* ESP home methods */

void TLC59116Output::setup() {
    this->begin();
}
void TLC59116Output::write_state(light::LightState *state) {
    ESP_LOGCONFIG(TAG, state);
}
void TLC59116Output::dump_config() {
    ESP_LOGCONFIG(TAG, "TLC59116");
    ESP_LOGCONFIG(TAG, " addr = %i", addr_);
}
light::LightTraits TLC59116Output::get_traits() {
  auto traits = light::LightTraits();
  traits.set_supported_color_modes({light::ColorMode::BRIGHTNESS});
  return traits;
}




} // namespace TLC59116
} // namespace esphome