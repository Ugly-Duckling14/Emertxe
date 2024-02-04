#include "dll.h"

/* Function to insert before the given data
 * Inputs: head - Pointer to the first node
 *         tail - Pointer to the last node
 *         gdata - Given data.
 *         ndata - New data to be inserted into the list.
 * Output: return LIST_EMPTY, SUCCESS, DATA_NOT_FOUND.
 * Description: If list is empty then returns LIST_EMPTY,
 *   else search for the gdata if found insert new data before given data & return SUCCESS,
 *       else return DATA_NOT_FOUND. 
 */
int dl_insert_before(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    // Checking list empty.
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    // Creating new node.
    Dlist *new_node = (Dlist*) malloc(sizeof(Dlist));

    if( new_node == NULL)
    {
        return DATA_NOT_FOUND;
    }
    new_node->data = ndata;

    // If given data is at first in the list.
    if( (*head)->data == gdata)
    {
        new_node->prev = NULL;
        new_node->next = *head;
        *head = new_node;
        return SUCCESS;
    }
    else    // If given data in between.
    {
        Dlist *temp = *head;

        while( temp != NULL)
        {
            // Checking given data is present, then insert befor the given data.
            if( temp->data == gdata)
            {
                new_node->prev = temp->prev;
                new_node->next = temp;
                new_node->prev->next = new_node;
                temp->prev = new_node;
                return SUCCESS;
            }

            // Traversing through the nodes.
            temp = temp->next;
        }
    }

    // If data not found.
    free(new_node);
    return DATA_NOT_FOUND;
}