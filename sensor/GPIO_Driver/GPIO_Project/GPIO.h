// address
#define RCC_APB2ENR   (*((unsigned int *)(0x40021000 + 0x18)))

#define GPIO_A          (*((unsigned int *) 0x40010800))
#define GPIO_B          (*((unsigned int *) 0x40010C00))
#define GPIO_C          (*((unsigned int *) 0x40011000))

// Define Port
#define Port_A 1
#define Port_B 2
#define Port_C 3

//  MODE 
#define Input 0
#define Output10 1
#define Output2 2
#define Output50 3

//  Configurations for INPUT Mode
#define I_Analog 0
#define I_Floating 1
#define I_PUPDR 2

// Configurations for Output Mode
#define O_GP_PP 0
#define O_GP_OD 1
#define O_AF_PP 2
#define O_AF_OD 3

// STATe
#define LOW 0
#define HIGH 1

// mode = MODEy[1:0] and config = CNFy[1:0] trong thanh ghi CR
void GPIO_Init(unsigned short port,  unsigned short pin, unsigned short mode, unsigned config);
int GPIO_Read(unsigned short port, unsigned short pin);
void GPIO_Write(unsigned short port, unsigned short pin, unsigned short state);
void GPIO_Toggle(unsigned short port, unsigned short pin);

