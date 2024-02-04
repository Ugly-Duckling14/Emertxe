/* 
Name : Munawir. E
Date : 13/09/2022
Description : Write an Embedded C program to display a pattern on the LEDs.
Working Logic:
	1. Consider 8 LEDs from the Board, these LEDs has to glow one by one as 
		  if a train bogie coming out of a tunnel every second (approx., 
		  none without timer implementation)from Left to Right as soon 
		  as the board is powered on or reset (Let’s call it as exit)
    2. Once all LEDs are ON, the LEDs should switch OFF one by one as 
		  if the train bogie is entering inside a tunnel from Left to Right (Let’s call it as entry).
    3. Once the exit and entry is complete , Change the direction of the 
		  train from Right to Left.
    4. This process of changing direction has to be repeated 
		  between every exit and entry of the train.
*/

#include "main.h"

void main(void)
{
	unsigned int time = 0, temp = 0x00;

	// Initialization of led configuration.
	init_config_LED();
	
	while(1)
	{
		// Unblocking delay.
		if( time == 50000)
		{
			if( temp++ <= 7) // Led start's glow as train from right to left.
			{ 
				PORTB = 0xFF & ((1 << temp) - 1 ); 
			} 
			else if( temp > 7 && temp <= 16) 	// Led glows as end of train from right to left.
			{ 
				PORTB = 0xFF << temp - 8;
			}
			else if( temp > 16 && temp <= 24)		// Led start's glow as train from left to right
			{
				PORTB = 0xFF & ~((1 << (24- temp))-1);
			}
			else if( temp > 24 && temp <= 32 )	// Led glows as end of train from left to right.
			{
				PORTB = 0xFF >> temp -24;
			}
			else
			{
				// Reseting the port and temp.
				temp = 0;
				PORTB = 0x00;
			}
			time = 0;
		}
		time++;
	}
}