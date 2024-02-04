/*
Name : Munawir E
Date : 26/05/2022

Description : WAP to get 'n' bits from given position of a number.
a. Read number num from user.
b. Read number n from user.
c. Read number pos from user.
d. Fetch n number of bits from given position 'pos' (starting from LSB) of num and return the decimal value of it.
If num is 12, n is 3 and pos is 4
7 6 5 4 3 2 1 0
12 -> 0 0 0 0 1 1 0 0 
The program should print 3 (0 1 1).
Pre-requisites.
 * Bitwise operators
 * Functions

 Sample I/P  :
 1) Enter the number: 12
 Enter number of bits: 3
 Enter the pos: 4
 2) Enter the number: 15
 Enter number of bits: 2
 Enter the pos: 2

 Sample O/P  :
 1) Result = 3
 2) Result =  3

*/

#include <stdio.h>

int get_nbits_from_pos(int, int, int);	// Function declaration.

int main ()
{
    // Initializing the variables.
    int num, N, pos, res = 0;

    //  Reading the input.
    printf("Enter the number: ");
    scanf("%d", &num );
    printf("Enter number of bits: ");
    scanf("%d", &N );
    printf("Enter the pos: ");
    scanf("%d", &pos );

    // Function call.
    res = get_nbits_from_pos( num, N, pos);

    // Printing the output.
    printf("Result = %d\n", res);

    return 0;
}

// Function definition
int get_nbits_from_pos( int num, int n, int pos)
{
    // Getting N bits from the position.
    //return ( num  & ((( 1 << n ) -1) << pos-n + 1 )) >> (pos -n + 1)  ;
    return ( num >> ( pos - n + 1 ) & ( ( 1 << n ) - 1 ) );
}
