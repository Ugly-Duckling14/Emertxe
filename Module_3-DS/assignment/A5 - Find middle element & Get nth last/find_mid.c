#include "sll.h"
/* Function to get the middle of the linked list
 * Inputs: head - Pointer to the first node, mid - Pointer to the mid node data.
 * Output: return LIST_EMPTY, SUCCESS.
 * Description: if list is empty returns LIST_EMPTY,
 * else return the mid value and SUCCESS 
 */
int find_mid(Slist *head, int *mid) 
{
    // Checking list is empty.
    if(head == NULL)
    {
        return LIST_EMPTY;
    }

    // Initializing structure pointer variable.
    Slist *temp = head, *current = temp;

    // Finding the mid value
    while(temp != NULL)
    {
        // For ODD nodes.
        if(temp->link == NULL)
        {
            break;
        }
        else    //For even nodes.
        {
            current = current->link;
            temp = temp->link->link;
        }
    }

    // Return the mid value.
    *mid = current->data;
    return SUCCESS;
} 