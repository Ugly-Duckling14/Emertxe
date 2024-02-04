#include "sll.h"

/* Function to merge two list in sorted order.
 * Inputs: head1 - Pointer to the first node of the first linked list
 *         head2 - Pointer to the first node of the second linked list
 * Output: Return LIST_EMPTY / SUCCESS.
 * Description: If both list are empty returns LIST_EMPTY,
 *      else merge two list and sort the list.
 */
int sorted_merge( Slist **head1, Slist **head2)
{
    // Checking both list are empty.
    if( *head1 == NULL && *head2 == NULL )
    {
        return LIST_EMPTY;
    }
    else if( *head1 == NULL )       // If 1st list is empty, Append 2nd list to first.
    {
        *head1 = *head2;
    }
    else if( *head1 != NULL && *head2 != NULL)      // When both list are not empty merging two SLL to one
    {
        Slist *temp = *head1;

        // Traversing through the 1st list till the end.
        while( temp->link != NULL )
        {
            temp = temp->link;
        }

        // Merging two list into an single SLL.
        temp->link = *head2;
    }

    // Function call to sort SLL.
    sort( head1);

    return SUCCESS;

}