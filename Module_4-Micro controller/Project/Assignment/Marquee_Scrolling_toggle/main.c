/*
Name : Munawir. E
Date : 01/10/2022
Description : Implement a scrolling number marquee with direction control.
	Requirements:
		As soon as the board is powered on or reset, a static message (hardcoded) should start scrolling from right to left SSD.
    	The scroll should repeat indefinitely unless and until the direction change keys are pressed. 
    	The scroll frequency should be 0.5Hz (Approximately, Non Timer Based). 
    	On press of Right Direction Key, the scroll direction should change from left to right on the same instance. 
    	On press of Left Direction Key, the scroll direction should change from right to left on the same instance. 
    	On press of Stop / Start Key the scroll should be stopped on the same instance. 
    	On press of any key the scroll should start on the same instance.
*/

#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
unsigned char once = 1;
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, BLANK, BLANK };

// Function definition configure ports.
void init_config(void)
{
	init_ssd_control();
	init_keypad();
}

void main(void)
{
	init_config();

	// Initializing local variables.
	unsigned char i = 0, j = 1, k = 2, l = 3, trig = 1, key, flag = 1;
	unsigned long delay = 0;

	while(1)
	{
		// Reading inputs.
		key = read_inputs();
		
		// If switch 1 toggle the scrolling marque.
		if( key == SWITCH1)
		{
			trig = !trig;
		}
		else if( key == SWITCH3 )	// If Switch3 is pressed start or stop the scrolling.
		{
			flag = !flag;
		}
		
		if( delay++ == 750)
		{
			delay = 0;

			if (trig == 0 && flag == 1)		// Scrolling from left to right.
			{
				ssd[3] = digit[i];
				ssd[2] = digit[j];
				ssd[1] = digit[k];
				ssd[0] = digit
				if( l == 11)
					l = 0;
				i = j;
				j = k;
				k = l++;
			}
			else if( trig == 1 && flag == 1)		// Scrolling from right to left.
			{
				ssd[0] = digit[i];
				ssd[1] = digit[j];
				ssd[2] = digit[k];
				ssd[3] = digit[l];

				if( l == 11)
					l = 0;
				i = j;
				j = k;
				k = l++;
			}
			else
			{
				if( trig )	// For Stop Scrolling the right to left marquee.
				{
					ssd[0] = digit[i];
					ssd[1] = digit[j];
					ssd[2] = digit[k];
					ssd[3] = digit[l];
				}
				else	// For stop scrolling the left to right marquee.
				{
					ssd[3] = digit[i];
					ssd[2] = digit[j];
					ssd[1] = digit[k];
					ssd[0] = digit[l];
				}	
			}
		}
		display( ssd);		// Function call to display value in SSD
	}
}