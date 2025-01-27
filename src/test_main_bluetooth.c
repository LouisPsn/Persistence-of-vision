#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "h/horloge.h"
#include "h/clock.h"
#include "h/buffer.h"
#include "h/SPI_led.h"
#include "h/hall.h"
#include "h/new_word.h"
#include "h/interrupt.h"
#include "h/clock.h"



static volatile char i_rec = 0;
static volatile int8_t data_h[6] = {0, 0, 0, 0, 0, 0};

ISR(USART_RX_vect)
{
    data_h[i_rec] = USART_Receive();
    data_h[i_rec] -= 48;

    i_rec++;
    if (i_rec > 5)
    {
        i_rec = 0;
    }
}

void main()
{
    USART_Init(MYUBRR);
    SPI_MasterInit();
    hall_sensor_init();
    init_clock_time();
    init_clock_aff();
    sei();

    while (1)
    {

        new_horloge();
    }
}

// static volatile int16_t position = 1;
// static struct ring_buffer rb;

// Generate an interrupt when the hall sensor detect a magnet
// ISR(INT0_vect)
// {
//     // Code things to do during the interruption, the code should be as short as possible
//     tic_par_tour = tic;
//     tic = 0;
//     first = 0;
// }

// ISR(TIMER0_COMPA_vect)
// {
//     time_mod++;
// }

        // if (time_mod != 0 && time_mod % 3250 == 0)
        // {
        // transmit_number(heures);
        // USART_Transmit(' ');
        // transmit_number(min);
        // USART_Transmit(' ');
        // transmit_number(first);
        // USART_Transmit('\n');

        // USART_Transmit(data_h[0] + 48);
        // USART_Transmit(data_h[1] + 48);
        // USART_Transmit(' ');
        // USART_Transmit(data_h[2] + 48);
        // USART_Transmit(data_h[3] + 48);
        // USART_Transmit(' ');
        // USART_Transmit(data_h[4] + 48);
        // USART_Transmit(data_h[5] + 48);
        // USART_Transmit('\n');
        // }
        // heures = data_h[0] * 10 + data_h[1];
        // min = data_h[2] * 10 + data_h[3];
        // sec = data_h[4] * 10 + data_h[5];