#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "h/clock.h"
#include "h/buffer.h"
#include "h/SPI_led.h"
#include "h/hall.h"
#include "h/new_word.h"
#include "h/interrupt.h"
#include "h/clock.h"

volatile char state = 0;
/*
state = 0b00 : horloge in buffer
state = 0b01 : old letter
*/




void setup()
{
    SPI_MasterInit();
    hall_sensor_init();
    init_clock_time();
    init_clock_aff();
    setup_hour(3, 25, 30);
    sei();
}

void loop()
{
    display_buffer();
}

void main()
{
    setup();
    while (1)
    {
        loop();
    }
}