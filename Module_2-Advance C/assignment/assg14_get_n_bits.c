/*
Name : Munawir E
Date : 23/05/2022
Description : WAP to get 'n' bits of a given number.
 * If num is 10 and n is 2,
 10 -> 0 0 0 0 1 0 1 0 
 Take 2 bits from LSB end of 10 (1 0) and return the corresponding decimal of that. 
 So get_nbits(10, 2) function should return 2
 Pre-requisites.
 * Bitwise operators
 * Functions

 Sample I/P  :
 1) Enter the number: 10
 Enter number of bits: 3
 2) Enter the number: 15
 Enter number of bits: 2

 Sample O/P  :
 1) Result = 2
 2) Result = 3
 */

#include<stdio.h>

int get_nbits(int, int);  // Function declaration.

int main()
{
    // Initializing the variables.
    int number ,N,res;

    // Reading the inputs.
    printf("Enter the number: ");
    scanf("%d",&number);
    printf("Enter number of bits: ");
    scanf("%d",&N);

    // Function call.
    res = get_nbits(number, N);

    // Printing the output.
    printf("Result = %d\n",res);
    return 0 ;
}

// Function definition.
int get_nbits(int number, int N)
{
    // Getting N bits.
    return ( number & (1 << N ) - 1 ) ;
}
