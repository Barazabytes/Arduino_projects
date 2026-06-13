#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t gpio_pin;
} dht22_sensor_t;


void dht22_sensor_init(uint8_t gpio_pin);
float get_temperature ();
float get_humidity    (); 