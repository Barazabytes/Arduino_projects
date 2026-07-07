#pragma once

#include <stdint.h>

class PotentiometerDriver {
private:
    uint8_t gpio_pin;

public:
    explicit PotentiometerDriver(uint8_t gpio_num);
    void potentiometer_init();
    int read_value();
};