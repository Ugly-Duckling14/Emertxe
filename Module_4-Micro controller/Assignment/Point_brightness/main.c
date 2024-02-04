/* 
Name : Munawir. E
Date : 3/10/2022
Description : Implement a point brightness control.
   Working logic:
	As soon as the board is powered on or reset, LED should glow with half brightness (Duty cycle = 10%)
On Interrupt, LED should glow with 100% brightness for 5 seconds
After 5 seconds, the LED should go back to 10% brightness
*/

#include "main.h"
unsigned int duty_cycle = 1000;
unsigned char timer;

void init_config(void)
{   
    // Function call initializing digital keypad.
    init_digital_keypad();
    
    // Function call initializing led.
    init_led();

    // Function call to initialize timer.
    init_config_timer0();
}


void main(void)
{
    unsigned char key;
    init_config();
   
    while(1)
    {
        // Checking for external interrupt.
        key = read_digital_keypad(STATE_CHANGE);
        if (key == SWITCH1)
        {
            duty_cycle = PERIOD;
            timer = 0;
        }
        pwm(duty_cycle);         // Function call to glow led.
    }
}
