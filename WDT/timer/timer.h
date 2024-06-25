#ifndef TIMER_H
#define TIMER_H
#include "Std_Types.h"

// Register addresses for Timer1
#define TCCR1A (*((volatile uint8 *)0x80))
#define TCCR1B (*((volatile uint8 *)0x81))
#define OCR1A  (*((volatile uint16 *)0x88))
#define TIMSK1 (*((volatile uint8 *)0x6F))
#define WGM12 3
#define CS10  0
#define CS11  1
#define OCIE1A 1


// Register addresses for Timer2
#define TCCR2A (*((volatile uint8 *)0xB0))
#define TCCR2B (*((volatile uint8 *)0xB1))
#define OCR2A  (*((volatile uint8 *)0xB3))
#define TIMSK2 (*((volatile uint8 *)0x70))
#define WGM21  1
#define CS20   0
#define CS21   1
#define CS22   2
#define OCIE2A 1











void Timer1_Init(void);
void Timer2_Init(void);

#endif


