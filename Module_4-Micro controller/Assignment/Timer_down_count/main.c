#include "main.h"

static unsigned char ssd[MAX_SSD_CNT];
static unsigned char digit[] = {ZERO, ONE,TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE};
unsigned char state = 0;

void init_config()
{
    init_digital_keypad();
    init_ssd_control();
    init_config_timer0();

    TRISE0 &= 0;
    ADCON1 = 0x0f;
    PORTE = 0;
    GIE = 1;
    PEIE = 1;
}

void main(void)
{
    unsigned short key, mode = 1, flag = 0, min = 0, sec = 0;

    init_config();

    while(1)
    {
        key = read_digital_keypad(STATE_CHANGE);

        if(key == SWITCH4)
        {
            mode = 1;
            flag = 0;
        }

        if( mode)
        {
            key = read_digital_keypad(LEVEL);
            
            if( key == SWITCH1)
            {
                if(flag )
                {
                    if( ++min ==  100)
                    {
                        min = 0;
                    }
                }
                else
                {
                    if( ++sec == 60)
                    {
                        sec = 0;
                    }
                }

            }
            else if( key == SWITCH2)
            {
                if(flag)
                {
                    if( min-- == 0)
                    {
                        min = 99;
                    }
                }
                else
                {
                    if( sec-- == 0)
                    {
                        sec = 59;
                    }
                }   
            }
            else if( key == SWITCH3)
            {
                flag = !flag;
            }
            else if( key == SWITCH4)
            {
                mode = 0;
            }
            
            if(state == 1 && flag)
            {
                ssd[3] = digit[sec%10];
                ssd[2] = digit[sec%100/10];
                ssd[1] = digit[min%10];
                ssd[0] = digit[ min%100/10];
            }
            else if(state == 1 )
            {
                ssd[3] = digit[sec%10];
                ssd[2] = digit[sec%100/10];
                ssd[1] = digit[min%10];
                ssd[0] = digit[ min%100/10];
            }
            else if( state == 2 && flag)
            {
                ssd[3] = digit[sec%10];
                ssd[2] = digit[sec%100/10];
                ssd[1] = BLANK;
                ssd[0] = BLANK;
                state =0;

            }
            else if( state == 2)
            {
                ssd[3] = BLANK;
                ssd[2] = BLANK;
                ssd[1] = digit[min%10];
                ssd[0] = digit[ min%100/10];
              //  display(ssd);
                state=0;
            }
           BUZZER = 0;
        }
        else
        {
            if( state == 1)
            {
                ssd[3] = digit[sec%10];
                ssd[2] = digit[sec%100/10];
                ssd[1] = digit[min%10];
                ssd[0] = digit[ min%100/10];
            }
            if( state == 2)
            {
                if( sec-- == 0 )
                {
                    sec = 59;
                    min--;
                }   
                
                if( min == 0 && sec == 0)
                {
                    mode = 1;
                    flag = 0;
                    BUZZER = 1;
                }
                state = 0;  
                ssd[1] = ssd[1]|DOT;   
            } 
        }
        display(ssd);
    }
}
