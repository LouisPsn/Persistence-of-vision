#ifndef WORD_H
#define WORD_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include "old_letter.h"
#include <stdbool.h>
#include <string.h>
#include "interrupt.h"

void print_word(char *str, int16_t tic, int16_t tic_par_tour, int16_t offset);

void word(char *str);

#endif