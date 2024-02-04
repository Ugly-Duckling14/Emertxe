#include "sll.h"

/* Function to print the SLL.
 * Inputs: head - Pointer to the first node
 * Output: List empty / print data's of all node.
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