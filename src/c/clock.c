#include <avr/interrupt.h>
#include "../h/clock.h"

// Function that initialize clock to generate 1000Hz signal in Fast PWM Mode, f clk_I/O = 13MHz, N = 8, TOP = 1624
void init_clock()
{
    // Set Fast PWM Mode
    TCCR1A |= (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM13) | (1 << WGM12);

    // Set Prescaler to 8
    TCCR1B |= (0 << CS12) | (1 << CS11) | (0 << CS10);

    // Set TOP to 6500
    OCR1A = 1624;

    // Set interruptions on overflow and input capture
    TIMSK1 |= (1 << TOIE1);

    sei();
}