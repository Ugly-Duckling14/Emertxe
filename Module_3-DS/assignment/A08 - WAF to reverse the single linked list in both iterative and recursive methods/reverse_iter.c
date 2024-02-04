#include "sll.h"

/* Function to reverse the given single linked list 
 * Inputs: head : Pointer to the first node
 * Output: Return LIST_EMPTY, SUCCESS.
 * Description: If list empty return LIST_EMPTY,
 *      else reverse the SLL.
 */
int reverse_iter(Slist **head) 
{ 
    // Checking list empty
    if( *head == NULL)
    {
        return LIST_EMPTY;
    }

    // Initializing the variables.
    Slist *temp = *head, *next = (*head)->link;

    // Assigning 1st value as link to NULL
    if( *head == temp && temp->link != NULL )
    {
        *head = temp->link;
        temp->link = NULL;
    }

    // Travrsing through list and reversing the list.
    while( next != NULL)
    {
        *head = next;
        next = next->link;
        (*head)->link = temp;   
        temp = *head;
    }
    return SUCCESS;
} 