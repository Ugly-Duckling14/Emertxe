#include "main.h"



void main(void)
{
    unsigned long count = 0;
    init_clcd();
    
    clcd_print( "  UP COUNTER    ", LINE1(0));

    while(1)
    {
            clcd_print( "  UP COUNTER    ", LINE1(0));

        count++;
        if( count != 9999999999)
        {
            clcd_print( count, LINE2(3));
        }
        else
            count = 0;
    }
}