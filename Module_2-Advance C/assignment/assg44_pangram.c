/*
Name : Munawir E
Date : 02/07/2022
Description : WAP to check given string is Pangram or not
 Pre-requisites:
  * Strings
  * Functions
  * Pointers
 Objective:
  * Strings
  * Functions
  * Pointers
Sample I/P  :
 1) Enter the string: The quick brown fox jumps over the lazy dog
 2) Enter the string: The quick brown fox jumps over the dog

Sample O/P  :
 1) The Entered String is a Pangram String
 2) The Entered String is not a Pangram String
*/

#include <stdio.h>

// Function declaration.
int pangram(char *);

int main()
{
    // Initializing the variables.
    char str[ 50 ];

    // Reading the input.
    printf("Enter the string : ");
    scanf("%[^\n]", str);
    
    // Printing the output.
    if( pangram(str) )          // Function call.
    {
        printf("The Entered String is a Pangram String\n");
    }
    else
    {
        printf("The Entered String is not a Pangram String\n");
    }

}

// Function definition.
int pangram(char * str)
{
    // Initializing the local variables.
    int array[ 26 ] = { 0 }, i = 0;
    
    // Finiding pangram.
    while( str[ i ] != '\0')
    {
        if( ( str[ i ] >= 65 && str[ i ] <= 90 ) || ( str[ i ] >= 97 && str[ i ] <= 127 ) )
        {
            if( str[ i ] <= 90)
            {
                array[ str[ i ] - 65 ] = 1;
            }
            else
            {
                array[ str[ i ] - 97 ] = 1;
            }
        }
        i++;
    }

    // If string is not pangram returns 0.
    for( i = 0; i< 26; i++)
    {
        if( array[ i ] != 1)
        {
            return 0;
        }
    }
    // If string is pangram then returns 1.
    return 1;
}