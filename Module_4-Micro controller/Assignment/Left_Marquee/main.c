/*
Name : Munawir. E
Date : 01/10/2022
Description : Implement a left scrolling number marquee
    Requirements: 
		As soon as the board is powered up or reset, a static message (hardcoded) should start scrolling from right to left on SSD.
		The scroll should repeat indefinitely.
		The scroll frequency should be 0.5Hz (Approximately, Non Timer Based).  
*/

#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, BLANK, BLANK };

void main(void)
{
	unsigned char i =0,j = 1,k = 2,l = 3;
	unsigned int delay = 0;

	init_ssd_control();		// Initializing SSD configuration.

	while(1)
	{
		// Assigning values for SSD
		ssd[0] = digit[i];
		ssd[1] = digit[j];
		ssd[2] = digit[k];
		ssd[3] = digit[l];
		display( ssd);		// Function call for Display left scrolling

		// Non-blocking delay
		if(delay++ == 1000)
		{
			if( l == 11)	//  reset the scrolling values
				l = 0;
			i = j;
			j = k;
			k = l++;
			delay = 0;		// Resetting the delay.
		}		
	}
}
