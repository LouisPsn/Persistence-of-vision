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
#include <string.h>
#include "h/bluetooth.h"

#define BUFFER_SIZE 60

volatile char state = 0;
/*
state = 0b00 : horloge in buffer
state = 0b01 : old letter
*/
volatile bool need_load_buffer = false;
volatile bool need_incr_hour = false;

// static volatile int16_t position = 1;
static struct ring_buffer rb_receive;

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

// boolean to check if data is received
static volatile char data_received = 0;

char command_buffer[BUFFER_SIZE];
uint8_t command_index = 0;

ISR(USART_RX_vect)
{
    ring_buffer_put(&rb_receive, USART_Receive());

}

void parse_command(char *command)
{
    if (strncmp(command, "set ", 4) == 0 && strlen(command) == 11)
    {
        //  convert the string to int
        int8_t h = (command[4]-48)*10 + (command[5]-48);
        int8_t m = (command[6]-48)*10 + (command[7]-48);
        int8_t s = (command[8]-48)*10 + (command[9]-48);
        setup_hour(h, m, s);
        transmit_txt("time set", 8);
    }
    else if (strncmp(command, "word ", 5) == 0 && strlen(command) > 5)
    {
        // display the word
        transmit_txt(command + 5, strlen(command) - 5);
        // TODO
    }
    // give time
    else if (strncmp(command, "time", 4) == 0)
    {
        char time[8];
        // TODO
        // transmit_txt(time, 8);
    }
    else
    {
        transmit_txt("command not found", 17);
    }
}

void parse_data()
{
    while (rb_has_data(&rb_receive))
    {
        char c = ring_buffer_get(&rb_receive);
        if (c == '\n')
        {
            command_buffer[command_index] = '\0';
            command_index = 0;
            // call the function to parse the command
            parse_command(command_buffer);
        }
        else
        {
            command_buffer[command_index] = c;
            command_index++;
        }
    }
}

void setup()
{
    // init a ring buffer for received data
    ring_buffer_init(&rb_receive);

    USART_Init(MYUBRR);
    SPI_MasterInit();
    hall_sensor_init();
    init_clock_time();
    init_clock_aff();
    setup_hour(3, 25, 30);
    load_mario();
    sei();
}

void loop()
{
    tic = read_timer_16();
    if (rb_has_data(&rb_receive))
    {
        parse_data();
    }
    if (!first)
    {
        
        if (state == 0b00)
        {
            if (((position) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (position + 1) * (tic_par_tour / RING_BUFFER_SIZE)))
            {
                SPI_MasterTransmit_us(ring_buffer_get_2(&rb, position), 10); //(int) time_ms_per_turn/(RING_BUFFER_SIZE)
                position++;
            }

            if (need_incr_hour)
            {
                incr_hour();
                need_incr_hour = false;
            }

            if (need_load_buffer)
            {
                horloge_in_buffer();
                need_load_buffer = false;
            }
        }
        //load_mario();
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