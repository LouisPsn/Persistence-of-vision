#include "interrupt.h"

// Set INT0 to fall edge of DD_HALL
void hall_sensor_init()
{
    EICRA |= (0 << ISC00);
    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);
}


// Generate an interrupt when the hall sensor detect a magnet
ISR(INT0_vect)
{
    // Code things to do during the interruption, the code should be as short
}