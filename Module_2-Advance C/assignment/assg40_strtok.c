/*
Name : Munawir E
Date : 01/07/2022
Description : WAP to implement strtok function
 Pr-requisites:-
  * Storage Classes
  * Strings
  * Pointers
 Objective: -
  * Strings
  * Pointers

Sample I/P  :
 1) Enter string1 : Bangalore;;::---Chennai:;Kolkata:;Delhi:-:Mumbai
    Enter string2 : ;./-:
 2) Enter string1 : -;Bangalore;;::---Chennai:;Kolkata:;Delhi:-
	Enter string2 : ;./-:

Sample O/P  :
 1) Tokens :
    Bangalore
	Chennai
	Kolkata
	Delhi
	Mumbai
 2) Tokens :
	Bangalore
	Chennai
	Kolkata
	Delhi
*/

#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>

// Function declaration.
char *my_strtok(char * str, const char *delim);

int main()
{
	// Initializing the variables.
    char str[100], delim[50];
    
	// Reading the input.
    printf("Enter the string  : ");
    scanf("%[^\n]", str);
    __fpurge(stdin);
 
    printf("Enter the delimeter : ");
    scanf("%[^\n]", delim);
    __fpurge(stdin);
    
	// Function call for string token.
    char *token = my_strtok(str, delim);
    
	// Printing the output.
	printf("Tokens :\n");       
 	while (token != NULL)
    {
        printf("%s\n", token);
        token = my_strtok( NULL, delim);
    }
}

// Function definition.
char *my_strtok(char * str, const char *delim)
{
	// Initializing local variables.
    static char *next_str;   
    int i, flag = 0;
   
    // Checking string is Null or not.
    if( str != NULL)
    {
    	next_str = str;
    }
    char *start = next_str;
   
	// Splitting the string by using delimiter.
    while( *next_str != '\0' )
    {
    	i = 0;
    	while( delim[ i ] != '\0' )
		{ 
	    	if( *start == delim[ i ] )			// Checking start address is delimiter, if true then update start address to next index.
	    	{
	    		start = next_str +1;
	    		break;
	    	}

	    	if( *next_str == delim[ i ]  )      // If delimiter found split the string.
      	    {
      	    	*next_str = '\0';
      	    	flag = 1;
      	    	break;
      	    }
	    	i++;
    	}
    	next_str++;

		// Returning the start address.
    	if( flag == 1 ||  ( *next_str == '\0' && *start != '\0' ) )
		{
	    	return start;
		}
    }
}

