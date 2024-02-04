#include "queue.h"

/* Function to Insert the element.
 * Inputs: queue → Pointer contains structure variable 
 *         data → Data to be added.
 * Output: Return FAILURE / SUCCESS.
 * Description: If queue is full returns FAILURE else insert data & return SUCCESS
 */
int enqueue(Queue_t *q, int data)
{
    // Checking queue is full.
    if( IsQueueFull(q) == FAILURE)
    {
        return FAILURE;
    }

    // Checking is empty then set front equal to 0.
    if( q->front == -1 )
    {
        q->front = 0;
    }

    // Inserting element to queue. 
    q->rear = (++(q->rear)) % q->capacity;
    q->Que[q->rear] = data;
    q->count++;
    
    return SUCCESS;
}