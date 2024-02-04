/*
Name : Munawir E
Date : 09/08/2022
Description : Implement stack using array
 Implement the stack using array:
	1.push(stack, data)
	2.pop(stack)
	3.peek(stack, data)
	4.peep(stack)
*/
#include "stack.h"

/* Creating the stack with given size.
 * Inputs: Pointer that contains address of structure variable,
 *  size of stack.
 * Output: Return SUCCESS / FAILURE.
 * Description: If stack is created return SUCCESS,
 * If stack is not created return FAILURE.
 */
int create_stack(Stack_t *stk, int size)
{
	// Initializing the dynamic array.
	stk->stack = (int*) malloc(size * sizeof(int));
	
	// Checking array is created.
	if(stk->stack == NULL)
	{
		return FAILURE;
	}

	// Assigning values.
	stk->capacity = size;
	stk->top = -1;
	return SUCCESS;
}

int main()
{
	// Initializing the variables.
	int choice, element, peek, size;
	Stack_t stk;

	// Reading the stack size.
    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
	// Function call to create stack.
    create_stack(&stk, size);

	printf("1. Push\n2. Pop\n3. Display Stack\n4. Peek(Element at Top)\n5. Exit\nEnter your choice : ");
    
	while (1)
	{
		// Ask user choice.
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to be pushed in stack : ");
				scanf("%d", &element);

				// Function call for push elements.
				if (Push(&stk, element) == FAILURE)	// Pass by reference.
				{
					printf("INFO : Stack Full\n");
				} 
				break;
			case 2:
				// Function call for pop elements.
				if (Pop(&stk) == FAILURE)
				{
					printf("INFO : Stack is empty\n");
				}
				else
				{
				    printf("INFO : Pop operation is successfull\n");
				}
				break;
			case 3:
				// Function call to print all elements in stack.
				Peep(stk);
				break;
			case 4:
				// Function call to get peek value.
				if ((peek = Peek(&stk)) == FAILURE)
				{
					printf("INFO : Stack is empty\n");
				}
				else
				{
					printf("INFO : Peek element is %d\n", peek);
				}
				break;
			case 5:
				// Terminate the program.
				return SUCCESS;
			default:
				// Default case.
				printf("Invalid Choice.\n");
				break;
		}
	}
	return 0;
}