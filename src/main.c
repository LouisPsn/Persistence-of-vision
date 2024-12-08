#include "h/clock.h"
#include "h/hall.h"
#include "h/new_word.h"
#include "h/clock.h"

void setup()
{
    USART_Init(MYUBRR);
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