#include "main.h"
extern unsigned int duty_cycle;
extern unsigned char timer;

// Function definition for ISR interrupt.
void interrupt ISR()
{ 
	unsigned int prog_cycle=0;
	
	// Checking timer0 flag is set or not.
	if( TMR0IF == 1)
	{
		TMR0IF = 0;
		timer++;

		// For timer is 5sec
		if (timer == 25 )
		{
			duty_cycle = 100;		
			timer = 0;	
		}
	}
}
