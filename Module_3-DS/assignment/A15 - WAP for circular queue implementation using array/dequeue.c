#include "queue.h"

/* Function to deque the element
 * Inputs: structure ptr variable.
 * Output: Return SUCCESS / FAILURE.
 * Description: If queue is empty returns FAILURE, else delete data & return SUCCESS.
 */
int dequeue(Queue_t *q)
{
    // Checking queue is empty.
    if( IsQueueEmpty(q) == SUCCESS)
    {
        return FAILURE;
    }
    
    // Removing element in queue.
    q->count--;
    q->front = (++(q->front)) % q->capacity;
    
    return SUCCESS;
}