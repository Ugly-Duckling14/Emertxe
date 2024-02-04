/*
Name : Munawir E
Date : 21/08/2022
Description : A19 - WAF to sort given array using bubble sort.
Sample Inputs: 
	Enter the size of an array
	5
	Enter the array elements
	3 4 2 1 5
Sample Output: Sorted array is : 1 2 3 4 5
*/

#include "main.h"

/* Main Function */
int main()
{
	int i, limit, option;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	data_t arr[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &arr[i]);
	}
		
	/* Calling the function to bubble sort */
	bubble(arr, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
	printf("\n");
		
	return 0;
}
