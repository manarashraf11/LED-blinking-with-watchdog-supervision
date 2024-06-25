
#include "WDGM.h"
#include "Std_Types.h"
#include "toggle.h"
#include "GPIO.h"


static uint8 wdgmStatus = 1;
static uint16 ledManageCalls = 0;
static uint8 wdgmMainFunctionCalled = 0;
static counter_wdg =0 ;

void WDGM_Init(void) {
    wdgmStatus = 1; // initially OK
    ledManageCalls = 0;
    wdgmMainFunctionCalled = 1;
}

void WDGM_MainFunction(void) {
	toggle_testPins(&DDRD, &PORTD,PIN2_ID);
    counter_wdg += 20; // This function is called every 10ms

    
    if (counter_wdg >= 100) {
        if (ledManageCalls >= 8 && ledManageCalls <= 12) {
        wdgmStatus = 1;
    } else {
        wdgmStatus = 0;
    }
}
      ledManageCalls = 0; // Reset count every 100ms
    wdgmMainFunctionCalled = 1; // Tells that Function is called

}

WDGM_StatusType WDGM_ProvideSupervisionStatus(void) {
    return wdgmStatus;
}

void WDGM_AlivenessIndication(void) {
    ledManageCalls++;
}


int WDGM_MainFunctionStuck(void) {
    // Check if WDGM_MainFunction was called
    if (wdgmMainFunctionCalled) {
        wdgmMainFunctionCalled = 0; // Reset the flag
        return 0; // Not stuck
    }
    return 1; // Stuck
}
