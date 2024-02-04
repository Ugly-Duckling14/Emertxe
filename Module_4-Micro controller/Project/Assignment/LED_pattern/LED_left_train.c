#include "main.h"

extern unsigned char led_train;

// Pattern-2: The LEDs should glow from left to Right and switch off from left to right, no direction control/ direction change.
void LED_left_train(void)
{
    // Led ON from left to right
    if( led_train++ <= 8)
    {
        PORTB = 0xFF & ((1 << led_train) - 1 );
    }
    else if( led_train <= 16)      // Led OFF from left to right.  
    {
        PORTB = 0xFF << led_train - 8 ;
    }
    else
    {
        led_train = 0;
    }
}