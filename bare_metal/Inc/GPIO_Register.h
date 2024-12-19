
#include "stdint.h"
 
#define GPIOA_BASE 				0x40010C00
#define GPIOB_BASE 				0x40010C00
#define GPIOC_BASE 	 			0x40011000
#define GPIOD_BASE 				0x40011400
#define GPIOE_BASE 				0x40011800
#define GPIOF_BASE 				0x40011C00 
#define GPIOG_BASE 				0x40012000

#define GPIOA ((GPIORegister_TypeDef*)GPIOA_BASE)
#define GPIOB ((GPIORegister_TypeDef*)GPIOB_BASE)
#define GPIOC ((GPIORegister_TypeDef*)GPIOC_BASE)
#define GPIOD ((GPIORegister_TypeDef*)GPIOD_BASE)
#define GPIOE ((GPIORegister_TypeDef*)GPIOE_BASE)
#define GPIOF ((GPIORegister_TypeDef*)GPIOF_BASE)
#define GPIOG ((GPIORegister_TypeDef*)GPIOG_BASE)

typedef struct
{
	volatile uint32_t GPIOx_CRL;
	volatile uint32_t GPIOx_CRH;
	volatile uint32_t GPIOx_IDR;
	volatile uint32_t GPIOx_ODR;
	volatile uint32_t GPIOx_BSRR;
	volatile uint32_t GPIOx_BRR;
	volatile uint32_t GPIOx_LCKR;
} GPIORegister_TypeDef;

