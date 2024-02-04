#include "main.h"

extern unsigned char once;

// Function definition to configure digital keypad.
void init_keypad(void)
{
    TRISC = TRISC | 0x0f;
}

// Function definition for read digital keypad.
unsigned int read_inputs()
{
    // State change switch
    if( (KEY_PORT & INPUT_PINS) &&  once)
    {
        once = 0;
        return KEY_PORT & INPUT_PINS;
    }
    else if( (KEY_PORT & INPUT_PINS) == ALL_RELEASED )
    {
        once = 1;
    }
}