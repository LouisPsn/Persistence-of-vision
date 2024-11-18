#include "../h/bluetooth.h"
#include "../h/clock.h"

void main()
{
    USART_Init(MYUBRR);
    init_clock();

    while (1)
    {
        transmit_txt("Second : ", 9);
        transmit_number(time/1000);
        USART_Transmit('\n');

        _delay_ms(1000);
    }
}