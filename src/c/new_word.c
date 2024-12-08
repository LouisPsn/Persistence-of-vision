#include "../h/clock.h"
#include "../h/new_word.h"
#include "../h/buffer.h"

/*
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
    if (time_ms >= 6500)
    {
        time_ms = 0;
        if (sec >= 59)
        {
            sec = 0;
            if (min >= 59)
            {
                min = 0;
                if (heures >= 11)
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
*/

void setup_hour(int8_t h, int8_t m, int8_t s)
{
    sec = s;
    min = m;
    heures = h;
}

void incr_hour()
{
    if (sec >= 59)
    {
        sec = 0;
        if (min >= 59)
        {
            min = 0;
            if (heures >= 11)
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

void horloge_in_buffer()
{
    clear_buffer(&rb);
    for (int i = 0; i < RING_BUFFER_SIZE; i++)
    {
        if (i == (int)RING_BUFFER_SIZE-sec)
        {
            ring_buffer_put_2(&rb, 0b1111111111111111, i);
        }
        else if (i == (int)RING_BUFFER_SIZE-min)
        {
            ring_buffer_put_2(&rb, 0b0000111111111110, i);
        }
        else if (i == (int)RING_BUFFER_SIZE-heures * 5)
        {
            ring_buffer_put_2(&rb, 0b0000000011111111, i);
        }
    }
}

void new_horloge()
{
    min = 25;
    heures = 3;
    sec = 30;

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

void load_mario()
{
    ring_buffer_put_2(&rb, 0b0000001111111111, 0);
    ring_buffer_put_2(&rb, 0b0000000111111111, 1);
    ring_buffer_put_2(&rb, 0b0000001111111111, 2);
    ring_buffer_put_2(&rb, 0b0000000111111111, 3);
    ring_buffer_put_2(&rb, 0b0000001000001111, 4);
    ring_buffer_put_2(&rb, 0b0000000000000000, 5);
    ring_buffer_put_2(&rb, 0b0000000000000000, 6);
    ring_buffer_put_2(&rb, 0b0000000001100000, 7);
    ring_buffer_put_2(&rb, 0b0000000001100000, 8);
    ring_buffer_put_2(&rb, 0b0000000001000000, 9);
    ring_buffer_put_2(&rb, 0b0000000000000000, 10);
    ring_buffer_put_2(&rb, 0b0000000000000000, 11);
    ring_buffer_put_2(&rb, 0b0000000000000000, 12);
    ring_buffer_put_2(&rb, 0b0000000000000000, 13);
    ring_buffer_put_2(&rb, 0b0000000000000000, 14);
    ring_buffer_put_2(&rb, 0b0000000000000000, 15);
    ring_buffer_put_2(&rb, 0b0000000000000000, 16);
    ring_buffer_put_2(&rb, 0b0000000000000000, 17);
    ring_buffer_put_2(&rb, 0b0000000000000000, 18);
    ring_buffer_put_2(&rb, 0b0000000000000000, 19);
    ring_buffer_put_2(&rb, 0b0000000010000000, 20);
    ring_buffer_put_2(&rb, 0b0000000010000001, 21);
    ring_buffer_put_2(&rb, 0b0000000000000000, 22);
    ring_buffer_put_2(&rb, 0b0000000000000000, 23);
    ring_buffer_put_2(&rb, 0b0000000000000000, 24);
    ring_buffer_put_2(&rb, 0b0000010000000111, 25);
    ring_buffer_put_2(&rb, 0b0000011111111111, 26);
    ring_buffer_put_2(&rb, 0b0000011111111111, 27);
    ring_buffer_put_2(&rb, 0b0000011111111111, 28);
    ring_buffer_put_2(&rb, 0b0000001111111111, 29);
    ring_buffer_put_2(&rb, 0b0000000111111111, 30);
    ring_buffer_put_2(&rb, 0b0000000111111111, 31);
    ring_buffer_put_2(&rb, 0b0000000011111111, 32);
    ring_buffer_put_2(&rb, 0b0000000001111111, 33);
    ring_buffer_put_2(&rb, 0b0000000001111111, 34);
    ring_buffer_put_2(&rb, 0b0000000001111111, 35);
    ring_buffer_put_2(&rb, 0b0000000000111111, 36);
    ring_buffer_put_2(&rb, 0b0000000000011111, 37);
    ring_buffer_put_2(&rb, 0b0000000000001111, 38);
    ring_buffer_put_2(&rb, 0b0000000000000111, 39);
    ring_buffer_put_2(&rb, 0b0100000000000011, 40);
    ring_buffer_put_2(&rb, 0b1100000000000001, 41);
    ring_buffer_put_2(&rb, 0b1100000000000000, 42);
    ring_buffer_put_2(&rb, 0b1110000000001100, 43);
    ring_buffer_put_2(&rb, 0b1110000000011010, 44);
    ring_buffer_put_2(&rb, 0b1110000000011010, 45);
    ring_buffer_put_2(&rb, 0b1111000000001100, 46);
    ring_buffer_put_2(&rb, 0b1110000000000000, 47);
    ring_buffer_put_2(&rb, 0b1110000000000001, 48);
    ring_buffer_put_2(&rb, 0b1110000000000001, 49);
    ring_buffer_put_2(&rb, 0b1110000000000011, 50);
    ring_buffer_put_2(&rb, 0b1110001000000111, 51);
    ring_buffer_put_2(&rb, 0b1110001100001111, 52);
    ring_buffer_put_2(&rb, 0b1110011100011111, 53);
    ring_buffer_put_2(&rb, 0b1110111011111111, 54);
    ring_buffer_put_2(&rb, 0b1111010000111111, 55);
    ring_buffer_put_2(&rb, 0b0100001000111111, 56);
    ring_buffer_put_2(&rb, 0b0000001011111111, 57);
    ring_buffer_put_2(&rb, 0b0000001111111111, 58);
    ring_buffer_put_2(&rb, 0b0000001111111111, 59);
}