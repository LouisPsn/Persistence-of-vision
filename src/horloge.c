#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"
#include "functions_hall.h"
#include "functions_horloge.h"

void setup(){
    SPI_MasterInit();
    hall_init();
}

void loop(){
    horloge_trigo();
}

int main(void){
    setup();
    while(1){
        loop();
    }
}