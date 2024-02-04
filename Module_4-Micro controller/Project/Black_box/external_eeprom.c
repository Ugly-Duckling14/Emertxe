#include "main.h"

/* Function to Write data to external EEPROM
 * Inputs : char variables address - Where data to be stored & data - What data to be stored.
 * Output : returns NIL.
 */
void write_external_eeprom(unsigned char address, unsigned char data)
{
	i2c_start();
	i2c_write(EXT_EEPROM_WRITE);
	i2c_write(address);
	i2c_write(data);
	
	i2c_stop();
	for( int i = 1000; i--;);
}

/* Function to read data from external EEPROM.
 * Inputs : char address - used to pass external EEPROM address from data to be fetch.
 * Output : Returns the data - value fetched from EEPROM
 */
unsigned char read_external_eeprom(unsigned char address)
{
	unsigned char data;

	i2c_start();
	i2c_write(EXT_EEPROM_WRITE);
	i2c_write(address);
	i2c_rep_start();
	i2c_write(EXT_EEPROM_READ);
	data = i2c_read();
	i2c_stop();

	return data;
}
