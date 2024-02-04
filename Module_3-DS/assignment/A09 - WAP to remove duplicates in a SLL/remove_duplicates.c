#include "sll.h"

/* Function to remove duplicate data's from list
 * Inputs: head -  Pointer to the first node
 * Output: Return SUCCESS / FAILURE.
 * Description: when list is empty return FAILURE,
 *      else rmove duplicate values and return SUCCESS
 */
int remove_duplicates( Slist **head )
{
    // Checking the list is empty.
    if( *head == NULL)
    {
        return FAILURE;
    }

    // Initializing the local variables.
    Slist *temp = *head, *cur, *prev;

    // Outer loop run until temp equal to NULL.
    while( temp != NULL)
    {
        // Inner loop run until cur equal to NULL.
        cur = temp->link;
        prev = temp;
        while( cur != NULL)
        {
            // Removing the duplicate and updating the nodes.
            if( temp->data == cur->data)
            {
                prev->link = cur->link;
                free(cur);
                cur = prev->link;
            }
            else    // Traversing prev & cur  when no duplicate elements present.
            {
                prev = cur;
                cur = cur->link;
            }
        }

        // Traversing temp, cur and prev. 
        temp = temp->link;
    }
    return SUCCESS;
}