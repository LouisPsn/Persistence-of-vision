#include <avr/io.h>
#include <util/delay.h>


#ifndef FUNCTIONS_HALL_H
#define FUNCTIONS_HALL_H

void hall_init(void){
    DDRD &= ~(1 << PD2); // PD2 en entrée, c'est le capteur à effet hall
}

char read_state_hall(void){
    if( (PIND&(1 << PD2))== (1 << PD2) ){
        return 1;
    }
    else{
        return 0;
    }
}

#endif