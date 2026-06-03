#include <stdint.h>
#include <stdbool.h>

typedef enum {
    PIN_MODE_INPUT,
    PIN_MODE_OUTPUT
} pin_mode_t;

void hal_gpio_init(uint8_t pin, pin_mode_t mode);
void hal_gpio_write(uint8_t pin, bool value);