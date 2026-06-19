#pragma once

#include <stdint.h>

class BuzzerDriver {
    private:
        uint8_t gpio_pin;

    public:
        explicit BuzzerDriver(uint8_t gpio_pin);
        void BuzzerInit();
        void BuzzerOn  ();
        void BuzzerOff ();
    
};