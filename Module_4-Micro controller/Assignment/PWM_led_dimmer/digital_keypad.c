#include "main.h"

// Function to configure digital keypad.
void init_digital_keypad(void)
{
	TRISC = TRISC | INPUT_PINS;
}

// Function to read input from digital keypad.
unsigned char read_digital_keypad(unsigned char detection_type)
{
	static unsigned char once = 1;

	// if detection then edge trigering 
	if (detection_type == STATE_CHANGE)
	{
		if (((KEY_PORT & INPUT_PINS) != ALL_RELAEASED) && once)
		{
			once = 0;

			return (KEY_PORT & INPUT_PINS);
		}
		else if ((KEY_PORT & INPUT_PINS) == ALL_RELAEASED)
		{
			once = 1;
		}
	}
	else if (detection_type == LEVEL)		// if detection type is 0 then level trigger.
	{
		return (KEY_PORT & INPUT_PINS);
	}

	return 0xFF;
}
