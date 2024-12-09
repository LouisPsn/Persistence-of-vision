#include "../h/old_letter.h"

void A(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0880,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0880,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0880,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void B(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0090,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0090,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0090,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x00F0,30);
    }
}

void C(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
}

void D(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x00F0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0090,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0090,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0090,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void E(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
}

void F(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
}

void G(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x09F0,30);
    }
}



void H(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0100,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0100,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0100,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void I(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
}

void J(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
}

void K(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0180,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0240,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0420,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
}


void L(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
}

void M(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0400,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0200,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x00400,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void N(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0600,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0180,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0060,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void O(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0810,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void P(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0F00,30);
    }
}

void Q(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0F00,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0900,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void R(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0980,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0940,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0920,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0F10,30);
    }
}

void S(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0F10,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0910,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x09F0,30);
    }
}

void T(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0800,30);
    }
}

void U(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void V(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0E00,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x01E0,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0010,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x01E0,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0E00,30);
    }
}

void W(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0020,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0040,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0020,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0FF0,30);
    }
}

void X(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0C30,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x03C0,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x03C0,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x00C30,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0000,30);
    }
}

void Y(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0C30,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x03C0,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0300,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0C00,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0000,30);
    }
}

void Z(int16_t tic, int16_t tic_par_tour, int16_t offset){
    if(((offset-1) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0830,30);
    }
    else if(((offset-2) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-1) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x00870,30);
    }
    else if(((offset-3) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-2) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0990,30);
    }
    else if(((offset-4) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-3) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0E10,30);
    }
    else if(((offset-5) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (offset-4) * (tic_par_tour / RING_BUFFER_SIZE))){ 
        SPI_MasterTransmit_us_clock(0x0C10,30);
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
