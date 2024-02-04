#include "main.h"

static short value = 0;
extern unsigned char flag;

unsigned int password_valid(unsigned short value, unsigned short password)
{
	unsigned short i, pass;
	unsigned short int count=0;
	//pass = read_internal_eeprom( 0x01);
	for( i =0; i< 8; i++)
	{
		if( value  ==  password )
		{
			count++;
		}
	}

	if( count == 8)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
unsigned char password_acess()
{
	unsigned short try = 3,input = 0;
    unsigned short value = 0;
    unsigned char key = 0,status;
	unsigned short blink = 100;
	unsigned short password;

	password = read_external_eeprom( 0x00);

	CLEAR_DISP_SCREEN;
    clcd_print(" ENTER PASSWORD", LINE1(0));
	while(1)
	{
        if( try > 0 )
		{
			if( input < 8)
			{	
				key = read_switches(STATE_CHANGE);
				for(int i = 5000; i--;);
				if (key == MK_SW8)
				{
					value = (value << 1) | 1;
					clcd_putch('*', LINE2(input++));
				}
				else if( key == MK_SW9)
				{
					value = (value << 1) | 0;
					clcd_putch('*', LINE2(input++));
				}	

				if( --blink == 0)
				{
					blink = 100;
				}
				else if( blink > 50  )
				{
					clcd_putch('_', LINE2(input));
				}
				else if( blink < 50)
				{
					clcd_putch(' ', LINE2(input));	
				}					
			}
			else
			{
				CLEAR_DISP_SCREEN;
				status = password_valid(value, password);
				if( status == 1)
				{
					try--;
					value = 0;
					input = 0;
					clcd_print(" ENTER PASSWORD", LINE1(0));
                    clcd_putch( try+48, LINE2(1));
                    clcd_print(" ATTEMPTS LEFT", LINE2(3));
                    __delay(3);
                    CLEAR_DISP_SCREEN;
					clcd_print(" ENTER PASSWORD", LINE1(0));
					continue;	
				}
				else
				{
					clcd_print(" ENTER PASSWORD", LINE1(0));
					clcd_print( "  SUCCESS   ", LINE2(0) );
					__delay(3);
					CLEAR_DISP_SCREEN;
                    return 3;
				}
			}
		}
		else
		{
			clcd_print( "Wrong password", LINE2(0) );
            return 1;
		} 
	}
	return 2;		
}

void set_password()
{
	unsigned short input = 0,retype = 2, i;
    unsigned short int value = 0,pass = 0, blink = 100;
    unsigned char key = 0;
	
	CLEAR_DISP_SCREEN;
	
	while(1)
	{
		if( retype  > 0)
		{	
			clcd_print("Enter new passwd", LINE1(0));
			if( input < 8)
			{
				key = read_switches(STATE_CHANGE);
				for( i = 5000; i--;);
				if (key == MK_SW8)
				{
					value = (value << 1) | 1;
					clcd_putch('*', LINE2(input++));
				}
				else if( key == MK_SW9)
				{
					value = (value << 1) | 0;
					clcd_putch('*', LINE2(input++));
				}	

				if( --blink == 0)
				{
					blink = 100;
				}
				else if( blink > 50  )
				{
					clcd_putch('_', LINE2(input));
				}
				else if( blink < 50)
				{
					clcd_putch(' ', LINE2(input));	
				}	
			}	 
			else
			{
				input = 0;
				pass = value;
				retype--;
			}

			if( retype == 1  && input == 0)
			{
				CLEAR_DISP_SCREEN;
				clcd_print("Re enter passwd ", LINE1(0));
				value = 0;
			}
		}
		else
		{
			CLEAR_DISP_SCREEN;	
			if( password_valid( value, pass) == 0)
			{
				write_external_eeprom( 0x00, value);
				clcd_print("PASSWORD CHANGED", LINE1(0));
				__delay(3);
				flag = 1;
				break;
			}
			else
			{
				retype = 2;
				clcd_print("PASSWORD NOT MATCH", LINE1(0));
				clcd_print( "   FAILED       ", LINE2(0));
				__delay(3);
			}
		}
	}
}
