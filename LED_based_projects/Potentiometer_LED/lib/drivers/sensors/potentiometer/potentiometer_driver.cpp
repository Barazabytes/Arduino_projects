#include <Arduino.h>
#include "potentiometer_driver.h"

PotentiometerDriver::PotentiometerDriver(uint8_t gpio_num) {
    gpio_pin = gpio_num;
    potentiometer_init();
}

void PotentiometerDriver::potentiometer_init() {
    pinMode(gpio_pin, INPUT);
    Serial.println("Pin for Potentiometer configured succesfully");
}

int PotentiometerDriver::read_value() {
    return analogRead(gpio_pin);
}
