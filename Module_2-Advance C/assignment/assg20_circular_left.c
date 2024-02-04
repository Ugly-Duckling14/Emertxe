/*
Name : Munawir E
Date : 3/06/2022
Description : WAP to implement Circular left shift.
 Pr-requisites:-
  * Bitwise Operators.
  * Type Modifiers.
  * Functions.
 Objective :-
  * Functions.
  * Bitwise Operators.
 -> Read a number num from user.
 -> Read a number n from user.
 -> Pass num and n to the function.
 -> Shift num, n times (towards left).
 -> While shifting the shifted bits should get replaced at the alternate end.
      * For left shifting, the shifted bits should come at right most side.
 -> Return the new number from the function.
 -> Print the new number.
 -> Example:
 	If num is -2, and n is 3, in circular_left_shift function
            12 -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0
           o/p -> 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1

Sample I/P  :
 1) Enter num: 12
    Enter n : 3
 2) Enter num: -2
    Enter n : 3

Sample O/P  :
 1) Result in Binary: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 1 0 0 0 0 0
 2) Result in Binary: 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 1 1 1
*/

#include<stdio.h>

// Function declarations.
int circular_left(int, int);
int print_bits(int);

int main()
{
    // Initializing the variables.
    int num, n, ret;

    // Reading the inputs.
    printf("Enter the num: ");
    scanf("%d", &num);
    printf("Enter n: ");
    scanf("%d", &n);

    // Function call for circular left shift.
    ret = circular_left( num, n );
    // Function call for printing the output.
    print_bits( ret );
    printf("\n");
    return 0 ;
}

// Function definition for circular_left shift.
int circular_left(int num, int n)
{
    // Calculating circular left shift and returns the output.
    return ( ( unsigned ) num >> ( 31 - n + 1 ) ) | ( ( num <<= n ) & ( ( 1 >> 31 - n ) - 1 ) );
}

// Function definition for printing the output.
int print_bits( int ret )
{
    // Initializing the variables.
    int i;

    // Printing the result in binary format.
    printf("Result in Binary: ");
    // Displays output bit by bit.
    for ( i = 31 ; i >= 0 ; i -- )
    {
	if ( ret & ( 1 << i) )
	{
	    printf("1 ");
	}
	else
	{
	    printf("0 ");
	}
    }
    return 0;
}

