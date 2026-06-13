#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t   gpio_pin;
    uint32_t  beep_delay;  
} buzzer_driver_t;


void buzzer_driver_init(uint8_t gpio_pin);
void buzzer_sound_on();
void buzzer_sound_off();