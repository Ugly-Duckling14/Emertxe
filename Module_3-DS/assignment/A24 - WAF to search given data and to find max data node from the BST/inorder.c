#include "tree.h"

/* Function to print the data in in order printing
 * Inputs: root - Pointer to the root node.
 * Output: return SUCCESS.
 * Description: prints the data in inorder & return SUCCESS.
 */
int inorder(Tree_t *root)
{
    // Condition for terminate recursive call.
    if( root != NULL )
    {
        // Recursive call for move to left child.
        inorder(root->left);

        // Printing the data.
        printf("%d ", root->data);
        
        // Recursive call for move to the right child.
        inorder(root->right);
    }

    return SUCCESS;
}