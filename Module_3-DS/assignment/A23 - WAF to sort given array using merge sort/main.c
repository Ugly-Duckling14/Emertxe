/*
Name : Munawir E
Date : 20/08/2022
Description : A23 - WAF to sort given array using merge sort
	Implement functions given below : 
		1.void merge(int *array, int narray, int *left, int nleft, int *right, int nright);
		2.int merge_sort(int *array, int narray);
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
	merge_sort(arr, limit);
	
	printf("Sorted array is : ");
	for (i = 0; i < limit; i++)
	{
	    printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
