/*
   Documentation
Name : Munawir E
Date : 18/05/2022
Description : WAP to print pyramid pattern as shown below
Read a number from user. Let's say if number is 5, you need to print numbers in pyramid pattern as shown below:
If n = 5, then,
5
4 5
3 4 5
2 3 4 5
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
Pre-requisites
 * Loops.
 Sample I/P  :
 1) Enter the number: 4
 2) Enter the number: 5

 Sample O/P  :
 1) 4
 3 4
 2 3 4
 1 2 3 4
 2 3 4
 3 4
 4
 2) 5
 4 5
 3 4 5
 2 3 4 5
 1 2 3 4 5
 2 3 4 5
 3 4 5
 4 5
 5
 */

#include<stdio.h>
int main ()
{  // Initializing the variables.
    int n , i , j , column;
    // Reading the input from user.
    printf("Enter a number : ");
    scanf("%d",&n);
    // To genrate the pattern, outer loop runs from 1 to less than n*2 times. 
    for ( i = 1 ; i < n * 2 ; i++ )
    {	// Checking i is less than n,if it's true then n-i+1 value will be assignd to column.
	if ( i < n )
	{ 
	    column = ( n - i + 1 ) ;   
	}	// If i less than n is false then i-n+1 value will be assigned to column.  
	else
	{
	    column = ( i - n + 1 ) ;
	}	// Loop inner loop will run from column to n times.
	for ( j = column ; j <= n ; j++ )
	{   // Pinting the value of j as the output.
	    printf("%d ",j);
	}  // For newline.
	printf("\n"); 
    }
    return 0;
}

