/* Allumage de LED par SPI */

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define DDR_SPI DDRB
#define DD_SS PB2
#define DD_MOSI PB3
#define DD_SCK PB5
#define DD_OE PC1
#define DD_LE PC2
#define DD_HALL PD2

#define FOSC 13000000 // Clock Speed
#define BAUD 38400
#define MYUBRR FOSC / 16 / BAUD - 1

#define FRAME_DELAY 105

uint16_t printable[360] = {0b1111111111111111};

int hour = 0;
int minute = 0;
int second = 0;

int i_print_led;

char test_time[6] = "000000";

void reset_printable()
{
    for (int i = 0; i < 360; i++)
    {
        printable[i] = 0b0000000000000000;
    }
}

void time_to_printable(char *time)
{
    int hour = (time[0] - 48) * 10 + time[1] - 48;
    if (hour >= 12)
    {
        hour -= 12;
    }
    int minute = (time[2] - 48) * 10 + time[3] - 48;
    int second = (time[4] - 48) * 10 + time[5] - 48;

    printable[hour * 30 + minute / 2] = 0b1111111100000000;
    printable[minute * 6 + second / 10] = 0b1111111101111111;
    for (int i = 0; i < second * 6; i += 6)
    {
        printable[i] = printable[i] | 0b0000000010000000;
    }
}

void wait_1_frame()
{
    _delay_us(FRAME_DELAY);
}

void wait_1_turn()
{
    for (int i = 0; i < 360; i++)
    {
        wait_1_frame();
    }
}

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

unsigned char USART_Receive(void)
{
    /* Wait for data to be received */
    while (!(UCSR0A & (1 << RXC0)))
        ;
    /* Get and return received data from buffer */
    return UDR0;
}

void transmit_txt(unsigned char *txt, int lenght)
{
    for (int i; i < lenght; i++)
    {
        USART_Transmit(txt[i]);
    }
}

void transmit_number(unsigned int num)
{
    int tab[12];
    int counter = 0;
    while (num > 10)
    {
        tab[counter] = num % 10 + 48;
        num = num / 10;
        counter++;
    }
    tab[counter] = num % 10 + 48;
    while (counter >= 0)
    {
        USART_Transmit(tab[counter]);
        counter--;
    }
    USART_Transmit('\n');
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
    SPCR = (1 << SPE) | (0 << DORD) | (1 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);
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

void MBI5024_SendData(int data)
{
    // Make DD_OE port at 0
    PORTC &= ~(1 << DD_OE);

    // Separation of 8 first bits and the 8 next bits into two 8 bits data
    unsigned char data1 = data & 0xFF;
    unsigned char data2 = (data >> 8) & 0xFF;

    SPI_MasterTransmit(data1);
    SPI_MasterTransmit(data2);

    // Make DD_LE port at 1
    PORTC |= (1 << DD_LE);
    // Make DD_LE port at 0
    PORTC &= ~(1 << DD_LE);

    // Make DD_OE port at 1
    PORTC |= (1 << DD_OE);
}

// Set INT0 to fall edge of DD_HALL
void hall_sensor_init()
{
    EICRA |= (0 << ISC00);
    EICRA |= (1 << ISC01);
    EIMSK |= (1 << INT0);
}

void print_led()
{
    for (int i = 359; i >= 0; i--)
    {
        MBI5024_SendData(printable[i]);
        MBI5024_SendData(0b0000000000000000);
        wait_1_frame();
    }
}

// Generate an interrupt when the hall sensor detect a magnet
ISR(INT0_vect)
{
    reset_printable();
    time_to_printable("222340");
    print_led();
}

void main(void)
{
    DDRC |= (1 << DD_OE) | (1 << DD_LE);    // DD_OE et DD_LE en sortie
    DDRB |= (1 << DD_MOSI) | (1 << DD_SCK); // DD_MOSI, DD_SCK en sortie

    // Make DD_OE port at 0
    PORTC &= ~(1 << DD_OE);
    // Make DD_LE port at 0
    PORTC &= ~(1 << DD_LE);

    // Initialize connexion with hall sensor
    DDRD &= ~(1 << DD_HALL);
    PORTD |= (1 << DD_HALL);

    // Initialize SPI as master
    USART_Init(MYUBRR);
    SPI_MasterInit();

    hall_sensor_init();
    ISR(INT0_vect);

    sei();

    while (1)
    {
        wait_1_turn();
    }
}