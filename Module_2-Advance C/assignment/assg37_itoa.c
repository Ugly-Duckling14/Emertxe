/*
Name : Munawir E
Date : 29/06/2022
Description : WAP to implement itoa function
 Pr-requisites:-
  * Functions
  * Pointers
 Objective: -
  * Functions
  * Pointers
 Working :-
    int itoa(int n, char *s)
     * Convert integer n into a string and store the string in s.
     * Return the length of string from the function.
Sample I/P  :
 1) Enter the number : 1234
 2) Enter the number : -1234
 3) Enter the number : +1234
 4) Enter the number : a1234

Sample O/P  :
 1) Integer to string is 1234
 2) Integer to string is -1234
 3) Integer to string is 1234
 4) Integer to string is 0
*/

#include <stdio.h>

// Function declaration.
int itoa(int num, char *str);

int main()
{
	// Initializing the variables.
    int num;
    char str[10];

	// Reading the input.
    printf("Enter the number : ");
    scanf("%d", &num);

	// Function call.
    itoa(num, str);

	// Printing the output.
    printf("Integer to string is %s\n", str);
}

// Function definition.
int itoa(int num, char *str)
{
	// Initializing the local variable.
    int flag = 0, rev = 0, i = 0,  temp;

	// Checking the input is integer or not.
    if( num != 0 )
    {
		// Checking number is negative or positive.
		if( num < 0)
		{
	    	flag= -1;

		}

		// Reversing the number
		while( num != 0 )
		{
	    	temp = num % 10;
	    	rev = rev * 10 +  temp;
	    	num = num / 10;
		}

		// Rearranging the number and storing as string.
		while( rev != 0)
		{
			// If number is negative storing 0th Index as - of the string.
	    	if( flag  == -1)
	    	{
				flag = 0;
				str[i] =  flag + 45 ;
				i++;
	    	}

	    	temp = rev % 10;
	    	
			if(str[ 0 ] == 45 )		// If the number is negative converting to positive.
	   		{
				temp *= -1;
	    	}
	    	str[ i ] = temp + 48;
	    	rev = rev / 10;
	    	i++;
		}
    }
    else		// If the input is not an integer  stores 0 into the string.
    {
		str[ i ]  = 48;
		i++;
		printf("num %d\n",num);
    }
    str[i] = '\0';		// Converting last Index to null character.
    return 0;
}

