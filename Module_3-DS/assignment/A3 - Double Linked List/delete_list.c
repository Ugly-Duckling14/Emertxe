#include "dll.h"

/* Function to delete all nodes in list.
 * Inputs: head → pointer to the first node.
 *         tail → pointer to last node
 * Output: Return FAILURE / SUCCESS.
 * Description: If head is empty return FAILURE,
 *    else delete all the nodes & return SUCCESS.
 */
int dl_delete_list(Dlist **head, Dlist **tail)
{
    // Checking list empty.
    if(*head == NULL)
    {
        return FAILURE;
    }

    // Initializing local variables.
    Dlist *temp = *head;

    // Delete all nodes one by one from head.
    while( *head != NULL)
    {
        *head = temp->next;
        free(temp);
        temp = *head;
    }

    // Updating tail.
    *tail = *head;
 
    return SUCCESS;
}