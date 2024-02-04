#include "main.h"

/* Function to merge and sort the array elements.
 * Inputs: array - Base address of the integer array
 *         narray - Length of the array
 *         left - Base address of the left sub integer array
 *         nleft - Length of the  left sub array
 *         right - Base address of the right sub integer array
 *         nright - Length of the right sub array
 * Output: Array in sorted format.
 */
void merge(int *array, int narray, int *left, int nleft, int *right, int nright)
{
    // Initializing the variables.
    int i = 0, j = 0, k = 0;

    // Sorting the elements.
    while( i < nleft && j < nright)
    {
        if( left[i] <= right[j])
        {
            array[k] = left[i];
            k++;
            i++;
        }
        else
        {
            array[k] = right[j];
            k++;
            j++;
        }
    }

    // Storing the remaining elements in left array to main array.
    while( i < nleft)
    {
        array[k] = left[i];
        k++;
        i++;
    }

    // Storing the remaining the elementsin right array to main array
    while( j < nright)
    {
        array[k] = right[j];
        k++;
        j++;
    }
}
