/* Allumage de LED par SPI */

#include <avr/io.h>
#include <util/delay.h>

#define DDR_SPI DDRB
#define DD_SS PB2
#define DD_MOSI PB3
#define DD_SCK PB5
#define DD_OE PC1
#define DD_LE PC2

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

void USART_Transmit(unsigned char data)
{
    /* Wait for empty transmit buffer */
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

void transmit_txt(unsigned char *txt, int lenght)
{
    for (int i; i < lenght; i++)
    {
        USART_Transmit(txt[i]);
    }
}

void transmit_reg(int reg)
{
    USART_Transmit(reg + 48);
}

void SPI_MasterInit(void)
{
    /* Set MOSI and SCK output, all others input */
    DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK) | (1 << DD_SS);
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (1 << SPR0);
}

void SPI_MasterTransmit(char cData)
{
    /* Start transmission */
    SPDR = cData;
    /* Wait for transmission complete */
    int counter = 0;
    while (!(SPSR & (1 << SPIF)))
        ;
}

void MBI5024_SendData(char data1, char data2)
{
    SPI_MasterTransmit(data1);
    SPI_MasterTransmit(data2);

    // Make DD_LE port at 1
    PORTC |= (1 << DD_LE);
    // Make DD_LE port at 0
    PORTC &= ~(1 << DD_LE);

    // Make DD_OE port at 1
    PORTC |= (1 << DD_OE);
    _delay_ms(25);
    // Make DD_OE port at 0
    PORTC &= ~(1 << DD_OE);
}

void main(void)
{
    // _delay_ms(5000);

    DDRC |= (1 << DD_OE) | (1 << DD_LE);    // DD_OE et DD_LE en sortie
    DDRB |= (1 << DD_MOSI) | (1 << DD_SCK); // DD_MOSI, DD_SCK en sortie

    // Make DD_OE port at 0
    PORTC &= ~(1 << DD_OE);
    // Make DD_LE port at 0
    PORTC &= ~(1 << DD_LE);

    // Initialize SPI as master
    USART_Init(MYUBRR);
    SPI_MasterInit();

    while (1)
    {
        MBI5024_SendData(0b10000000, 0b00000000);
        MBI5024_SendData(0b01000000, 0b00000000);
        MBI5024_SendData(0b00100000, 0b00000000);
        MBI5024_SendData(0b00010000, 0b00000000);
        MBI5024_SendData(0b00001000, 0b00000000);
        MBI5024_SendData(0b00000100, 0b00000000);
        MBI5024_SendData(0b00000010, 0b00000000);
        MBI5024_SendData(0b00000001, 0b00000000);
        MBI5024_SendData(0b00000000, 0b10000000);
        MBI5024_SendData(0b00000000, 0b01000000);
        MBI5024_SendData(0b00000000, 0b00100000);
        MBI5024_SendData(0b00000000, 0b00010000);
        MBI5024_SendData(0b00000000, 0b00001000);
        MBI5024_SendData(0b00000000, 0b00000100);
        MBI5024_SendData(0b00000000, 0b00000010);
        MBI5024_SendData(0b00000000, 0b00000001);

        MBI5024_SendData(0b00000000, 0b00000001);
        MBI5024_SendData(0b00000000, 0b00000010);
        MBI5024_SendData(0b00000000, 0b00000100);
        MBI5024_SendData(0b00000000, 0b00001000);
        MBI5024_SendData(0b00000000, 0b00010000);
        MBI5024_SendData(0b00000000, 0b00100000);
        MBI5024_SendData(0b00000000, 0b01000000);
        MBI5024_SendData(0b00000000, 0b10000000);
        MBI5024_SendData(0b00000001, 0b00000000);
        MBI5024_SendData(0b00000010, 0b00000000);
        MBI5024_SendData(0b00000100, 0b00000000);
        MBI5024_SendData(0b00001000, 0b00000000);
        MBI5024_SendData(0b00010000, 0b00000000);
        MBI5024_SendData(0b00100000, 0b00000000);
        MBI5024_SendData(0b01000000, 0b00000000);
        MBI5024_SendData(0b10000000, 0b00000000);
    }
}