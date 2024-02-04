#include "tree.h"

extern int status;
/* Function to delete the node 
 * Inputs: root - pointer to the root node.
 *         data - data to be inserted.
 * Output: Return pointer / NULL.
 * Description: If data found delete data and then, return the address,
 *          else return NULL.
 */
Tree_t * delete_BST(Tree_t * root, int data)
{
    // Initializing the variable.
    int flag;
    Tree_t *temp = root ,*cur;

    while( temp != NULL)
    {
        // Checking data is less than parent.
        if( temp->data > data)
        {
            // Traversing to the left.
            cur = temp;
            temp = temp->left;
            flag = 0;
        }
        else if( temp->data < data )    // Checking data is greater than parent.
        {
            // Traversing to the right.
            flag = 1;
            cur = temp;
            temp = temp->right;
        }
        else if( temp->data == data)
        {
            // If data is at the leaf node.
            if(temp->left == NULL && temp->right == NULL )
            {
                // Checking data is at left or right of parent node.
                if(flag == 0)
                {
                    cur->left = NULL;
                }
                else
                {
                    cur->right = NULL;
                }
                
                // Removing the data.
                free(temp);

                return root;
            }
            else if( temp->left == NULL)     // If data having only right node.
            {
                // Checking data is at left or right of parent node.
                if( flag == 0)
                {
                    cur->left = temp->right;
                }
                else
                {
                    cur->right = temp->right;
                }   

                // Removing the data.
                free(temp);
                
                return root;
            }
            else if( cur->right == NULL)  // If data having only left node.
            {
                // Checking data is at left or right of parent node.
                if( flag == 0)
                {
                    cur->left = temp->left;
                }
                else
                {
                    cur->right = temp->left;
                }
                
                // Removing the data.
                free(temp);
                
                return root;
            }
            else        // If data having two childs.
            {
                Tree_t *prev;
                cur = temp;

                // Finding the data's left side maximum value    
                temp = temp->left;
                
                while( temp->right != NULL)
                {
                    prev = temp;
                    temp = temp->right;                    
                }
                prev->right = NULL;
                
                // Assigning left max value to cur node.
                cur->data = temp->data;
                free(temp);
                return root;
            }
        }
    }

    // If data is not found.
    return NULL;
}