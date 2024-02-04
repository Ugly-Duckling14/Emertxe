#include "sll.h"

/* Function to get the nth node from the last of a linked list
 * Inputs: head - Pointer to the first node, 
 *         pos - Position from the last node, 
 *         data - Pointer to Nth last node data.
 * Output: return LIST_EMPTY, SUCCESS, POSITION NOT FOUND.
 * Description: If list is empty returns LIST_EMPTY, else return SUCCESS if nth last 
 *   position found, else returns POSITION NOT FOUND.
 */
int find_nth_last(Slist *head, int pos, int *data) 
{
    // Checking the list is empty or not.
    if(head == NULL)
    {
        return LIST_EMPTY;
    }

    // Initializing the variables.
    int count = 0;
    Slist *temp = head, *current = temp;
    
    if( pos > 0 )
    {
        // Finding the nth last position.
        while(temp != NULL)
        {
            count++;
        
            if( pos < count)
            {
                current = current->link;
            }
        
            temp = temp->link;
        }

        // Returns the data of nth last position.
        if(pos <= count)
        {
            *data = current->data;
            return SUCCESS;
        }
    }

    // Return failure if position not found.
    return FAILURE;
} 