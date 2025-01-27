#ifndef CLOCK_H
#define CLOCK_H

#include <avr/io.h>
#include <avr/interrupt.h>

static volatile long long time_ms = 0;

// Function that initialize clock to generate 3250Hz signal in Clear Timer on Compare Match (CTC) Mode, f clk_I/O = 13MHz, N = 8, TOP = 249
void init_clock_time();


// Function that initialize clock to generate 1000Hz signal in Fast PWM Mode, f clk_I/O = 13MHz, N = 8, TOP = 1624
void init_clock_aff();

int16_t read_timer_16();

void clear_timer_16();


#endif