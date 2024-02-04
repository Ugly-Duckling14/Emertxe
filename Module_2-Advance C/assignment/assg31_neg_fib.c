/*
Name : Munawir E
Date : 06/06/2022
Description : WAP to generate negative fibbonacci numbers using recursion
 Pr-requisites:-
  * Arithmetic Operators.
  * Recursions.
 Objective: -
  * Recursive Functions.
 Note :- In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers in the following integer sequence  0, 1, -1, 2, -3, 5, -8, 13, -21, 34, -55, 89, -144 . . .
  By definition, the first two numbers in the Fibonacci sequence are 0 and 1, each subsequent number is the subtraction of the previous two
Sample I/P  :
 1) Enter a number: -8
 2) Enter a number: -10
 3) Enter a number: -21
 4) Enter a number: 21

Sample O/P  :
 1) 0, 1, -1, 2, -3, 5, -8
 2) 0, 1, -1, 2, -3, 5, -8
 3) 0, 1, -1, 2, -3, 5, -8, 13, -21
 4) Invalid input
 */

#include <stdio.h>

// Function declaration.
void negative_fibonacci(int, int, int, int);

int main()
{
    // Initializing the variables.
    int limit;

    // Reading the output.
    printf("Enter the limit : ");
    scanf("%d", &limit);

    // Function call for finding negative fibonacci series.
    negative_fibonacci(limit, 0, 1, 0);
    return 0;
}

// Function definition for negative fibonacci series.
void negative_fibonacci(int limit, int term1, int term2, int fibonacci)
{
    // Checking number is negative or equal to zero. If true it executes if statements
    if( limit <= 0 )
    {
	// Finding the negative fibonacci numbers between the specified range. 
	if( fibonacci >= limit &&  -fibonacci >= limit )
	{
	    printf("%d", fibonacci);	// Printing the output.

	    // Swapping the values.
	    term1 = term2 ;
	    term2 = fibonacci ;
	    // Subtracting term1 and term2 and assigning to fibonacci.
	    fibonacci = term1 - term2 ;
	    if( fibonacci >= limit &&  -fibonacci >= limit )
	    {   
		// Printing comma and space.
		printf(", ");
	    }
	    // Recursive function call for negative fiboncci.
	    negative_fibonacci(limit, term1, term2, fibonacci);
	}
	printf("\n");  // For new line.
    }
    else 
    {
	printf("Invalid input\n");  // if number is positive.
    }
}
