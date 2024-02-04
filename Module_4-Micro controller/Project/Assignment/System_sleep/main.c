#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
unsigned short count = 0;
bit key_detected;

void init_config()
{
    PEIE =1;
    GIE = 1;
    ADCON1 = 0x0f;
    TRISB0 = 1;
    TRISB1 = 0;
    
    LED1 = 1;
   
    init_config_timer0();
    init_ssd_control();
    init_external_interrupt();
}


void main(void)
{
    init_config();

    while(1)
    {   
        if( count < 5)
        { 
            ssd[0] = ONE;
            ssd[1] = TWO;
            ssd[2] = THREE;
            ssd[3] = FOUR;
        }
        else
        {
            ssd[0] = FOUR;
            display(ssd);
            SLEEP();
        }
            
        display(ssd);

        if (key_detected)
		{
			key_detected = 0;
            count = 0;  
        }
    }
}
