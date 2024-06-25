

#include "toggle.h"
#include "Bit_Operations.h"
#include "Std_Types.h"


void toggle_testPins(volatile uint8 *ddr, volatile uint8 *port, int pin) {
    *ddr |= (1 << pin); // set as output
    *port ^= (1 << pin); // toggle the pin
}





