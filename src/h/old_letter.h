#ifndef LETTER_H
#define LETTER_H

#include <avr/io.h>
#include <util/delay.h>
#include "SPI_led.h"
#include "hall.h"
#include <stdbool.h>
#include "buffer.h"



void A(int16_t tic, int16_t tic_par_tour, int16_t offset);

void B(int16_t tic, int16_t tic_par_tour, int16_t offset);

void C(int16_t tic, int16_t tic_par_tour, int16_t offset);

void D(int16_t tic, int16_t tic_par_tour, int16_t offset);

void E(int16_t tic, int16_t tic_par_tour, int16_t offset);

void F(int16_t tic, int16_t tic_par_tour, int16_t offset);

void G(int16_t tic, int16_t tic_par_tour, int16_t offset);

void H(int16_t tic, int16_t tic_par_tour, int16_t offset);

void I(int16_t tic, int16_t tic_par_tour, int16_t offset);

void J(int16_t tic, int16_t tic_par_tour, int16_t offset);

void K(int16_t tic, int16_t tic_par_tour, int16_t offset);

void L(int16_t tic, int16_t tic_par_tour, int16_t offset);

void M(int16_t tic, int16_t tic_par_tour, int16_t offset);

void N(int16_t tic, int16_t tic_par_tour, int16_t offset);

void O(int16_t tic, int16_t tic_par_tour, int16_t offset);

void P(int16_t tic, int16_t tic_par_tour, int16_t offset);

void Q(int16_t tic, int16_t tic_par_tour, int16_t offset);

void R(int16_t tic, int16_t tic_par_tour, int16_t offset);

void S(int16_t tic, int16_t tic_par_tour, int16_t offset);

void T(int16_t tic, int16_t tic_par_tour, int16_t offset);

void U(int16_t tic, int16_t tic_par_tour, int16_t offset);

void V(int16_t tic, int16_t tic_par_tour, int16_t offset);

void W(int16_t tic, int16_t tic_par_tour, int16_t offset);

void X(int16_t tic, int16_t tic_par_tour, int16_t offset);

void Y(int16_t tic, int16_t tic_par_tour, int16_t offset);

void Z(int16_t tic, int16_t tic_par_tour, int16_t offset);

void choose_letter(char letter, int16_t tic, int16_t tic_par_tour, int16_t offset);

#endif