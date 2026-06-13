#include "buzzer_driver.h"
#include <Arduino.h>

buzzer_driver_t buzzer;

void buzzer_driver_init(uint8_t gpio_pin) {
    buzzer.gpio_pin   = gpio_pin;
    buzzer.beep_delay = 0;

    pinMode(buzzer.gpio_pin, OUTPUT);
}

void buzzer_sound_on() {
    digitalWrite(buzzer.gpio_pin, HIGH);
}

void buzzer_sound_off() {
    digitalWrite(buzzer.gpio_pin, LOW);
}
