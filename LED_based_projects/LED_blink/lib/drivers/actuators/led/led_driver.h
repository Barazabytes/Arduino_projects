#pragma once

#include <stdint.h>


class LedDriver {
private:
    uint8_t gpio_pin;

public:
    explicit LedDriver();
    void led_init(uint8_t gpio_pin);
    void led_on();
    void led_off();
};