#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"

void setup(){
    SPI_MasterInit();
}

void loop(){
    SPI_MasterTransmit_ms(0x8000, 1000);
    _delay_ms(20000);
    SPI_MasterTransmit_ms(0x0001, 1000);
    _delay_ms(20000);
}

int main(void){
    setup();
    while(1){
        loop();
    }
}
