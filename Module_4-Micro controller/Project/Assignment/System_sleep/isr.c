#include "main.h"

extern unsigned short count;
static unsigned short delay1;
bit key_detected;
void interrupt ISR()
{
	// interrupt for timer0
	if( TMR0IF == 1)
	{
		TMR0IF = 0;
		delay1++;
		if (delay1 == 5)
		{
			count++;
			delay1 = 0;
			LED1 = ~LED1;
		}
		TMR0 += 3038;		// restarting timer0 from 3038 - 65536
	}

	if (INT0F == 1)
	{
		key_detected = 1;

		INT0F = 0;
	}
}
