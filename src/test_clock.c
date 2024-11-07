#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

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

void transmit_txt(unsigned char *txt)
{
    int i = 0;
    while (txt[i] != '\0')
    {
        USART_Transmit(txt[i]);
        i++;
    }
}

void transmit_number(int num)
{
    int val[10];
    int counter = 0;
    while (num >= 10)
    {
        val[counter] = num % 10;
        num /= 10;
        counter++;
    }

    for (int i = 9; i >= 0; i--)
    {
        USART_Transmit(val[i] + 48);
    }
}

void init_clock()
{
    TCCR1A = (0 << COM1A1) | (1 << COM1A0) | (1 << WGM11) | (1 << WGM10);
    TCCR1B = (0 << WGM13) | (0 << WGM12) | (1 << CS12) | (0 << CS11) | (1 << CS10);
}

void main()
{
    USART_Init(MYUBRR);
    init_clock();

    while (1)
    {
        unsigned int i = TCNT1;
        transmit_txt("TCNT1 : ");
        transmit_number(TCNT1);
        USART_Transmit('\n');
        transmit_txt("OCR1A : ");
        transmit_number(OCR1A);
        USART_Transmit('\n');
    }
}