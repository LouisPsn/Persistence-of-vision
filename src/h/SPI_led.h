#ifndef FUNCTIONS_SPI_LED_H
#define FUNCTIONS_SPI_LED_H

#include <avr/io.h>
#include <util/delay.h>

#define DDR_SPI DDRB
#define SS PC2 // tres important
#define DD_MOSI PB3
#define DD_SCK PB5
#define LE PC2
#define OE PC1

void SPI_MasterInit(void);

void SPI_MasterTransmit_us(int16_t cData, int16_t d);

void SPI_MasterTransmit_us_clock(int16_t cData, int16_t d);

void SPI_MasterTransmit_ms(int16_t cData, int16_t d);

void SPI_MasterTransmit(int16_t cData, int16_t d);

#endif