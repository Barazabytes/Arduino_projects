#include "buzzer_driver.h"
#include <Arduino.h>


BuzzerDriver::BuzzerDriver(uint8_t _gpio_pin) : gpio_pin(_gpio_pin) {
    BuzzerInit();
    Serial.print("Buzzer initialized on GPIO pin: ");
    Serial.println(gpio_pin);
}

void BuzzerDriver::BuzzerInit() {
    Serial.print("Initializing buzzer on GPIO pin: ");
    Serial.println(gpio_pin);
    pinMode(gpio_pin, OUTPUT);
}

void BuzzerDriver::BuzzerOn() {
    Serial.print("Turning buzzer on GPIO pin: ");
    Serial.println(gpio_pin);
    digitalWrite(gpio_pin, HIGH);
}

void BuzzerDriver::BuzzerOff() {
    Serial.print("Turning buzzer off GPIO pin: ");
    Serial.println(gpio_pin);
    digitalWrite(gpio_pin, LOW);
}