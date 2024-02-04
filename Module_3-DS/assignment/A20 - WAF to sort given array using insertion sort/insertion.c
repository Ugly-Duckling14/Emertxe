#include "main.h"

/* Function to sort using insertion sort.
 * Inputs: arr - Base address of the integer array
 *         size - size of array.
 * Output: return 0.
 * Description: Sort the array using insertion sort and return 0.
 */
data_t insertion(data_t *arr, data_t size)
{
    // Initializing the variables.
    data_t i, j, key;

    for(i = 1; i < size; i++)
    {
        // Updating the key and j value.
        key = arr[i];
        j = i - 1;
        
        while(j >= 0 && arr[j] > key)
        {
            // Swapping the values.
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return 0;   
}
