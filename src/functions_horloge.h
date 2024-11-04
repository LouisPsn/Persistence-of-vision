#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"
#include "functions_hall.h"
#include <stdbool.h>

#ifndef FUNCTIONS_HORLOGE_H
#define FUNCTIONS_HORLOGE_H

void horloge_trigo(){
    volatile int16_t tic_par_tour = 0;
    volatile int16_t tic = 0;
    volatile char first=1;
    volatile int8_t sec = 0;
    volatile int8_t min = 10;

    while(1){
        if(!read_state_hall()){
            tic_par_tour=tic;
            tic=0;
            while(!read_state_hall()){SPI_MasterTransmit_us(0x8000,1);}
            first=0;
        }
        else{
            tic++;
            if(tic==100){
                sec++;
                if(sec==60){
                    min++;
                    sec=0;
                    if(min==60){
                        min=0;
                    }
                }
            }
            if(!first){
                if(tic== (int) (/*tic_par_tour/2 + */ min*tic_par_tour/60)){ // la grande aiguille
                    SPI_MasterTransmit_us(0xFFFF,10);
                }
                else if(tic == (int) (/*tic_par_tour/2 + */ sec*tic_par_tour/60)){ // la grande aiguille
                    SPI_MasterTransmit_us(0x80FF,10);
                }
                else{
                    SPI_MasterTransmit_us(0x8000,10);
                }
            }
        }
    }
}


void horloge_2(){
    volatile int16_t tic_par_tour = 0;
    volatile int16_t tic = 0;
    volatile int8_t sec = 0;
    volatile int8_t min = 10;
    volatile char first = 1;
    volatile char save = read_state_hall();

    while(1){
        if(save==0 && read_state_hall()==1){
            tic_par_tour=tic;
            tic=0;
            if(first){first=0;}
        }
        save=read_state_hall();
        tic++;
        if(tic==10){
            sec++;
            if(sec==60){
                min++;
                sec=0;
                if(min==60){
                    min=0;
                }
            }
        }
        if(first==0){
            if(tic== (int) (/*tic_par_tour/2 + */ min*tic_par_tour/60)){ // la grande aiguille
                SPI_MasterTransmit_us(0xFFFF,2);
            }
            else if(tic == (int) (/*tic_par_tour/2 + */ sec*tic_par_tour/60)){ // la petite aiguille
                SPI_MasterTransmit_us(0x80FF,2);
            }
            else{
                SPI_MasterTransmit_us(0x8000,2);
            }
        }

    }
}

void test_horloge(){
    if(!read_state_hall()){
        SPI_MasterTransmit_ms(0xFFFF,1);
    }
    else{
        SPI_MasterTransmit_ms(0x0000,1);
    }
}


#endif