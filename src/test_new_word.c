#include <avr/io.h>
#include <util/delay.h>
#include "h/SPI_led.h"
#include "h/hall.h"
#include "h/new_word.h"
#include "h/interrupt.h"

void setup()
{
    SPI_MasterInit();
    hall_sensor_init();
    sei();
}

void loop()
{
    new_word();
}

int main(void)
{
    setup();
    while (1)
    {
        loop();
    }
}