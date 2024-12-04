#ifndef PRINT_FRAME_H
#define PRINT_FRAME_H

#include <avr/io.h>
#include <avr/interrupt.h>
/*
volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile int16_t sec = 0;
volatile int16_t min = 0;
volatile char first = 1;
*/
volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile int16_t sec = 0;
volatile int16_t min = 0;
volatile char first = 1;

uint16_t frame[60];

ISR(INT0_vect);

#endif