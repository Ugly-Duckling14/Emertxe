/*
 * Name : Munawir. E
 * Date : 28/10/2022
 * Project name : Car Black Box.
 */

#include "main.h"

/* Declaring global variables. */
unsigned char time[9],flag = 1;
unsigned char addrs = 1, display[17];
unsigned char option[6][17] = {"View log", "Download log", "Clear log", "Set time", "Password chnge","                "};

/* Function to Initialize the configurations.
 * Inputs: NIL
 * Output: Initializes/Configure the Ports. 
 */
void init_config(void)
{
	init_clcd();        // Function call to initialize the clcd.
	init_i2c();         // Function call to initialize i2c.
	init_ds1307();      // Function call to initialize RTC.
    init_matrix_keypad();   // Function call to initialize matrix keypad.
    init_uart();            // Function call to initialize UART.
    init_adc();             // Function call to initialize adc.
    write_external_eeprom( 0x00, 0);	    // setting by default password as '00000000'
}

void main(void)
{
    unsigned char  key, addr =1,read[17];
    unsigned short i,gear = 0, event = 0;
    unsigned short int speed = 0;
   
    init_config();    // Function call for configure ports.
    
    // Assigning spaces in char array to print in clcd.
    display[8] = ' ';
    display[11] = ' ';
    display[12] = ' ';
    display[16] = '\0';
   
    while(1)
    {
        get_time();     // Function call to get time from RTC.
        
        speed = read_adc(CHANNEL4)/10;              // Function call to get speed from adc.
        display[13] = (speed%1000/100) +'0';        // Converting ADC valus to character.
        display[14] = (speed%100/10) +'0';
        display[15] = (speed%10) +'0';   
        
        if( flag == 1)
        {
            key = read_switches(STATE_CHANGE);
            clcd_print("  TIME   EV  SP", LINE1(0));
            my_strcpy( display, time);      // copying time from time array to display array.
            clcd_print(display , LINE2(0));
            
            if( event < 10)
            {
                // For gear up and down.
                if( key == MK_SW1)      
                {
                    event++;
                    if(gear <= 5)
                    {    
                        gear++;
                        display[10] = gear+'0';
                    }
                    else if( gear == 6)
                    {    
                        display[10] = 'R';
                        
                    }
                    for( i = 0; i < 16; i++)
                    {
                        write_external_eeprom( addrs, display[i]);
                        addrs++;
                    }
                }
                else if( key == MK_SW2)
                {
                    event++;
                    if( gear > 0)
                        gear--;
                     display[10] = gear+'0';

                    for( i = 0; i < 16; i++)
                    {
                        write_external_eeprom( addrs,display[i]);
                        addrs++;
                    }    
                    
                }
                else if( key == MK_SW3)
                {
                    event++;
                    display[9] = ' ';
                    display[10] = 'C';
                   
                    for( i = 0; i < 16; i++)
                    {
                        write_external_eeprom( addrs,display[i]);
                        addrs++;
                    }   
                }
                else if( key == MK_SW8)
                {
                    flag = 2;
                }

                if(gear == 0 )
                {
                    display[9] = 'O';
                    display[10] = 'N';
                }
                else
                {
                    display[9] = 'G';
                }
                clcd_print( display, LINE2(0));   
            }  
            else
            {
                event =0;
                addrs = 1;
            }
        }
        else if( flag == 2)
        {
           // key = 0;
           flag = password_acess();     // Function call to read & validate password.
		}
        else if(flag == 3)
        {
            key = read_switches( LEVEL_CHANGE);
            display_menu(key);              // Function call to display different modes/setings inside blackbox.
        }
    }
}