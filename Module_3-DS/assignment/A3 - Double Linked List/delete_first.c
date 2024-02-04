#include "dll.h"

/* Function to delete node at first.
 * Inputs: head → pointer to the first node.
 *         tail → pointer to last node
 * Output: Return FAILURE / SUCCESS.
 * Description: If head is empty return FAILURE,
 *    else delete the node at first & return SUCCESS.
 */
int dl_delete_first(Dlist **head, Dlist **tail)
{
    // Checking list is empty.
    if( *head == NULL)
    {
        return FAILURE;
    }

    // If list is having only one element.
    if(*head == *tail)
    {
        free(*head);
        *head = *tail = NULL;
    }
    else
    {
        // Initializing the temp node.
        Dlist *temp = *head;
        
        // Deleting the first node.
        *head = temp->next;
        temp->next->prev = NULL;
        free(temp);  
    }
    
    return SUCCESS;
}