#include "sll.h"

/* Insert element at the first of SLL.
 * Inputs: head - pointer containing first node address, data - item to be added.
 * Output: status - SUCCESS / FAILURE.
 * Description: If data is added successfully at the first SLL then return SUCCESS. 
 * IF failed to add data at the first SLL then return FAILURE.
 */
int insert_at_first(Slist **head, data_t data)
{
    Slist *new_node = (Slist*)malloc( sizeof(Slist));       // Initializing the new node.

    // Checking new node is created or not.
    if( new_node == NULL )
    {
        return FAILURE;
    }

    // Updating values to new node.
    new_node->data = data;
    new_node->link = *head;
    *head = new_node;               // Linking the new node to SLL.
    return SUCCESS;	
}