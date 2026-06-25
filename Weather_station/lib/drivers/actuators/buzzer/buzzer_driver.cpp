#include "buzzer_driver.h"
#include "buzzer_config.h"
#include <Arduino.h>


BuzzerDriver::BuzzerDriver() {
    gpio_pin = BUZZER_PIN;
}

void BuzzerDriver::BuzzerInit() {
    Serial.println(gpio_pin);
    pinMode(gpio_pin, OUTPUT);
}

void BuzzerDriver::BuzzerOn() {
    Serial.println(gpio_pin);
    digitalWrite(gpio_pin, HIGH);
}

void BuzzerDriver::BuzzerOff() {
    Serial.println(gpio_pin);
    digitalWrite(gpio_pin, LOW);
}