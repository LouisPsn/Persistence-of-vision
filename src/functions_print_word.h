#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"
#include "functions_hall.h"
#include "functions_print_letter.h"
#include <stdbool.h>
#include <string.h>

#ifndef FUNCTIONS_LETTER_1_H
#define FUNCTIONS_LETTER_1_H

/*
void print_hello(int16_t tic, int16_t tic_par_tour, int16_t offset);

void print_test(int16_t tic, int16_t tic_par_tour, int16_t offset);
*/

void print_word(char *str, int16_t tic, int16_t tic_par_tour, int16_t offset);

void word(char *str);

#endif