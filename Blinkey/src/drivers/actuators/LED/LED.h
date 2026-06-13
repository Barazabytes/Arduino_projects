#include <stdint.h>
#include <stdbool.h>
#include "../../../app_hal/hal_gpio/hal_gpio.h"

typedef struct {
    uint8_t pin;
    gpio_mode_t mode;
} LED_t;

void LED_init(uint8_t pin, pin_mode_t mode);
void LED_on(uint8_t pin);
void LED_off(uint8_t pin);