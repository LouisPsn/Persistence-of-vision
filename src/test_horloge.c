#include <avr/io.h>
#include <util/delay.h>
#include "h/SPI_led.h"
#include "h/hall.h"
#include "h/horloge.h"
#include "h/interrupt.h"

void setup(){
    SPI_MasterInit();
    hall_sensor_init();
    init_clock();
    sei();
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