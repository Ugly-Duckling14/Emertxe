#include "sll.h"    

//sortList() will sort nodes of the list in ascending order  
int sort(Slist **head) 
{  
     // Initializing the variables.
    int size = 0, i;
    Slist *cur = *head ,*next, *prev;
    
    // Checking list is empty.
    if( *head == NULL)
    {
        return FAILURE;
    }
    
    // checking the size of SLL.
    while( cur != NULL)
    {
        size++;
        cur = cur->link;
    }
    
    // Sorting the SLL.
    for( i = 0; i < size; i++)
    {
        // Condition for inner loop
        cur = *head;
        prev = cur;
        next = cur->link;
        while( next != NULL)
        {
            // Swapping the data
            if( cur->data > next->data)
            {
                // If head data is greater then swapping the head.
                if( (*head)->data > next->data)
                {
                    cur->link = next->link;
                    next->link = *head;
                    *head = next;
                }
                else if( cur->data > next->data)
                {
                    // Swapping the data other than head
                    prev->link = next;
                    cur->link = next->link;
                    next->link = cur;
                }
                prev = cur;
                cur = next;
                next = cur->link;      
            }
            else     // Updating nodes when not swapping
            {
                prev = cur;
                cur = next;
                next = next->link;
            }
        }  
    }

    return 0;
}  
