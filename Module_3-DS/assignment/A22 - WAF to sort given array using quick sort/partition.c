#include "main.h"

/* Function to partition the array
 * Inputs: arr - Base address of the integer array
 *         first - Starting index
 *         last - Ending  index 
 * Output: Sorting the array using pivot.
 */
int partition(int *arr, int first, int last)
{
    // Initializing the variables.
    int pivot = first, p = first+1, q = last;
    
    // Sorting the elements using pivot.
    while( p <= q)
    { 
        while( arr[p] <= arr[pivot])
        {
           p++;
        }
        while( arr[q] > arr[pivot])
        {
            q--;
        }
    
        // Swap element if element at p and q are not in sorted position with respect to pivot.
        if( p < q )
        {
            swap(&arr[p], &arr[q]); 
        } 
    }

    // Swap pivot and q if p exceeds q.
    if( q != pivot)
    {
        swap(&arr[pivot], &arr[q]);
    }
    return q;
}

/* Function to swap the elements.*/
void swap( int *first, int *last)
{
    int temp = *first;
    *first = *last;
    *last = temp;
}