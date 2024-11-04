#include <avr/io.h>
#include <util/delay.h>
#include "functions_SPI_led.h"
#include "functions_hall.h"
#include "functions_letter_1.h"

void setup(){
    SPI_MasterInit();
    hall_init();
}

void loop(){
    word("eirbototo");
}

int main(void){
    setup();
    while(1){
        loop();
    }
}