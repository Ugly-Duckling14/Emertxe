#include "queue.h"

/* Function to deque the element
 * Inputs: Front → pointer to first node 
 *         rear → pointer to last node
 * Output: Return FAILURE / SUCCESS.
 * Description: If queue is empty return FAILURE,
 *    else Delete the data from the front end (free node in LL) and return FAILURE.
 */
int dequeue(Queue_t **front, Queue_t **rear)
{
    // Checking queue is empty.
    if( *front == NULL)
    {
        return FAILURE;
    }

    // Delete data from the front data.
    Queue_t *temp = *front;
    if( *front == *rear)
    {
        *front = NULL;
        *rear = NULL;
        free(temp);
    }
    else
    {
        *front = temp->link;
        free(temp);
    }

    return SUCCESS;
}