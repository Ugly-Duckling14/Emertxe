#ifndef MODES_H
#define MODES_H

#define DELAY 1000

/* Function declaration to display menu */
void display_menu( unsigned char key);

/* Function declaration to display logs in clcd*/
unsigned char view_log();

/* Function declaration to to display log on system / Download logs */
unsigned char download_log();

/* Function declaration to clear logs */
unsigned char clear_log();

/* Function declaration to give blocking delay */
void __delay( unsigned short int delay);

/* Function declaration to copy the string */
char *my_strcpy( char *dest, const char *src);

#endif