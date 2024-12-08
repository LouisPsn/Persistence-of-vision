#include "../h/new_word.h"

char word_received[WORD_SIZE_MAX] = {0};

ISR(INT0_vect)
{
    tic_par_tour = read_timer_16();
    clear_timer_16();
    first = 0;
    position = 0;
    time_us_per_turn = tic_par_tour * 1000000 / 203125 * 2;
}

ISR(TIMER0_COMPA_vect)
{
    time_ms++;
    if (time_ms >= 6500)
    {
        time_ms = 0;
        need_incr_hour = true;
        if (state == 0b00)
        {
            need_load_buffer = true;
        }
    }
}

ISR(USART_RX_vect)
{
    ring_buffer_put(&rb_receive, USART_Receive());
}

void parse_command()
{
    if (strncmp(command_buffer, "set ", 4) == 0 && strlen(command_buffer) == 11)
    {
        state = 0b00;
        //  convert the string to int
        int8_t h = (command_buffer[4] - 48) * 10 + (command_buffer[5] - 48);
        int8_t m = (command_buffer[6] - 48) * 10 + (command_buffer[7] - 48);
        int8_t s = (command_buffer[8] - 48) * 10 + (command_buffer[9] - 48);
        while (h > 11)
        {
            h -= 12;
        }
        while (m > 59)
        {
            m -= 60;
        }
        while (s > 59)
        {
            s -= 60;
        }

        setup_hour(h, m, s);
        transmit_txt("time set", 8);
    }
    else if (strncmp(command_buffer, "word ", 5) == 0 && strlen(command_buffer) > 5)
    {
        // display the word
        // transmit_txt(command_buffer + 5, strlen(command_buffer) - 5);
        state = 0b01;

        clear_buffer(&rb);

        for (int i = 0; i < WORD_SIZE_MAX; i++)
        {
            word_received[i] = 0;
        }

        transmit_number(strlen(word_received));
        USART_Transmit('\n');

        int i = 0;
        while (command_buffer[i + 5] != '\0')
        {
            word_received[i] = command_buffer[i + 5];
            // if (i < strlen(command_buffer) - 5)
            // {
            //     word_received[i] = command_buffer[i + 5];
            // }
            // else
            // {
            //     word_received[i] = 0;
            // }
            i++;
        }

        transmit_txt(word_received, strlen(command_buffer) - 5);
    }
    else if (strncmp(command_buffer, "image ", 6) == 0 && strlen(command_buffer) > 6)
    {
        state = 0b11;
        if (command_buffer[6] == 'm')
        {
            state_img = 0;
        }
        if (command_buffer[6] == 'o')
        {
            state_img = 1;
        }
        if (command_buffer[6] == 'c')
        {
            state_img = 2;
        }

        need_load_buffer = true;
        // if (command[7] == 'm') {
        //     state_img = 0;
        // }
        // if (command[7] == 'o') {
        //     state_img = 0;
        // }
        // if (command[7] == 'c') {
        //     state_img = 0;
        // }
    }
    // give time
    else if (strncmp(command_buffer, "time", 4) == 0)
    {
        state = 0b00;
        char time[8];
        horloge_in_buffer();
        // TODO
        // transmit_txt(time, 8);
    }
    else if (strncmp(command_buffer, "turn_time", 9) == 0)
    {
        state = 0b00;
        transmit_number(tic_par_tour*1000000/203125);
        USART_Transmit('\n');
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
            parse_command();
        }
        else
        {
            command_buffer[command_index] = c;
            command_index++;
        }
    }
}

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
        if (i == (int)RING_BUFFER_SIZE - sec * RING_BUFFER_SIZE / 60)
        {
            ring_buffer_put_2(&rb, 0b1111111111111111, i);
        }
        else if (i == (int)RING_BUFFER_SIZE - min * RING_BUFFER_SIZE / 60)
        {
            ring_buffer_put_2(&rb, 0b0000111111111110, i);
        }
        else if (i == (int)RING_BUFFER_SIZE - heures * RING_BUFFER_SIZE / 12)
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

void load_mario()
{
    clear_buffer(&rb);
    ring_buffer_put_2(&rb, 0b0100100000000011, 0);
    ring_buffer_put_2(&rb, 0b0100100000000011, 1);
    ring_buffer_put_2(&rb, 0b0000000000000111, 2);
    ring_buffer_put_2(&rb, 0b0011000000001111, 3);
    ring_buffer_put_2(&rb, 0b0000000000000111, 4);
    ring_buffer_put_2(&rb, 0b0000000000000111, 5);
    ring_buffer_put_2(&rb, 0b1000000000000111, 6);
    ring_buffer_put_2(&rb, 0b1000000000000111, 7);
    ring_buffer_put_2(&rb, 0b1000000000000111, 8);
    ring_buffer_put_2(&rb, 0b1100000000000111, 9);
    ring_buffer_put_2(&rb, 0b1100000000000111, 10);
    ring_buffer_put_2(&rb, 0b1110000000000111, 11);
    ring_buffer_put_2(&rb, 0b1110000001000111, 12);
    ring_buffer_put_2(&rb, 0b1111000011000111, 13);
    ring_buffer_put_2(&rb, 0b1111100011000111, 14);
    ring_buffer_put_2(&rb, 0b1111110001100111, 15);
    ring_buffer_put_2(&rb, 0b1111110001110111, 16);
    ring_buffer_put_2(&rb, 0b1111111000110111, 17);
    ring_buffer_put_2(&rb, 0b1111110000101111, 18);
    ring_buffer_put_2(&rb, 0b1111110000000010, 19);
    ring_buffer_put_2(&rb, 0b1111110000000010, 20);
    ring_buffer_put_2(&rb, 0b1111111001000000, 21);
    ring_buffer_put_2(&rb, 0b1111111111000000, 22);
    ring_buffer_put_2(&rb, 0b1111111111000000, 23);
    ring_buffer_put_2(&rb, 0b1111111111000000, 24);
    ring_buffer_put_2(&rb, 0b1111111111000000, 25);
    ring_buffer_put_2(&rb, 0b1111111110000000, 26);
    ring_buffer_put_2(&rb, 0b1111111110000000, 27);
    ring_buffer_put_2(&rb, 0b1111111110000000, 28);
    ring_buffer_put_2(&rb, 0b1111111110000000, 29);
    ring_buffer_put_2(&rb, 0b1111111110000000, 30);
    ring_buffer_put_2(&rb, 0b1111000011000000, 31);
    ring_buffer_put_2(&rb, 0b1110000001000000, 32);
    ring_buffer_put_2(&rb, 0b1000000000000000, 33);
    ring_buffer_put_2(&rb, 0b0000000000000000, 34);
    ring_buffer_put_2(&rb, 0b0000000000000000, 35);
    ring_buffer_put_2(&rb, 0b0000000000000000, 36);
    ring_buffer_put_2(&rb, 0b0000011000000000, 37);
    ring_buffer_put_2(&rb, 0b0000011000000000, 38);
    ring_buffer_put_2(&rb, 0b0000011000000000, 39);
    ring_buffer_put_2(&rb, 0b0000001000000000, 40);
    ring_buffer_put_2(&rb, 0b0000000000000000, 41);
    ring_buffer_put_2(&rb, 0b0000000000000000, 42);
    ring_buffer_put_2(&rb, 0b0000000000000000, 43);
    ring_buffer_put_2(&rb, 0b0000000000000000, 44);
    ring_buffer_put_2(&rb, 0b0000000000000000, 45);
    ring_buffer_put_2(&rb, 0b0000000000000000, 46);
    ring_buffer_put_2(&rb, 0b0000000000000000, 47);
    ring_buffer_put_2(&rb, 0b0000000000000000, 48);
    ring_buffer_put_2(&rb, 0b0000000000000000, 49);
    ring_buffer_put_2(&rb, 0b0000000000000000, 50);
    ring_buffer_put_2(&rb, 0b0000000000000000, 51);
    ring_buffer_put_2(&rb, 0b0000000000000000, 52);
    ring_buffer_put_2(&rb, 0b0000000000000000, 53);
    ring_buffer_put_2(&rb, 0b0000000000000000, 54);
    ring_buffer_put_2(&rb, 0b0000000000000000, 55);
    ring_buffer_put_2(&rb, 0b0000000000000000, 56);
    ring_buffer_put_2(&rb, 0b0000000100000000, 57);
    ring_buffer_put_2(&rb, 0b0000000100000000, 58);
    ring_buffer_put_2(&rb, 0b0000001100000000, 59);
    ring_buffer_put_2(&rb, 0b1000000100000000, 60);
    ring_buffer_put_2(&rb, 0b0000000100000000, 61);
    ring_buffer_put_2(&rb, 0b0000000000000000, 62);
    ring_buffer_put_2(&rb, 0b0000000000000000, 63);
    ring_buffer_put_2(&rb, 0b0000000000000000, 64);
    ring_buffer_put_2(&rb, 0b0000000000000000, 65);
    ring_buffer_put_2(&rb, 0b1000000000100000, 66);
    ring_buffer_put_2(&rb, 0b1110000001100000, 67);
    ring_buffer_put_2(&rb, 0b1111111111100000, 68);
    ring_buffer_put_2(&rb, 0b1111111111100000, 69);
    ring_buffer_put_2(&rb, 0b1111111111100000, 70);
    ring_buffer_put_2(&rb, 0b1111111111100000, 71);
    ring_buffer_put_2(&rb, 0b1111111111100000, 72);
    ring_buffer_put_2(&rb, 0b1111111111000000, 73);
    ring_buffer_put_2(&rb, 0b1111111111000000, 74);
    ring_buffer_put_2(&rb, 0b1111111110000000, 75);
    ring_buffer_put_2(&rb, 0b1111111110000000, 76);
    ring_buffer_put_2(&rb, 0b1111111100000000, 77);
    ring_buffer_put_2(&rb, 0b1111111100000000, 78);
    ring_buffer_put_2(&rb, 0b1111111000000000, 79);
    ring_buffer_put_2(&rb, 0b1111111000000000, 80);
    ring_buffer_put_2(&rb, 0b1111111000000000, 81);
    ring_buffer_put_2(&rb, 0b1111111000000000, 82);
    ring_buffer_put_2(&rb, 0b1111111000000000, 83);
    ring_buffer_put_2(&rb, 0b1111111000000000, 84);
    ring_buffer_put_2(&rb, 0b1111110000000000, 85);
    ring_buffer_put_2(&rb, 0b1111100000000000, 86);
    ring_buffer_put_2(&rb, 0b1111000000000000, 87);
    ring_buffer_put_2(&rb, 0b1111000000000000, 88);
    ring_buffer_put_2(&rb, 0b1110000000000000, 89);
    ring_buffer_put_2(&rb, 0b1110000000000000, 90);
    ring_buffer_put_2(&rb, 0b1100000000000010, 91);
    ring_buffer_put_2(&rb, 0b1100000000000010, 92);
    ring_buffer_put_2(&rb, 0b1000000000000011, 93);
    ring_buffer_put_2(&rb, 0b1000000000000011, 94);
    ring_buffer_put_2(&rb, 0b0000000000000011, 95);
    ring_buffer_put_2(&rb, 0b0000000000000011, 96);
    ring_buffer_put_2(&rb, 0b0010000000000011, 97);
    ring_buffer_put_2(&rb, 0b0000100000000011, 98);
    ring_buffer_put_2(&rb, 0b0100100000000011, 99);
    need_load_buffer = true;
}

void load_croix_occitane()
{
    clear_buffer(&rb);
    ring_buffer_put_2(&rb, 0b0111100000000000, 0);
    ring_buffer_put_2(&rb, 0b0111110000000000, 1);
    ring_buffer_put_2(&rb, 0b0000111000000000, 2);
    ring_buffer_put_2(&rb, 0b0000011000000000, 3);
    ring_buffer_put_2(&rb, 0b0000011000111111, 4);
    ring_buffer_put_2(&rb, 0b0000011111111111, 5);
    ring_buffer_put_2(&rb, 0b0000111111111111, 6);
    ring_buffer_put_2(&rb, 0b0011111111111111, 7);
    ring_buffer_put_2(&rb, 0b0011110000001111, 8);
    ring_buffer_put_2(&rb, 0b0001110000000111, 9);
    ring_buffer_put_2(&rb, 0b0000000000000011, 10);
    ring_buffer_put_2(&rb, 0b0000000000000011, 11);
    ring_buffer_put_2(&rb, 0b0000000000000001, 12);
    ring_buffer_put_2(&rb, 0b0000000000000011, 13);
    ring_buffer_put_2(&rb, 0b0000000000000011, 14);
    ring_buffer_put_2(&rb, 0b0001100000000111, 15);
    ring_buffer_put_2(&rb, 0b0011110000001111, 16);
    ring_buffer_put_2(&rb, 0b0011111111111111, 17);
    ring_buffer_put_2(&rb, 0b0001111111111111, 18);
    ring_buffer_put_2(&rb, 0b0000011111111111, 19);
    ring_buffer_put_2(&rb, 0b0000011001111111, 20);
    ring_buffer_put_2(&rb, 0b0000011000000000, 21);
    ring_buffer_put_2(&rb, 0b0000011000000000, 22);
    ring_buffer_put_2(&rb, 0b0011111000000000, 23);
    ring_buffer_put_2(&rb, 0b0111110000000000, 24);
    ring_buffer_put_2(&rb, 0b0111100000000000, 25);
    ring_buffer_put_2(&rb, 0b0111110000000000, 26);
    ring_buffer_put_2(&rb, 0b0000111000000000, 27);
    ring_buffer_put_2(&rb, 0b0000011000000000, 28);
    ring_buffer_put_2(&rb, 0b0000011000011110, 29);
    ring_buffer_put_2(&rb, 0b0000011111111111, 30);
    ring_buffer_put_2(&rb, 0b0000111111111111, 31);
    ring_buffer_put_2(&rb, 0b0001111111111111, 32);
    ring_buffer_put_2(&rb, 0b0011110000011111, 33);
    ring_buffer_put_2(&rb, 0b0001110000000111, 34);
    ring_buffer_put_2(&rb, 0b0000000000000111, 35);
    ring_buffer_put_2(&rb, 0b0000000000000011, 36);
    ring_buffer_put_2(&rb, 0b0000000000000011, 37);
    ring_buffer_put_2(&rb, 0b0000000000000001, 38);
    ring_buffer_put_2(&rb, 0b0000000000000011, 39);
    ring_buffer_put_2(&rb, 0b0001100000000011, 40);
    ring_buffer_put_2(&rb, 0b0011110000000111, 41);
    ring_buffer_put_2(&rb, 0b0011111100111111, 42);
    ring_buffer_put_2(&rb, 0b0001111111111111, 43);
    ring_buffer_put_2(&rb, 0b0000011111111111, 44);
    ring_buffer_put_2(&rb, 0b0000011001111111, 45);
    ring_buffer_put_2(&rb, 0b0000011000000110, 46);
    ring_buffer_put_2(&rb, 0b0000011000000000, 47);
    ring_buffer_put_2(&rb, 0b0110110000000000, 48);
    ring_buffer_put_2(&rb, 0b0111110000000000, 49);
    ring_buffer_put_2(&rb, 0b0111100000000000, 50);
    ring_buffer_put_2(&rb, 0b0011110000000000, 51);
    ring_buffer_put_2(&rb, 0b0000011000000000, 52);
    ring_buffer_put_2(&rb, 0b0000011000000000, 53);
    ring_buffer_put_2(&rb, 0b0000011000001100, 54);
    ring_buffer_put_2(&rb, 0b0000011111111110, 55);
    ring_buffer_put_2(&rb, 0b0001111111111111, 56);
    ring_buffer_put_2(&rb, 0b0011111111111111, 57);
    ring_buffer_put_2(&rb, 0b0011110000001111, 58);
    ring_buffer_put_2(&rb, 0b0001100000000111, 59);
    ring_buffer_put_2(&rb, 0b0000000000000111, 60);
    ring_buffer_put_2(&rb, 0b0000000000000011, 61);
    load_mario();
    ring_buffer_put_2(&rb, 0b0000000000000011, 62);
    ring_buffer_put_2(&rb, 0b0000000000000011, 63);
    ring_buffer_put_2(&rb, 0b0000000000000011, 64);
    ring_buffer_put_2(&rb, 0b0001100000000111, 65);
    ring_buffer_put_2(&rb, 0b0011110000001111, 66);
    ring_buffer_put_2(&rb, 0b0011111111111111, 67);
    ring_buffer_put_2(&rb, 0b0001111111111111, 68);
    ring_buffer_put_2(&rb, 0b0000011111111111, 69);
    ring_buffer_put_2(&rb, 0b0000011000011110, 70);
    ring_buffer_put_2(&rb, 0b0000011000000000, 71);
    ring_buffer_put_2(&rb, 0b0000010000000000, 72);
    ring_buffer_put_2(&rb, 0b0111110000000000, 73);
    ring_buffer_put_2(&rb, 0b1111100000000000, 74);
    ring_buffer_put_2(&rb, 0b0111100000000000, 75);
    ring_buffer_put_2(&rb, 0b0000110000000000, 76);
    ring_buffer_put_2(&rb, 0b0000011000000000, 77);
    ring_buffer_put_2(&rb, 0b0000011000000000, 78);
    ring_buffer_put_2(&rb, 0b0000011011111111, 79);
    ring_buffer_put_2(&rb, 0b0000011111111111, 80);
    ring_buffer_put_2(&rb, 0b0001111111111111, 81);
    ring_buffer_put_2(&rb, 0b0011110000011111, 82);
    ring_buffer_put_2(&rb, 0b0011100000000111, 83);
    ring_buffer_put_2(&rb, 0b0001100000000011, 84);
    ring_buffer_put_2(&rb, 0b0000000000000011, 85);
    ring_buffer_put_2(&rb, 0b0000000000000011, 86);
    ring_buffer_put_2(&rb, 0b0000000000000011, 87);
    ring_buffer_put_2(&rb, 0b0000000000000011, 88);
    ring_buffer_put_2(&rb, 0b0001100000000111, 89);
    ring_buffer_put_2(&rb, 0b0011110000001111, 90);
    ring_buffer_put_2(&rb, 0b0011111101111111, 91);
    ring_buffer_put_2(&rb, 0b0001111111111111, 92);
    ring_buffer_put_2(&rb, 0b0000011111111111, 93);
    ring_buffer_put_2(&rb, 0b0000011001111110, 94);
    ring_buffer_put_2(&rb, 0b0000011000000000, 95);
    ring_buffer_put_2(&rb, 0b0000011000000000, 96);
    ring_buffer_put_2(&rb, 0b0000110000000000, 97);
    ring_buffer_put_2(&rb, 0b0111110000000000, 98);
    ring_buffer_put_2(&rb, 0b0111100000000000, 99);
    need_load_buffer = true;
}

void load_chirac()
{
    clear_buffer(&rb);
    ring_buffer_put_2(&rb, 0b1010000000000000, 0);
    ring_buffer_put_2(&rb, 0b1010000000000000, 1);
    ring_buffer_put_2(&rb, 0b0010000000000000, 2);
    load_mario();
    ring_buffer_put_2(&rb, 0b0000000000000000, 3);
    ring_buffer_put_2(&rb, 0b0000000011000000, 4);
    ring_buffer_put_2(&rb, 0b0001000000000000, 5);
    ring_buffer_put_2(&rb, 0b0000100000000000, 6);
    ring_buffer_put_2(&rb, 0b0000011000000000, 7);
    ring_buffer_put_2(&rb, 0b0000010100000000, 8);
    ring_buffer_put_2(&rb, 0b0101110000000000, 9);
    ring_buffer_put_2(&rb, 0b1001010100000000, 10);
    ring_buffer_put_2(&rb, 0b1110111010000000, 11);
    ring_buffer_put_2(&rb, 0b1111111010000000, 12);
    ring_buffer_put_2(&rb, 0b1011110000000000, 13);
    ring_buffer_put_2(&rb, 0b1011000001000100, 14);
    ring_buffer_put_2(&rb, 0b1000000000000100, 15);
    ring_buffer_put_2(&rb, 0b0000000000000100, 16);
    ring_buffer_put_2(&rb, 0b0000000000000100, 17);
    ring_buffer_put_2(&rb, 0b0100000000001100, 18);
    ring_buffer_put_2(&rb, 0b1100000000001100, 19);
    ring_buffer_put_2(&rb, 0b1110000000001100, 20);
    ring_buffer_put_2(&rb, 0b0110000000011100, 21);
    ring_buffer_put_2(&rb, 0b0110000000011100, 22);
    ring_buffer_put_2(&rb, 0b1110000000111100, 23);
    ring_buffer_put_2(&rb, 0b1110000011111100, 24);
    ring_buffer_put_2(&rb, 0b1111000011111100, 25);
    ring_buffer_put_2(&rb, 0b1111011111111110, 26);
    ring_buffer_put_2(&rb, 0b1111111111111110, 27);
    ring_buffer_put_2(&rb, 0b1111111111111110, 28);
    ring_buffer_put_2(&rb, 0b1111111111111110, 29);
    ring_buffer_put_2(&rb, 0b0011111111111110, 30);
    ring_buffer_put_2(&rb, 0b1111111111111110, 31);
    ring_buffer_put_2(&rb, 0b1111111111111100, 32);
    ring_buffer_put_2(&rb, 0b1111111111111100, 33);
    ring_buffer_put_2(&rb, 0b1111111111111100, 34);
    ring_buffer_put_2(&rb, 0b1111111111111100, 35);
    ring_buffer_put_2(&rb, 0b1111111111111100, 36);
    ring_buffer_put_2(&rb, 0b1111111111111100, 37);
    ring_buffer_put_2(&rb, 0b1111111111111100, 38);
    ring_buffer_put_2(&rb, 0b1111111111111100, 39);
    ring_buffer_put_2(&rb, 0b1111111111111100, 40);
    ring_buffer_put_2(&rb, 0b1111111111110000, 41);
    ring_buffer_put_2(&rb, 0b1111111111110000, 42);
    ring_buffer_put_2(&rb, 0b1111111111111000, 43);
    ring_buffer_put_2(&rb, 0b1111111111110000, 44);
    ring_buffer_put_2(&rb, 0b1111111111110000, 45);
    ring_buffer_put_2(&rb, 0b1111111111100000, 46);
    ring_buffer_put_2(&rb, 0b1111111111000000, 47);
    ring_buffer_put_2(&rb, 0b1111111110000001, 48);
    ring_buffer_put_2(&rb, 0b1111111100000000, 49);
    ring_buffer_put_2(&rb, 0b1111111011101100, 50);
    ring_buffer_put_2(&rb, 0b1111100100010010, 51);
    ring_buffer_put_2(&rb, 0b1111100011000000, 52);
    ring_buffer_put_2(&rb, 0b1111111000011011, 53);
    ring_buffer_put_2(&rb, 0b1111111111111111, 54);
    ring_buffer_put_2(&rb, 0b1111111111000011, 55);
    ring_buffer_put_2(&rb, 0b1111111111111010, 56);
    ring_buffer_put_2(&rb, 0b1111111111111110, 57);
    ring_buffer_put_2(&rb, 0b1111111111111110, 58);
    ring_buffer_put_2(&rb, 0b1111111111111011, 59);
    ring_buffer_put_2(&rb, 0b1111111111111010, 60);
    ring_buffer_put_2(&rb, 0b1111111111111000, 61);
    ring_buffer_put_2(&rb, 0b1111111111111100, 62);
    ring_buffer_put_2(&rb, 0b1111111111111101, 63);
    ring_buffer_put_2(&rb, 0b1111111111111100, 64);
    ring_buffer_put_2(&rb, 0b1111111111111100, 65);
    ring_buffer_put_2(&rb, 0b1111111110111100, 66);
    ring_buffer_put_2(&rb, 0b1111111111111100, 67);
    ring_buffer_put_2(&rb, 0b1111111111111100, 68);
    ring_buffer_put_2(&rb, 0b1111111111111100, 69);
    ring_buffer_put_2(&rb, 0b1111111111111100, 70);
    ring_buffer_put_2(&rb, 0b1111111111111100, 71);
    ring_buffer_put_2(&rb, 0b0111111111111100, 72);
    ring_buffer_put_2(&rb, 0b0111111111111100, 73);
    ring_buffer_put_2(&rb, 0b0111111111111100, 74);
    ring_buffer_put_2(&rb, 0b0011111111111100, 75);
    ring_buffer_put_2(&rb, 0b0001111111111100, 76);
    ring_buffer_put_2(&rb, 0b0000111111111100, 77);
    ring_buffer_put_2(&rb, 0b0000001111111100, 78);
    ring_buffer_put_2(&rb, 0b1000000111111100, 79);
    ring_buffer_put_2(&rb, 0b1100000011111100, 80);
    ring_buffer_put_2(&rb, 0b0110000001111100, 81);
    ring_buffer_put_2(&rb, 0b0001100000111110, 82);
    ring_buffer_put_2(&rb, 0b0000000000011010, 83);
    ring_buffer_put_2(&rb, 0b1100000000011000, 84);
    ring_buffer_put_2(&rb, 0b1100010100011000, 85);
    ring_buffer_put_2(&rb, 0b1100000110000000, 86);
    ring_buffer_put_2(&rb, 0b1111000110000000, 87);
    ring_buffer_put_2(&rb, 0b0100000010000000, 88);
    ring_buffer_put_2(&rb, 0b0000000000000000, 89);
    ring_buffer_put_2(&rb, 0b0000000000000000, 90);
    ring_buffer_put_2(&rb, 0b0000000100000000, 91);
    ring_buffer_put_2(&rb, 0b0000001000000000, 92);
    ring_buffer_put_2(&rb, 0b0000110000000000, 93);
    ring_buffer_put_2(&rb, 0b0001100000000000, 94);
    ring_buffer_put_2(&rb, 0b0001000000000000, 95);
    ring_buffer_put_2(&rb, 0b0000000000000000, 96);
    ring_buffer_put_2(&rb, 0b0000000000000000, 97);
    ring_buffer_put_2(&rb, 0b0010000000000000, 98);
    ring_buffer_put_2(&rb, 0b1010000000000000, 99);
    need_load_buffer = true;
}

void display_buffer()
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
        else if (state == 0b01)
        {
            print_word(word_received, tic, tic_par_tour, 100);
        }
        else if (state == 0b11)
        {
            if (need_load_buffer)
            {
                if (state_img == 0)
                {
                    load_mario();
                }
                if (state_img == 1)
                {
                    load_croix_occitane();
                }
                if (state_img == 2)
                {
                    load_chirac();
                }
                need_load_buffer = false;
            }
        }
        if (state != 0b01 && ((position) * (tic_par_tour / RING_BUFFER_SIZE) <= tic) && (tic <= (position + 1) * (tic_par_tour / RING_BUFFER_SIZE)))
        {
            SPI_MasterTransmit_us(ring_buffer_get_2(&rb, position), time_us_per_turn / (RING_BUFFER_SIZE)); //(int) time_ms_per_turn/(RING_BUFFER_SIZE)
            position++;
        }
    }
}