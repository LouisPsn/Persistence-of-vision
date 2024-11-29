#include "../h/horloge.h"

// // Generate an interrupt when the hall sensor detect a magnet
// ISR(INT0_vect)
// {
//     // Code things to do during the interruption, the code should be as short as possible
//     tic_par_tour = tic;
//     tic = 0;
//     first = 0;
// }

// ISR(TIMER1_OVF_vect)
// {
//     time_ms++;
// }



void horloge_trigo()
{
    tic++;
    sec = time_ms / 1000;
    if (sec >= 60)
    {
        time_ms = 0;
        sec = 0;
        min++;
    }
    if (min == 60)
    {
        min = 0;
        heures++;
    }
    if (heures >= 12)
    {
        heures = heures - 12;
    }

    if (!first)
    {
        if (tic_par_tour - tic <= (int)(/*tic_par_tour/2 + */ sec * tic_par_tour / 60))
        { // rond extérieur, aiguille des secondes
            SPI_MasterTransmit_us(0b1000000000000000, 10);
        }
        if (tic_par_tour - tic == (int)(/*tic_par_tour/2 + */ heures * tic_par_tour / 12))
        { // la petite aiguille, aiguille des heurs
            SPI_MasterTransmit_us(0b0000000011111111, 10);
        }
        if (tic_par_tour - tic == (int)(/*tic_par_tour/2 + */ min * tic_par_tour / 60))
        { // la grande aiguille, aiguille des minutes
            SPI_MasterTransmit_us(0b1111111111111110, 10);
        }
    }
}

void horloge_2()
{
    volatile char save = read_state_hall();

    while (1)
    {
        if (save == 0 && read_state_hall() == 1)
        {
            tic_par_tour = tic;
            tic = 0;
            if (first)
            {
                first = 0;
            }
        }
        save = read_state_hall();
        tic++;
        if (tic == 10)
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
        if (first == 0)
        {
            if (tic == (int)(/*tic_par_tour/2 + */ min * tic_par_tour / 60))
            { // la grande aiguille
                SPI_MasterTransmit_us(0xFFFF, 2);
            }
            else if (tic == (int)(/*tic_par_tour/2 + */ sec * tic_par_tour / 60))
            { // la petite aiguille
                SPI_MasterTransmit_us(0x80FF, 2);
            }
            else
            {
                SPI_MasterTransmit_us(0x8000, 2);
            }
        }
    }
}

void test_horloge()
{
    if (!read_state_hall())
    {
        SPI_MasterTransmit_ms(0xFFFF, 1);
    }
    else
    {
        SPI_MasterTransmit_ms(0x0000, 1);
    }
}