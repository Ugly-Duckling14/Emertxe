#include "stack.h"

/* Fuction for inserting the element
 * Inputs : stack → Pointer that contains address of structure variable 
 * data → Data to be inserted into stack
 * Output: Return SUCCESS / FAILURE.
 * Description: If stack is not full push the element.
 * If stack is full return FAILURE.
 */
int Push(Stack_t *s, int element)
{
    // Checking the stack is full 
    if( s->top == (int) s->capacity-1)
    {
        return FAILURE;
    }

    // Pushing element to stack.
    s->top++;
    s->stack[s->top] = element;
    return SUCCESS;
}