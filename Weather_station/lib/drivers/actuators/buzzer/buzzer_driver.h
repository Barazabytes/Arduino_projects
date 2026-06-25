#pragma once

#include <stdint.h>

class BuzzerDriver {
    private:
        uint8_t gpio_pin;

    public:
        explicit BuzzerDriver();
        void BuzzerInit();
        void BuzzerOn  ();
        void BuzzerOff ();
    
};