#include "functions_print_word.h"

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

void print_word(char *str, int16_t tic, int16_t tic_par_tour, int16_t offset) {
    for (int i = 0; i < strlen(str) && str[i] != '\0'; i++) {
        choose_letter(str[i], tic, tic_par_tour, offset - 6 * i);
    }
}

void word(char * str){
    volatile int16_t tic_par_tour = 0;
    volatile int16_t tic = 0;
    volatile char first=1;

    while(1){
        if(!read_state_hall()){
            tic_par_tour=tic;
            tic=0;
            while(!read_state_hall()){}
            first=0;
        }
        else{
            tic++;
            if(!first){
                print_word(str, tic, tic_par_tour, 55);
            }
        }
    }
}


#endif