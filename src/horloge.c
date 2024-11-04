#include <avr/io.h>
#include <util/delay.h>
#include "Functions_in_h/functions_SPI_led.h"
#include "Functions_in_h/functions_hall.h"
#include "Functions_in_h/functions_horloge.h"
#include "Functions_in_h/interrupt.h"

void setup(){
    SPI_MasterInit();
    hall_sensor_init();
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