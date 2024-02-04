/*
   Documentation
Name : Munawir E
Date : /05/2022
Description : WAP to count number of set bits in a given number and print parity.
 * Read a number from the user. Check number of set bits in a given number. If number of set bits is odd, then Bit parity is odd. Similarly, If number of set bits is even, then Bit parity is even. 
 * For example, If num = 7, number of set bits = 3 which is odd number, so bit parity is odd. Similarly, if num = 3, number of set bits = 2, bit parity should be even.

 Sample I/P  :
 1) Enter the number : 7
 Number of set bits = 3
 2) Enter the number : 15
 Number of set bits = 4
 3) Enter the number : 6
 Number of set bits = 2
 Sample O/P  :
 1) Bit parity is Odd
 2) Bit parity is Even
 3) Bit parity is Even
 */

#include<stdio.h>
int main()
{	// Initializing the variables.
    int  number , count = 0 , i ;
    // Reading input from user.
    printf("Enter the number : ");
    scanf("%d",&number);

    for ( i = 1 ; i != 0 ; i <<= 1 )
    { 
	if ( number & i )
	{
	    count++;
	}

    }
    printf("Number of set bits = %d\n",count);
    if ( count % 2 == 0 )
    {
	printf("Bit parity is Even\n");
    }
    else
	printf("Bit parity is Odd\n");
    return 0;

}

