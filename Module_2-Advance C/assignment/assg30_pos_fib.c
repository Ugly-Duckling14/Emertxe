/*
Name : Munawir E
Date : 09/06/2022
Description : WAP to generate fibbonacci numbers using recursion.
 Pr-requisites:-
  * Arithmetic Operators.
  * Recursions.
 Objective: -
  * Recursive Functions.
 Note :- In mathematics, the Fibonacci numbers or Fibonacci sequence are the numbers in the following integer sequence 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .OR 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 . . .
   By definition, the first two numbers in the Fibonacci sequence are either 1 and 1, or 0 and 1, depending on the chosen starting point of the sequence, and each subsequent number is the sum of the previous two.

Sample I/P  :
 1) Enter a number: 8
 2) Enter a number: 10
 3) Enter a number: 21
 4) Enter a number: -12

Sample O/P  :
 1) 0, 1, 1, 2, 3, 5, 8
 2) 0, 1, 1, 2, 3, 5, 8
 3) 0, 1, 1, 2, 3, 5, 8, 13, 21
 4) Invalid input
*/

#include <stdio.h>

// Function declaration.
void positive_fibonacci(int, int, int, int);

int main()
{
    // Initializing th variables.
    int limit;

    // Reading th input.
    printf("Enter the limit : ");
    scanf("%d", &limit);

    // Function call for finding the positive fibonacci series.
    positive_fibonacci(limit, 0, 1, 0);
    printf("\n");
    return 0;
}

// Function definition for fibonacci series.
void positive_fibonacci( int limit, int term1, int term2, int fibonacci)
{
    // Checking number is positive or not.
    if( limit >= 0 )
    {
	// Finding fibonacci numbers till the specified range.
	if( fibonacci <= limit )
	{
	    printf("%d", fibonacci);		// Printing the output.

	    // Swapping the values.
	    term1 = term2 ;			
	    term2 = fibonacci ;
	    // Adding term1 and term2 and assigning to fibonacci.
	    fibonacci = term1 + term2 ;	 
	    if( fibonacci <= limit )
	    {   
		// Printing comma and space
		printf(", ");
	    }

	    // Recursive function call for fibonacci series.
	    positive_fibonacci(limit, term1, term2, fibonacci);
	}
    }
    else
    {
	// Printing error message for negative number.
	printf("Invalid input");
    }
}
