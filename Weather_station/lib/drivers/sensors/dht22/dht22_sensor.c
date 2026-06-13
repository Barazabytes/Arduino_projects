#include <DHT.h>
#include <DHT_U.h>
#include <Arduino.h>
#include "dht22_sensor.h"
#include <Adafruit_Sensor.h>

#define DHTTYPE    DHT22

dht22_sensor_t dht22_sensor;
    DHT_Unified dht(dht22_sensor.gpio_pin, DHTTYPE);


void dht22_sensor_init(uint8_t gpio_pin) {
    dht22_sensor.gpio_pin = gpio_pin;
    pinMode(gpio_pin, INPUT);

    dht.begin();

}


float get_temperature () {
    sensors_event_t event;
        dht.temperature().getEvent(&event);
        if (isnan(event.temperature)) {
            Serial.println(F("Error reading temperature!"));
        }
        else {
            Serial.print(F("Temperature: "));
            Serial.print(event.temperature);
            Serial.println(F("°C"));
        }
}

float get_humidity    ();