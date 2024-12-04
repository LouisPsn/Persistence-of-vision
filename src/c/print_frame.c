#include "print_frame.h"


// Generate an interrupt when the hall sensor detect a magnet
ISR(INT0_vect)
{
    // Code things to do during the interruption, the code should be as short as possible
    tic_par_tour = tic;
    tic = 0;
    first = 0;
}

void print_led()
{
    tic++;
    if (tic == 100)
    {
        sec++;
        if (sec == 60)
        {
            min++;
            sec = 0;
            if (min == 60)
            {
                min = 0;
            }
        }
    }
    if (!first)
    {
        if (tic == (int)(/*tic_par_tour/2 + */ min * tic_par_tour / 60))
        { // la grande aiguille
            SPI_MasterTransmit_us(0xFFFF, 10);
        }
        else if (tic == (int)(/*tic_par_tour/2 + */ sec * tic_par_tour / 60))
        { // la grande aiguille
            SPI_MasterTransmit_us(0x80FF, 10);
        }
        else
        {
            SPI_MasterTransmit_us(0x8000, 10);
        }
    }
}