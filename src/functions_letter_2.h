#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"
#include "functions_hall.h"
#include <stdbool.h>

#ifndef FUNCTIONS_LETTER_2_H
#define FUNCTIONS_LETTER_2_H

void A(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0880,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0880,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0880,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void B(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0090,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0090,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0090,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x00F0,10);
    }
}

void C(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
}

void D(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x00F0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0090,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0090,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0090,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void E(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
}

void F(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
}

void G(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x09F0,10);
    }
}



void H(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0100,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0100,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0100,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void I(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
}

void J(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
}

void K(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0180,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0240,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0420,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
}


void L(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
}

void M(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0400,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0200,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x00400,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void N(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0600,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0180,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0060,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void O(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0810,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void P(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0F00,10);
    }
}

void Q(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0F00,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0900,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void R(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0980,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0940,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0920,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0F10,10);
    }
}

void S(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0F10,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0910,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x09F0,10);
    }
}

void T(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0800,10);
    }
}

void U(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void V(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0E00,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x01E0,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0010,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x01E0,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0E00,10);
    }
}

void W(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0020,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0040,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0020,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0FF0,10);
    }
}

void X(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0C30,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x03C0,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x03C0,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x00C30,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0000,10);
    }
}

void Y(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0C30,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x03C0,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0300,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0C00,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0000,10);
    }
}

void Z(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(tic== (int) (offset)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0830,10);
    }
    else if(tic==(int) (offset-1)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x00870,10);
    }
    else if(tic==(int) (offset-2)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0990,10);
    }
    else if(tic==(int) (offset-3)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0E10,10);
    }
    else if(tic==(int) (offset-4)*(tic_par_tour/60)){ 
        SPI_MasterTransmit_us(0x0C10,10);
    }
}

void choose_letter(char letter, int16_t tic, int16_t tic_par_tour, int16_t offset){
    switch (letter) {
        case 'a':
            A(tic, tic_par_tour, offset);
            break;
        case 'b':
            B(tic, tic_par_tour, offset);
            break;
        case 'c':
            C(tic, tic_par_tour, offset);
            break;
        case 'd':
            D(tic, tic_par_tour, offset);
            break;
        case 'e':
            E(tic, tic_par_tour, offset);
            break;
        case 'f':
            F(tic, tic_par_tour, offset);
            break;
        case 'g':
            G(tic, tic_par_tour, offset);
            break;
        case 'h':
            H(tic, tic_par_tour, offset);
            break;
        case 'i':
            I(tic, tic_par_tour, offset);
            break;
        case 'j':
            J(tic, tic_par_tour, offset);
            break;
        case 'k':
            K(tic, tic_par_tour, offset);
            break;
        case 'l':
            L(tic, tic_par_tour, offset);
            break;
        case 'm':
            M(tic, tic_par_tour, offset);
            break;
        case 'n':
            N(tic, tic_par_tour, offset);
            break;
        case 'o':
            O(tic, tic_par_tour, offset);
            break;
        case 'p':
            P(tic, tic_par_tour, offset);
            break;
        case 'q':
            Q(tic, tic_par_tour, offset);
            break;
        case 'r':
            R(tic, tic_par_tour, offset);
            break;
        case 's':
            S(tic, tic_par_tour, offset);
            break;
        case 't':
            T(tic, tic_par_tour, offset);
            break;
        case 'u':
            U(tic, tic_par_tour, offset);
            break;
        case 'v':
            V(tic, tic_par_tour, offset);
            break;
        case 'w':
            W(tic, tic_par_tour, offset);
            break;
        case 'x':
            X(tic, tic_par_tour, offset);
            break;
        case 'y':
            Y(tic, tic_par_tour, offset);
            break;
        case 'z':
            Z(tic, tic_par_tour, offset);
            break;

        default:
            break;
    }
}


#endif