#ifndef NEW_WORD_H
#define NEW_WORD_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include <stdbool.h>
#include <stdlib.h>
#include "bluetooth.h"
#include "../h/clock.h"
#include "../h/buffer.h"
#include <string.h>
#include "word.h"

#define BUFFER_DATA_SIZE 20

static int16_t tic_par_tour = 0;
static int16_t tic = 0;
static char first = 1;
static int16_t position = 0;
struct ring_buffer rb;

static int8_t sec = 0;
static int8_t min = 0;
static int8_t heures = 0;

static long long last_time_ms = 0;
static long long time_us_per_turn = 0;

static bool need_load_buffer = false;
static bool need_incr_hour = false;

static char state = 0b00;
static char state_img = 0;

struct ring_buffer rb_receive;

// boolean to check if data is received
static char data_received = 0;

static char word_received[20] = {0};

char command_buffer[BUFFER_DATA_SIZE];
static uint8_t command_index = 0;


void setup_hour(int8_t h, int8_t m, int8_t s);
void incr_hour();
void horloge_in_buffer();
void new_horloge();
void new_word();

void load_mario();
void load_croix_occitane();
void load_chirac();

void display_buffer();

#endif