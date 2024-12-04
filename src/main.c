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

//volatile char state = 0;
volatile bool need_load_buffer = false;
volatile bool need_incr_hour = false;

ISR(INT0_vect)
{
    tic_par_tour = read_timer_16();
    clear_timer_16();
    first = 0;
    position = 0;
}

ISR(TIMER0_COMPA_vect)
{
    time_ms++;
    if (time_ms >= 6500)
    {
        time_ms = 0;
        need_incr_hour = true;
        need_load_buffer = true;
    }
}

void setup()
{
    SPI_MasterInit();
    hall_sensor_init();
    init_clock_time();
    init_clock_aff();
    sei();

    setup_hour(3, 25, 30);

}

void loop()
{
    tic = read_timer_16();
    if (!first)
    {
        if (((position) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (position + 1) * (tic_par_tour / RING_BUFFER_SIZE)))
        {
            SPI_MasterTransmit_us(ring_buffer_get_2(&rb, position), 10); //(int) time_ms_per_turn/(RING_BUFFER_SIZE)
            position++;
        }

        if (need_incr_hour)
        {
            incr_hour();
            need_incr_hour=false;
        }

        if (need_load_buffer)
        {
            horloge_in_buffer();
            need_load_buffer = false;
        }
    }
}

void main()
{
    setup();
    while (1)
    {
        loop();
    }
}