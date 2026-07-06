#pragma once

#include <stdint.h>


class LedDriver {
private:
    uint8_t gpio_pin;

public:
    explicit LedDriver(uint8_t gpio_num);
    void led_init();
    void led_on();
    void led_off();
    void led_toggle();
};