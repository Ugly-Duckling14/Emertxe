/*
   Documentation
Name : Munawir E
Date : 12/05/2022
Description : WAP to generate positive Fibonacci numbers.
Pre-Requists :-
 * Loops
 * Operators
Objectives :-
 * Loops
 * If else construct

Sample I/P  :
1) Enter a number: 8
2) Enter a number: 10
3) Enter a number: 21
4) Enter a number: -21

Sample O/P  :
1) 0, 1, 1, 2, 3, 5, 8
2) 0, 1, 1, 2, 3, 5, 8
3) 0, 1, 1, 2, 3, 5, 8, 13, 21
4) Invalid input
*/

#include<stdio.h>
void main()
{
    // Initializing the variable.
    int term1=0,term2=1,fibonacci=0,number;
    // Reading the variable.
    printf("Enter a number: ");
    scanf("%d",&number);

    // Checking number is positive.
    if ( number >= 0 )
    {
    	// Checking fibonacci is less than or equal to number. If true loop will run.
	while ( fibonacci <= number )
	{
	    printf("%d, ",fibonacci);		// Printing the output.
	    // Swapping the values.
	    term1 = term2 ;			
	    term2 = fibonacci ;
	    // Adding term1 and term2 and assigning to fibonacci.
	    fibonacci = term1 + term2 ;
	}
	printf("\n");  // For new line.
    }
    else printf("Invalid input\n");  // if number is negative.
}

