// led.c
#include <avr/io.h>
#include <util/delay.h>

void delay()
{
    _delay_ms(1);
}

int main(void)
{
    DDRD |= (1 << PD6); // PD6 en sortie
    while (1)
    {
        ;
        for (int i = 1; i < 100; i++)
        {
            PORTD |= (1 << PD6); // PD6 à 1
            for (int j = 0; j < i; j++)
            {
                delay();
            }
            PORTD &= ~(1 << PD6); // PD6 à 1
            for (int j = 0; j < i; j++)
            {
                delay();
            }
        }
        for (int i = 99; i > 0; i--)
        {
            PORTD |= (1 << PD6); // PD6 à 1
            for (int j = 0; j < i; j++)
            {
                delay();
            }
            PORTD &= ~(1 << PD6); // PD6 à 1
            for (int j = 0; j < i; j++)
            {
                delay();
            }
        }
    }
}