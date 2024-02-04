#include "sll.h"

/* Finding the position of data present SLL.
 * Inputs: head - pointer containing first node address, data - data to be found in the list.
 * Output: status - SUCCESS / FAILURE.
 * Description: If data is found successfully then return the position of data. 
 * IF data is not found then return FAILURE.
 */
int find_node(Slist *head, data_t data)
{
    int count = 0;      // Initialzing variable for get the position.
   
    // Checking SLL is empty or not. 
    if(head == NULL)
    {
        return FAILURE;
    }

    // Finding the node position for the given data.
    Slist *temp = head;

    while(temp->link != NULL)
    {
        if(temp->data == data)
        {
            return count;
        }
        count++;
        temp = temp->link;
    }
    return FAILURE;
}
