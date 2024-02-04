#include "main.h"

void init_keypad(void)
{
    TRISC = TRISC | 0x0f;
}

// Function definition for read inputs.
unsigned int read_inputs()
{
    return KEY_PORT & INPUT_PINS; 
}
