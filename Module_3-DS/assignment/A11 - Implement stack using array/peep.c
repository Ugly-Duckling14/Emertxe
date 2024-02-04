#include "stack.h"

/* Function for print the data's in the stack
 * Input: Stack → Pointer that holds address of structure variable 
 * Output: Print all the data’s stored in stack.
 * Description: If stack is empty return FAILURE.
 * If stack id not empty print all data in stack.
 */
void Peep(Stack_t s)
{
	/* Checking the Stack is empty or not */
	if (s.top == -1)
	{
		printf("INFO : Stack is empty\n");
	}
    else
    {
	    /* Declaring the temp for store the top value to print the values in the Stack*/
	    printf("Top -> ");
	    while (s.top > -1)
	    {
		    printf("%d ", s.stack[(s.top)--]);
	    }
	    printf("\n");
    }
}