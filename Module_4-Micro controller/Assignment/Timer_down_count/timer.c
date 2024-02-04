#include "main.h"

// Cofiguration for timer0.
void init_config_timer0()
{
    GIE = 1;
    PEIE= 1;
    TMR0ON = 1;         // Setting timer0 ON 
    T08BIT = 1;         // Set Timer0 as 16bit
    T0CS = 0;           // Enable internal clock.
    PSA = 1;            // Prescalar is disabled.
    
    TMR0IF = 0;         
    TMR0IE = 1;   
    TMR0 = 6;            // TMR0 starts from 6 - 255
}

