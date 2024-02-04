/* 
Name : Munawir. E
Date : 3/10/2022
Description : Using Timer based PWM, implement a LED dimmer application.
	Requirement:
	    As soon as the board is powered on or reset, The LED should glow with 50% Duty Cycle (i.e the glow, half of its maximum intensity).
        The Increment Brightness Input should increase the Duty Cycle upto 100% (Total ON)
        The Decrement Brightness Input should decrease the Duty Cycle to 0% (Total OFF)
*/

#include "main.h"

// Function configure ports.
static void init_config(void)
{
	ADCON1 = 0x0F;

	RB0 = OFF;
	TRISB = 0;

	init_digital_keypad();
}

void main(void)
{
	init_config();

	while (1)
	{
		software_pwm();		// Function call for PWM.
	}
}
