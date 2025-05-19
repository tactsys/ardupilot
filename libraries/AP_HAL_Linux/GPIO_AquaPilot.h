#pragma once

#include <AP_HAL_Linux/GPIO_RPI.h>

#if HAL_LINUX_GPIO_AQUAPILOT_ENABLED

using namespace Linux;

extern const AP_HAL::HAL& hal;

class GPIO_AquaPilot : public GPIO_RPI {
public:
    void pinMode(uint8_t pin, uint8_t output) override;
    void pinMode(uint8_t pin, uint8_t output, uint8_t alt) override;
    uint8_t read(uint8_t pin) override;
    void write(uint8_t pin, uint8_t value) override;

private:
    uint8_t AllowedGPIOS[6] = {
        RPI_GPIO_<4>(),  // LED C
        RPI_GPIO_<12>(), // Buzzer
        RPI_GPIO_<18>(), // Aux Output for PWMs
        RPI_GPIO_<26>(), // PCA OUTPUT_ENABLE
        RPI_GPIO_<22>(), // LED B
        RPI_GPIO_<27>()  // LED A
    };
    bool pinAllowed(uint8_t pin);
};

#endif  // HAL_LINUX_GPIO_AQUAPILOT_ENABLED