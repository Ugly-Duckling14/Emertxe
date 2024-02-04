/*
Name : Munawir E
Date : 28/06/2022
Description : WAP to implement atoi function.
 Pr-requisites:-
  * Functions
  * Pointers
 Objective: -
  * Functions
  * Pointers
  Working:
   Int my_atoi(const char *s)
	* The function will recieve a string and covert the number stored in the string into exact integer number.
    * Return the number.

Sample I/P  :
 1) Enter a numeric string: 12345
 2) Enter a numeric string: -12345
 3) Enter a numeric string: +12345
 4) Enter a numeric string: +-12345
 5) Enter a numeric string: 12345-
 6) Enter a numeric string: abcd12345
 7) Enter a numeric string: 12345abcd

Sample O/P  :
 1) String to integer is 12345
 2) String to integer is -12345
 3) String to integer is 12345
 4) String to integer is 0
 5) String to integer is 12345
 6) String to integer is 0
 7) String to integer is 12345
*/

#include <stdio.h>

// FUnction declaration.
int my_atoi(const char *);

int main()
{
    // Initializing the variables.
    char str[20];

    // Reading the input.
    printf("Enter a numeric string : ");
    scanf("%s", str);

    // Fuction call, calculate the atoi values and printing the output.
    printf("String to integer is %d\n", my_atoi(str));
}

// Function definition.
int my_atoi(const char *str)
{
    // Initializing the local variable. 
    int flag = 0, num = 0, temp = str[ 1 ], i;

    // Finding the atoi values.
    while( *str != '\0' )
    {
	// Checking the 0th Index is '+' , '-' or 'integer'.
	if( str[0] == 43 || str[0] == 45 || (str[0] >= 48 && str [0] <=  57))
	{
	    // Checking the 1st Index is an integer or not.
	    if( temp >= 48 && temp <= 57)
	    {
		// Checking the given value is negative ot not.
		if( str[0] == 45)
		{
		    flag = -1;
		    str++;
		    continue;
		}
		else if( str[0] == 43)			// Checking the 1st Index is '+'.
		{
		    str++;
		    continue;
		}
		else					// Converting the string to integer.
		{
		    num = num * 10 + ( *str - 48);
		    str++;
		}
	    }
	    else			// Terminate the loop if string is not an integer.
	    {
		break;
	    }
	}
	else				// Terminate the loop if the string is not an integer. 
	{
	    break;
	}
    }

    // If number is negative converting the output to -ve.
    if( flag == -1)
    {
	num *= -1;
    }  
    return num;								// Returning the number.
}

