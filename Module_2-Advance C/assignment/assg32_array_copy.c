/*
Name : Munawir E
Date : 21/06/2022
Description : Print the values in sorted order without modifying or copying array
 Pr-requisites:-
  * Functions
  * Arrays
  * Pointers
 Objective: -
  * Functions
  * Arrays
  * Pointers

Sample I/P  :
 1) Enter the size : 5
    Enter 5 elements 
    10 1 3 8 -1
 2) Enter the size : 7
    Enter 7 elements 
    1 3 2 5 4 7 6
 3) Enter the size : 4
    Enter 4 elements 
    -1 -2  4 3

Sample O/P  :
 1) After sorting: -1 1 3 8 10
    Original array values 10 1 3 8 -1
 2) After sorting: 1 2 3 4 5 6 7
    Original array values 1 3 2 5 4 7 6
 3) After sorting: -2 -1 3 4
    Original array values -1 -2  4 3
*/

#include <stdio.h>

// Function declaration/.
void print_sort(int *, int);

int main()
{
    // Initializing the variables.
    int size, iter;

    // Reading the input.
    printf("Enter the size : ");
    scanf("%d", &size);

    // Initializing the array and reading the elements in array
    int arr[size];
    printf("Enter 5 elements\n");
    for(iter = 0; iter < size; iter++)
    {
	scanf("%d", &arr[ iter ]);
    }

    // Function call.
    print_sort( arr, size);
    return 0;
}

// Function definition.
void print_sort(int *arr, int size)
{
    // Initializing local variables for function.
    int i, j, small= *arr, large= *arr, temp;

    // Finding the largest and smallest values in array.
    for( i = 1; i < size; i++ )
    {
	if( arr[ i ] < small )
	{
	    small = arr[ i ];
	}
	if( arr[ i ] > large )
	{
	    large = arr[ i ];
	}
    }    
    temp = large;

    // Sorting array elements in ascending order and printing the output.
    printf("After sorting: ");
    for( i = 0 ; i< size ; i++ )
    {     
	for( j = 0 ; j < size ; j++)
	{	     
	    if( large > arr[ j ] && small < arr[ j ]  )
	    {
		large = arr[ j ];
	    }
	}
	printf("%d ", small);
	small = large;
	large = temp;
    }

    // Printing the original array.
    printf("\nOriginal array values ");
    for( i = 0; i < size; i++)
    {
	printf("%d", arr[ i ] );
    }
}

