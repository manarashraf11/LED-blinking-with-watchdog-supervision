

#include "WDGDRV.h"
#include <avr/wdt.h>




void WDGDrv_Init(void){
    
    DISABLE_INTERRUPTS(); // Disable global interrupts
    
//    wdt_enable();
	__asm__ __volatile__ (
			"sts %0, %1" "\n\t"
			"sts %0, %2" "\n \t"
			: /* no outputs */
			: "n" (_SFR_MEM_ADDR(_WD_CONTROL_REG)),
			"r" ((uint8_t)(_BV(_WD_CHANGE_BIT) | _BV(WDE))),
			"r" ((uint8_t) ((2 & 0x08 ? _WD_PS3_MASK : 0x00) |
					_BV(WDE) | (2 & 0x07)) )
			: "r0"
	);
//   // Configure the watchdog timer for a 64ms timeout
//    WDTCSR |= (1 << WDCE) | (1 << WDE);  // Set Watchdog Change Enable
//    WDTCSR = (1 << WDE) | (1 << WDP1) | (1 << WDP0);  // Set timeout to 64ms

    ENABLE_INTERRUPTS(); // Enable global interrupts
    



}
void WDGDrv_Refresh(void) {
    // Reset the watchdog timer
        wdt_reset();
}


