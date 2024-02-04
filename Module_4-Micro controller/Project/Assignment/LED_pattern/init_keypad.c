#include "main.h"

// Function defintion for initializing the digital keypad.
void init_keypad(void)
{
    TRISC = TRISC | 0x0f;
}

// Function definition for read inputs from digital keypad.
unsigned int read_inputs()
{
    return KEY_PORT & INPUT_PINS;  
}