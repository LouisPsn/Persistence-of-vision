#ifndef DIGIT_HORLOGE_H
#define DIGIT_HORLOGE_H

#include <avr/io.h>
#include <util/delay.h>
#include "buffer.h"

volatile static int16_t zero_hg[RING_BUFFER_SIZE/4]={0xFFFF};
volatile static int16_t un_hg[RING_BUFFER_SIZE/4]={0xFFFF};
////////////////////////////////////////
volatile static int16_t zero_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t un_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t deux_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t trois_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t quatre_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t cinq_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t six_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t sept_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t huit_hd[RING_BUFFER_SIZE/4]={0x0FFF};
volatile static int16_t neuf_hd[RING_BUFFER_SIZE/4]={0x0FFF};
////////////////////////////////////////
volatile static int16_t zero_bg[RING_BUFFER_SIZE/4]={0xF0FF};
volatile static int16_t un_bg[RING_BUFFER_SIZE/4]={0xF0FF};
volatile static int16_t deux_bg[RING_BUFFER_SIZE/4]={0xF0FF};
volatile static int16_t trois_bg[RING_BUFFER_SIZE/4]={0xF0FF};
volatile static int16_t quatre_bg[RING_BUFFER_SIZE/4]={0xF0FF};
volatile static int16_t cinq_bg[RING_BUFFER_SIZE/4]={0xF0FF};
////////////////////////////////////////
volatile static int16_t zero_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t un_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t deux_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t trois_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t quatre_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t cinq_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t six_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t sept_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t huit_bd[RING_BUFFER_SIZE/4]={0xFF0F};
volatile static int16_t neuf_bd[RING_BUFFER_SIZE/4]={0xFF0F};
////////////////////////////////////////
volatile static int16_t error[RING_BUFFER_SIZE/4]={0xFFFF};
volatile static int16_t nothing[RING_BUFFER_SIZE/4]={0};

void setup_const();

void digit_in_buffer(struct ring_buffer *rb, volatile int16_t data[RING_BUFFER_SIZE/4], int16_t quart);

void hour_digit_in_buffer(struct ring_buffer *rb, int8_t h, int8_t m);

#endif