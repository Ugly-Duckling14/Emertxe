#include "main.h"

// Initializing digital keypad
void init_digital_keypad(void)
{
	TRISC = TRISC | INPUT_PINS;
}

// Function definition for read digital keypad
unsigned char read_digital_keypad(unsigned char detection_type)
{
	static unsigned char once = 1;

	// If detection type is 1 switch edge trigger
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
	else if (detection_type == LEVEL)		// If detection type is 0 level trigger.
	{
		return (KEY_PORT & INPUT_PINS);
	}

	return 0xFF;		// If key is not pressed
}
