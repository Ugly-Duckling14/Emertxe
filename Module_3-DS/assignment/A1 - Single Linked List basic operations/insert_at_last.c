#include "sll.h"

/* Insert element at the last of SLL.
 * Inputs: head - pointer containing first node address, data - item to be added.
 * Output: status - SUCCESS / FAILURE.
 * Description: If data is added successfully at the end SLL then return SUCCESS. 
 * IF failed to add data at the end SLL then return FAILURE.
 */
int insert_at_last(Slist **head, data_t data)
{
    // Initializing structure pointer.
    Slist *new_node = (Slist*)malloc( sizeof(Slist));

    // Checking new node is created or not.
    if( new_node == NULL )
    {
        return FAILURE;
    }

    // Storing values to new node.
    new_node->data = data;
    new_node->link = NULL;

    // Checking the SLL is empty or not.
    if( *head == NULL)
    {
        *head = new_node;
        return SUCCESS;
    }
    else
    {
        // Initialing temporary structure ptr.
        Slist *temp = *head;

        // Traversing through the SLL & links new node at the end of SLL.
        while( temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = new_node;
        return SUCCESS;
    }
}