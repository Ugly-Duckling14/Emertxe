#include "main.h"

/* Function to sort array using selection sort.
 * Inputs: arr - Base address of the integer array
 *         size - size of array.
 * Output: return 0.
 * Description: Sort the array using selection sort then return 0.
 */
data_t selection(data_t *arr, data_t size )
{
    // Initializing the variables.
    data_t j, cur_min, cur_item;

    for(j = 0; j < size; j++)
    {
        // Assigning min values index in cur_min
        cur_min = j;
        
        for( cur_item = j + 1; cur_item < size; cur_item++)
        {
            // Swapping values.
            if(arr[cur_item] < arr[cur_min])
            {
                cur_min = cur_item;
            }
        }

        // Swapping when min != j.
        if( cur_min != j)
        {
            swap( &arr[j], &arr[cur_min]);
        }
    }

    return 0;
}

/* Function to swap the values. */
void swap(data_t *item, data_t *min)
{
    data_t temp;

    // Swaping values.
    temp = *item;
    *item = *min;
    *min = temp;
}