/*
Allumage et éteignage de la led
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= (1 << PD6); // PB5 en sortie

    while (1){
        
        PORTD |= (1 << PD6); // PB5 à 1
        _delay_ms(500);

        PORTD &= ~(1 << PD6); // PB5 à 0
        _delay_ms(500);
    }
}