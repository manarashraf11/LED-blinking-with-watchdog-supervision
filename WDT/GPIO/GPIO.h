

#ifndef GPIO_H
#define GPIO_H

#include "Bit_Operations.h"
#include "Std_Types.h"

#define DDRB  (*(uint8 *)0x24)
#define PORTB (*(uint8 *)0x25)

#define DDRD  (*(uint8 *)0x2A)
#define PORTD (*(uint8 *)0x2B)

#define PIN0_ID                0
#define PIN1_ID                1
#define PIN2_ID                2
#define PIN3_ID                3
#define PIN4_ID                4
#define PIN5_ID                5
#define PIN6_ID                6
#define PIN7_ID                7

#define HIGH        (1u)
#define LOW         (0u)



void GPIO_Init(void);
void GPIO_Write(int PinId, int PinData);

#endif



