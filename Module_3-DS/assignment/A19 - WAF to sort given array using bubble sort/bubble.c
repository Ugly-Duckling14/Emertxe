#include "main.h"
/* Function to sort the array using bubble sort.
 * Inputs: arr - Base address of the integer array
 *         size - Size of array.
 * Output: return 0.
 * Description: Sorting the array and returns 0.
 */
data_t bubble(data_t *arr, int size )
{
    // Initializing the variables.
    data_t i, j, temp;

    for( i = 0; i < size; i++)
    {
        for(j = 0; j < size - 1 - i; j++ )
        {
            // Swaping the variables.
            if( arr[ j ] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[ j + 1];
                arr[j + 1] = temp; 
            }
        }
    }
    return 0;   
}
