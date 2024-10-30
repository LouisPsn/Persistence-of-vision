/*
Allumage et éteignage de la led c
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= (1 << PD6); // PD6 en sortie

    while (1){
        
        PORTD |= (1 << PD6); // PD6 à 1
        _delay_ms(500);

        PORTD &= ~(1 << PD6); // PD6 à 0
        _delay_ms(500);
    }
}