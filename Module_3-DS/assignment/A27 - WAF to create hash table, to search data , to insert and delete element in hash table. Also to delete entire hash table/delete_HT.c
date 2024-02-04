#include"hash.h"

/* Function to delete entire hash table.
 * Inputs: arr - array for hash table,
 *         size - size of array.
 * Output: Return SUCCESS.
 * Description: Delete the entire hash table and return SUCCESS.
 */
int destroy_HT(hash_t *arr, int size)
{
    int i;
    hash_t *temp;

    // Deleting the entire hash table.
    for(i = 0; i < size; i++)
    {
        if(arr[i].value != -1)
        {
            if(arr[i].link == NULL)
            {
                arr[i].value = -1;
            }
            else
            {
                temp = arr[i].link;
                
                while(temp != NULL)
                {
                    arr[i].link = temp->link;
                    free(temp);
                    temp = arr[i].link;
                }
                arr[i].value = -1;
            }
        }
    }
    return SUCCESS;
}