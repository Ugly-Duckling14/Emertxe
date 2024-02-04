/*
Name : Munawir E
Date : 05/06/2022
Description : WAP to implement your own isblank() function.
 Pr-requisites: -
  * Functions
 Objective: -
  * Functions.
  
Sample I/P  :
 1) Enter the character: a
 2) Enter the character:    
 
Sample O/P  :
 1) Entered character is not blank character
 2) Entered character is blank character 
*/

#include<stdio.h>

// Function declaration.
int my_isblank(int);

int main ( )
{
    // Initializing the variables.
    char ch;
    int ret;

    // Reading the input.
    printf("Enter the character: ");
    scanf("%c", &ch);

    // Function call.
    ret = my_isblank( ch);

    // Printing the output.
    if ( ret == 1 )
    {
    	printf("Entered character is blank character\n");
    }
    else
    {
    	printf("Entered character is not blank character\n");
    }
    return 0 ;
}

// Function definition.
int my_isblank( int is_blank )
{
    // Returns 1 if the value is blank else return 0.
    return is_blank == 32 || is_blank == 9 ;
}
