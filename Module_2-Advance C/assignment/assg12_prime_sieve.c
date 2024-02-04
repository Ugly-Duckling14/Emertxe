/*
Name : Munawir E
Date : 24/05/2022
Description : WAP to print all primes using Sieve of Eratosthenes method.
 * In mathematics, the sieve of Eratosthenes, one of a number of prime number sieves, is a simple, ancient algorithm for finding all prime numbers up to any given limit. It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the multiples of 2.
 * The sieve of Eratosthenes is one of the most efficient ways to find all of the smaller primes. It is named after Eratosthenes of Cyrene, a Greek mathematician.
 Pre-requisites.
 * Loops.
 * Operators.
 * Arrays.
 Objectives.
 * To understand the concept of if-else constructs
 * Arrays

 Sample I/P  :
 1) Enter the value of 'n' : 20
 2) Enter the value of 'n' : -20

 Sample O/P  :
 1) The primes less than or equal to 20 are : 2, 3, 5, 7, 11, 13, 17, 19
 2) Please enter a positive number which is > 1
 */

#include<stdio.h>

int main ()
{
    // Initializing the variables. 
    int N, i, j;

    // Reading input from user.
    printf("Enter the value of 'n' : ");
    scanf("%d", &N);

    // Checking the number is greater than 1 or not.
    if ( N > 1 )
    {
	// Initializing  the array.
	int array[ N - 1 ];

	// Generating array from 2 to N natural numbers.
	for ( i = 0 ; i <= N - 1 ; i++ )
	{
	    array[ i ] = i + 2 ;
	}

	// Finding the prime number from 2 to N values.
	for ( i = 2 ; i <= N / 2 ; i ++ )
	{
	    for ( j = 2 ; i * j <= N ; j ++ )
	    {
		//  Checking Non-Prime values are zero or not. If not it will set to zero.
		if ( array[ i * j - 2 ] != 0 )
		{
		    array[ i * j - 2 ] = 0 ;    
		}
	    }
	}

	// Printing the output.
	printf("The primes less than or equal to %d are : ", N);
	for ( i = 0 ; i < N - 1 ; i ++)
	{
	    if ( array[ i ] != 0 )
	    {
		printf("%d, ", array[ i ] ) ;
	    }
	}
	printf("\n");
    }

    // If the number is not greater than 1 display error message.
    else 
    {
	printf("Please enter a positive number which is > 1\n");
    }
    return 0 ;
}

