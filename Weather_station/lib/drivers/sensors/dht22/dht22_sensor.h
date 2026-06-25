#pragma once
#include <stdint.h>

class DHT22Sensor {
    private:
        uint8_t gpio_pin;

    public:
        void DHT22Init();
        float ReadTemperature();
        float ReadHumidity();
};

