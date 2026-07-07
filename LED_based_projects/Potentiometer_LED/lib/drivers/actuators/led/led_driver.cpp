#include <Arduino.h>
#include "led_driver.h"

LedDriver::LedDriver(uint8_t gpio_num) {
    gpio_pin = gpio_num;
    led_init();
}

void LedDriver::led_init() {
    pinMode(gpio_pin, OUTPUT);
    digitalWrite(gpio_pin, LOW);
    Serial.println("LED pin configuration done");
}

void LedDriver::led_on() {
    digitalWrite(gpio_pin, HIGH);
}

void LedDriver::led_off() {
    digitalWrite(gpio_pin, LOW);
}

void LedDriver::led_toggle() {
    Serial.println("LED state toggled");
    digitalWrite(gpio_pin, !digitalRead(gpio_pin));
}

void LedDriver::led_set_brightness(uint8_t brightness) {
    Serial.println("LED brightness set to: " + String(brightness));
    analogWrite(gpio_pin, brightness);
}