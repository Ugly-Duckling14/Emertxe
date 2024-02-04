/*
Documentation
Name : Munawir E
Date : 16/05/2022

Description : WAP to print triangle pattern as shown below.
 Pre-requisites.
  * Loops.
 Sample I/P  :
  1) Enter the number: 4
  2) Enter the number: 5

 Sample O/P  :
  1) 1 2 3 4
     5   6
     7 8
     9
  2) 1 2 3 4 5
     6     7
     8   9
     10 11
     12
 */

#include<stdio.h>
int main()
{   // Initializing the variables.
    int i,n,j,count=1;
    // Reading the variables.
    printf("Enter the number: ");
    scanf("%d",&n);
    // Generating the pattern. i loop run from 1 to 5 , same for the inner loop j loop run from 1 to 5.
    for ( i = 1; i <= n; i++ )
    {
	for ( j = 1 ; j <= n ; j++ )
	{   // When either i is or j is 1 or i+j = n+1 it prints the value of count and increment the value of count.
	    if ( i == 1 || j == 1 || ( i + j ) == ( n + 1 ) )
	    {
		printf("%d ", count);
		count++;
	    } // if condition is false prints blank space.
	    else 
	    {
		printf("  ");
	    }
	}
	printf("\n");
    }
    return 0 ;
}
