#include "tree.h"

/* Function to print the tree in pre order
 * Inputs: root - Pointer to the root node.
 * Output: return SUCCESS.
 * Description: prints the data in preorder & return SUCCESS.
 */
int preorder(Tree_t *root)
{
    // Condition to terminate recursive call.
    if( root != NULL )
    {
        // Printing the data
        printf("%d ", root->data);

        // Recursive call to move to the left child.
        preorder(root->left);

        // Recursive call to move to the right child.
        preorder(root->right);
    }

    return SUCCESS;
}