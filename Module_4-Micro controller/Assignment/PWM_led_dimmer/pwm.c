#include "main.h"

// Function for PWM
void software_pwm(void)
{
	unsigned char key;
	static unsigned short wait = 0;
	static unsigned char prog_cycle;
	static unsigned char duty_cycle = 50;

    // Reading input from switch1.
	key = read_digital_keypad(LEVEL);

	if (!wait--)    // Non-blocking delay
	{
		wait = 1000;

		if (key == SWITCH1)
		{
            // Increasing the duty cycle.
			if (duty_cycle != PERIOD)
			{
				duty_cycle++;
			}
		}
		if (key == SWITCH2)
		{
            // Decreasing the duty cycle.
			if (duty_cycle != 0)
			{
				duty_cycle--;
			}
		}
	}

	if (prog_cycle < duty_cycle)
	{
	    RB0 = ON;
	}
	else
	{
		RB0 = OFF;
	}

	if (prog_cycle++ == PERIOD)
	{
		prog_cycle = 0;
	}
}