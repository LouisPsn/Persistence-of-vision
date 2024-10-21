/*
Allumage et éteignage de la led PD6 
quand capteur hall est activé
*/

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD &= ~(1 << PD6); // PD6 en sortie
    DDRD &= ~(1 << PD2); // PD2 en entrée

    while (1){
        if (PIND & (1 << PD2)){ //PIND read, PORTD write
            PORTD &= ~(1 << PD6); // PD6 à 0
        }
        else{
            PORTD |= (1 << PD6); // PD6 à 1
        }
    }
}