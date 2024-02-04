/*
   Documentation
Name : Munawir E
Date : 16/05/2022
Description : WAP to generate AP, GP, HP series
AP :
In mathematics, an arithmetic progression (AP) or arithmetic sequence is a sequence of numbers such that the difference between the consecutive terms is constant.
For instance, the sequence 5, 7, 9, 11, 13, 15 ... is an arithmetic progression with common difference of 2.
GP :
In mathematics, a geometric progression, also known as a geometric sequence, is a sequence of numbers where each term after the first is found by multiplying the previous one by a fixed, non-zero number called the common ratio.
For example, the sequence 2, 6, 18, 54, ... is a geometric progression with common ratio 3. Similarly 10, 5, 2.5, 1.25, ... is a geometric sequence with common ratio 1/2.
HP :
In mathematics, a harmonic progression (or harmonic sequence) is a progression formed by taking the reciprocals of an arithmetic progression.
Pre-requisites.
 * Loops
 * Operators
 * Data Types
 Objective.
 * Continuous looping.
 * If-else constructs
 * Type Casting

 Sample I/P  :
 1) Enter the First Number 'A': 2
 Enter the Common Difference / Ratio 'R': 3
 Enter the number of terms 'N': 5
 2) Enter the First Number 'A': 2
 Enter the Common Difference / Ratio 'R': 3
 Enter the number of terms 'N': -5

 Sample O/P  :
 1) AP = 2, 5, 8, 11, 14
 GP = 2, 6, 18, 54, 162
 HP = 0.5, 0.2, 0.125, 0.0909091, 0.0714285
 2) Invalid input
 */

#include<stdio.h>
int main()
{   // Initializing the variables.
    int A,R,N,AP,GP,i;
    float HP;
    // Reading  the values for variables.
    printf("Enter the First Number 'A': ");
    scanf("%d",&A);
    printf("Enter the Common Difference / Ratio 'R': ");
    scanf("%d",&R);
    printf("Enter the number of terms 'N': ");
    scanf("%d",&N);
    // Checking A , R , N are greater than one.
    if ( A > 1 && R > 1 && N > 1 )
    {
	printf("AP = ");
	AP = A ;				// Assigning initial value for AP.
	// Calculating AP and printing the AP values
	for ( i = 1 ; i < N ; i++ )		
	{
	    printf("%d, ",AP);
	    AP = AP + R ;
	}
	printf("%d\nGP = ",AP);
	GP = A ;		// Assigning initial value for GP.
	// Calculating the value for GP and printing the GP values.
	for ( i = 1 ; i < N ; i++ )
	{
	    printf("%d, ",GP);
	    GP = GP * R ;
	}
	printf("%d\nHP = ",GP);
	AP = A ;     				// Assigning initial value for AP. HP is reciprocal of AP so inorder to find HP we need to find AP
	// Calculating HP and printing Values of HP
	for ( i = 1 ; i < N ; i++ )
	{
	    HP = 1 / ( float ) AP ;
	    AP = AP + R;
	    printf("%g, ",HP);
	}
	printf("%d\n",HP);
    }
    else					// Error when user enters negative value, The values should be positive 
    {	
	printf("Invalid input\n");   
    }
    return 0 ;
}

