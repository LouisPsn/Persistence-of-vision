#ifndef FUNCTIONS_HORLOGE_H
#define FUNCTIONS_HORLOGE_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include "interrupt.h"
#include "bluetooth.h"
#include <stdbool.h>
#include "../h/clock.h"

void horloge_trigo();

void horloge_2();

void test_horloge();

#endif