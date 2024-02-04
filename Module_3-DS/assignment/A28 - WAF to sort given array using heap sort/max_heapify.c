#include "main.h"

/* Function to check the number is minimum or maximum to decide the position
 * Inputs:heap - Base address of the integer array
 *         size - Length of the array
 * Output: return 0
 * Description:
 */
void max_heap(int *heap, int i, int size)
{
    // Initializing the variables.
    int lc = 2 * i + 1;
    int rc = 2 * i + 2, large;

    // Checking left side child is greater than parent.
    if( heap[lc] > heap[i] && lc < size)
    {
        large = lc;
    }
    else        // If left child not greater assigning large is index.
    {
        large = i;
    }

    // Checking right child is greater than large.
    if( heap[large] < heap[rc] && rc < size )
    {
        large = rc;
    }

    // If index is not lager 
    if( large != i)
    {
        // Swaping the larger value and parent.
        swap( &heap[i], &heap[large]);

        // Recursive call for max_heap.
        max_heap( heap, large, size);
    }
}

// Function to swap the values
void swap( int *first, int *last)
{
    int temp = *first;
    *first = *last;
    *last = temp;
}