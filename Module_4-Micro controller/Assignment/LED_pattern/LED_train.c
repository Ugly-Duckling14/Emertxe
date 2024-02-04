#include "main.h"
extern unsigned char led_train;

// Pattern-1: The LEDs should glow from Left to Right and Right to left as explained in the assignment-1.
void LED_train()
{
	if( led_train++ <= 7) // Led start's glow as train from right to left.
	{ 
		PORTB = 0xFF & ((1 << led_train) - 1 ); 
	} 
	else if( led_train > 7 && led_train <= 16) 	// Led glows as end of train from right to left.
	{ 
		PORTB = 0xFF << led_train - 8 ;
	}
	else if( led_train > 16 && led_train <= 24)		// Led start's glow as train from left to right
	{
		PORTB = 0xFF & ~((1 << (24- led_train))-1);
	}
	else if( led_train > 24 && led_train <= 32 )	// Led glows as end of train from left to right.
	{
		PORTB = 0xFF >> led_train -24;
	}
	else
	{
		// Reseting the port and glow.
		led_train = 0;
		PORTB = 0x00;
	}
}