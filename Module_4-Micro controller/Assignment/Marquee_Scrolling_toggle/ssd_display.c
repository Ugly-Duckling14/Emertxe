#include "main.h"

// Function definition for Configuring SSD.
void init_ssd_control(void)
{
	/* Setting PORTB as output for Data Lines */
	TRISD = 0x00;
	/* Setting SSD Enable lines as output */
	TRISA = TRISA & 0xF0;

	/* Switching OFF all the SSDs to start with */
	SSD_CNT_PORT = SSD_CNT_PORT & 0xF0;
}

// Function definition to display values in marquee
void display(unsigned char data[])
{
	unsigned long wait;
	unsigned char data_bit;
	unsigned char digit;

	for (digit = 0; digit < MAX_SSD_CNT; digit++)
	{
		SSD_DATA_PORT = data[digit];
		SSD_CNT_PORT = (SSD_CNT_PORT & 0xF0) | (0x01 << digit);

		for (wait = 100; wait--; );
	}
}
