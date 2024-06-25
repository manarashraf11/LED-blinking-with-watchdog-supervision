

#include "GPIO.h"

#include "Bit_Operations.h"
#include "Std_Types.h"


void GPIO_Init(void){

     //PB2 as output
	DDRB |= (1 << PIN2_ID);
    // Initlally LED ON
	PORTB |= (1 << PIN2_ID);
   
}


void GPIO_Write(int PinId, int PinData) {


    if(PinData == HIGH)
			{
				SET_BIT(PORTB,PinId);  // Set pin high
			}
			else
			{
				CLEAR_BIT(PORTB,PinId); // Set pin low
			}
}

