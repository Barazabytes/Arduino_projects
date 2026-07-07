#include <Arduino.h>
#include "application.h"
#include "application_config.h"
#include "actuators/led/led_driver.h"
#include "sensors/potentiometer/potentiometer_driver.h"

PotentiometerDriver potentiometer(POTENTIOMETER_PIN);
LedDriver led(LED_PIN);

Application::Application() {
    application_init();
}

void Application::application_init() {
    led.led_init();
    potentiometer.potentiometer_init();
}

int Application::pot_to_led_mapping(int pot_value) {
    // Map potentiometer value (0-1023) to LED brightness (0-255)
    return (int)(((float)pot_value / POT_MAX_VALUE) * LED_MAX_BRIGHTNESS);
}

void Application::app_run() {
    while (1) {
        int pot_value = potentiometer.read_value();
        int led_brightness = pot_to_led_mapping(pot_value);
        led.led_set_brightness(led_brightness);
        delay(100); 
    }
}
