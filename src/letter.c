#include <avr/io.h>
#include <util/delay.h>
#include "Functions_in_h/functions_SPI_led.h"
#include "Functions_in_h/functions_hall.h"
#include "Functions_in_h/functions_print_word.h"
#include "Functions_in_h/interrupt.h"


void setup(){
    SPI_MasterInit();
    hall_sensor_init();
    sei();
}

void loop(){
    word("arthurosssssssssssss");
}

int main(void){
    setup();
    while(1){
        loop();
    }
}