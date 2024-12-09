#ifndef NEW_WORD_H
#define NEW_WORD_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include <stdbool.h>
#include <stdlib.h>
#include "bluetooth.h"
#include "clock.h"
#include "buffer.h"
#include <string.h>
#include "word.h"

#define WORD_SIZE_MAX 20

volatile static int16_t tic_par_tour = 0;
volatile static int16_t tic = 0;
volatile static char first = 1;
volatile static int16_t position = 0;
static struct frame_buffer rb;

volatile static int8_t sec = 0;
volatile static int8_t min = 0;
volatile static int8_t heures = 0;

volatile static long long last_time_ms = 0;
volatile static long long time_us_per_turn = 0;

volatile static bool need_load_buffer = false;
volatile static bool need_incr_hour = false;
volatile static bool need_load_gif = false;

volatile static char state = 0b00;
volatile static char state_img = 0;
volatile static char state_gif = 0;

static struct ring_buffer rb_receive;

// boolean to check if data is received
volatile static char data_received = 0;



static char command_buffer[BUFFER_DATA_SIZE] = {0};
static uint8_t command_index = 0;


void setup_hour(int8_t h, int8_t m, int8_t s);
void incr_hour();
void horloge_in_buffer();
void new_horloge();
void new_word();

void load_mario();
void load_croix_occitane();
void load_chirac();

void load_penta();

void display_buffer();

#endif