#ifndef PASSWD_H
#define PASSWD_H

/* Function declaration to enter password */
unsigned char password_acess();

/* Function declaration to validate password */
unsigned int password_valid(unsigned short value, unsigned short password);

/* Function declaration to set the password */
void set_password(); 

#endif