#include "main.h"

// Pattern-3: The LEDs should blink alternately.
void LED_alternate(int state)
{
    PORTB = state ? 0xFF & 0xAA : 0xFF & 0x55; 
}