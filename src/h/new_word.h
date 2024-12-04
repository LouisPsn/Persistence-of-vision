#ifndef NEW_WORD_H
#define NEW_WORD_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include <stdbool.h>

volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile char first = 1;
volatile int16_t position = 0;
struct ring_buffer rb;

volatile int8_t sec = 0;
volatile int8_t min = 0;
volatile int8_t heures = 0;

volatile long long last_time_ms = 0;
volatile long long time_ms_per_turn = 0;


void horloge_in_buffer();
void new_horloge();
void new_word();

#endif