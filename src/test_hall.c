/* Communication par bluetooth */

#include <avr/io.h>
#include <util/delay.h>

#define DD_HALL PD2

#define FOSC 13000000 // Clock Speed
#define BAUD 38400
#define MYUBRR FOSC / 16 / BAUD - 1

void USART_Init(unsigned int ubrr)
{
    /*Set baud rate */
    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;
    /* Enable receiver and transmitter */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    /* Set frame format: 8data, 2stop bit */
    UCSR0C = (1 << USBS0) | (3 << UCSZ00);
}

unsigned char USART_Receive(void)
{
    /* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)))
        ;
    /* Get and return received data from buffer */
    return UDR0;
}

void USART_Transmit(unsigned char data)
{
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

void transmit_txt(unsigned char* txt, int lenght)
{
    for(int i; i < lenght; i++) {
        USART_Transmit(txt[i]);
    }
}


uint8_t detect_magnet()
{
    uint8_t value = PIND & (1 << DD_HALL);
    return value;
}


void main(void)
{
    DDRD &= ~(1 << DD_HALL);
    PORTD |= (1 << DD_HALL);

    USART_Init(MYUBRR);
    while (1)
    {
        transmit_txt("Valeur hall : ", 14);
        USART_Transmit(detect_magnet() + 48);
        transmit_txt("\n", 1);
    }
}