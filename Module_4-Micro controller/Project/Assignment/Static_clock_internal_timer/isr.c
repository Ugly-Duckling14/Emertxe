#include "main.h"
extern unsigned char flag;

void interrupt ISR()
{
	static unsigned char delay = 0;	
	// interrupt for timer0
	if( TMR0IF == 1)
	{ 
		TMR0 += 3036 + 2;	// restarting timer0 from 3038
		
		if(++delay == 5)
		{
			delay = 0;
			flag++;
        }
		
		TMR0IF = 0;			
	}
}
