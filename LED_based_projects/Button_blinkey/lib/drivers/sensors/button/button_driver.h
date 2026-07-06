#pragma once

#include <stdint.h>

class ButtonDriver {
private:
    uint8_t pin;
    bool last_state = false;
    uint64_t press_start_time = 0;
    bool held_triggered = false;

public:
    explicit ButtonDriver(uint8_t gpio_num);
    void button_init();
    bool is_button_pressed();
    bool is_button_released();
    bool is_button_held();
    bool is_button_clicked();

};