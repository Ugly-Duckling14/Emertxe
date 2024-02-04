#include "stack.h"

/* Function for Poping the element 
 * Inputs: stack → Pointer that contains address of structure variable 
 * Output: Return SUCCESS / FAILURE.
 * Description: If stack is not empty remove top element,
 * If stack is empty returns FAILURE.
 */
int Pop(Stack_t *s)
{
    // Checking stack is empty.	
    if( s->top == -1)
    {
        return FAILURE;
    }

    // Removing element from stack
    s->top--;
    return SUCCESS;
}