#include "interrupt.h"

// Set INT0 to fall edge of DD_HALL
void hall_sensor_init()
{
    EICRA |= (0 << ISC00);
    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);
}