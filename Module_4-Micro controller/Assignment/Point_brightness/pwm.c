#include "main.h"

// Function definition for glow led according to pwm.
void pwm(unsigned int duty_cycle)
{
    unsigned static int prog_cycle;
	
	if (prog_cycle < duty_cycle)
	{
	    PORTB = 0xFF;		// Led on according to duty cycle.
	}
	else
	{
		PORTB = 0x00;		// Led OFF not matching period.
	}
	
	if (prog_cycle++ == PERIOD)
	{
		prog_cycle = 0;
	}

}