#include "stack.h"

/* Function for print the data's in the stack
 * Inputs : stack → Pointer to the first node
 * Output: Print all the data’s stored in stack.
 * Description: If stack is empty return FAILURE.
 * If stack id not empty print all data in stack.
 */
int Peep(Stack_t *top)
{
	/* Checking the list is empty or not */
	if (top == NULL)
	{
		printf("INFO : Stack is empty\n");
		return FAILURE;
	}

	/* Storing the value in top for traversing */
	Stack_t *temp = top;	
	while (temp)		
	{
		/* Printing the value from stack */
		printf("%d -> ", temp -> data);

		/* Traversing to next node */
		temp = temp -> link;
	}

	printf("NULL\n");
	return SUCCESS;
}