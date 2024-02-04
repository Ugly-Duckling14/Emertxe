/*
Name : Munawir. E
Date : 01/10/2022
Description : Implement a 4 digit key press counter.
    Requirements:
         Implement a 4 digit key press counter
    	 On every key press counter value should increment by 1.
    	 On a long key press (2 seconds), count should reset to zero.
*/

#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

// Function to initialize configuration.
void init_config(void)
{
	// Function call for initializing digital keypad configuration.
	init_keypad();

	// Function call for initializing ssd configuration
	init_ssd_control();
}

void main(void)
{
	unsigned int value = 0;
	unsigned char  count = 0, key;

	init_config();
	
	while(1)
	{
		// Reading input from digital keypad.	
		key = read_inputs();

		// Checking switch pressed for counter or reset.
		if( key == SWITCH1 )
		{
			count++;
			 
			if( count > 100)
			{
				value = 0;				
			}
		}
		else
		{
			if( count < 100 && count != 0  )
			{	
				value++;	
			}
			
			count = 0;
		}
		
		// Assigning values for SSD
		ssd[3] = digit[value%10];
		ssd[2] = digit[(value % 100) / 10];
		ssd[1] = digit[(value %1000) / 100];
		ssd[0] = digit[(value % 10000) / 1000];
		
		// Function call for display values in SSD
		display( ssd);
	}
}
