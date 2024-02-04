/*
Name : Munawir E
Date : 05/06/2022
Description : WAP to implement your own isalnum() function.
 Pr-requisites: -
  * Functions.
 Objective: -
  * Functions.
 -> c-type library functions check whether ch, which must have the value of an unsigned char or EOF, falls into a certain character class according to the current locale.
    isalnum() - checks for an alphanumeric character; it is equivalent to (isalpha(c) || isdigit(c)).

Sample I/P  :
 1) Enter the character: a
 2) Enter the character: ?

Sample O/P  :
 1) Entered character is alphanumeric character
 2) Entered character is not alphanumeric character
*/

#include<stdio.h>

// Function declaration.
int my_isalnum( int);

int main ( )
{
    // Initializing the variables.
    char ch;
    int ret;

    // Reading the input.
    printf("Enter the character: ");
    scanf("%c", &ch);

    // Function call. 
    ret = my_isalnum( ch );

    // Printing the output.
    if ( ret == 1)
    {
    	printf("Entered character is alphanumeric character\n");
    }
    else
    {
    	printf("Entered character is not alphanumeric character\n");
    }
    return 0 ;
}

// Function definition for checking alphabets and numbers
int my_isalnum( int as_ch )
{
    // Returns 1 if the value is numbers or alphabets else returns 0.
    return as_ch >= 65 && as_ch <= 90 || as_ch >= 95 && as_ch <= 122 || as_ch >= 48 && as_ch <= 57 ;
}
