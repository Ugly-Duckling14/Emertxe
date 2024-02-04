#include "stack.h"

/* Function for display the top of the element in Stack 
 * Inputs : stack → Pointer to the first node
 * Output: Return top most value/ Failure.
 * Description: If stack is not empty returns top most value of stack,
 * If stack is empty returns FAILURE.
 */
int Peek(Stack_t **top)
{
    // Checking list is empty or not.
    if( *top == NULL)
    {
        return FAILURE;
    }

    // Returns the peek value in stack.
    return (*top)->data;
}