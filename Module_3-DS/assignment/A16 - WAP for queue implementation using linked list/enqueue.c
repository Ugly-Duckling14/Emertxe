#include "queue.h"

/* Function to Insert the element.
 * Inputs: front → pointer to first node 
 *         rear → pointer to last node 
 *         data → Data to be added.
 * Output: Return FAILURE / SUCCESS.
 * Description: If queue is full returns FAILURE else insert data & return SUCCESS
 */
int enqueue(Queue_t **front, Queue_t **rear, int data)
{
    Queue_t *new_node = (Queue_t*) malloc(sizeof(Queue_t));

    // Inserting element to queue. 
    new_node->data = data; 
    new_node->link = NULL;

    // Checking queue is empty then update front and rear.
    if( *front == NULL  )
    {
        *front = new_node;
        *rear =new_node;
    }
    else
    {
        // Updating the data at rear end.
        (*rear)->link = new_node;
        *rear = new_node;
    }
    return SUCCESS;
}