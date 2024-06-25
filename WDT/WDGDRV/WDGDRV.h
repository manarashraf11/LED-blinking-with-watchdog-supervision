#ifndef WDDRV_H
#define WDDRV_H
#include "Std_Types.h"



#define WDTCSR (*( uint32 *)0x60)
#define WDE    3
#define WDCE   4
#define WDP2   2
#define WDP1   1
#define WDP0   0
#define WDIF   7
#define WDIE   6

#define SREG    (*(uint32 *)0x5F)
#define SREG_I  7

#define ENABLE_INTERRUPTS()  (SREG |= (1 << SREG_I))
#define DISABLE_INTERRUPTS() (SREG &= ~(1 << SREG_I))



#define WDGM_STATUS_OK       (0x01)
#define WDGM_STATUS_NOT_OK   (0x00)
void WDGDrv_Init(void);
void WDGDrv_Refresh(void);

#endif
