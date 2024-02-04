/*
Name : Munawir E
Date : 05/06/2022
Description : WAP to implement your own islower() function.
 Pr-requisites: -
  * Functions.
 Objective: -
  * Functions.
 Note  :-  c-type library functions check whether ch, which must have the value of an unsigned char or EOF, falls into a certain character class according to the current locale.
        islower() - checks for a lower case alphabet whether entered character is between 'a' to 'z'.

Sample I/P  :
 1) Enter the character: a
 2) Enter the character: 3

Sample O/P  :
 1) Entered character is lower case alphabet
 2) Entered character is not lower case alphabet
*/

#include <stdio.h>

// Function declaration.
int my_islower(int);

int main()
{
    // Initializing the variable.
    char ch;
    int ret;

    // Reading the input.
    printf("Enter the character: ");
    scanf("%c", &ch);

    // Function call checking islower.
    ret = my_islower( ch );

    // Printing the output.
    if ( ret == 1 )
    {
	printf("Entered character is lower case alphabet\n");
    }
    else
    {
	printf("Entered character is not lower case alphabet\n");
    }
    return 0;
}

// Function definition for check the character is lower or not.
int my_islower( int ch )
{
    // return 1 if the character is in lower else returns 0.
    return ch >= 97 && ch <= 122 ;
}

