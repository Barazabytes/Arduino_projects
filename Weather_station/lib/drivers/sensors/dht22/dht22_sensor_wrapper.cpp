#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>
#include "dht22_sensor.h"
#include <Adafruit_Sensor.h>


DHT22_Handle dht_create(uint8_t pin, unsigned char type) {
    return new DHT(pin, type);
}

void dht_begin(DHT22_Handle handle) {
    ((DHT*)handle)->begin();
}

float dht_read_temperature(DHT22_Handle handle) {
    return ((DHT*)handle)->readTemperature();
}

float dht_read_humidity(DHT22_Handle handle) {
    return ((DHT*)handle)->readHumidity();
}

void dht_destroy(DHT22_Handle handle) {
    delete ((DHT*)handle);
}