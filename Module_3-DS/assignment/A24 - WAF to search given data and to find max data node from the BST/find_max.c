#include "tree.h"

/* Function to find the maximum value in the tree.
 * Inputs: root - Pointer to the root node.
 * Output: return MAX_VALUE / FAILURE.
 * Description: If tree is empty return FAILURE,
 *      else return the max value in tree. 
 */
int findmax(Tree_t * root)
{
    // Checking tree is empty
    if( root == NULL)
    {
        return FAILURE;
    }

    // Traversing through tree to find max value.
    while( root->right != NULL)
    {
        root = root->right;
    }

    // Returning max value in tree.
    return root->data;
}
