/* 
Name : Munawir. E
Date : 09/10/2022
Description : Implement a static clock on SSD using internal timer
	Requirements:
        As soon as the board is powered on or reset, the clock should start at 12.00.
        The decimal point of the hours field (one’s place) should blink every 500 msecs (0.5 Hz)
        The clock format should be 24 Hrs.
		
*/

#include "main.h"

unsigned char ssd[MAX_SSD_CNT];         // Array for 4 digit ssd
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};     // Storing Digit values is array.
unsigned unsigned char flag;

void init_config()
{
    init_config_timer0();       // Function call for configure timer 0;
    init_ssd_control();         // Function call for configure ssd
}

void main(void)
{
    unsigned short int hrs = 12,mins = 0, sec = 0;

    init_config();

    while(1)
    {
        if( flag == 1 )     // Blinking the dot in one's place in hr
        {	
       		ssd[1] = ssd[1] | DOT;
   		}
        else if( flag == 2 )
         {
            flag = 0;
            sec++;
            if( sec == 119)
            {
                if( mins < 59)      // Increasing the min.
                    mins++;
                else if( hrs < 23 && mins == 59)        // Increasing the hr.
                {
                    hrs++;
                    mins = 0;
                }
                else        // Resetting hr and min when reaching 24hr.
                {
                    hrs = 0;
                    mins = 0;
                }
                sec =0;
            }

            // Assigning min and hr value in an array
            ssd[3] = digit[ mins%10];
            ssd[2] = digit[ mins/10];
            ssd[1] = digit[ hrs%10];
            ssd[0] = digit[ hrs/10];
        }
        
        display(ssd);       // Function call to display value in ssd
    }
}