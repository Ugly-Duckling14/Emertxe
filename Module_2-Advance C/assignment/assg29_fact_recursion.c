/*
Name : Munawir E
Date : 15/06/2022
Description : WAP to find factorial of given number using recursion
 Pr-requisites:-
  * Storage Classes
  * Recursions
 Objective: -
  *     To understand the concept of Recursion and static keyword.
Sample I/P  :
 1) Enter the value of N : 7
 2) Enter the value of N : 5
 3) Enter the value of N : -1
 4) Enter the value of N : 0
 
Sample O/P  :
 1) Factorial of the given number is 5040
 2) Factorial of the given number is 120
 3) Invalid Input
 4) Factorial of the given number is 1
*/

#include<stdio.h>

int main()
{
    // Initializing the variable.
    static int num = -1;
    static unsigned long long int fact = 1;

    // Reading the input.
    if( num == -1 )
    {
	printf("Enter the value of N : ");
	scanf("%d", &num);
    }
    
    // Checking number is positive.
    if( num >= 0 )
    {
        // Finding factorial till num reaches to 1.
	if( num >= 1 )
	{
	    fact *= num--;
	    return  main();  // Recursive call of main.
	}
	
	// Printing the output.
	printf("Factorial of the given number is %d\n", fact);
    }
    else
    {
        // Printing error message if number is negative.
	printf("Invalid Input\n");
    }
}

