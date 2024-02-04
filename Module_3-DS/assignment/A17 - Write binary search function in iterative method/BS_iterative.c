#include "main.h"

/* Function for binary search using iterations
 * Inputs: arr - Base address of the integer array
 *         size - Length of the array
 *         key - 	 Element to be searched
 * Output: return position if key found else return DATA_NOT_FOUND. 
 */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    // Initializing the variables.
    data_t low = 0, high = size-1, mid;
    
    while( low <= high)
    {
        mid = (low + high) / 2;

        // If key found returns the position.
        if( arr[mid] == key )
        {
            return mid;
        }
        else if( arr[mid] > key)        // If key is less than mid
        {
            high = mid - 1;
        }
        else        // If key is greater than mid
        {
            low = mid + 1;
        }
    }

    // Return -1 if key not found.
    return DATA_NOT_FOUND;
}
