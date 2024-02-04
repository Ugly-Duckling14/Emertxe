#include"hash.h"

/* Function to insert element to hash table.
 * Inputs: arr - array for hash table,
 *         element - data to be inserted. 
 *         size - size of array.
 * Output: Return SUCCESS / FAILURE.
 * Description: Insert the element at the index value and return SUCCESS,
 *      else return FAILURE.
 */
int insert_HT(hash_t *arr, int element, int size)
{
    // Initializing the index and assigning the index value.
    int index = element % size;

    // If No element present at index position.
    if(arr[index].value == -1)
    {
        arr[index].value = element;
    }
    else
    {
        // Creating new node and updating values.
        hash_t *new_node = (hash_t*) malloc(sizeof(hash_t));
        hash_t *temp = arr[index].link;
        
        if(new_node == NULL)
        {
            return FAILURE;
        }

        new_node->value = element;
        new_node->index = index;
        new_node->link = NULL;

        // Checking at the given index having only one element.
        if(temp == NULL && arr[index].value != element)
        {
            arr[index].link = new_node;
        }
        else        // If the given index having more than 2 element.
        {
            // Checking the node reached at the end.
            while(temp->link != NULL)
            {
                temp = temp->link;
            }

            temp->link = new_node;
        }
    }

    return SUCCESS;
}