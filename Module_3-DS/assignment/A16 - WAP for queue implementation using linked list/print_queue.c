#include "queue.h"

/* Function to print the Queue
 * Inputs: Front → pointer to first node 
 *         rear → pointer to last node
 * Output: Return FAILURE / SUCCESS.
 * Description: If queue is empty returns FAILURE, else print the data and return SUCCESS.
 */
int print_queue(Queue_t *front, Queue_t *rear)
{
	if (front == NULL)
	{
		printf("INFO : Queue is Empty\n");
		return FAILURE;
	}

	printf("Front -> ");
	while (front)		
	{
		printf("%d ", front -> data);
		front = front -> link;
		if (rear -> link != front)
		{
		    printf("-> ");
		}
		else
		    break;
	}

	printf("<- Rear\n");
	return SUCCESS;
}