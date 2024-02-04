/*
Name : Munawir. E
Date : 02/10/2022
Description : Self counter using SSDs with storage on key press.
	Requirements :
		As soon as the board is powered up or reset, counter should start self incrementing at rate of 1Hz from 0000 up to 9999 and then roll of to 0000 (Approximately, Non Timer Implementation)
		On save key press, count value should be  stored in internal EEPROM
		On subsequent power ups or reset the counter should start from the previous stored value.
*/

#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

// Function defintion to configure ports
void init_config(void)
{
	init_keypad();
	init_ssd_control();
}

void main(void)
{
	unsigned int  i, data = 0;
	unsigned char key;

	init_config();

	// Reading data from EEPROM ( Read 2 digit data from single address and convert 4 digit data).
	data = read_internal_eeprom( 0x00);
	data = data * 100 + read_internal_eeprom( 0x01);

	while(1)
	{
		key = read_inputs();
		if( key == SWITCH2)
		{
			// Writing data to EEPROM ( Write 2 digit on single address)
			write_internal_eeprom( 0x01, data%100);
			write_internal_eeprom(0x00, data/100);
		}
		else
		{
			// Self incrementing Counter from either 0 or the value taken from EEPROM.
			data++;
			for(i = 5000; i--; );
			
			if(data == 9999)		// Resetting data when reaches 9999.
			{
				data = 0;
			}
			
		}

		// Displaying the data
		ssd[3] = digit[data%10];
		ssd[2] = digit[(data % 100) / 10];
		ssd[1] = digit[(data %1000) / 100];
		ssd[0] = digit[(data % 10000) / 1000];
		display( ssd);
	}
}