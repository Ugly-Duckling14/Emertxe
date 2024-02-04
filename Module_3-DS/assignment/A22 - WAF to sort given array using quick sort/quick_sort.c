#include "main.h"

/* Function to sort the array in quick sort method
 * Inputs: arr - Base address of the integer array
 *         first - Starting index 
 *         last - Ending  index 
 * Output: returns the sorted array
 */
int quick_sort( int *arr, int first, int last )
{
    int index;

    // Recursive function call for sorting elements.
    if( first <= last)
    {
        index = partition( arr, first, last);
        quick_sort(arr, first, index - 1);
        quick_sort(arr, index + 1, last);
    }
    return 0;
}
