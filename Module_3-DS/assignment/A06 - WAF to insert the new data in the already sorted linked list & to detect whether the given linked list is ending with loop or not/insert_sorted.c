#include "sll.h"

/* Function for insert the number in sorted linked list.
 * Inputs: head - Pointer to the first node, data - New data to be inserted into the sorted list.
 * Output: Return SUCCESS / FAILURE.
 * Description: If list is empty insert at first position,
 *   else insert data into the sorted position.
 */
int insert_sorted( Slist **head, data_t data) 
{
    // Creating the new node.
    Slist *new_node = (Slist*)malloc(sizeof(Slist));

    // Checking node is created or not.
    if( new_node == NULL)
    {
        return FAILURE;
    }

    // Assigning data to new_node node.
    new_node->data = data;

    if( *head == NULL)  // Checking head is null then insert at first pos.
    {
        new_node->link = *head;
        *head = new_node;  
    }
    else if( (*head)->data >= data)  // Checking new data less than first data.
    {
        new_node->link = *head;
        *head = new_node;
    }
    else    // if data is greater than first data in SLL.
    {
        Slist *temp = *head, *prev = *head;
        while( temp != NULL)
        {
            if( temp->data > data)  // If new data is comes in middle of the list.
            {
                new_node-> link = temp;
                prev->link = new_node;
                break;
            }
            else if( temp->link == NULL)    // If new data is comes at last in list.
            {
                new_node->link = temp->link;
                temp->link = new_node;
                break;
            }
            prev = temp;
            temp = temp->link;
        }
    }
    return SUCCESS;
} 