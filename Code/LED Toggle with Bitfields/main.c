#include "main.h";

    uint32_t *pClkCtrlReg = (uint32_t*)0x40023830;
    uint32_t *pPortDModeReg = (uint32_t*)0x40020C00;
    uint32_t *pPortDOutReg = (uint32_t*)0x40020C14;

int main(void){
	RCC_AHB1ENR_t volatile *const pClkCtrlReg = (RCC_AHB1ENR_t*) 0x40023830;

	GPIOx_ODR_t volatile *const pPortDOutReg = (GPIOx_ODR_t*) 0x40020C14;

	GPIOx_MODE_t volatile *const pPortDModeReg = (GPIOx_MODE_t*) 0x40020C00;

	pClkCtrlReg->gpiod_en = 1;
	pPortDModeReg->pin_12 = 1;

	while(1){
		//3. SET 12th bit of the output data register to I/O pin-12 as High
		    *pPortDOutReg |= (1 << 12);

		    //introduce small human observable delay
		    for(uint32_t i=0;i<10000;i++);

		    //Turn OFF the LED
		    *pPortDOutReg &= ~(1 << 12);

		    for(uint32_t i=0;i<10000;i++);
	}
}
