#include "../Functions_in_h/functions_print_word.h"

/*
void print_hello(int16_t tic, int16_t tic_par_tour, int16_t offset){
    H(tic, tic_par_tour, offset);
    E(tic, tic_par_tour, offset-6);
    L(tic, tic_par_tour, offset-2*6);
    L(tic, tic_par_tour, offset-3*6);
    O(tic, tic_par_tour, offset-4*6);
}

void print_test(int16_t tic, int16_t tic_par_tour, int16_t offset){
    Z(tic, tic_par_tour, offset);
}
*/

volatile int16_t tic_par_tour = 0;
volatile int16_t tic = 0;
volatile char first = 1;

// Generate an interrupt when the hall sensor detect a magnet
ISR(INT0_vect)
{
    // Code things to do during the interruption, the code should be as short as possible
    tic_par_tour = tic;
    tic = 0;
    first = 0;
}

void print_word(char *str, int16_t tic, int16_t tic_par_tour, int16_t offset)
{
    for (int i = 0; i < strlen(str) && str[i] != '\0'; i++)
    {
        choose_letter(str[i], tic, tic_par_tour, offset - 6 * i);
    }
}

void word(char *str)
{

    while (1)
    {
        tic++;
        if (!first)
        {
            print_word(str, tic, tic_par_tour, 55);
        }
    }
}