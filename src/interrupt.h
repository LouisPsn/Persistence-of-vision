#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void hall_sensor_init();

ISR(INT0_vect);