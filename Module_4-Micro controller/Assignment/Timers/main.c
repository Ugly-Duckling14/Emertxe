/* 
Name : Munawir. E
Date : 28/09/2022
Description : Implement the time separator with Timer 0, Timer 1 and Timer 2
	Requirement:
	    All three LEDs assigned to specific timer should toggle at frequency of 0.5 Hz (500 msecs) as soon as the board is powered on or reset.
    	There should be time synchronization between all LEDs on longer runs greater than hours (No drifts in the output should be seen).
*/

#include "main.h"

unsigned short delay1 = 0, delay2 = 0, delay3 = 0;

void init_config(void)
{
	PEIE = 1;
	/* Clear old content */
	PORTB = 0x00;

	/* Set PORTB as a Output */
	TRISB = 0x00;

	/* Config PORTB as digital */
	ADCON1 = 0x0F;

	init_config_timer0();
	init_config_timer1();
	init_config_timer2();

	GIE = 1;
}


void main(void)
{
	//static unsigned short count;

	init_config();
	while (1)
	{
		;
	}
}

