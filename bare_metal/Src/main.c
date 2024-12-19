#include "Clock.h"
#include "GPIO.h"
#include "ADC.h"

#define ADC_MIN_VALUE 0     // ADC value at rest
#define ADC_MAX_VALUE 4095    // ADC value at max bend
#define ANGLE_MIN 0           // Angle at rest (degrees)
#define ANGLE_MAX 180          // Angle at max bend (degrees)

static uint16_t value = 0;
static float voltage = 0;
static float angle = 0;


void delay(volatile int time);

void delay(volatile int time)
{
		while (time--);
}

float calculate_angle(uint32_t adc_value) {
    if (adc_value < ADC_MIN_VALUE) adc_value = ADC_MIN_VALUE;
    if (adc_value > ADC_MAX_VALUE) adc_value = ADC_MAX_VALUE;

    // Linear interpolation
    float angle = ANGLE_MIN + ((float)(adc_value - ADC_MIN_VALUE) /
                              (ADC_MAX_VALUE - ADC_MIN_VALUE)) *
                              (ANGLE_MAX - ANGLE_MIN);
    return angle;
}

int main()
{
	//Clock config
	GPIO_Init(GPIOA);
	ADC_ClockConfig();
	ADC_Config(ADC1);
	ADC_Start(ADC1);

	while (1) 
	{
		value=ADC_GetValue(ADC1);
		voltage = (float) (value * 3.3) / ADC_RESOLUTION;
		angle = (voltage * ANGLE_MAX / 3.3);

		delay(300000);
	}
}
