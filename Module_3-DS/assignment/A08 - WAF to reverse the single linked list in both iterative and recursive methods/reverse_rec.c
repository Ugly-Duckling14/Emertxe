#include "sll.h"

/* Function to reverse the SLL using recursion
 * Inputs: head : Pointer to the first node
 * Output: Return LIST_EMPTY, SUCCESS.
 * Description: If list empty return LIST_EMPTY,
 *      else reverse the SLL.
 */
int reverse_recursion(Slist ** head)
{
    // Checking list is empty.
    if( *head == NULL)
    {
        return LIST_EMPTY;
    }
    
    // Initializing the variables.
    static Slist *prev = NULL;
    Slist *next, *cur = *head;

    // Traversing and reversing the nodes.
    next = cur->link;
    cur->link = prev;
    prev = cur;
    cur = next;

    // Condition to terminate the program.
    if( cur != NULL )
    {
        reverse_recursion( &cur);
    }

    // Updating the head.
    *head = prev;

    return SUCCESS;    
}