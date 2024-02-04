#include "tree.h"

/* Function to search data in BST using Iterative
 * Inputs: root - pointer to the root node.
 *         data - data to be inserted.
 * Output: Return FAILURE / SUCCESS / NOELEMENT.
 * Description: If tree is empty return FAILURE.
 *    else search for data if data found Return SUCCESS,
 *        if data not found return NOELEMENT.
 */
int search_BST(Tree_t * root, int data)
{
    // Checking tree is empty.
    if( root == NULL)
    {
        return FAILURE;   
    }

    // Traversing through the tree till end according to th data to be found
    while( root != NULL)
    {
        // If data is greater than parent child.
        if( root->data < data)
        {
            root = root->right;
        }
        else if( root->data > data )    // If data is less than parent.
        {
            root = root->left;
        }
        else    // If data found return SUCCESS.
        {
            return SUCCESS;
        }
    }

    // If data not found.
    return NOELEMENT;    

}