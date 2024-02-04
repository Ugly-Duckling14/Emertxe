#include "invert_index.h"

/* Function to validate command line arguments.
 * Inputs: argc - CLA count, argv - CLA,
 *         head - pointer to first node SLL, iter - count for terminate recursion.
 * Output: Return SUCCESS / FAILURE.
 * Description: Validating duplicate file is present then skip else store in SLL and return SUCCESS.  
 */
Status Validate( int argc, char *argv[], sll_node **head, int iter)
{
    // Condition to terminate recursive call.
    if( iter < argc)
    {
        // Initializing local variables.
        int flag = 1;
        sll_node *new_node = (sll_node*) malloc(sizeof(sll_node));

        if(new_node == NULL)
        {
            return FAILURE;
        }

        strcpy(new_node->file_name, argv[iter]);
        new_node->link = NULL;

        // If SLL is empty.
        if( *head == NULL)
        {
            *head = new_node;
            printf("\033[32mINFO: File %s is Added Successfully.\n", new_node->file_name);

        }
        else
        {
            sll_node *temp = *head;
            while( temp->link != NULL)
            {
                // Skipping the duplicate files.
                if( !strcmp(argv[iter], temp->file_name ))
                {
                    flag = 0;
                    break;
                }
                temp = temp->link;
            }

            // Adding the files to SLL.
            if( strcmp(argv[iter], temp->file_name ) && flag == 1)
            {
                temp->link = new_node;
                printf("\033[0;32m");
                printf("INFO: File %s is Added Successfully.\n", new_node->file_name);
            }
            else    // Deallocating the node.
            {
                printf("\033[0;33m");
                printf("WARNING: Duplicate File %s Found.\nSKIPPING: The File...\n", new_node->file_name);
                free(new_node);
            }
        }

        // Function recursive call.
        Validate( argc, argv, head, ++iter);
    }
    return SUCCESS;
}


/* Function to check file empty */
Status Is_empty( FILE *fptr_name)
{
    fseek(fptr_name, 0, SEEK_END);

    if( ftell( fptr_name) != 0)
    {
        return SUCCESS;
    }
    return FAILURE;
}
