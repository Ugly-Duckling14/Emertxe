/*
Name : Munawir E
Date : 27/06/2022
Description :WAP to replace each string of one or more blanks by a single blank
 Pr-requisites:-
  * Functions
  * Pointers
 Objective: -
  * Functions
  * Pointers  

Sample I/P  :
 1) Enter the string with more spaces in between two words
    Pointers     are               sharp     knives.
 2) Enter the string with more spaces in between two words
    Welcome                to Emertxe
 3) Enter the string with more spaces in between two words
    Welcome to Emertxe
Sample O/P  :
 1) Pointers are sharp knives.
 2) Welcome to Emertxe
 3) Welcome to Emertxe
*/

#include <stdio.h>

// Function Declaration
void replace_blank(char *);

int main()
{
    // Initializing the variables
    char str[50];

    // Reading the input.
    printf("Enter the string with more spaces in between two words\n");
    scanf("%[^\n]", str);

    // Function call.
    replace_blank(str);

    // Printing the output.
    printf("%s\n", str);
    return 0;
}

// Function definition for remove extra blanks.
void replace_blank(char *str)
{
    // Initializing the variables.
    int i=0, j;

    // Checking character is blank or not.
    while( str[ i ] != '\0')
    {
	if( str[ i ] == 32 && str[ i ] == str[ i + 1 ] )
	{
	    for( j = i ;  str[j] != '\0'; j++ )
	    {
		str[ j ] = str[j+1];
	    }
	    str[j] ='\0';
	    i--;
	}
	i++;
    }
}
