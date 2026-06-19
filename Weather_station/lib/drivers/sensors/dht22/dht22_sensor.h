#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint8_t gpio_pin;
} dht22_sensor_t;

typedef void *DHT22_Handle;

DHT22_Handle dht_create(uint8_t gpio_pin, unsigned char type);
void dht_begin(DHT22_Handle handle);

void dht22_sensor_init(uint8_t gpio_pin);
float get_temperature();
float get_humidity   (); 

void dht_destroy(DHT22_Handle handle);

#ifdef __cplusplus
}
#endif