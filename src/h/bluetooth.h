/* Communication par bluetooth */

#ifndef BLUETOOTH_H
#define BLUETOOTH_H

#include <avr/io.h>
#include <util/delay.h>

#define FOSC 13000000 // Clock Speed
#define BAUD 38400
#define MYUBRR FOSC / 16 / BAUD - 1

void USART_Init(unsigned int ubrr);

unsigned char USART_Receive(void);

void USART_Transmit(unsigned char data);

void transmit_txt(unsigned char* txt, int lenght);

void transmit_number(long long num);

#endif