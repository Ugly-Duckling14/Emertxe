/* 
Name : Munawir. E
Date : 13/10/2022
Description : Implement a key detection feedback using UART
	Requirements:
      - On a press of any key from digital keypad, a message has to be sent to host system.
      - The message should be like “Switch X Pressed”, where X could range from 1 to 4.
*/

#include <xc.h>
#include "digital_keypad.h"
#include "uart.h"

void init_config(void)
{
	init_uart();
	init_digital_keypad();

	puts("Key detection feedback using UART\n\r");
}

void main()
{
	unsigned char key;
	unsigned short int i;

	init_config();
	
	puts("Press any digital key:\n\r");

	while (1)
	{
		key = read_digital_keypad(STATE_CHANGE);		// Reading the key.
			
		if( key == SWITCH1)		// If Switch 1 is pressed.
		{
			puts("\nSWITCH 1 DETECTED");
		}
        else if( key == SWITCH2)		// If Switch 2 is pressed.
		{
			puts("\nSWITCH 2 DETECTED");
		}
		else if( key == SWITCH3)		// If switch 3 is pressed.
		{
			puts("\nSWITCH 3 DETECTED");
		}
		else if( key == SWITCH4)		// If Switch 4 is pressed.
		{
			puts("\nSWITCH 4 DETECTED");
		}
		
		for(i=250;i--;);
	}
}
