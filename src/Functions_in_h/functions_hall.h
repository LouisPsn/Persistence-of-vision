#include <avr/io.h>
#include <util/delay.h>

#ifndef FUNCTIONS_HALL_H
#define FUNCTIONS_HALL_H

void hall_init();

char read_state_hall();

#endif