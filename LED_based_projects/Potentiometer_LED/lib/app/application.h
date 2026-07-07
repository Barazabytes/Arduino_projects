#pragma once

#include <stdint.h>

class Application {

private:
    uint8_t led_pin;
    uint8_t potentiometer_pin;

    int pot_to_led_mapping(int pot_value);

public:
    explicit Application();
    void application_init();
    void app_run();

};