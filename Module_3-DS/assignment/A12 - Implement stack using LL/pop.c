#include "stack.h"

/* Function for Poping the element 
 * Inputs : stack → Pointer to the first node
 * Output: Return SUCCESS / FAILURE.
 * Description: If stack is not empty remove top element,
 * If stack is empty returns FAILURE.
 */
int Pop(Stack_t **top)
{
    // Checking list is empty or not.
    if( *top == NULL)
    {
        return FAILURE;
    }
    
    // Removing elements from stack.
    Stack_t *temp = *top;
    *top = temp->link;
    free(temp);
    return SUCCESS;
}