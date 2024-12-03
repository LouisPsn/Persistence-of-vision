#ifndef NEW_WORD_H
#define NEW_WORD_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include <stdbool.h>

void horloge_in_buffer();
void new_horloge();
void new_word();

#endif