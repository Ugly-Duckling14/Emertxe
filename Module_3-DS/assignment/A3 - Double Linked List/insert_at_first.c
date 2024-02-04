#include "dll.h"

/* Function to insert element at first.
 * Inputs: head → pointer to first node.
 *         tail → pointer to last node
 *        data → data to be inserted.
 * Output: Return FAILURE / SUCESS.
 * Description : If list is empty return FAILURE,
 *   else insert element at first and return SUCCESS.
 */
int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    // Creating new node for insert data.
    Dlist *new_node = (Dlist*) malloc(sizeof(Dlist));

    // Checking new node is created or not.
    if( new_node == NULL)
    {
        return FAILURE;
    }

    // Updating the data.
    new_node->data = data;

    // If listis empty.
    if(*head == NULL)
    {
        new_node->prev = *head;
        new_node->next = *tail;
        *head = new_node;
        *tail = new_node;
    }
    else
    {
        // Insert at first when list is not empty
        new_node->next = *head;
        new_node->prev = new_node->next->prev;
        new_node->next->prev = new_node;
        *head = new_node;
    }

    return SUCCESS;
}