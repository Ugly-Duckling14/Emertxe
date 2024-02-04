#include "sll.h"

/* Function to insert data at given position inn SLL.
 * Inputs: head → pointer to first node.
 *         gdata → given data (should be present in the list).
 *         ndata → data to be inserted in the list before gdata.
 * Output: return SUCCESS / FAILURE / LIST_EMPTY / POSITION_NOT_FOUND.
 * Description: If list is empty returns list empty, if the given position present
 *  in the SLL. insert data at the given postion. else position not found.
 */
int sl_insert_nth(Slist **head, data_t data, data_t n)
{
    // Initializing new node and update the data.
    Slist *new = malloc(sizeof(Slist));
    
    /* Check whether new node created or not */
    if(new == NULL)
    {
        return FAILURE;
    }
    
    if( n == 1)    // If the position is 1 of SLL.
    {
        new->data = data;
        new->link = *head;
        *head = new;
        return SUCCESS;
    }
    else if(*head == NULL) // Checking list is empty or not.
    {
        return LIST_EMPTY;
    }
    
    Slist *temp = *head;
    int pos = 0;
    
    while( temp != NULL)
    {
        pos++;
        // Finding the position and inserting new data to givn position.
        if( pos == n - 1)
        {
            new->data = data;
            new->link = temp->link;
            temp->link = new;
            return SUCCESS;
        }
        else if( pos == n)   // If the position at end of SLL.
        {
            new->data = data;
            new->link = temp->link;
            temp->link = new;
            return SUCCESS;
        }
        temp = temp->link;
    }
    return POSITION_NOT_FOUND;
}