#include "tree.h"

/* Function to insert the data's in BST  
 * Inputs: root - pointer to the root node.
 *         data - data to be inserted.
 * Output: Return SUCCESS / DUPLICATE / FAILURE.
 * Description: If new node is not created return FAILURE,
 *      else Travrse through the node till end to left of right according parent & data
 *          & insert data, If duplicate data is found return DUPLICATE.
 */
int insert_into_BST(Tree_t **root, int data)
{
    int flag = 0;

    // Creating new node
    Tree_t *new_node = (Tree_t*) malloc(sizeof( Tree_t));

    if( new_node == NULL )
    {
        return FAILURE;
    }

    // Assigning values to new node.
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    // Checking tree is empty then add the data as root node.
    if( *root == NULL )
    {
        *root = new_node;
    }
    else
    {
        // Initializing temp variables for traverse through nodes.
        Tree_t *temp = *root, *parent;

        while( temp != NULL )
        {
            parent = temp;

            // If data is greater than parent node move to right side.
            if( temp->data < data)
            {
                flag = 1;
                temp = temp-> right;
            }
            else if( temp->data > data)     // If data is less than parent node move to left side.
            {
                flag = 0;
                temp = temp->left;
            }
            else    // If data is already present.
            {
                free(new_node);
                return DUPLICATE;
            }
        }

        // If flag is one data insert to right child.
        if( flag == 1 )
        {
            parent->right = new_node;
        }
        else if( flag == 0) // If flag is 0 data insert to left child.
        {
            parent->left = new_node;
        }  
    }
    return SUCCESS;
}