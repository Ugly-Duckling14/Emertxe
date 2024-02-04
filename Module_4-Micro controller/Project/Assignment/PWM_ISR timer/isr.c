#include "main.h"

extern unsigned short prog_cycle;

void interrupt ISR()
{
	// interrupt for timer0
	if( TMR0IF == 1)
	{
		TMR0IF = 0;
		prog_cycle++;
		TMR0 += 15536;		// restarting timer0 from 3038 - 65536
	}
}
