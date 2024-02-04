/*
   Documentation
Name : Munawir E
Date : 12/05/2022
Description : WAP to check if number is odd or even
Pre-requisites
 * Arithmetic Operators.
 * Nested If-else construct.
 Objective
 * To understand the concept of Nested if-else
 Sample I/P  : 
 1) Enter the value of 'n' : -2 
 2) Enter the value of 'n' : 2
 3) Enter the value of 'n' : 0

 Sample O/P  : 
 1) -2 is negative even number
 2) 2 is positive even number
 3) 0 is neither odd nor even

*/

#include<stdio.h>
void main()
{
    //Initializing the variables.
    int number;
    // Reading the values. 
    printf("Enter the value of 'n' : ");
    scanf("%d",&number);

    if ( number == 0 )	// Checking number is equal to zero.
    {   printf("0 is neither odd nor even\n"); }
    else	// When number is not equal to zero.
    {
	if ( number % 2 == 0 )	// Checking the remainder of number divided by two equal to zero.
	{
	    if ( number > 0 ) 
	    {   printf("%d is positive even number\n",number);	  }  // Checking the number is postive number, if true printing number is positive even number.
	    else 
	    {    printf("%d is negative even number\n",number);	 }  // Printing the number is negative even number.
	}
	else
	{
	    if ( number > 0 ) 
	    {    printf("%d is positive odd number\n",number);  }   // Checking the number is positive number, if true printing number is positive odd number.
	    else 
	    {    printf("%d is negative odd number\n",number);	 }	//Printing the number is negative odd number.
	}}}
