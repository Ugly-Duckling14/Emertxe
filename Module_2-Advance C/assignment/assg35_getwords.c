/*
Name : Munawir E
Date : 25/06/2022
Description : WAP to implement getword function
 Pr-requisites:-
  * Functions
  * Pointers
 Objective: -
  * Functions
  * Pointers

Sample I/P  :
 1) Enter the string : Welcome to Emertxe
 2) Enter the string : Hello

Sample O/P  :
 1) You entered Welcome and the length is 7
 2) You entered Hello and the length is 5
*/

#include <stdio.h>

// Function declaration.
int getword(char *str);

int main()
{
    // Initializing the variables.
    int len = 0;
	char str[ 100 ];

    // Reading the input.
	printf("Enter the string : ");
	scanf(" %[^\n]", str);

    // Function call.
	len = getword(str);

    // Printing the output.
    printf("You entered %s and the length is %d\n", str, len);
    return 0;
}

// Function definition.
int getword(char *str)
{
    // Initializing the local variables.
    int length = 0;

    // Finding the the length of 1st word.
    while( str[length] != 32 && str[ length ] != '\0')
    {
    	length++;
    }
    str[length] = '\0';
    return length;
}
