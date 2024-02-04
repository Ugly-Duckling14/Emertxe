#include "sll.h"

/* Function to print list.
 * Inputs: head - Pointer to the first node.
 * Output: Display list empty / display th data in SLL.
 */
void print_list(Slist *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%d -> ", head -> data);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}