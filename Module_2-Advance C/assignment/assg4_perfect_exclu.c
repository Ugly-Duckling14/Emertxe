/*
   Documentation
Name : Munawir E
Date : 13/05/2022
Description : WAP to check if number is perfect or not.
 * In number theory, a perfect number is a positive integer that is equal to the sum of its proper positive divisors, that is, the sum of its positive divisors excluding the number itself (also known as its aliquot sum).`
 * Equivalently, a perfect number is a number that is half the sum of all of its positive divisors (including itself).
Example:
 * The first perfect number is 6, because 1, 2, and 3 are its proper positive divisors, and 1 + 2 + 3 = 6. Equivalently, the number 6 is equal to half the sum of all its positive divisors: ( 1 + 2 + 3 + 6 ) / 2 = 6
 * The next perfect number is 28 = 1 + 2 + 4 + 7 + 14. This is followed by the perfect numbers 496 and 8128
 Pre-requisites
 * Loops.
 * Operators.
 Objective
 * If-else construct

 Sample I/P  :
 1) Enter a number: 6
 2) Enter a number: 10
 3) Enter a number: -1

 Sample O/P  :
 1) Yes, entered number is perfect number
 2) No, entered number is not a perfect number
 3) Error : Invalid Input, Enter only positive number
 */

#include<stdio.h>
int main()
{   // Initializing the variables.
    int number,i,sum=0;
    // Reading the variables.
    printf("Enter a number: ");
    scanf("%d",&number);
    // Checking the number is positive or not. If true statement inside if is executed.
    if(  number > 0)
    {	// The loop will run till the half of the entered number times. 
	for( i = 1 ; i <= number/2 ; i++ )
	{   // Checking the remainder of number by each whole number till number/2 is equal to zero.
	    if ( number % i == 0 )
	    {	sum = sum + i ; }  // If the remainder of number by i is eual to zero. Assigning sum equal to sum + i.
	}    // Checking the value os sum equal to number, If it true it prints entered number is perfect.
	if( sum == number )
	{   printf("Yes, entered number is perfect number\n"); }
	else   // IF the sum is not equal to number prints number is not perfect. 
	{   printf("No, entered number is not a perfect number\n"); }
    }
    else // If the entered number is not positive prints error message. 
    {	printf("Error : Invalid Input, Enter only positive number\n"); }
    return 0;
}

