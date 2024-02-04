#include "tree.h"

/* Function to find minimum value in the tree
 * Inputs: root - Pointer to the root node.
 * Output: return SUCCESS / FAILURE.
 * Description: If tree is empty return FAILURE,
 *      else find the minimum value and return the minimum value
 */
int findmin(Tree_t * root)
{
    // Checking tree is empty
    if( root ==  NULL)
    {
        return FAILURE;
    }

    // Traversing through the tree to find min value.
    while( root->left != NULL)
    {
        root = root->left;
    }

    // Returning minimum value.
    return root->data;
}
