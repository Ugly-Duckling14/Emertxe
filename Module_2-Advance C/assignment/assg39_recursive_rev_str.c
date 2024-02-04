/*
Name : Munawir E
Date : 30/06/2022
Description : WAP to reverse the given string using recursive method.
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
void reverse_recursive(char *str, int ind, int len);
int my_strlen(const char *str);

int main()
{
    // Initializing the variables.
    char str[30],strlen;

    // Reading the input.
    printf("Enter any string : ");
    scanf("%[^\n]", str);

    // Function call for finding the string length.
    strlen= my_strlen(str);
   
    // Function call for reversing the string.
    reverse_recursive(str, 0 ,  (strlen));

    // Printing the output.
    printf("Reversed string is %s\n", str);
}

// Function definition for reversing the string.
void reverse_recursive(char *str, int ind, int len)
{
    // Initializing the local variables.
    int temp;

    // Reversing the string.
    if( ind < ( len / 2 ) )  
    {
	    temp = str[ ind ];
	    str[ ind ] = str[ len -1 - ind ];
	    str[ len -1 - ind ] = temp;
        ind++;
	    reverse_recursive(str, ind ,  len);         // Recursive call.
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
