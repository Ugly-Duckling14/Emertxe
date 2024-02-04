#ifndef External_EEPROM_H
#define External_EEPROM_H

#define EXT_EEPROM_READ		0xA1
#define EXT_EEPROM_WRITE	0xA0



//void init_external_eeprom(void);
void write_external_eeprom(unsigned char address,  unsigned char data);
unsigned char read_external_eeprom(unsigned char address);

#endif
