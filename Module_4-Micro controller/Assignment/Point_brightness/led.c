#include "main.h"

// Function definition to initialize the led configuration.
void init_led(void)
{
    ADCON1 = 0x0F;
    TRISB = 0x00;
    PORTB = 0x00;
}
