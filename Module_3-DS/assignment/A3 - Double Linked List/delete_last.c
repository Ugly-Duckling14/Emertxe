#include "dll.h"

/* Function to delete node at last.
 * Inputs: head → pointer to the first node.
 *         tail → pointer to last node
 * Output: Return FAILURE / SUCCESS.
 * Description: If head is empty return FAILURE,
 *    else delete the node at last & return SUCCESS.
 */
int dl_delete_last(Dlist **head, Dlist **tail)
{
    // Checking the list is empty.
    if(head == NULL)
    {
        return FAILURE;
    }

    // If list is having only one element.
    if(*head == *tail)
    {
        free(*tail);
        *head = *tail = NULL;
    }
    else
    {
        // Initializing temp variable.
        Dlist *temp = *tail;
        
        // If list is having more than one element.
        *tail = temp->prev;
        temp->prev->next = NULL;
        free(temp);
    }
    
    return SUCCESS;
}