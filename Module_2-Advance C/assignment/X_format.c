/*
Documentation
Name : Munawir E
Date : 13/05/2022

Description : WAP to print the numbers in X format as shown below.
Pre-requisites
 *  Loops
Sample I/P  : 
 1) Enter the number: 4
 2) Enter the number: 5

Sample O/P  :
 1) 1  4
     23
     23
    1  4
 2)1   5
    2 4
     3
    2 4
   1   5 
*/

#include<stdio.h>
int main()
{
    // Initializing the variable.
    int i,j,number;
    // Reading the variables.
    printf("Enter the number: ");
    scanf("%d",&number);
    // The row loop will run until number is less than or equal to number.
    for ( i = 1 ; i<= number ;i++)
    {   // The column loop will run until the number is less than or equal to number.
	for ( j = 1 ; j <= number ; j++ )
	{   // Checking the i value is equal to j, if true it will enter inside statement.
	    if ( i == j )
	    {   // If i == j is true then it prints the output into a diagonal values from left to right.
		printf("%d",i);
	    } // Checking the i+j value equal to number+1 if it's true the below statement is executed.
	    else if ( (i+j) == (number+1) )
	    {   // If i+j value equal to number+1 is true, then it prints the output into diagonal values  from right to left
		printf("%d",j);
	    }  // if both the above condition is false the below statement executes which prints spaces to get exact X format as output.
	    else { printf(" "); }
	}
	printf("\n");   // Printing a new line.
    }
    return 0;
}

