#include "dll.h"

/* Function to delete element.
 * Inputs: head - Pointer to the first node
 *         tail - Pointer to the last node
 *         gdata - Given data.
 *         ndata - New data to be inserted into the list.
 * Output: return LIST_EMPTY, SUCCESS, DATA_NOT_FOUND
 * Description: If list is empty then returns LIST_EMPTY,
 *   else search for the data if found then delete the data & return SUCCESS,
 *       else return DATA_NOT_FOUND.
 */
int dl_delete_element(Dlist **head, Dlist **tail, int data)
{
    // Checking list is empty.
    if( *head == NULL)
    {
        return LIST_EMPTY;
    }

    Dlist *temp = *head;

    // Checking data to be deleted is at first
    if( (*head)->data == data)
    {
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return SUCCESS;
    }
    else if( (*tail)->data == data )    // Chcking the data to deleted is at last.
    {
        temp = *tail;
        *tail = temp->prev;
        (*tail)->next = NULL;
        free(temp);
        return SUCCESS;
    }
    else
    {
        // Checking the data to be deleted is in between
        while( temp!= NULL)
        {
            if( temp->data == data)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                free(temp);
                return SUCCESS;
            }

            // Traversing through the node
            temp = temp->next;
        }
    }

    // If data not found.
    return DATA_NOT_FOUND;  
}