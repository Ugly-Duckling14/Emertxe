/*
Name : Munawir E
Date : 1/06/2022
Description : WAP to print 'n' bits from LSB of a number.
 Pre-requisites :-
  * Bitwise operators.
  * Functions.
 Steps :-
  a. Read number num from user.
  b. Read number n from user.
  c. Do error checking
     -> If n is greater than integer size, assign n value as sizeof integer.
  d. Print n number of bits of num from LSB end.
     If num is 10 and n is 12, then print last 12 bits of binary representation of 10.
     The output should be -> 0 0 0 0 0 0 0 0 1 0 1 0

Sample I/P  :
 1) Enter the number: 10
    Enter number of bits: 12
 2) Enter the number: 15
    Enter number of bits: 4

Sample O/P  :
 1) Binary form of 10: 0 0 0 0 0 0 0 0 1 0 1 0 
 2) Binary form of 15: 1 1 1 1
*/

#include<stdio.h>

// Function declaration.
int print_bits(int, int);

int main()
{
    // Initializing the variables.
    int num, n;

    // Reading the input.
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter number of bits: ");
    scanf("%d", &n);

    // Printing the output.
    printf("Binary form of %d: ", (num & ~ ( 1 << n )));
    // Function call for  Printing bits.
    print_bits(num, n);
    printf("\n");
    return 0 ;
}

// Function definition for printing bits.
int print_bits(int num, int n)
{
    // Initializing the variables.
    int i;

    // Printing number in bits bit for the specified length.
    for ( i = n - 1 ; i >= 0 ; i -- )
    {
    	if ( num & ( 1 << i) ) 
	{
	    printf("1 ");
	}
	else
	{
	    printf("0 ");
	}
    }
    return 0 ;
}
