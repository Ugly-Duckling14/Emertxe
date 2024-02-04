/* 
Name : Munawir. E
Date : 6/10/2022
Description : Implement a brightness control using potentiometer
	Requirement:
	    On giving power supply to the board, read the value of pot. Based on that value, set the duty cycle. Again read the pot value
        	If it is different from previous value, update duty cycle accordingly
        	If it is same do nothing
    	Repeat the same on regular interval or continuously. 
    	Use program cycles to generate PWM
*/
#include "main.h"

#define PERIOD 100

// Function configure ports.
static void init_config(void)
{
	// configuring port B
	ADCON1 = 0x0F;
	LED = OFF;
	TRISB = 0;
	init_adc();	// Function call for configure potentiometer.
}

void main(void)
{
	unsigned short adc_reg_val;
	unsigned char prog_cycle;
	
	init_config();

	while (1)
	{
		adc_reg_val = (read_adc( CHANNEL4))/1023;
		
		if (prog_cycle < adc_reg_val)	// LED on state till reaches adc_reg_val.
		{
		    LED = ON;
		}
		else		// LED off period
		{
			LED = OFF;
		}

		if (prog_cycle++ == PERIOD)		// Resettng prog cycle.
		{
			prog_cycle = 0;
		}
	}
}
