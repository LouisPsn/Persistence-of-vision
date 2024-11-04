#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"
#include "functions_hall.h"
#include "interrupt.h"
#include "bluetooth.h"
#include <stdbool.h>

#ifndef FUNCTIONS_HORLOGE_H
#define FUNCTIONS_HORLOGE_H

void horloge_trigo();

void horloge_2();

void test_horloge();

#endif