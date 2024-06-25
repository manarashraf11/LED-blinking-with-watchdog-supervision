
//#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>
#include "timer.h"
#include "WDGDRV.h"
#include "WDGM.h"
#include "GPIO.H"
#include "toggle.h"
#include "Std_Types.h"



void Timer1_Init() {
	//disable power saving mode
	PRR &= ~(1<<PRTIM1);
    // Set CTC mode (Timer Counter Control Reg)
    TCCR1B |= (1 << WGM12);

    // prescaler = 64 , start the timer
    TCCR1B |= (1 << CS11) | (1 << CS10);

    //Output Compare Register
    OCR1A = 815; // 6249 for 8 MHz , 12499 for 16MHz Clock ,815 for 1MHz

    // Enable timer compare interrupt
    // TIMSK1 Giving semantic error, so if not defined replace by its address
    #ifdef TIMSK1
    TIMSK1 |= (1 << OCIE1A);
    #else
    *((volatile uint8 *)0x6F) |= (1 << 1);
    #endif
}


ISR(TIMER1_COMPA_vect) {

	 // This ISR will be called every 50ms
	// toggle B0 for debugging

    if ((WDGM_ProvideSupervisionStatus() && !WDGM_MainFunctionStuck())) {
		toggle_testPins(&DDRB, &PORTB,PIN0_ID); //ISR PIN
        WDGDrv_Refresh();
    } 
     else {
     	wdt_enable(WDTO_15MS);
     }
}
//
//void Timer2_Init() {
//    // Set CTC mode (Clear Timer on Compare Match)
//    TCCR2A |= (1 << WGM21);
//
//    // Set prescaler to 1024
//    TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
//
//    // Set compare match register for 500ms interval
//    OCR2A = 255; // for 8 MHz clock
//
//    // Enable timer compare interrupt
//	#ifdef TIMSK2
//	TIMSK2 |= (1 << OCIE2A);
//	#else
//	*((volatile uint8 *)0x70) |= (1 << 1);
//	#endif
//}

// ISR for Timer2 compare match
ISR(TIMER2_COMPA_vect) {
    PORTB ^= (1 << PIN2_ID); // Toggle PB2 for 500ms interval
}


