#include "tree.h"

/* Function to print the tree in post order 
 * Inputs: root - Pointer to the root node.
 * Output: return SUCCESS.
 * Description: prints the data in postorder & return SUCCESS.
 */
int postorder(Tree_t *root)
{
    // Condition to terminate recursive call.
    if( root != NULL)
    {
        // Recursive call for move to left side of tree.
        postorder(root->left);

        // Recursive call for move to the right side of tree.
        postorder(root->right);

        // print the data in postorder.
        printf("%d ", root->data);
    }

    return SUCCESS;
}