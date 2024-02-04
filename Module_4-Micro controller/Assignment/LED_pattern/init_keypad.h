#ifndef INIT_KEYPAD_H
#define INIT_KEYPAD_H

#define KEY_PORT					PORTC

#define SWITCH1					0x0E
#define SWITCH2					0x0D
#define SWITCH3					0x0B
#define SWITCH4					0x07
#define ALL_RELEASED			0x0F
#define INPUT_PINS              0x0F

void init_keypad(void);
unsigned int read_inputs();


#endif