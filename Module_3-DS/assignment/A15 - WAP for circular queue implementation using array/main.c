/*
Name : Munawir E
Date : 15/08/2022
Description : A15 - WAP for circular queue implementation using array
	Implement functions given below :
		1. Enqueue(queue, data) 
		2. Dequeue(queue) 
		3. Print_queue(queue) 
*/
#include "queue.h"

/* Function to create the queue.
 * Inputs: queue → Pointer contains structure variable 
 *         size - Size of queue array.
 * Output: Return FAILURE / SUCCESS.
 */
int create_queue(Queue_t *q, int size)
{
	q->Que = (int*) malloc(sizeof(int) * size);

	if( q->Que == NULL)
	{
		return FAILURE;
	}

	q->front = -1;
	q->rear = -1;
	q->count = 0;
	q->capacity = size;
	return SUCCESS;
}

int main()
{
	Queue_t q;
	int size;
	printf("Enter the size of the queue : ");
	scanf("%d", &size);
	if (create_queue(&q, size) == FAILURE)
	{
	    printf("INFO : Queue not created\n");
	    return FAILURE;
	}

	char ch;
	int choice, data;
	printf("1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\nEnter the option : ");
	while (1)
	{
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				/* Function to Enqueue the Queue */
				printf("Enter the element you want to insert : ");
				scanf("%d", &data);
				if (enqueue(&q, data) == FAILURE)
				{
					printf("INFO : Queue full\n");
				}
				break;
			case 2:
				/* Function to dequeueue the queue */
				if (dequeue(&q) == FAILURE)
				{
					printf("INFO : Queue is empty\n");
				}
				else
				{
					printf("INFO : Dequeue successfull\n");
				}
				break;
			case 3:
				/* Function to print the queue */
				print_queue(q);
				break;
			case 4:
				return SUCCESS;
			default:
				printf("Invalid option !!!\n");
		}

	}
}