#include <Arduino.h>
#include "application.h"
#include "application_config.h"
#include "actuators/led/led_driver.h"
#include "sensors/button/button_driver.h"

ButtonDriver button(BUTTON_PIN);
LedDriver led(LED_PIN);

Application::Application() {
    application_init();
}

void Application::application_init() {
    led.led_init();
    button.button_init();
}

void Application::app_run() {
    while (1) {
        if(button.is_button_held()) {
            for(int i = 0; i < 10; i++) {
                led.led_toggle();
                delay(200);
            }
        } else if(button.is_button_clicked()) {
            led.led_toggle();
        }
    }
}