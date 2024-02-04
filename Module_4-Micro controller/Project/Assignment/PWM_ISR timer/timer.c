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
    T0PS1 = 0;
    T0PS0 = 0;
    TMR0IF = 0;         
    TMR0IE = 1;   
    TMR0 = 15536;            // TMR0 starts from 3036-65536
}

// Cofiguration for Timer1
void init_config_timer1()
{
    T1RUN = 1;         // Enabling system clock
    T1OSCEN = 1;       // Timer1 oscillator is enabled.
    TMR1ON = 1;        // Set Timer1 is ON
    TMR1IF = 0;
    TMR1IE = 1;
    TMR1CS = 0;        // Enabling timer1 internal clock
    
    T1RD16 = 1;        // Enabling timer1 16bit.
   
    T1CKPS1 = 0;       // Prescalar is 1:1 ratio
    T1CKPS0 = 0;

    TMR1 = 3036;       // TMR1 value starts from 3036-65536

}

// Cofiguration for Timer2
void init_config_timer2()
{
    TMR2ON = 1;             // Set Timer2 is ON
    TMR2IE = 1;
    TMR2IF = 0;
    TMR2 = 6;               // TMR2 starts from 6-256

    T2CKPS1 = 1;            // Timer2 prescalar  1:16bit ratio.
    T2CKPS0 = 0;
}