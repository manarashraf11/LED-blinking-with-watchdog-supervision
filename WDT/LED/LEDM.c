

#include "LEDM.h"
#include "GPIO.C"
#include "WDGM.h"
#include "Std_Types.h"
#include "toggle.h"
#include "GPIO.h"




static uint32 ledState = 0;
static uint32 counter = 0;

void LEDM_Init(void) {
	GPIO_Init();
    ledState = 0;
    counter = 0;
}

void LEDM_Manage(void) {
	toggle_testPins(&DDRD, &PORTD,PIN0_ID); // Toggle test pin for debugging
    counter += 10; // This function is called every 10ms

    if (counter >= 500) {
        ledState = !ledState; // Toggle LED state
        GPIO_Write(2,ledState);
        counter = 0;
    }
    WDGM_AlivenessIndication(); // Indicate aliveness to the watchdog manager
}

//void LED_Manage(void) {
//    toggle_testPins(&DDRD, &PORTD, PIN0_ID); // Toggle test pin for debugging
//    WDGM_AlivenessIndication(); // Indicate aliveness to the watchdog manager
//}
