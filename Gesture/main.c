#include "Clock.h"
#include "ADC.h"
#include "Oled.h"
#include "GPIO.h"

static int value = 0;
static int counter = 0; 
static char buffer[100]; 

static double angle =0;

void delay(volatile int time);

void delay(volatile int time)
{
		while (time--);
}

int main()
{
	//Clock config
	int target_angle;
	//GPIO_Init(GPIOC, GPIO_PIN_13, GPIO_OUTPUT_SPEED10_MODE, GPIO_MODE_OUTPUT_PP);
	oled_init_64(I2C1);
	oled_print(I2C1,4,60,"Hello", 's'); 
	oled_clear(I2C1);
	
	//adc
	GPIO_Init(GPIOA,GPIO_PIN_0,GPIO_MODE_INPUT,GPIO_MODE_ANALOG);
	ADC_ClockConfig();
	ADC_Config(ADC1);
	ADC_Start(ADC1);
	
	while (1) 
	{
		value=(int)ADC_GetValue(ADC1);
		
		target_angle = (int)(value * 180 / ADC_RESOLUTION);
		
		oled_print(I2C1,3,60,&value,'i');
		oled_print(I2C1,4,60,&target_angle,'i');
		//delay(5000000);
		oled_clear(I2C1);
		//GPIO_TogglePin(GPIOA,GPIO_PIN_0);
		//GPIO_TogglePin(GPIOC,GPIO_PIN_13);
		//value = GPIO_ReadInputPin(GPIOA, GPIO_PIN_0);
		//delay(500000);
	}
}
