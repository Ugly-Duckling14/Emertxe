/*
Name : Munawir E
Date : 08/06/2022
Description : WAP to find 2nd largest element in an array.
 Pre-requisites:-
  * Arrays.
  * Functions.
  * Pointers.
 Objectives :- 
  * To understand the concept of Functions.
  * To undrstand the concept of Pointers.
 Notes :-
  * Read size and array elements from the user. You need to find 2nd largesst element in the array without sorting or modifying the array.
  * You need to pass array to the function. U need to collect as pointer inside a function as shown below:
              int sec_largest(int *arr, int size);
  * In function you need to find second largest element of the array and you need to return it to the main

Sample I/P  :
 1) Enter the size of the Array : 5
    Enter the elements into the array: 5 1 4 2 8
 2) Enter the size of the Array : 4
    Enter the elements into the array: 66 22 11 3

Sample O/P  :
 1) Second largest element of the array is 5
 2) Second largest element of the array is 22

*/

#include <stdio.h>

// Function declaration.
int sec_largest(int *, int);

int main()
{
    // Initializing the variables.
    int size, ret, i;

    //Read size from the user
    printf("Enter the size of the array : ");
    scanf("%d", &size);

    int array[size];

    //Read elements into the array.
    for( i = 0 ; i < size ; i++ )
    {
	scanf("%d", &array[ i ]);
    }

    //funtion call
    ret = sec_largest(array, size);

    // Printing the output.
    printf("Second largest element of the array is %d\n", ret);
    return 0;
}

// Function definition
int sec_largest(int *array, int size)                                   

{
    // Local variable declaration for function.	
    int first_largest, second_largest, i;                   

    first_largest = array[ 0 ];                                              //assigned 0 index array element as first largest number
    second_largest = array[ 1 ];                               //assigned second array element to array index 1 element.

    // Finding the second largest element
    for ( i = 1 ; i < size; i++)                                           
    {
	if( array[ i ] > first_largest)                                      
	{
	    second_largest = first_largest;                               
	    first_largest = array[ i ];                                      
	}
	else if( ( array[ i ] > second_largest ) && ( array[ i ] < first_largest ) )        
	{
	    second_largest = array[ i ];                                        
	}
    }

    // Returning second largst value.  
    return second_largest;                                   
}
