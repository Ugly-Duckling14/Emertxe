/* 
Name : Munawir. E
Date : 13/09/2022
Description :
*/

#include "main.h"

/* Function to initializing the Ports */
static void init_config_LED(void)
{
    TRISB = 0x00;       // Making the portb pin as output.
    ADCON1 = INPUT_PINS;      // Making the portb pins as digital.
    PORTB = 0x00;       // Turn off all LED by default.
}

void init_digital_keypad( void)
{
    TRISC |= INPUT_PINS;
}

void main(void)
{
	unsigned long time = 0, led_train = 0x00,j;
	unsigned short int trig,once;

	// Initialization of led configuration.
	init_config_LED();
	
	while(1)
	{
		if( RC0 == 0 && once == 1)
		{
			trig = !trig;
			for(j = 1000; j--;);
			once = 0;				
		}
		else if( RC0 == 1)
			once = 1;

		// Unblocking delay.
		if( time == 60000)
		{
			if( trig == 0)
			{
				if( led_train++ <= 7) // Led start's glow as train from right to left.
				{ 
					PORTB = PORTB | (1 << led_train) ; 
				} 
				else if( led_train > 7 && led_train <= 16) 	// Led glows as end of train from right to left.
				{ 
					PORTB = PORTB << led_train - 8;
				}
				else
				{
					// Reseting the port and led_train.
					led_train = 0;
					PORTB = 0x00;
				}
			}
			else
			{
				if( led_train++ <= 7 )		// Led start's glow as train from left to right
				{
					PORTB = 0x00 | (0 >> led_train);
				}
				else if( led_train > 7 && led_train <= 16 )	// Led glows as end of train from left to right.
				{
					PORTB = 0x80 | (1 >> (led_train - 8));
				}
				else
				{
					// Reseting the port and led_train.
					led_train = 0;
					PORTB = 0x00;
				}
			}
			time = 0;
		}
		time++;

		
	}
}