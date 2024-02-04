#include "main.h"

// Configuring digital keypad
void init_keypad(void)
{
    TRISC = TRISC | 0x0f;
}

// Reading input from switch.
unsigned int read_inputs()
{
    return KEY_PORT & INPUT_PINS;
}