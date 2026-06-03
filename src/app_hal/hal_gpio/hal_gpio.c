#include "hal_gpio.h"
#include <Arduino.h>

static pin_mode_t convert_mode(pin_mode_t mode) {
    if(mode == PIN_MODE_INPUT)
        return INPUT;
    else if(mode == PIN_MODE_OUTPUT)
        return OUTPUT;
    else
        return INPUT;
}

void hal_gpio_init(uint8_t pin, pin_mode_t mode) {
    pinMode(pin, convert_mode(mode));
}

void hal_gpio_write(uint8_t pin, bool value) {
    digitalWrite(pin, value ? HIGH : LOW);
}