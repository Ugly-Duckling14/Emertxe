/* 
Name : Munawir. E
Date : 13/09/2022
Description : Implement multiple patterns on LEDs controlled by switches.
Working Logic:
	    Upon giving the power supply, all 8 LEDs should be OFF.

    	Now, press switch-1 on the Digital Keypad, LEDs should glow according to the pattern-1*

    	Press switch-2, LEDs should glow according to the pattern-2*

    	Press switch-3, LEDs should glow according to the pattern-3*

    	Press switch-4, LEDs should glow according to the pattern-4*

	*pattern-1: The LEDs should glow from Left to Right and Right to left as explained in the assignment-1.

	*pattern-2: The LEDs should glow from left to Right and switch off from left to right, no direction control/ direction change.

	*pattern-3: The LEDs should blink alternately.

	*pattern-4: The LEDs has to blink nibble wise, i.e first 4 LEDs will be ON, next 4 LEDs will be OFF, after first 4 LEDs will be OFF, next 4 LEDs will be ON.
*/

#include "main.h"

unsigned int led_train;

void main(void)
{
	// Initializing local variables.
	unsigned int time = 0, trig = 1, i, state = 1;
	unsigned int key;

	// Initialization of led configuration.
	init_config_LED();
	
	while(1)
	{
		// Unblocking delay.
		if( time == 50000)
		{
			// Switch pressing detection.
			if( KEY_PORT != ALL_RELEASED)
			{
				key = read_inputs();
				if(key == SWITCH1)
				{
					trig = 1;
					led_train = 0;
				}
				else if (key == SWITCH2)
				{
					trig = 2;
					led_train = 0;
				}
				else if (key == SWITCH3)
				{
					trig = 3;
				}
				else if( key == SWITCH4)
				{
					trig = 4;
				}
				for(i = 5000; i--;);
			}
			
			if( trig == 1 )				// Pattern 1
			{
				LED_train();
			}
			else if( trig == 2 )		// Pattern 2
			{
				LED_left_train();
			}
			else if( trig == 3)			// Pattern 3
			{
				LED_alternate(state);
				state = !state;
			}
			else if( trig == 4)			// Pattern 4
			{
				LED_nibble(state);
				state = !state;
			}

			time = 0;
		}
		time++;
	}
}