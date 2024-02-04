#include "stack.h"

/* Fuction for inserting the element
 * Inputs : stack → Pointer to the first node
 * data → Data to be inserted into stack
 * Output: Return SUCCESS / FAILURE.
 * Description: If stack is not full push the element.
 * If stack is full return FAILURE.
 */
int Push(Stack_t **top, data_t data)
{
    Stack_t *new_node = (Stack_t*)malloc( sizeof(Stack_t));       // Initializing the new node.

    // Checking new node is created or not.
    if( new_node == NULL )
    {
        return FAILURE;
    }

    // Pushing the element to stack.
    new_node->data = data;
    new_node->link = *top;
    *top = new_node;               // Linking the new node to stack.
    
    return SUCCESS;	
}