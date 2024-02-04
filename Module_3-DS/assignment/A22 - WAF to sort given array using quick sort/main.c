/*
Name : Munawir E
Date : 20/08/2022
Description : A22 - WAF to sort given array using quick sort
  Implement functions given below :
	1.quick_sort(int *, int, int )
	2.partition(int *, int , int )
*/

#include "main.h"

/* Main Function */
int main()
{
	int i, limit;

	/* Scanning the size */
	printf("Enter the size of an array\n");
	scanf("%d", &limit);

	/* Declaring the array with size */
	int arr[limit];

		
	printf("Enter the array elements\n");
	for (i = 0; i < limit; i++)
	{
	    /* Scanning the array elements */
		scanf("%d", &arr[i]);
	}
		
	/* Calling the function to bubble sort */
	quick_sort(arr, 0, limit - 1);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
	printf("\n");
		
	return 0;
}
