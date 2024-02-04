#include "sll.h"

/* Insert element at the last of SLL.
 * Inputs: head - pointer containing first node address, data - item to be added.
 * Output: status - SUCCESS / FAILURE.
 * Description: If data is added successfully at the end SLL then return SUCCESS. 
 * IF failed to add data at the end SLL then return FAILURE.
 */
int insert_at_last(Slist **head, data_t data)
{
	/* create new node */
	Slist *new = malloc(sizeof(Slist));
	if (!new)
	{
		return FAILURE;
	}

	/* if new node created, update data + link */
	new->data = data;
	new->link = NULL;

	/* If list is empty */
	if (*head == NULL)
	{
		/* add new node to first position */
		*head = new;
		return SUCCESS;
	}

	/* else */
	/* temp points to first node */
	Slist *temp = *head;

	/* traverse to next node check next node is present or not */
	while (temp->link != NULL)
	{
		temp = temp->link;
	}

	/* establish the link between last and new node*/
	temp->link = new;

	return SUCCESS;
}