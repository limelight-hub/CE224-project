#include "GPIO.h"

void GPIO_ClockEnable(GPIORegister_TypeDef* gpiox)
{
	if (gpiox == GPIOA)
	{
		GPIOA_PCLK_EN();
	}
	else if (gpiox == GPIOB)
	{
		GPIOB_PCLK_EN();
	} 
	else if (gpiox == GPIOC)
	{
		GPIOC_PCLK_EN();
	}
	else if (gpiox == GPIOD)
	{
		GPIOD_PCLK_EN();
	} 
	else if (gpiox == GPIOE)
	{
		GPIOE_PCLK_EN();
	} 
	
}

void GPIO_Init(GPIORegister_TypeDef* portx)
{
	GPIO_TypeDef GPIO_InitStruct = {0};
	
	GPIO_InitStruct.GPIO_PinMode = GPIO_MODE_INPUT;
	GPIO_InitStruct.GPIO_PinNumber = GPIO_PIN_0;
	GPIO_InitStruct.GPIO_PinType = GPIO_MODE_ANALOG;
	//Enable peripheral clock
	GPIO_ClockEnable(portx);
	//Config mode of GPIO pin and speed
	portx->GPIOx_CRL &= ~(1u << 0);
	portx->GPIOx_CRL &= ~(1u << 2);
}


void GPIO_WriteOutputPin(GPIORegister_TypeDef* gpiox, unsigned int pinNumber, unsigned int value)
{
	if (value == 1) gpiox->GPIOx_ODR |= (1 << pinNumber);
	else if (value == 0) gpiox->GPIOx_ODR &= ~(1u << pinNumber);
}


unsigned int GPIO_ReadInputPin(GPIORegister_TypeDef* gpiox, unsigned int pinNumber)
{
	unsigned int value;
	value = ((gpiox->GPIOx_IDR) >> pinNumber) & 0x00000001;
	return value;
}

void GPIO_TogglePin(GPIORegister_TypeDef* gpiox, unsigned int pinNumber)
{
	if (((gpiox->GPIOx_ODR >> pinNumber) & GPIO_PIN_SET))
		gpiox->GPIOx_ODR &= ~(1u << pinNumber);
	else if (!((gpiox->GPIOx_ODR >> pinNumber) & GPIO_PIN_SET))
		gpiox->GPIOx_ODR |= (1 << pinNumber);

}
