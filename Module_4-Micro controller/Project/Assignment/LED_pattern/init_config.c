#include "main.h"

/* Function to initializing the Ports */
void init_config_LED(void)
{
    TRISB = 0x00;       // Making the portb pin as output.
    ADCON1 = 0x0f;      // Making the portb pins as digital.
    PORTB = 0x00;       // Turn off all LED by default.

    // Function call for initializing digital keypad.
    init_keypad();
}