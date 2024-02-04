#include "sll.h"

/* Function to insert element before the given data.
 * Inputs: head → pointer to first node.
 *         gdata → given data (should be present in the list).
 *         ndata → data to be inserted in the list before gdata.
 * Output: Return LIST_EMPTY / FAILURE / SUCCESS / DATA_NOT_FOUND.
 * Description: If list is empty return list empty, if given data found insert new data before
 *  the given data and return success, else return data not found,
 */
int sl_insert_before(Slist **head, data_t g_data, data_t ndata)
{
    // Checking list is empty or not.
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Initializing structure pointer variables.
    Slist *new = (Slist*) malloc(sizeof(Slist));

    /* Check whether new node created or not */
    if(new == NULL)
    {
        return FAILURE;
    }

    // Adding new data.
    new->data = ndata;
    Slist *temp = *head;
    Slist *prev;

    while(temp != NULL)
    {
        // Checking given data found at first of the SLL.
        if(temp->data == g_data && temp == *head)
        {
            new->link = temp;
            *head = new;
            return SUCCESS;
        }
        else if(temp->data == g_data)   // Chcking data is found.
        {
            new->link = temp;
            prev->link = new;
            return SUCCESS;
        }
        prev = temp;
        temp = temp->link;
    }
    return DATA_NOT_FOUND;
}