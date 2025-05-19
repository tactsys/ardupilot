#include <AP_HAL_Linux/GPIO_AquaPilot.h>

#if HAL_LINUX_GPIO_AQUAPILOT_ENABLED

uint8_t GPIO_AquaPilot::read(uint8_t pin)
{
    if (pinAllowed(pin)) {
        return GPIO_RPI::read(pin);
    }
    if (hal.rcout->supports_gpio()) {
        return (uint8_t)hal.rcout->read(pin - 1);
    }
    return 0;
}

void GPIO_AquaPilot::write(uint8_t pin, uint8_t value)
{
    if (pinAllowed(pin)) {
        GPIO_RPI::write(pin, value);
        return;
    }
    if (hal.rcout->supports_gpio()) {
        hal.rcout->write_gpio(pin - 1, value);
    }
}

void GPIO_AquaPilot::pinMode(uint8_t pin, uint8_t output)
{
    if (pinAllowed(pin)) {
        GPIO_RPI::pinMode(pin, output);
    }
}

void GPIO_AquaPilot::pinMode(uint8_t pin, uint8_t output, uint8_t alt)
{
    if (pinAllowed(pin)) {
        GPIO_RPI::pinMode(pin, output, alt);
    }
}

bool GPIO_AquaPilot::pinAllowed(uint8_t pin)
{
    for (const auto &gpio : AllowedGPIOS) {
        if (pin == gpio) {
            return true;
        }
    }
    return false;
}

#endif  // HAL_LINUX_GPIO_AQUAPILOT_ENABLED