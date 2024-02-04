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

#define PERIOD 100
unsigned char prog_cycle;


// Function configure ports.
static void init_config(void)
{
	ADCON1 = 0x0F;
	LED = OFF;
	TRISB = 0;
	
	init_adc();
	init_config_timer0();
}

void main(void)
{
	unsigned short adc_reg_val;
	unsigned char key;

	init_config();

	while (1)
	{
		adc_reg_val = read_adc( CHANNEL4);
		
		adc_reg_val /= 1023;
	
		if (prog_cycle < adc_reg_val)
		{
		    LED = ON;
		}
		else
		{
			LED = OFF;
		}

		if (prog_cycle == PERIOD)
		{
			prog_cycle = 0;
		}
	}
}
