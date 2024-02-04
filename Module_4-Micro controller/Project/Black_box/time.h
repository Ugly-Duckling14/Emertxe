#ifndef TIME_H
#define TIME_H

/* Function declaration to get the time from RTC*/
void get_time(void);

/* Function declaration to set the time*/
unsigned char set_time();

/* Function declaration to store time to RTC*/
void store_time(unsigned short int *arr);

#endif