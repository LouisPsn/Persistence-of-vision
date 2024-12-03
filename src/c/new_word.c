#include "../h/clock.h"
#include "../h/new_word.h"
#include "../h/buffer.h"

volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile char first = 1;
volatile int16_t position = 0;
struct ring_buffer rb;

volatile int8_t sec = 0;
volatile int8_t min = 0;
volatile int8_t heures = 0;

volatile long long last_time_ms = 0;
volatile long long time_ms_per_turn = 0;

// Generate an interrupt when the hall sensor detect a magnet
ISR(INT0_vect)
{
    // Code things to do during the interruption, the code should be as short as possible
    tic_par_tour = read_timer_16();
    clear_timer_16();
    first = 0;
    position = 0;
    // time_ms_per_turn = time_ms - last_time_ms;
    // last_time_ms = time_ms;
    horloge_in_buffer();
}

ISR(TIMER0_COMPA_vect)
{
    time_ms++;
    if (time_ms == 6500)
    {
        time_ms = 0;
        if (sec == 59)
        {
            sec = 0;
            if (min == 59)
            {
                min = 0;
                if (heures == 11)
                {
                    heures = 0;
                }
                else
                {
                    heures++;
                }
            }
            else
            {
                min++;
            }
        }
        else
        {
            sec++;
        }
    }
}

void horloge_in_buffer()
{
    clear_buffer(&rb);
    for (int i = 0; i < RING_BUFFER_SIZE; i++)
    {
        if (i == (int)min)
        { 
            ring_buffer_put_2(&rb, 0b0000000011111111, i);
        }
        else if (i == (int)heures*6)
        { 
            ring_buffer_put_2(&rb, 0b0000111111111110, i);
        }
        else if(i == (int)sec)
        {
            ring_buffer_put_2(&rb, 0b1111111111111111, i);
        }
    }
}

void new_horloge()
{
    min = 25;
    heures = 3;
    sec=30;

    // clear_buffer(&rb);

    horloge_in_buffer();

    while (1)
    {
        tic = read_timer_16();
        if (!first)
        {
            if (((position) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (position + 1) * (tic_par_tour / RING_BUFFER_SIZE)))
            {
                SPI_MasterTransmit_us(ring_buffer_get_2(&rb, position), 10); //(int) time_ms_per_turn/(RING_BUFFER_SIZE)
                position++;
            }
        }
    }
}

void new_word()
{
    ring_buffer_init(&rb);
    for (int i = 0; i < RING_BUFFER_SIZE; i++)
    {
        ring_buffer_put(&rb, 0xFFFF);
    }

    while (1)
    {
        tic++;
        if (!first)
        {
            if (1)
            {
                SPI_MasterTransmit_us(ring_buffer_get(&rb), 1);
                position++;
            }
        }
    }
}
