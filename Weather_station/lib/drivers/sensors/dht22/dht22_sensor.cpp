#include <Adafruit_Sensor.h>
#include "dht22_sensor.h"
#include "dht22_config.h"
#include <Arduino.h>
#include <DHT_U.h>
#include <DHT.h>

DHT_Unified dht(DHT22_PIN, DHTTYPE);

void DHT22Sensor::DHT22Init() {
    dht.begin();
}


float DHT22Sensor::ReadTemperature() {
    // Implementation for reading temperature
    sensors_event_t event;
    dht.temperature().getEvent(&event);
    return event.temperature;
}

float DHT22Sensor::ReadHumidity() {
    // Implementation for reading humidity
    sensors_event_t event;
    dht.humidity().getEvent(&event);
    return event.relative_humidity;
}
