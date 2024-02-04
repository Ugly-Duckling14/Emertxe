#include "main.h"

extern unsigned short timer_cycle;

void interrupt ISR()
{
	// interrupt for timer0
	if( TMR0IF == 1)
	{
		TMR0IF = 0;
		timer_cycle++;
		TMR0 += 8;		// restarting timer0 from 8 - 255
	}
}
