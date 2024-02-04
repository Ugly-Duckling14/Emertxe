/*
Name : Munawir E
Date : 26/05/2022
Description : WAP to toggle 'n' bits from given position of a number.
a. Read number num from user.
b. Read number n from user.
c. Read number pos from user.
d. Invert the n number of bits from pos positionth bit of num.
e. Return the new value of num
If num is 10, n is 3, and pos is 5
7 6 5 4 3 2 1 0
10 -> 0 0 0 0 1 0 1 0
return value -> 0 0 1 1 0 0 1 0
So the function should return 50 (0 0 1 1 0 0 1 0)
Pre-requisites.
 * Bitwise operators
 * Functions

 Sample I/P  :
 1) Enter the number: 10
 Enter number of bits: 3
 Enter the pos: 5
 2) Enter the number: 15
 Enter number of bits: 2
 Enter the pos: 2

 Sample O/P  : 
 1) Result = 50
 2) Result =  9

*/

#include <stdio.h>

int toggle_nbits_from_pos(int, int, int );	// Function declaration.

int main ()
{
    // Initializing the variable.
    int num, n, pos, res = 0;

    // Reading the input.
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter number of bits: ");
    scanf("%d", &n);
    printf("Enter the pos: ");
    scanf("%d", &pos);

    // Function call.
    res = toggle_nbits_from_pos( num, n, pos );

    // Printing the output.
    printf("Result = %d\n", res);
    return 0 ;
}

// Function definition.
int toggle_nbits_from_pos( int num, int n, int pos)
{
    // Toggle N bits from the given position.
    return num ^ ( ( 1 << n ) - 1 ) << ( pos - n + 1 );
}

