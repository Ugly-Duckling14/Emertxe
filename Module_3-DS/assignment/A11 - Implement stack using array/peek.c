#include "stack.h"

/* Function for display the top of the element in Stack 
 * Inputs: stack → Pointer that contains address of structure variable
 * Output: Return top most value/ Failure.
 * Description: If stack is not empty returns top most value of stack,
 * If stack is empty returns FAILURE.
 */
int Peek(Stack_t *s)
{
    // Checking stack is empty or not.
    if(s->top == -1)
    {
        return FAILURE;
    }

    // Returns the peek value in stack.	
    return s->stack[s->top];
}