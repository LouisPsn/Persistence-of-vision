#ifndef PRINT_FRAME_H
#define PRINT_FRAME_H

#include <avr/io.h>
#include <avr/interrupt.h>

uint16_t frame[60];

ISR(INT0_vect);

#endif