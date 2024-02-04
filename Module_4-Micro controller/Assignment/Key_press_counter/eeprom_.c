#include "main.h"

// Function definition for read internal EEPROM.
unsigned char read_internal_eeprom(unsigned char address)
{
    EEADR = address;        // Assigning EEPROM address.

    EEPGD = 0;      // Access data EEPROM memory
    CFGS = 0;       // Access Flash program or data EEPROM memory

    WREN = 0;       // Disable write cycle to EEPROM.

    RD = 1;         // Initiates an EEPROM read

    return EEDATA;      // Returns EEPROM data.

}

// Function definition for Write in internal EEPROM.
unsigned char write_internal_eeprom( unsigned char address, unsigned char data)
{
    EEADR = address;        // Assigning EEPROM address.
    EEDATA = data;          // Assigning EEPROM data.
    EEPGD = 0;              // Access data EEPROM memory.
    CFGS = 0;               // Access Flash program or data EEPROM memory
    WREN = 1;               //  Allows write cycles to Flash program/data EEPROM

    GIE = 0;            // Disabling Global interrupt enable.

    EECON2 = 0x55;      
    EECON2 = 0xAA;
    WR = 1;             // Initiates data EEPROM erase/write cycle.
    while( !EEIF );     // Poll checking for write is complete or not
        EEIF = 0;       
    GIE = 1;            // Enabling Global interrupt enable

    WREN = 0;           // Write cycle to the EEPROM is complete
}