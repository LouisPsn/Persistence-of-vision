#ifndef HORLOGE_H
#define HORLOGE_H

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
#include "SPI_led.h"
#include "hall.h"
#include "interrupt.h"
#include "bluetooth.h"
#include "../h/clock.h"

/*
volatile static int16_t tic_par_tour = 0;
volatile static int16_t tic = 0;
volatile static char first = 1;

volatile static int8_t heures = 10;
volatile static int8_t min = 10;
volatile static int8_t sec = 0;

void set_time(int8_t h, int8_t m, int8_t s);
*/
void horloge_trigo();

void horloge_2();

void test_horloge();

#endif