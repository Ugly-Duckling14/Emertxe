#include "main.h"

void init_config_timer0()
{
    TMR0ON = 1;
    T08BIT = 0;     // Setting timer0 as 16bit.
    T0CS = 0;
    
    // Setting presclar as 16 bit
    PSA = 0;
    T0PS2 = 0;
    T0PS1 = 1;
    T0PS0 = 1;
    
    TMR0IF = 0;
    TMR0IE = 1;   
    TMR0 = 3036;        // initializing timer0 from 3036.
    GIE = 1;
    PEIE = 1;
}
