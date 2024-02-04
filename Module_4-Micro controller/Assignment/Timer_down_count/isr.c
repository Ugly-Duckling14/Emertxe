#include "main.h"
extern unsigned char state;
void interrupt ISR()
{	
	static unsigned int delay = 0;
	// interrupt for timer0
	if( TMR0IF == 1)
	{ 
		TMR0 += 6 + 2;	// restarting timer0 from 8
		
		if(++delay == 625)
		{
			delay = 0;
			state++;
        }
		
		TMR0IF = 0;			
	}
}
