/*
Name : Munawir E
Date : 05/06/2022
Description : WAP to implement your own ispunct() function.
 Pr-requisites: -
  * Functions.
 Objective: -
  * Functions. 
 Ispunct() - checks  for  any  printable character which is not a space or an alphanumeric character.

Sample I/P  :
 1) Enter the character: a
 2) Enter the character: $

Sample O/P  :
 1) Entered character is not punctuation character
 2) Entered character is punctuation character
*/

#include <stdio.h>

// Function declaration.
int my_ispunct( int );

int main()
{
    // Initializing the varialbles.
    char ch;
    int ret;
    
    // Reading the input. 
    printf("Enter the character: ");
    scanf("%c", &ch);
    
    // Function call for checking the value is punctuation or not.
    ret = my_ispunct( ch);
    
    // Printing the output.
    if ( ret == 1 )
    {
    	printf("Entered character is punctuation character\n");
    }
    else
    {
    	printf("Entered character is not punctuation character\n");
    }
    return 0;
}

// Function definition for checking punctuation or not.
int my_ispunct( int ch )
{
    // Return 1 if the character is punctuation else return 0.
    return ch >= 33 && ch <= 47 || ch >= 58 && ch <= 64 || ch >= 91 && ch <= 96 || ch >= 123 && ch <= 126;
}
