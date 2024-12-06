#include "GPIO.h"

void GPIO_Init(unsigned short port, unsigned short pin, unsigned short mode, unsigned config)
{
		unsigned int *CR ;
		unsigned short tPIN = pin;
		unsigned short offset = 0x00;
		
		if(pin > 7)
		{
			tPIN -= 8;
			offset = 0x01;
		}
		if(port == 1)
		{
			// enable port A
			RCC_APB2ENR |= (1 << 2);
			CR  = (unsigned int*)(&GPIO_A + offset);	
		}
		else if(port == 2)
		{
			// enable port B
			RCC_APB2ENR |= (1 << 3);
			CR  = (unsigned int*)(&GPIO_B + offset);	
		}
		else if(port == 3)
		{
			// enable port C
			RCC_APB2ENR |= (1 << 4);
			CR  = (unsigned int*)(&GPIO_C + offset);	
		}
		
		
		/// Reset bits on CR
		*CR &= ~(0xF << tPIN *4);
		// Set MODE and CONFIG on the PIN
		*CR |= (mode << tPIN*4) | (config << tPIN*4 + 2);
	
}


int GPIO_Read(unsigned short port, unsigned short pin)
{
		unsigned int* IDR;
		unsigned int offset = 0x02;
		int state;
		// Assign IDR Address 
		if(port == 1)
		{
			IDR = (unsigned int*)(&GPIO_A + offset);	
		}
		else if(port == 	2)
		{
			IDR = (unsigned int*)(&GPIO_B + offset);	
		}
		else if(port == 3)
		{
			IDR = (unsigned int*)(&GPIO_C + offset);	
		}
		// read
		state = ((*IDR & (1<<pin))>>pin);
		return state;
}

void GPIO_Write(unsigned short port, unsigned short pin, unsigned short state)
{
		unsigned int* ODR;
		unsigned int offset = 0x03;

		// Assign ODR Address 
		if(port == 1)
		{
			ODR = (unsigned int*)(&GPIO_A + offset);	
		}
		else if(port == 	2)
		{
			ODR = (unsigned int*)(&GPIO_B + offset);	
		}
		else if(port == 3)
		{
			ODR = (unsigned int*)(&GPIO_C + offset);	
		}
		
		// Write
		if(state)
		{
			*ODR |= (1 << pin);
		}
		else
		{
			*ODR &= ~(1<<pin);
		}
}

void GPIO_Toggle(unsigned short port, unsigned short pin)
{
	if (GPIO_Read(port,pin))
		{
			GPIO_Write(port,pin,0);
		}
	else
		{
			GPIO_Write(port,pin,1);
		}
}



