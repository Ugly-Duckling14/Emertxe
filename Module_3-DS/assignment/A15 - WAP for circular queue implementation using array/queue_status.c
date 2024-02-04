#include "queue.h"

// Function to check queue is full.
int IsQueueFull(Queue_t *q)
{
    if( q->count == (int)q->capacity)
    {
        return FAILURE;
    }
    return SUCCESS;
}

// Function to check queue is empty
int IsQueueEmpty(Queue_t *q)
{
    if( q->count == 0 )
    {
        q->front = 0;
        return SUCCESS;
    }
    return FAILURE;
   
}