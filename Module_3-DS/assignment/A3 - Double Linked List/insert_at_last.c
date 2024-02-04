#include "dll.h"

/* Function to insert element at first.
 * Inputs: head → pointer to first node.
 *         tail → pointer to last node
 *        data → data to be inserted.
 * Output: Return FAILURE / SUCESS.
 * Description : If list is empty return FAILURE,
 *   else insert element at first and return SUCCESS.
 */
int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    // Creating new node to insert data at last.
    Dlist *new_node = (Dlist*)malloc( sizeof(Dlist));

    // Checking new node is created.
    if( new_node == NULL)
    {
        return FAILURE;
    }

    // Updating the data.
    new_node->data = data;

    // If list is empty.
    if(*head == NULL)
    {
        new_node->next = *tail;
        new_node->prev = *head;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        // Insert at last when list is not empty.
        new_node->prev = *tail;
        new_node->next = new_node->prev->next;
        new_node->prev->next = new_node;
        *tail = new_node;
    }
    
    return SUCCESS;
}