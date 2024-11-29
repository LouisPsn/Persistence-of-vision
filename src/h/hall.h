#ifndef HALL_H
#define HALL_H

#include <avr/io.h>
#include <util/delay.h>

void hall_init();

char read_state_hall();

#endif