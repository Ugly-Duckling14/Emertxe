#include "sll.h"

/* Deleting the last nodes of SLL.
 * Inputs: head - pointer containing first node address.
 * Output: status - SUCCESS / FAILURE.
 * Description: Last node is deleted successfully then return SUCCESS. 
 * IF list is empty then return FAILURE.
 */
int sl_delete_last(Slist **head)
{
    // Checking list is empty or not.
    if( *head == NULL)
    {
        return FAILURE;
    }

    Slist *temp = *head;
    if(temp->link == NULL)
    {
        // Checking temp is having only one element.
        *head = temp->link;
        free(temp);
    }
    else
    {
        // Traverse through the list
        while( temp->link->link != NULL)
        {
            temp = temp->link;
        }

        // Deleting the last node.
        free(temp->link);
        temp->link = NULL;
    }
    return SUCCESS;
}