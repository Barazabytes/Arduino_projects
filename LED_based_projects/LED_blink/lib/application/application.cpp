#include "application.h"
#include "application_config.h"
#include "../drivers/actuators/led/led_driver.h"
#include <Arduino.h>


LedDriver led;

App::App() {
    blink_delay = BLINK_DELAY;
}

void App::app_run() {
    while (1) {
        led.led_off();
        delay(blink_delay);

        led.led_on();
        delay(blink_delay);
    }
    
}