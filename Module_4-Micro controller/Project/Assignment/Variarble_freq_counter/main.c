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
	init_ssd_control();
	init_adc();
}

void main(void)
{
	unsigned int  i, data = 9999;
	unsigned short adc_reg_val, count=0;

	init_config();

	while(1)
	{
		adc_reg_val = read_adc(CHANNEL4);
			// Self incrementing Counter from either 0 or the value taken from EEPROM.
			
			//for(i = 5000; i--; );
			if(count != 0 && count < (1023/10))
			{
				count--;
			}
			else
			{
				data--;
				count = (1023 - (adc_reg_val))/10;
				if(data == 0000)		// Resetting data when reaches 9999.
				{
					data = 9999;
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