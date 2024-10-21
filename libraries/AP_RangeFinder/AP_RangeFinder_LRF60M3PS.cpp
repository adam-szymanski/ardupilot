/*
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "AP_RangeFinder_LRF60M3PS.h"

#if AP_RANGEFINDER_LRF60M3PS_ENABLED

// distance returned in reading_m, signal_ok is set to true if sensor reports a strong signal
bool AP_RangeFinder_LRF60M3PS::get_reading(float &reading_m)
{
    if (uart == nullptr) {
        return false;
    }
    constexpr uint8_t STOP_MEASUREMENT = 0x58;
    uart->write(STOP_MEASUREMENT);
    constexpr const uint8_t* const READ_SINGLE = "\xAA\x00\x00\x20\x00\x01\x00\x00\x21";
    uart->write(READ_SINGLE, 9);

    // no readings so return false
    return false;
}

#endif  // AP_RANGEFINDER_LRF60M3PS_ENABLED
