/*
Name : Munawir. E
Date : 02/10/2022
Description : Implement a 4 digit key press counter with persistence.
	Requirements:
		As soon as the board is powered up or reset, counter should display 0000 on SSDs.
		On every key press  counter value should increment by 1.
		On a  long key press (2 seconds), Count should  reset to zero.
		On pressing STORE switch, the current count should be  stored in internal EEPROM.
		On subsequent power ups or reset the counter should start from the previous stored value in the EEPROM.
*/

#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};

// Configuring Ports.
void init_config(void)
{
	init_keypad();
	init_ssd_control();
}

void main(void)
{
	unsigned int data = 0;
	unsigned char count = 0, key, once = 1;

	init_config();

	// Reading data from EEPROM ( Read 2 digit data from single address and convert 4 digit data).
	data = read_internal_eeprom( 0x00);
	data = data * 100 + read_internal_eeprom( 0x01);

	while(1)
	{
		key = read_inputs();

		// If switch one is pressed incrementing the count.
		if( key == SWITCH1 )
		{
			count++;
			 
			if( count > 100)
			{
				data = 0;				
			}
		}
		else
		{
			if( count < 100 && count != 0  )
			{	
				data++;	
			}
			
			count = 0;
		}

		// If switch is pressed storing data to EEPROM
		if(key == SWITCH2 && once)
		{
			// Writing data to EEPROM ( Write 2 digit on single address)
			write_internal_eeprom( 0x01, data%100);
			write_internal_eeprom(0x00, data/100);
			once = 0;
		}
		else if( key == ALL_RELEASED)
			once = 1;
		
		// Displaying data to EEPROM
		ssd[3] = digit[data%10];
		ssd[2] = digit[(data % 100) / 10];
		ssd[1] = digit[(data %1000) / 100];
		ssd[0] = digit[(data % 10000) / 1000];
		display( ssd);
	}
}