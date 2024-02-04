/*
Name : Munawir E
Date : 30/06/2022
Description : WAP to reverse the given string using iterative method.
 Pr-requisites:-
  * Strings
  * Loops
Objective: -
 * Strings
 * Loops

Sample I/P  :
 1) Enter a string : Hello World
 2) Enter a string : EMERTXE

Sample O/P  :
 1) Reverse string is : dlroW olleH
 2) Reverse string is : EXTREME
*/

#include <stdio.h>

// Function declaration.
void reverse_iterative(char *str);
int my_strlen(const char *);

int main()
{
    // Initializing the variable.
    char str[ 30 ];
    
    // Reading the input.
    printf("Enter any string : ");
    scanf("%[^\n]", str);
    
    // Function call for reverse the string.
    reverse_iterative(str);
    
    // Printing the output.
    printf("Reversed string is %s\n", str);
    return 0;
}

// Function definition for reversing the string.
void reverse_iterative(char *str)
{
    // Initializing the local variable.
    int strlen, i, temp;
    
    // Function call for finding th string length.
    strlen = my_strlen( str);

    // Reversing the string.
    for( i = 0; i < ( strlen / 2 ) ; i++ )
    {     
	    temp = str[ i ];
	    str[ i ] = str[ strlen - 1- i ];
	    str[ strlen - 1 - i ] = temp;
    }
}

// Function definition for finding string length.
int my_strlen(const char *str)
{
    int strlen = 0;
    while( *str++ != '\0' )
    {
    	strlen++;
    }
    return strlen;
}
