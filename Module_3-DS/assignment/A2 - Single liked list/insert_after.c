#include "sll.h"

/* Function to insert element after the given data.
 * Inputs: head → pointer to first node.
 *         gdata → given data (should be present in the list).
 *         ndata → data to be inserted in the list after gdata.
 * Output: Return LIST_EMPTY / FAILURE / SUCCESS / DATA_NOT_FOUND.
 * Description: If list is empty return list empty, if given data found insert new data after
 *  the given data and return success, else return data not found,
 */
int sl_insert_after(Slist **head, data_t g_data, data_t ndata)
{
    // Checking list is empty or not.
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Initializing new node and updating the values.
    Slist *new = (Slist*) malloc(sizeof(Slist));

    /* Check whether new node created or not */
    if(new == NULL)
    {
        return FAILURE;
    }

    new->data = ndata;
    Slist *temp = *head;
    
    while(temp != NULL)
    {
        // Checking the given data is found or not.
        if(temp->data == g_data)
        {
            new->link = temp->link;
            temp->link = new;
            return SUCCESS;
        }
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}