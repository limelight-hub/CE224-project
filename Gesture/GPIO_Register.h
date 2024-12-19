 #ifndef INC_GPIO_REGISTER_H_
 
#include "stdint.h"
 
#define GPIOA_BASE 				0x40010800
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
	uint32_t GPIOx_CRL;
	uint32_t GPIOx_CRH;
	uint32_t GPIOx_IDR;
	uint32_t GPIOx_ODR;
	uint32_t GPIOx_BSRR;
	uint32_t GPIOx_BRR;
	uint32_t GPIOx_LCKR;
} GPIORegister_TypeDef;

#define INC_GPIO_REGISTER_H_

#endif /* INC_GPIO_REGISTER_H_ */
