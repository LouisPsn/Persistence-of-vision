#include "../h/clock.h"

// Function that initialize clock to generate 3250Hz signal in Clear Timer on Compare Match (CTC) Mode, f clk_I/O = 13MHz, N = 8, TOP = 249
void init_clock_time()
{
    // Set Fast PWM Mode
    TCCR0A |= (1 << WGM01) | (0 << WGM00);
    TCCR0B |= (0 << WGM02);

    // Set Prescaler to 8
    TCCR0B |= (0 << CS02) | (1 << CS01) | (0 << CS00);

    // Set TOP to 249
    OCR0A = 249;

    // Set interruptions on overflow and input capture
    TIMSK0 |= (1 << OCIE0A);
    // TIFR0 |= (1 << OCF0A);
}


void init_clock_routine()
{
    // Set Fast PWM Mode
    TCCR1A |= (1 << WGM11) | (1 << WGM10);
    TCCR1B |= (1 << WGM13) | (1 << WGM12);

    // Set Prescaler to 8
    TCCR1B |= (0 << CS12) | (1 << CS11) | (1 << CS10);

    // Set TOP to 1624
    OCR1A = 40624;

    // Set interruptions on overflow and input capture
    TIMSK1 |= (1 << TOIE1);
}