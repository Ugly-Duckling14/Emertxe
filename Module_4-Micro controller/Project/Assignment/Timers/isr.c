#include "main.h"
extern unsigned short delay1, delay2, delay3;
void interrupt ISR()
{
	// interrupt for timer0
	if( TMR0IF == 1)
	{
		TMR0IF = 0;

		delay1++;
		if (delay1 == 5)
		{
			delay1 = 0;
			LED1 = ~LED1;
		}
		TMR0 += 3038;		// restarting timer0 from 3038 - 65536
	}

	// Interrupt for timer1 
	if (TMR1IF == 1)
	{
		TMR1IF = 0;

		delay2++;
		if ( delay2 == 80)
		{
			delay2 = 0;
			LED2 = ~LED2;
		}

		TMR1 += 3038;		// restarting timer1 from 3038 - 65536

	}
 
	// Interrupt for timer2
	if( TMR2IF == 1)
	{
		TMR2IF = 0;
		delay3++;
		if ( delay3 == 1250)
		{
			delay3 = 0;
			LED3 = ~LED3;
		}

		TMR2 += 8;			// restarting timer2 from 8 - 255
	}
}
