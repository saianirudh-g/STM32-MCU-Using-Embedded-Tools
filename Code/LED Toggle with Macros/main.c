#include <stdio.h>
#include <stdint.h>
#include "main.h"

int main(void)
{
    // RCC AHB1 clock enable register
    RCC_AHB1ENR_t volatile *const pClkCtrlReg = ADDR_REG_AHB1ENR;

    // GPIOD MODER register (mode configuration)
    GPIOx_MODE_t volatile *const pPortDModeReg = (GPIOx_MODE_t*) 0x40020C00;

    // GPIOD ODR register (output data)
    GPIOx_ODR_t volatile *const pPortDOutReg = (GPIOx_ODR_t*) 0x40020C14;

    // 1. Enable clock for GPIOD
    pClkCtrlReg->gpiod_en = CLOCK_ENABLE;

    // 2. Configure PD12 as output
    pPortDModeReg->pin_12 = MODE_CONF_OUTPUT;

    while(1)
    {
        // Turn ON LED (PD12)
        pPortDOutReg->pin_12 = PIN_STATE_HIGH;

        for(uint32_t i = 0; i < DELAY_COUNT; i++);

        // Turn OFF LED
        pPortDOutReg->pin_12 = PIN_STATE_LOW;

        for(uint32_t i = 0; i < DELAY_COUNT; i++);
    }

    for(;;);
}
