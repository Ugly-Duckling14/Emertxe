#include "main.h"

extern unsigned char time[9];
unsigned char clock_reg[3];

/* Function to Get time From RTC.
 * Inputs : void
 * Output : Get HH:MM:SS from RTC & store into an array.
 */
void get_time(void)
{
	clock_reg[0] = read_ds1307(HOUR_ADDR);
	clock_reg[1] = read_ds1307(MIN_ADDR);
	clock_reg[2] = read_ds1307(SEC_ADDR);

	// Converting BCD value to character.
	if (clock_reg[0] & 0x40)
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x01);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	else
	{
		time[0] = '0' + ((clock_reg[0] >> 4) & 0x03);
		time[1] = '0' + (clock_reg[0] & 0x0F);
	}
	time[2] = ':';
	time[3] = '0' + ((clock_reg[1] >> 4) & 0x0F);
	time[4] = '0' + (clock_reg[1] & 0x0F);
	time[5] = ':';
	time[6] = '0' + ((clock_reg[2] >> 4) & 0x0F);
	time[7] = '0' + (clock_reg[2] & 0x0F);
	time[8] = '\0';
}

/* Function to Set time.
 * Inputs : From matrix keypad & RTC (to get current time in RTC).
 * Output : The time to be set is stored in an integer array( for easy to change time and understand) & in char array( to display in clcd) array.
 */
unsigned char set_time()
{
	unsigned char chng_time[9], key, state = 0;
	unsigned short int temp[3], mode = 1,count = 0, blink = DELAY;
	
	CLEAR_DISP_SCREEN;
	clcd_print(" SET TIME", LINE1(0));
	my_strcpy( chng_time, time);
	chng_time[8] = '\0';
	
	// Converting the time in character to integer.
	temp[0] = ((chng_time[0] - '0') *10) + (chng_time[1] -48);
	temp[1] = ((chng_time[3] - '0') *10) + (chng_time[4] -48);
	temp[2] = ((chng_time[6] - '0') *10) + (chng_time[7] -48);
	
	clcd_print(chng_time, LINE2(0));
 
	 while(1)
	{
		key = read_switches(LEVEL_CHANGE);

		if( key == MK_SW11)
		{
			count++;
			 
			if( count > 350)		// For long press of switch11 store the updated time.
			{
				store_time(temp);
				count = 0;
				return 1;
			}
			else
			{
				state = 1;
			}	
		}	
		else if( key == MK_SW12)
		{
			count++;
			if(count > 350)			// For long press of switch12 return without update time
			{
				count = 0;
				return 3;
			}	
			else 
			{
				state = 2;
			}
		}
		else
		{
			if( (count < 350 && count != 0 ) && state == 1 )
			{	
				if( mode == 1)		// For changing the value of second.
				{
					if( temp [2] <59)
						temp[2]++;
					else
						temp[2] = 0;
				}
				else if( mode == 2)		// For changing the value of minute
				{
					if( temp [1] <59)
						temp[1]++;
					else
						temp[1] = 0;
				}
				else if( mode == 3)		// For changing the value of hour.
				{
					if( temp [0] < 12)
						temp[0]++;
					else
						temp[0] = 0;
				}
			}
			else if( (count < 350 && count != 0) && state == 2 )		// For changing modes from sec/min/hrs.
			{
				if( mode < 3)
					mode++;
				else
					mode = 1;
			}
			state = 0;
			count = 0;	
		}
		
		// To blink the pointer of time where we're changing.
		if( --blink == 0)
		{
			blink = DELAY;
		}
		else if( blink > DELAY/2  )	
		{
			// Displaying the st time in clcd.
			chng_time[0] = (temp[0]/10) +'0';
			chng_time[1] = (temp[0]%10) +'0';
			chng_time[3] = (temp[1]/10) +'0';
			chng_time[4] = (temp[1]%10) +'0';
			chng_time[6] = (temp[2]/10) +'0';
			chng_time[7] = (temp[2]%10)+ '0';
		}
		else if( blink < DELAY/2)
		{
			if( mode == 1)
			{
				chng_time[6] = ' ';
				chng_time[7] = ' ';
			}
			else if( mode == 2)
			{
				chng_time[3] = ' ';
				chng_time[4] = ' ';
			}
			else if( mode = 3)
			{
				chng_time[0] = ' ';
				chng_time[1] = ' ';
			}	
		}
		clcd_print(chng_time, LINE2(0));
	} 
}

/* Function to Store the time to RTC after setting.
 * Inputs : Array of pointer.
 * Output : Store the time in RTC, print message in CLCD of 'Time set' And return void
 */
void store_time(unsigned short int *arr)
{
	unsigned char value[3];

	// converting from integer to BCD.
	value[0] = (arr[0]/10 << 4) & 0x30 | arr[0]%10 & 0x0F;
	value[1] = (arr[1]/10 << 4) & 0xf0 | arr[1]%10 & 0x0F;
	value[2] = (arr[2]/10 << 4) & 0xF0 | arr[2]%10 & 0x0F;
	CLEAR_DISP_SCREEN;
	
	// Writting the BCD value to RTC
	write_ds1307( HOUR_ADDR, value[0]);
	write_ds1307( MIN_ADDR, value[1]);
	write_ds1307( SEC_ADDR, value[2]);
	clcd_print("time SET", LINE2(0));
	__delay(3);
}