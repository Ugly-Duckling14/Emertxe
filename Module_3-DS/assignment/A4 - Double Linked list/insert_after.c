#include "dll.h"

/* Function to insert after the given data
 * Inputs: head - Pointer to the first node
 *         tail - Pointer to the last node
 *         gdata - Given data.
 *         ndata - New data to be inserted into the list.
 * Output: return LIST_EMPTY, SUCCESS, DATA_NOT_FOUND.
 * Description: If list is empty then returns LIST_EMPTY,
 *   else search for the gdata if found insert new data after given data & return SUCCESS,
 *       else return DATA_NOT_FOUND. 
 */
int dl_insert_after(Dlist **head, Dlist **tail, int gdata, int ndata)
{
    // Checking the list is empty.
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }

    // Creating the new node.
    Dlist *new_node = (Dlist*) malloc(sizeof(Dlist));
    
    // Checking new node is created.
    if(new_node == NULL)
    {
        return DATA_NOT_FOUND;
    }

    new_node->data = ndata;

    Dlist *temp = *head;
    
    while(temp != NULL)
    {
        // Checking given data present in the list.
        if( temp->data == gdata)
        {
            // If given data present then insert new data after the given data.
            new_node->next = temp->next;
            new_node->prev = temp;
            temp->next = new_node;

            // Checking given data is at last.
            if(new_node->next == NULL)
            {
                *tail = new_node;
                return SUCCESS;
            }
            else    // If the given data not at last.
            {
                new_node->next->prev = new_node;
                return SUCCESS;
            }      
        }

        // Traversing through list.
        temp = temp->next;
    }

    // If data not found.
    free(new_node);
    return DATA_NOT_FOUND;
}