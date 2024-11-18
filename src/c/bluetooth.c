#include "../h/bluetooth.h"

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

void transmit_number(long long num)
{
    int val[10] = {0};
    int counter = 0;
    while (num > 10)
    {
        val[counter] = num % 10;
        num /= 10;
        counter++;
    }
    if (num == 10)
    {
        val[counter] = 0;
        counter++;
        val[counter] = 1;
    }
    else {
        val[counter] = num;
    }

    for (int i = 9; i >= 0; i--)
    {
        USART_Transmit(val[i] + 48);
    }
}