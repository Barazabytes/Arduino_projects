#include <Arduino.h>
#include "led_config.h"
#include "led_driver.h"

LedDriver::LedDriver() {
    gpio_pin = LED_PIN;
    led_init(gpio_pin);
}

void LedDriver::led_init(uint8_t pin) {
    pinMode(pin, OUTPUT);
}

void LedDriver::led_on() {
    digitalWrite(gpio_pin, HIGH);
}

void LedDriver::led_off() {
    digitalWrite(gpio_pin, LOW);
}