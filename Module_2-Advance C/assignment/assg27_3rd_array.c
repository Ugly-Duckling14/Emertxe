/*
Name : Munawir E
Date : 17/06/2022
Description :WAP to find 3rd largest element in an array
 Pre-requisites:
  * Arrays
  * Functions
  * Pointers
Objective: -
  * Arrays
  * Functions
  * Pointers

Sample I/P  :
 1) Enter the size of the Array : 5
    Enter the elements into the array: 5 1 4 2 8
 2) Enter the size of the Array : 4
    Enter the elements into the array: 66 22 11 3

Sample O/P  :
 1) Third largest element of the array is 4
 2) Third largest element of the array is 22
*/


#include <stdio.h>

// Function declaration.
int third_largest(int *, int);

int main()
{
    int size, ret, i;

    //Read size from the user
    printf("Enter the size of the array :");
    scanf("%d", &size);

    int array[size];

    //Read elements into the array.
    printf("Enter the elements into the array: ");
    for( i = 0 ; i < size ; i++ )
    {
	scanf("%d", &array[ i ]);
    }    

    //funtion call
    ret = third_largest(array, size);

    // Printing the output.
    printf("Third largest element of the array is %d\n", ret);
}

// Function definition to find second largest.
int third_largest(int *array, int size)
{
    // Initializing local variables for function.
    int first_largest, second_largest, third_largest, i;                   

    first_largest = array[ 0 ];                                              // Assigned 0 index array element as first largest number
    second_largest = array[ 1 ];                               // Assigned second array element to array index 1 element.
    third_largest = array[ 2 ];                                 // Assigned second array element to array index 2 element.
								
    // Finding the third largest element.
    for ( i = 1 ; i < size; i++)                                           
    {
	if( array[ i ] > first_largest)                                      
	{
	    third_largest = second_largest;
	    second_largest = first_largest;                               
	    first_largest = array[ i ];                                      
	}
	else if( ( array[ i ] > second_largest ) && ( array[ i ] < first_largest ) )        
	{
	    third_largest = second_largest;
	    second_largest = array[ i ];                                        
	}
	else if( ( array[ i ] > third_largest ) && ( array[ i ] < second_largest ) )
	{
	    third_largest = array[ i ];
	}
	
	// Returning second largst value.  
	return third_largest;                                   
}
