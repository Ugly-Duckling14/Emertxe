#include "sll.h"

/* Function for finding the loop in the link.
 * Inputs: head - Pointer to the first node.
 * Output: Return LIST_EMPTY / LOOP_NOT_DETECTED / SUCCESS.
 * Description: if list empty return LIST_EMPTY,
 *    else if loop detected return SUCCCESS, else return LOOP_NOT_DETECTED.
 */
int find_loop(Slist *head)
{
    // Checking list is empty.
    if( head == NULL)
    {
        return LIST_EMPTY;
    }

    // Initializing the structure pointer.
    Slist *temp1 = head, *temp2 = head->link;

    while( temp1 != NULL)
    {
        // Checking no NULL present in list traverse.
        if(temp2-> link != NULL && temp2->link->link != NULL )
        {
            temp2 = temp2->link->link;
            temp1 = temp1->link;
        }
        else if( temp2->link == NULL || temp2->link->link == NULL )     // If NULL is found is list return loop not found.
        {
            return LOOP_NOT_FOUND;
        }
        
        // If loop found terminate the loop. 
        if( temp1->data == temp2->data)
        {
            break;
        }
    }

    return SUCCESS;
}