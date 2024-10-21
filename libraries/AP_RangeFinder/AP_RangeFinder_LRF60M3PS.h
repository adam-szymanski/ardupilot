#pragma once

#include "AP_RangeFinder_config.h"

#if AP_RANGEFINDER_LRF60M3PS_ENABLED

#include "AP_RangeFinder.h"
#include "AP_RangeFinder_Backend_Serial.h"

class AP_RangeFinder_LRF60M3PS : public AP_RangeFinder_Backend_Serial
{

public:

    static AP_RangeFinder_Backend_Serial *create(
        RangeFinder::RangeFinder_State &_state,
        AP_RangeFinder_Params &_params) {
        return NEW_NOTHROW AP_RangeFinder_LRF60M3PS(_state, _params);
    }

protected:

    MAV_DISTANCE_SENSOR _get_mav_distance_sensor_type() const override {
        return MAV_DISTANCE_SENSOR_LASER;
    }

    uint32_t initial_baudrate(uint8_t serial_instance) const override {
        return 19200;
    }

private:
};

#endif  // AP_RANGEFINDER_LRF60M3PS_ENABLED
