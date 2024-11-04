#include <avr/io.h>
#include <util/delay.h>

#define DDR_SPI     DDRB
#define SS          PC2   //tres important
#define DD_MOSI     PB3
#define DD_SCK      PB5
#define LE          PC2
#define OE          PC1

#ifndef FUNCTIONS_SPI_LED_H
#define FUNCTIONS_SPI_LED_H

void SPI_MasterInit(void){
    /* Set MOSI and SCK output, all others input */
    DDR_SPI = (1<<DD_MOSI)|(1<<DD_SCK)|(1<<SS); //|(1<<DD_MISO)
    /* Enable SPI, Master, set clock rate fck/16 */
    SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);

    DDRC |= (1 << LE); // PC2 en sortie, c'est LE
    DDRC |= (1 << OE); // PC1 en sortie, c'est OE

    PRR &= ~(1<<PRSPI);
}

void SPI_MasterTransmit_us(int16_t cData, int16_t d){
    PORTC |= (1 << OE); //
    _delay_us(10);

    // Transmettre les 8 bits de poids fort
    SPDR = (cData >> 8) & 0xFF; 
    while(!(SPSR & (1<<SPIF))){}

    // Transmettre les 8 bits de poids faible
    SPDR = cData & 0xFF; 
    while(!(SPSR & (1<<SPIF))){}

    PORTC |= (1 << LE);
    _delay_us(1);

    PORTC &= ~(1 << LE);;
    //_delay_us(1);

    PORTC &= ~(1 << OE);
    for(int i=0; i<d; i++ ){_delay_us(1);}

    PORTC |= (1 << OE);
    //for(int i=0; i<d; i++ ){_delay_ms(1);}
    //_delay_us(10);
}

void SPI_MasterTransmit_ms(int16_t cData, int16_t d){
    PORTC |= (1 << OE); //
    _delay_us(10);

    // Transmettre les 8 bits de poids fort
    SPDR = (cData >> 8) & 0xFF; 
    while(!(SPSR & (1<<SPIF))){}

    // Transmettre les 8 bits de poids faible
    SPDR = cData & 0xFF; 
    while(!(SPSR & (1<<SPIF))){}

    PORTC |= (1 << LE);
    _delay_us(1);

    PORTC &= ~(1 << LE);;
    //_delay_us(1);

    PORTC &= ~(1 << OE);
    for(int i=0; i<d; i++ ){_delay_ms(1);}

    PORTC |= (1 << OE);
    //for(int i=0; i<d; i++ ){_delay_ms(1);}
    //_delay_us(10);
}

void SPI_MasterTransmit(int16_t cData, int16_t d){
    PORTC |= (1 << OE); //
    _delay_us(10);

    // Transmettre les 8 bits de poids fort
    SPDR = (cData >> 8) & 0xFF; 
    while(!(SPSR & (1<<SPIF))){}

    // Transmettre les 8 bits de poids faible
    SPDR = cData & 0xFF; 
    while(!(SPSR & (1<<SPIF))){}

    PORTC |= (1 << LE);
    _delay_us(1);

    PORTC &= ~(1 << LE);;
    _delay_us(1);

    PORTC &= ~(1 << OE);
    for(int i=0; i<d; i++ ){_delay_us(1);}

    PORTC |= (1 << OE);
    //for(int i=0; i<d; i++ ){_delay_ms(1);}
    //_delay_us(10);horloge_trigo();
}

#endif