#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef FUNCTION_PRINT_FRAME_H
#define FUNCTION_PRINT_FRAME_H

uint16_t frame[60];

ISR(INT0_vect);

#endif