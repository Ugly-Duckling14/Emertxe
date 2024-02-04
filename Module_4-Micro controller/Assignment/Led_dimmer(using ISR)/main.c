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

// Declaring timer cycle and macro for period
#define PERIOD 100
unsigned short timer_cycle = 0;

// Function configure ports.
static void init_config(void)
{
	ADCON1 = 0x0F;
	LED = OFF;
	TRISB = 0;
	init_digital_keypad();
	init_config_timer0();
}

void main(void)
{
	unsigned char key;
	unsigned short duty_cycle = 0, delay= 0;
	init_config();

	while (1)
	{
		key = read_digital_keypad( LEVEL);	// Reading input from keypad.

		if(!delay-- )
		{
			delay = 1000;
		
			if( key == SWITCH1)
			{
				if( duty_cycle != PERIOD)
					duty_cycle++;		// Increasing the value of duty cycle.
			}
			else if( key == SWITCH2)
			{
				if( duty_cycle != 0)
					duty_cycle--;		// Decreasing the value of duty cycle.
			}
		}
			
		/* LED is glowing according to PWM value. */
		if (timer_cycle < duty_cycle)
		{
		    LED = ON;
		}
		else
		{
			LED = OFF;
		}

		if (timer_cycle == PERIOD)
		{
			timer_cycle = 0;
		}	
	}
}
