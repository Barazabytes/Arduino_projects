#pragma once

#include <stdint.h>
#include <stdbool.h>


typedef struct {
    uint8_t gpio_pin;
}sound_module_t;


void sound_module_init(uint8_t gpio_pin);
void sound_task(void *param);
