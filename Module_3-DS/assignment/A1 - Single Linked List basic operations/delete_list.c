#include "sll.h"

/* Deleting all nodes one by one.
 * Inputs: head - pointer containing first node address.
 * Output: status - SUCCESS / FAILURE.
 * Description: If all the nodes deleted successfully then return SUCCESS. 
 * IF list is empty then return FAILURE.
 */
int sl_delete_list(Slist **head)
{
    // Checking the list is empty or not.
    if(*head == NULL)
    {
        return FAILURE;
    }

    // Deleting all node one by one.
    Slist *temp = *head;
    while( *head != NULL)
    {
        *head = temp->link;
        free(temp);
        temp = *head;        
    }	
    return SUCCESS;
}