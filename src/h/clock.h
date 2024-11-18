#ifndef CLOCK_H
#define CLOCK_H

#include <avr/io.h>
#include <avr/interrupt.h>

volatile long long time_ms = 0;

// Function that initialize clock to generate 1000Hz signal in Fast PWM Mode, f clk_I/O = 13MHz, N = 8, TOP = 1624
void init_clock();

ISR(TIMER1_OVF_vect);

#endif