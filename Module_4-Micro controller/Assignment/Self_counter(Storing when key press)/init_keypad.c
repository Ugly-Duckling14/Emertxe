#include "main.h"

// Configuring digital keypad. 
void init_keypad(void)
{
    TRISC = TRISC | 0x0f;
}

// Reading input from switches.
unsigned int read_inputs()
{
    unsigned static char once = 1;

    if( (KEY_PORT & INPUT_PINS ) && once )
    {
        once = 0;
        return KEY_PORT & INPUT_PINS;
    }
    else
        once = 1;
    
    return 0xFF; 
}