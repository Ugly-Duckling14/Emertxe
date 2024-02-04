#include "main.h"

// Cofiguration for timer0.
void init_config_timer0()
{
    TMR0ON = 1;         // Setting timer0 ON 
    T08BIT = 0;         // Set Timer0 as 16bit
    T0CS = 0;           // Enable internal clock.
    PSA = 0;            // Enabling prescalar.
    // Set prescalar 16bit
    T0PS2 = 0;
    T0PS1 = 1;
    T0PS0 = 1;
    TMR0IF = 0;         
    TMR0IE = 1;   
    TMR0 = 3036;            // TMR0 starts from 3036-65536
}


