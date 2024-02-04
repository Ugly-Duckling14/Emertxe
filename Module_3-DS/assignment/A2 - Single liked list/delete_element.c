#include "sll.h"

/* Function delete the given data.
 * Inputs: head → pointer to first node, data → the data to be deleted.
 * Output: Return SUCCCES / FAILURE.
 * Description: if the givn data is deleted return success,
 * Else return failure.
 */
int sl_delete_element(Slist **head, data_t data)
{
    // Checking list is empty or not.
    if(*head == NULL)
    {
        return FAILURE;
    }

    // Intializing structure pointer variables.
    Slist *temp1, *temp2;
    temp1 = *head;
    
    while( temp1 != NULL)
    {
        // Checking data is present or not.
        if( temp1->data != data)
        {
            temp2 = temp1;
            temp1 = temp1->link;
        }
        else 
        {
            // Deleting elements.
            if( (*head)->data == data)
            {
                *head = temp1->link;
                free(temp1); 
            }
            else
            {
                temp2->link = temp1->link;
                free(temp1);
            }
            return SUCCESS;
        }  
    }
    return DATA_NOT_FOUND;
}