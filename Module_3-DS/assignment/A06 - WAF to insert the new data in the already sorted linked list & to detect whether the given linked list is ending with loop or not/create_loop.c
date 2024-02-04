#include "sll.h"

/* Function to create the loop 
 * Inputs: head - Pointer to the first node, data - data which the loop start.
 * Output: LIST_EMPTY / DATA_NOT_FOUND / SUCCESS.
 * Description: If list is empty return LIST_EMPTY,
 *    else check data present in List, if present creates LOOP else
 *    return DATA_NOT_FOUND.
 */
int create_loop(Slist **head, data_t data)
{
    // Checking list is empty.
    if( *head == NULL)
    {
        return LIST_EMPTY;
    }

    // Initializing the structure pointer.
    Slist *cur = NULL, *temp = *head;

    while( temp != NULL)
    {
        // Storing the address to cur where the loop should start.
        if( temp->data == data)
        {
            cur = temp;
        }

        // Creating the loop
        if( cur != NULL && temp->link == NULL)
        {
            temp->link = cur;
            return SUCCESS;
        }

        temp = temp->link;
    }

    return DATA_NOT_FOUND;
}