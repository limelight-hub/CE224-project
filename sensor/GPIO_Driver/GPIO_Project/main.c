#include "GPIO.h"


void delay(volatile int time)
{
		while (time --);
}

int main()
{
		GPIO_Init(Port_A,0,Input,I_PUPDR);
		GPIO_Init(Port_A,7,Output50,O_GP_PP);
	
		while(1)
		{			
			if(GPIO_Read(Port_A,0) == 1)
			{
				GPIO_Toggle(Port_A,7);
				delay(1000000);
			}
			else
			{
				GPIO_Write(Port_A,7,1);
			  delay(1000000);
			}
		}
}

