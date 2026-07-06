#include <Arduino.h>
#include "esp_timer.h"
#include "button_driver.h"
#include "button_config.h"

ButtonDriver::ButtonDriver(uint8_t gpio_num) {
    pin = gpio_num;
    button_init();
}

void ButtonDriver::button_init() {
    pinMode(pin, INPUT_PULLUP);
    Serial.println("Pin for Button configured succesfully");
}

bool ButtonDriver::is_button_pressed() {
    return digitalRead(pin) == LOW;
}

bool ButtonDriver::is_button_released() {
    return digitalRead(pin) == HIGH;
}

bool ButtonDriver::is_button_clicked() {
    bool currently_pressed = is_button_pressed();
    bool clicked = false;

    // Released after a short press, and it wasn't already flagged as a hold
    if (!currently_pressed && last_state && !held_triggered) {
        uint64_t elapsed_time = esp_timer_get_time() - press_start_time;
        if (elapsed_time < BUTTON_HOLD_TIME) {
            clicked = true;
        }
    }

    last_state = currently_pressed;
    return clicked;
}


bool ButtonDriver::is_button_held() {
    bool currently_pressed = is_button_pressed();

    // Just transitioned to pressed -> start the clock
    if (currently_pressed && !last_state) {
        press_start_time = esp_timer_get_time();
        held_triggered = false;
    }

    // Still pressed -> check duration
    if (currently_pressed && last_state && !held_triggered) {
        uint64_t elapsed_time = esp_timer_get_time() - press_start_time;
        if (elapsed_time >= BUTTON_HOLD_TIME) {
            held_triggered = true;
            last_state = currently_pressed;
            Serial.println("Button Held");
            return true;
        }
    }

    last_state = currently_pressed;
    return false;
}
