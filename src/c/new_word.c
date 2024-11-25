#include "../h/new_word.h"
#include "../h/buffer.h"

volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile char first = 1;
volatile int16_t position = 1;
struct ring_buffer rb;

// Generate an interrupt when the hall sensor detect a magnet
ISR(INT0_vect)
{
    // Code things to do during the interruption, the code should be as short as possible
    tic_par_tour = tic;
    tic = 0;
    first = 0;
    position=1;
}

/*
void print_word(char *str, int16_t tic, int16_t tic_par_tour, int16_t offset)
{
    for (int i = 0; i < strlen(str) && str[i] != '\0'; i++)
    {
        choose_letter(str[i], tic, tic_par_tour, offset - 6 * i);
    }
}
*/

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
            if (tic == (int)(position) * (tic_par_tour / RING_BUFFER_SIZE))
            {
                SPI_MasterTransmit_us(ring_buffer_get(&rb), 10);
                position++;
            }
        }
    }
}
