/* 
Name : Munawir. E
Date : 13/10/2022
Description : Implement a message display using UART and CLCD.
	Requirements:
    	* Any message typed on the host system should be shown in a CLCD.
    	* On completion of the first line it should start on the second line.
    	* One full screen the second line should be moved to first line.
*/

#include <xc.h>
#include "clcd.h"
#include "uart.h"

/* Function to configure ports. */
void init_config(void)
{
	init_uart();		// Function call for config uart.
	init_clcd();		// Function call for config clcd.

	puts("Message display using UART and CLCD.\n\r");		// Display message in Host
}

void main()
{
	unsigned char ch, line1[17];
	unsigned short i = 0;

	init_config();
	
	puts("Whatever you type in LAPTOP, You will get back the message in CLCD & in Minicom :\n\r");


	while (1)
	{
		ch = getche();		// Get the message from host and sent back to host.
		
		if( ch != '\0')
		{
			if( i < 16)			// Display the message in clcd line1.
			{
				line1[i++] = ch;
				line1[i] = '\0';
				clcd_print( line1, LINE1(0));
			}
			else if( i < 32)		// Display the message in clcd line2.
			{
				line1[ i - 16 ] = ch;
				line1[++i - 16] = '\0';
				clcd_print( line1, LINE2(0));
			}
			ch = '\0';
		}
		if( i == 32)			// Display line2 message to line1 when CLCD is full.
		{
			i = 16;
			CLEAR_DISP_SCREEN;
			clcd_print(line1, LINE1(0));
		}
	}
}

