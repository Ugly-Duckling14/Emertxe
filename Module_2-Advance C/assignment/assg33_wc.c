/*
Name : Munawir E
Date : /06/2022
Description :WAP to count no. of characters, words and lines, entered through stdin
 Objective: -
  * Standard input & output
Sample I/P  :
 1) Hello world
    Dennis Ritchie
    Linux
 2) Hello         world
    Dennis    Ritchie
    Linux

Sample O/P  :
 1) Character count : 33
    Line count : 3
    Word count : 5
 2) Character count : 39
    Line count : 3
    Word count : 5
*/

#include<stdio.h>

int main()
{
    // Initializing the variables.
    int word_count = 0, line_count = 0, char_count = 0;
    char temp, str;

    // Reads the characters till encounters EOF & counts the number of words,lines & character.
    while( str != EOF )
    {
	// Reading input character by charactr from user till EOF.
	str = getchar();

	char_count++;				// Counting the number of characters.   				
	if( str == 32 || str == 9 || str == 10 )
	{ 	
	    if( str != temp && temp != 9 && temp != 32 )
	    {
		word_count++;			// Counting the number of words.
	    }
	}
	if( str == '\n')
	{
	    line_count++;                      // Counting the line numbers.
	}
	temp = str;
    }

    // Printing the output.
    printf("Character count : %d\nLine count : %d\nWord count : %d\n", char_count, line_count, word_count);
    return 0 ;
}
