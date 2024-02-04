#include <xc.h>

void init_i2c(void)
{
	/* Set SCL and SDA pins as inputs */
	TRISC3 = 1;
	TRISC4 = 1;
	/* Set I2C master mode */
	SSPCON1 = 0x28;

	SSPADD = 0x31;
	/* Use I2C levels, worked also with '0' */
	CKE = 0;
	/* Disable slew rate control  worked also with '0' */
	SMP = 1;
	/* Clear SSPIF interrupt flag */
	SSPIF = 0;
	/* Clear bus collision flag */
	BCLIF = 0;
}

void i2c_idle(void)
{
	while (!SSPIF);
	SSPIF = 0;
}

void i2c_ack(void)
{
	if (ACKSTAT)
	{
		/* Do debug print here if required */
	}
}

/* Funtion to Sent start bit in i2c Bus*/
void i2c_start(void)
{
	SEN = 1;
	i2c_idle();
}

/* Function to sent Stop bit in i2c Bus.*/
void i2c_stop(void)
{
	PEN = 1;
	i2c_idle();
}

/* Function to repeat the start from 12c BUS ( ex:- when reading data 1st we've to pass address as write mode,
 *  then again to we've to set the data line to read mode to get data without senting stop bit, inorder to avoid 
 *  other nodes to communicate)
 */
void i2c_rep_start(void)
{
	RSEN = 1;
	i2c_idle();
}

/* Function to Write data through i2c Bus */
void i2c_write(unsigned char data)
{
	SSPBUF = data;
	i2c_idle();
}

void i2c_rx_mode(void)
{
	RCEN = 1;
	i2c_idle();
}

void i2c_no_ack(void)
{
	ACKDT = 1;
	ACKEN = 1;
}

/* Function to read data through i2c Bus */
unsigned char i2c_read(void)
{
	i2c_rx_mode();
	i2c_no_ack();

	return SSPBUF;
}
