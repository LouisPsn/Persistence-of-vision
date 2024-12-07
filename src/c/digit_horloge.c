#include "../h/digit_horloge.h"

void setup_const()
{

}

void digit_in_buffer(struct ring_buffer *rb, volatile int16_t data[RING_BUFFER_SIZE / 4], int16_t quart)
{
    for (int i = 0; i < RING_BUFFER_SIZE / 4; i++)
    {
        ring_buffer_put_2(rb, data[i], i + quart * RING_BUFFER_SIZE / 4);
    }
}

void hour_digit_in_buffer(struct ring_buffer *rb, int8_t h, int8_t m)
{
    // premier quart, dixaine des heures
    if (h < 10)
    {
        digit_in_buffer(rb, zero_hg, 0);
    }
    else
    {
        digit_in_buffer(rb, un_hg, 0);
    }
    // deuxime quart, unitée des heures
    h = h % 10;
    switch (h)
    {
    case 0:
        digit_in_buffer(rb, zero_hd, 1);
        break;
    case 1:
        digit_in_buffer(rb, un_hd, 1);
        break;
    case 2:
        digit_in_buffer(rb, deux_hd, 1);
        break;
    case 3:
        digit_in_buffer(rb, trois_hd, 1);
        break;
    case 4:
        digit_in_buffer(rb, quatre_hd, 1);
        break;
    case 5:
        digit_in_buffer(rb, cinq_hd, 1);
        break;
    case 6:
        digit_in_buffer(rb, six_hd, 1);
        break;
    case 7:
        digit_in_buffer(rb, sept_hd, 1);
        break;
    case 8:
        digit_in_buffer(rb, huit_hd, 1);
        break;
    case 9:
        digit_in_buffer(rb, neuf_hd, 1);
        break;
    default:
        digit_in_buffer(rb, error, 1);
        break;
    }
    // quatrieme quart, dixaine des minutes
    if (m < 10)
    {
        digit_in_buffer(rb, zero_bg, 3);
    }
    else if (m < 20)
    {
        digit_in_buffer(rb, un_bg, 3);
    }
    else if (m < 30)
    {
        digit_in_buffer(rb, deux_bg, 3);
    }
    else if (m < 30)
    {
        digit_in_buffer(rb, trois_bg, 3);
    }
    else if (m < 50)
    {
        digit_in_buffer(rb, quatre_bg, 3);
    }
    else if (m < 60)
    {
        digit_in_buffer(rb, cinq_bg, 3);
    }
    else
    {
        digit_in_buffer(rb, error, 3);
    }
    // troisième quart, unitée des minutes
    m = m % 10;
    switch (m)
    {
    case 0:
        digit_in_buffer(rb, zero_bd, 2);
        break;
    case 1:
        digit_in_buffer(rb, un_bd, 2);
        break;
    case 2:
        digit_in_buffer(rb, deux_bd, 2);
        break;
    case 3:
        digit_in_buffer(rb, trois_bd, 2);
        break;
    case 4:
        digit_in_buffer(rb, quatre_bd, 2);
        break;
    case 5:
        digit_in_buffer(rb, cinq_bd, 2);
        break;
    case 6:
        digit_in_buffer(rb, six_bd, 2);
        break;
    case 7:
        digit_in_buffer(rb, sept_bd, 2);
        break;
    case 8:
        digit_in_buffer(rb, huit_bd, 2);
        break;
    case 9:
        digit_in_buffer(rb, neuf_bd, 2);
        break;
    default:
        digit_in_buffer(rb, error, 2);
        break;
    }
}