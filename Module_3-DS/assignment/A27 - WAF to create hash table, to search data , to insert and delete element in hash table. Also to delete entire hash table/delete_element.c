#include"hash.h"

/* Function to delete the data.
 * Inputs: arr - array for hash table,
 *         data - data to be inserted. 
 *         size - size of array.
 * Output: Return SUCCESS / DATA_NOT_FOUND.
 * Description: If data found delete the element,
 *      else return DATA_NOT_FOUND.
 */
int delete_element(hash_t *arr, int data, int size)
{
    // Finding the index value.
    int index = data % size;

    // If the data at index is empty.
    if(arr[index].value == -1)
    {
        return DATA_NOT_FOUND;
    }

    // If the index having only one element.
    if(arr[index].value == data && arr[index].link == NULL)
    {
        arr[index].value = -1;
        return SUCCESS;
    }
    else
    {
        hash_t *temp = arr[index].link;

        // If the value at 1st and index having more than one value.
        if(arr[index].value == data)
        {
            arr[index].value = temp->value;
            arr[index].link = temp->link;
            free(temp);
        }
        else if( temp->value == data)       // If the value is at 2nd position.
        {
            arr[index].link = temp->link;
            free(temp);
        }
        else
        {
            hash_t *cur = temp;

            // If the value is at 3rd position or above.
            while(temp != NULL)
            {
                if(temp->value == data)
                {
                    cur->link = temp->link;
                    free(temp);
                    return SUCCESS;
                }

                cur = temp;
                temp = temp->link;
            }

            // Return FAILURE if data is not found.
            return DATA_NOT_FOUND;
        }

        return SUCCESS;
    }
    
    return DATA_NOT_FOUND;
}