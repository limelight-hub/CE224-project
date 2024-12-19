#include "Clock.h"

void RCC_HSEConfig(void)
{
	//External high-speed clock bypass
	pRCC_CR |= (1 << 18);
	//HSEON: HSE clock enable
	pRCC_CR |= (1 << 16);
	//External high-speed clock ready flag
	pRCC_CR |= (1 << 17);
	//PLL clock ready flag
	while (!((pRCC_CR << 25) & 1));
}

void RCC_PLLConfig(void)
{
	//PLL enable
	pRCC_CR |= (1 << 24);
	//Microcontroller clock output: System clock (SYSCLK) selected
	pRCC_CFGR |= (4 <<24);
	// PLL multiplication factor: 9
	pRCC_CFGR |= (7 << 18);
	//HSE divider for PLL entry: HSE clock not divided
	pRCC_CFGR &= ~(1u << 17);
	//PLL entry clock source: HSE
	pRCC_CFGR |= (1 << 16);
	//ADC prescaler: 8
	pRCC_CFGR |= (3 << 14);
	//APB high-speed prescaler (APB2): 1
	pRCC_CFGR &= ~(1u << 11);
	//AHB prescaler: 1
	pRCC_CFGR &= ~(1u << 4);
	//System clock switch: PLL selected as system clock
	pRCC_CFGR |= (2 << 0);
}

void RCC_AdcConfig(void)
{

}
