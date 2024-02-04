/*
Name : Munawir E
Date : 23/05/2022
Description : WAP to find the median of two unsorted arrays.
 * In probability theory and statistics, a median is described as the number separating the higher half of a sample, a population, or a probability distribution, from the lower half. The median of a finite list of numbers can be found by arranging all the numbers from lowest value to highest value and picking the middle one.
 * Example: For getting the median of input array { 12, 11, 15, 10, 20 }, first sort the array. We get { 10, 11, 12, 15, 20 } after sorting. Median is the middle element of the sorted array which is 12.
 Pre-requisites.
  * Loops
  * Arrays
 Objectives. 
  * To understand the concept of One-dimensional Arrays.

Sample I/P  :
 1) Enter the 'n' value for Array A: 5
    Enter the 'n' value for Array B: 5
    Enter the elements one by one for Array A: 3 2 8 5 4
    Enter the elements one by one for Array B: 12 3 7 8 5
 2) Enter the 'n' value for Array A: 5
    Enter the 'n' value for Array B: 4
    Enter the elements one by one for Array A: 3 2 8 5 4
    Enter the elements one by one for Array B: 12 13 7 5

Sample O/P  :
 1) Median of array1 : 4
    Median of array2 : 7
    Median of both arrays : 5.5
 2) Median of array1 : 4
    Median of array2 : 9.5                                      
    Median of both arrays : 6.75
*/

#include<stdio.h>

int main()
{
    // Initializing the variables.
    int A , B ,i , j , temp = 0 ;
    float medianA = 0 , medianB = 0 ;
    
    // Reading the variables from user.
    printf("Enter the 'n' value for Array A: ");
    scanf("%d",&A);
    printf("Enter the 'n' value for Array B: ");
    scanf("%d",&B);
    
    // Initializing arrays.
    int arrayA[ A ] , arrayB[ B ];

    printf("Enter the elements one by one for Array A: ");
    for ( i = 0 ; i < A ; i ++ )
    {
	scanf("%d", &arrayA [ i ] );
    }

    // Sorting the array1 using bubble sorting.
    for ( i = 0 ; i < A ; i ++ )
    {
	for ( j = 0 ; j < A - i - 1  ; j ++ )
	{
	    if ( arrayA[ j ] > arrayA[ j + 1 ] )
	    {
	    	// Swaping the values.
		temp = arrayA[ j ];
		arrayA[ j ] = arrayA[ j + 1 ];
		arrayA[ j + 1 ] = temp ;
	    }
	}
    }
    // Finding the median of array1.
    if ( A % 2 == 0 )
    {
	medianA = ( arrayA[ A / 2 ] + arrayA[ ( A / 2 ) - 1 ] ) / 2.0 ;
    }
    else
    {
	medianA = arrayA[ A / 2 ];
    }

    // Reading the value of array2.
    printf("Enter the elements one by one for Array B: ");
    for ( i = 0 ; i < B ; i ++ )
    {
	scanf("%d", &arrayB[ i ] );
    }
    
    // Sorting the array2 using bubble sorting.
    for ( i = 0 ; i < B ; i ++ )
    {
	for ( j = 0 ; j < B -i - 1 ; j ++ )
	{
	    if ( arrayB[ j ] > arrayB[ j + 1 ] )
	    {
	    	// Swaping the values.
		temp = arrayB[ j ];
		arrayB[ j ] = arrayB[ j + 1 ];
		arrayB[ j + 1 ] = temp ;
	    }   
	}
    } 
    // Finding the median of array2.
    if ( B % 2 == 0 )
    {
	medianB = ( arrayB[ ( B / 2 ) ] + arrayB[ ( B / 2 ) - 1 ] ) / 2.0 ;
    }
    else  
    {
	medianB = arrayB[ B / 2 ] ;
    }
    
    // Printing the output.
    printf("Median of array1 : %g \n", medianA);
    printf("Median of array2 : %g \n", medianB);
    printf("Median of both arrays : %g\n", ( medianA + medianB ) / 2 );
    return 0 ;
}

