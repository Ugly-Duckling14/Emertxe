#include "sll.h"

/* Prints the data present in SLL.
 * Inputs: head - pointer containing first node address.
 * Output: If list is not empty display the elements present in list,
 * If list is empty print error message.
 * Description: Prints error message is SLL is empty, 
 * else prints the elements presents in the SLL.
 */
void print_list(Slist *head)
{
	// Checking list is empty or not.
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
		// Printing the data inside SLL.
	    while (head)		
	    {
		    printf("%d -> ", head -> data);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}