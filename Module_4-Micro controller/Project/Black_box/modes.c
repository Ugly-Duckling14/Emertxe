#include "main.h"

// Getting globally value declared in main. 
extern unsigned char option[6][17], display[17],time[9];
static unsigned char menu = 1;
extern unsigned char flag;

/* Function to Display menu after Successfully entering password
 * Inputs : char key - to know which key is pressed.
 * Output : Nil
 */
void display_menu( unsigned char key)
{
	static unsigned short opt = 0 ,count = 0;
	static unsigned char flag1 =0;
	

	if( key == MK_SW8)
	{
		CLEAR_DISP_SCREEN;
		count++;
			 
		if( count > 350)		// To enter into an particular option
		{
			if( menu == 1)
			{
				menu = 2;
			}
			count =0;
		}
		else
			flag1 =1;	
	}	
	else if( key == MK_SW9)
	{
		CLEAR_DISP_SCREEN;
		count++;
		if(count > 350)		// To go  back from paticular menu.
		{
			if( menu == 1)
			{
				flag = 1;
			}
			else if( menu == 2)
			{
				menu = 1;		
			}
			count =0;	
		}
		else
		{
			flag1 = 2;
		}	
	}
	else		// For Scrolling the options.
	{
		if( (count < 350 && count != 0 ) && flag1 == 2 )
		{	CLEAR_DISP_SCREEN;
			if( opt < 4)
			{	opt++;
				flag1 = 0;
			}
		}
		else if( (count < 350 && count != 0)  && flag1 == 1 )
		{
			CLEAR_DISP_SCREEN;
			if( opt > 0)
			{	opt--;
				flag1 = 0;
			}
		}
		count = 0;	
	}

	if( menu == 1)		// Displaying the options
	{
		clcd_putch( '*', LINE1(0));
		clcd_print( option[opt], LINE1(1));
		clcd_print( option[opt+1], LINE2(1));
	}
	else if( menu == 2)
	{	
		if( opt == 0)
		{
			menu = view_log(key);	// Function call to view the logs in clcd.
		}
		else if( opt == 1)
		{
			menu = download_log();		// Function call to download logs into the system.
		}			
		else if( opt == 2)
		{
			menu = clear_log();		// Function call to clear the logs from external EEPROM. 
			CLEAR_DISP_SCREEN;
		}
		else if( opt == 3)
		{
			flag = set_time();		// Function call to set the time.
			menu = 1;
			opt = 0;
		}
		else if( opt == 4)		
		{
			set_password();			// Function call to set password.
			menu = 1;
			opt = 0;
		} 
		
	}
}

/* Function to copy string*/
char *my_strcpy( char *dest, const char *src)
{
    char *start = dest;
        while(  *src != '\0' )
        {   
            *dest = *src;
            src++;
            dest++;
        }   
   //*dest = '\0';
   return start;
}

/* Function to view logs  in clcd
 * Inputs : key - to scroll the logs and go back from the log.
 * Output : Display th log values 
 */
unsigned char view_log()
{
	static unsigned short int k =0, j;
	static unsigned char line1[17], line2[17],flag1 = 0, key;
	static unsigned short addr = 1, count1 = 0;
	CLEAR_DISP_SCREEN;
	while(1)
	{
		key = read_switches(LEVEL_CHANGE);
		
		if( key == MK_SW9)
		{
			count1++;
			if( count1 > 250)		// Go back from view logs.
			{
				count1 = 0;
				return 1;
			}
		}
		else if( key == MK_SW8)
		{
			flag1 = 1;
		}
		else
		{
			// loading 1st 2 log values from external EEPROM
			if( k == 0)
			{
				for( j = 0; j< 16; j++)
				{
					line1[j] = read_external_eeprom(addr);
					addr++; 	
				}
				line1[16] = '\0';
				for( j = 0; j< 16; j++)
				{
					line2[j] = read_external_eeprom(addr);
					addr++; 	
				}
				line2[16] = '\0';
				k++;
			}

			if( line1[9] == 'C' && line1[10] == 'L')		// Checking log is Cleared or not.
			{
				clcd_print("Logs:", LINE1(2));
				clcd_print("EMPTY Logs", LINE2(0));
			}
			else
			{
				// Scrolling the logs up & down
				if( k < 8 && count1 < 250 && count1 != 0)
				{
					k++;
					my_strcpy( line1, line2);
					for( j = 0; j< 16; j++)
					{
						line2[j] = read_external_eeprom(addr);
						addr++; 
					}
					line2[16] = '\0';
				}
				if( k > 1  && flag1 == 1)
				{
					k--;
					my_strcpy( line2, line1);
						for( j = 16; j > 0; j--)
					{
						line1[j] = read_external_eeprom(addr);
						addr--; 
					}
					line1[16] = '\0';
				}
				count1 = 0;
				flag1 = 0;
				clcd_print( line1, LINE1(0));
				clcd_print( line2, LINE2(0));
			}
		}
	}
}

/* Function to download the logs into the system
 * Can be displayed in Minicom.
 */
unsigned char download_log()
{
	unsigned short int i, j, addr = 0x01;
	unsigned char line[17];
	line[16] = '\0';

	clcd_print("Downloading Logs.... ", LINE1(0));
	puts("Downloading Logs......\n\r");
	__delay(3);

	for( i = 0; i < 10; i++)
	{
		for( j = 0; j < 16; j++)
		{
			line[j] = read_external_eeprom(addr);
			addr++;
		}
		puts(line);			// Printing logs on system.
		puts("\n\r");
		if( line[9] == 'C' && line[10] == 'L')
		{
			break;
		}
		
	} 

	my_strcpy( line, display);
	line[9] = 'D';
	line[10] = 'L';
	puts(line);		// Printing the download logs in minicom
	CLEAR_DISP_SCREEN;
	clcd_print(" DONE........ ", LINE1(0)); 
	__delay(4);
	return 1;
}

/* Function to Clear the logs
 * clears the data inside External EEPROM.
 */
unsigned char clear_log()
{
	unsigned char i,j,addr=1;

	display[9] = 'C';
	display[10] = 'L';
	for( j = 0; j < 16; j++)
	{
		write_external_eeprom( addr, display[j]);
		addr++;
	}
	for( i = 1; i < 10; i++)
	{
		for( j = 0; j < 16; j++)
		{
			write_external_eeprom(addr, ' ');
			addr++;
		}
	}
	return 1;
}

/* To Give some blocking delay.*/
void __delay( unsigned short int delay)
{
	for( int i = 0; i < 10 ; i++)
	{
		for( int j = delay; delay--;);
	}
}