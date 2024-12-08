#include "../h/word.h"


volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile char first = 1;

void print_word(char *str, int16_t tic, int16_t tic_par_tour, int16_t offset)
{
    for (int i = 0; i < strlen(str) && str[i] != '\0'; i++)
    {
        choose_letter(str[i], tic, tic_par_tour, offset - 6 * i);
    }
}