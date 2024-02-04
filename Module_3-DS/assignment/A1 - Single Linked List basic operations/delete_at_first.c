#include "sll.h"

/* Deleting the first nodes of SLL.
 * Inputs: head - pointer containing first node address.
 * Output: status - SUCCESS / FAILURE.
 * Description: First node is deleted successfully then return SUCCESS. 
 * IF list is empty then return FAILURE.
 */
int sl_delete_first(Slist **head)
{
    // Checking list is empty or not.
    if( *head == NULL)
    {
        return FAILURE;
    }
    
    // Deleting the first node in SLL.
    Slist *temp = *head;
    *head = temp->link;
    free(temp);
    return SUCCESS;
}