#ifndef TOGGLE_H
#define TOGGLE_H

#include "Bit_Operations.h"
#include "Std_Types.h"

void toggle_testPins(volatile uint8 *ddr, volatile uint8 *port, int pin);

#endif // TOGGLE_H
