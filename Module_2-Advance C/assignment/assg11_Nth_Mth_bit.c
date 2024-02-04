/*
Name : Munawir E
Date : 23/05/2022
Description : WAP to check N th bit is set or not, If yes, clear the M th bit.
 * Read a number, M and N from the user. You need to check whether N th bit is set(1) or not, If yes, then you need to clear the M th bit of the number and print the updated value of num.
 Pre-requisites.
  * Bitwise operator.
Sample I/P  :
 1) Enter the number: 19
    Enter 'N': 1
    Enter 'M': 4
 2) Enter the number: 19
    Enter 'N': 2
    Enter 'M': 4
Sample O/P  :
 1) Updated value of num is 3 
 2) Updated value of num is 19 
*/

#include<stdio.h>

int main ()
{
    // Initialiing the variables.
    int numbe, N, M ;

    // Reading the input from user.
    printf("Enter the number: ");
    scanf("%d", &number);
    printf("Enter 'N': ");
    scanf("%d", &N);
    printf("Enter 'M': ");
    scanf("%d", &M);

    // Checking the Nth bit is set(1) or not.
    if ( number & ( 1 << N ) )
    {
	// If Mth bit is set then clearing that bit.
	number &= ~ ( 1 << M );
    }
    printf("Updated value of num is %d \n", number);
    return 0 ;
}
