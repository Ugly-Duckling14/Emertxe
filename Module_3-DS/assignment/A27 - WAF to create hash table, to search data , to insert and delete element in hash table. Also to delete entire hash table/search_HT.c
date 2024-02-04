#include"hash.h"

/* Function to search the data in hash table.
 * Inputs: arr - array for hash table,
 *         element - data to be inserted. 
 *         size - size of array.
 * Output: Return SUCCESS / FAILURE.
 * Description: Searches the data, if data found then return SUCCESS,
 *      else return DATA_NOT_FOUND. 
 */ 
int search_HT(hash_t *arr, int data, int size)
{
    int index = data % size;

    // If data at given index is empty.
    if( arr[index].value == -1)
    {
        return DATA_NOT_FOUND;
    }

    // Checking data is at first.
    if(arr[index].value == data)
    {
        return SUCCESS;
    }
    else    // Searching data when data is not at first.
    {
        hash_t *temp = arr[index].link;

        while(temp != NULL)
        {
            if(temp->value == data)
            {
                return SUCCESS;
            }

            temp = temp->link;
        }
    }

    // return error when data not fouund.
    return DATA_NOT_FOUND;
}