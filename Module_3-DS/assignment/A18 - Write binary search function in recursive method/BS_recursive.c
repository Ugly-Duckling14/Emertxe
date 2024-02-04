#include "main.h"

/* Function to search the element using binary search 
 * Inputs: arr - Base address of the integer array
 *         size - size of the array.
 *         key - Element to be searched
 *         first - Starting index
 *         last - Ending index
 */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    // Initializing the variables.
    data_t mid;
    
    // Checking the condition for the termination of recursive call
    if( last >= first )
    {
        // Assigning mid value. 
        mid = first + (last - first) / 2;
        
        // checking key is at middle.
        if( arr[mid] == key )
        {
            return mid;   
        }
        else if( arr[mid] > key)     // Checking mid is greater than key
        {
            // Function for recursive call when key is less than mid.
            return binarySearch_recursive(arr, size, key, first, mid - 1);
        }
        else
        {
            // Function for recursive call when key is greater than mid.
            return binarySearch_recursive(arr, size, key, mid + 1, last);
        }
    }
    return DATA_NOT_FOUND;
}
