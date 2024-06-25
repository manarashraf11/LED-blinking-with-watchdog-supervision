
#include "WDGDRV.h"
#include "WDGM.h"
#include <util/delay.h>
#include "LEDM.h"
#include "timer.h"
#include "GPIO.h"

uint32 counter_main=0;


int main(void) {
	DDRB |= (1 << PIN7_ID);
	GPIO_Write(7,1);

    LEDM_Init();
    WDGDrv_Init();
    WDGM_Init();
    Timer1_Init();
//    Timer2_Init();

    ENABLE_INTERRUPTS(); // Enable global interrupts

    while (1) {
    	 _delay_ms(10);
        LEDM_Manage();
        counter_main++;
        if(counter_main>=2){
            WDGM_MainFunction();
            counter_main = 0;
        }




}
    
    return 0;
}
//-------------------------------------------------------------------------------------------------//

/*

 Scenario B:

 -Comment WDGM_MainFunction and check if the watchdog resets after 50ms.

*/

//-------------------------------------------------------------------------------------------------//

/*

 Scenario C:

 -Comment WDGM_AlivenessIndication() in LED_manage & verify the watchdog reset after 100ms.

 */

//-------------------------------------------------------------------------------------------------//

/* Scenario D:

check if the watchdog resets after 100ms.


    Main loop would be like this:

while (1) {
		_delay_ms(5);
		LEDM_Manage();
		wdg_counter++;
		if (wdg_counter>=4){
			WDGM_MainFunction();
			wdg_counter=0;
		}
 }
*/
