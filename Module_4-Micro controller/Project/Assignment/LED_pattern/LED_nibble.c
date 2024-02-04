#include "main.h"

// Pattern-4: The LEDs has to blink nibble wise, i.e first 4 LEDs will be ON, next 4 LEDs will be OFF, after first 4 LEDs will be OFF, next 4 LEDs will be ON.
void LED_nibble(int state)
{
    PORTB = state ? 0xFF & 0xF0 : 0xFF & 0x0F;
}