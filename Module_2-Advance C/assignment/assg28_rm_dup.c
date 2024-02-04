/*
Name : Munawir E
Date : 21/06/2022
Description : WAP to remove duplicate elements in a given array.
 Pre-requisites:
  * Arrays
  * Pointers
 Objectives:-
  * Arrays
  * Pointers
Sample I/P  :
 1) Enter the size: 5
    Enter elements into the array: 5 1 3 1 5
 2) Enter the size: 5
    Enter elements into the array: 2 1 1 1 5

Sample O/P  :
 1) After removing duplicates: 5 1 3
 2) After removing duplicates: 2 1 5
*/

#include<stdio.h>

// Function declaration.
void fun(int *arr1, int size, int *arr2, int *new_size);

int main()
{
    // Initializing the variables.
    int size, size1, *new_size, i, count;

    // Reading the input.
    printf("Enter the size: ");
    scanf("%d", &size);

    // Initializing the arrays.
    int arr1[size], arr2[size]; 
    count= size;
    new_size = &count;

    // Reading the array elements.
    printf("Enter elements into the array: ");
    for( i = 0 ; i < size ; i++ )
    {
	scanf("%d", &arr1[i]);
    }

    // Function call.
    fun( arr1, size, arr2, new_size);

    // Printing the output after removing duplicates.
    printf("After removing duplicates: ");
    for( i = 0 ; i < count ; i ++ )
    {
	printf("%d ", arr2[ i ] );
    }  
    printf("\n");
    return 0 ;
}

void fun(int *arr1, int size, int *arr2, int *new_size)
{
    // Initializing the local variables.
    int i, j, k;

    // Making the duplicate value in array1  to zero
    for( i = 0 ; i < size ; i ++ )
    {
	for( j = 1 ; j < size ; j++ )
	{
	    if( arr1[ j ] == 0  )
	    {
		continue;
	    }
	    else if( arr1[i] == arr1[j] && i != j )
	    {  
	    	arr1[ j ] = 0; 
		(*new_size)--;
	    }
	}
    }

    // Copying the array elements array2 by eliminating zero.
    for( i = 0 ; i < size; i++ )
    {
	if( *arr1 == 0 )
	{
	    arr1++;
	    continue;
	}
	else
	{
	    *arr2 = *arr1;
	    arr1++;
	    arr2++;
	}
    }
}

