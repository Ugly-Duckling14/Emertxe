/*
Name : Munawir E
Date : 3/06/2022
Description : WAP to implement Circular right shift.
 Pr-requisites:-
  * Bitwise Operators
  * Type Modifiers
  * Functions
 Objective: -
  * To understand the concept of
       -> Functions
       -> Bitwise Operators
 Steps :-
  -> Read a number num from user.
  -> Read a number n from user.
  -> Pass num and n to the function.
  -> Shift num, n times (towards right).
  -> While shifting the shifted bits should get replaced at the alternate end.
      For right shifting, the shifted bits should come at left most side.
  -> Return the new number from the function.
  -> Print the new number.
  -> Example:- 
 	If num is 12, and n is 3, in circular_right_shift function
            12 -> 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0
           o/p -> 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
Sample I/P  :
 1) Enter num: 12
    Enter n : 3
 2) Enter num: -12
    Enter n : 3
Sample O/P  :
 1) Result : 10000000 00000000 00000000 00000001
 2) Result : 10011111 11111111 11111111 11111110
*/

#include<stdio.h>

// Function Declaration.
int circular_right( int, int );
int print_bits( int );

int main ()
{
    // Initializing the variables.
    int num, n, ret;

    // Reading input from User.
    printf("Enter the num: ");
    scanf("%d", &num);
    printf("Enter n: ");
    scanf("%d", &n);

    // Function call for circular right shift.
    ret = circular_right( num, n);

    // Function call for printing the output.
    print_bits ( ret );
    printf("\n");
    return 0 ;
}

// Function definition for circular right shift. 
int circular_right ( int num, int n ) 
{
    // Doing circular right shift and returns the output.
    return  ( num << 31 - n + 1 ) | ( ( num >>= n )  & ( ( 1 << 32 - n ) - 1) ) ;
}

// Function definition for printing output.
int print_bits( int ret )
{
    // Initializing the variable.
    int i;

    // Printing the output.
    printf("Result : ");

    // Printing the output in bit by bit, from MSB to LSB.
    for ( i = 31 ; i >= 0 ; i -- )
    {
	// Checking the Bit is one or zero.
	if ( ret & ( 1 << i ) )
	{
	    printf("1");
	}
	else
	{
	    printf("0");
	}

	// Printing space between each byte.
	if ( i % 8 == 0 )
	{
	    printf(" ");
	}
    }
    return 0;
}

