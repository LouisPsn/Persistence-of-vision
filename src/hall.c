#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRD |= (1 << PD6); // PD6 en sortie, c'est la led
    DDRD &= ~(1 << PD2); // PD2 en entrée, c'est le capteur à effet hall
    //volatile char state_led=0;

    while (1){

        if( (PIND&(1 << PD2))== (1 << PD2) ){
            PORTD |= (1 << PD6); // PD6 à 1
        }
        else{
            PORTD &= ~(1 << PD6); // PD6 à 0
        }
    }
}