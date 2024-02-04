#include "tree.h"

/* Function to find the height of the tree.
 * Inputs: root - pointer to th root node.
 * Output: Return SUCCESS / height.
 * Description: If tree is empty return SUCCESS,
 *      else return height of the tree.
 */
int find_height(Tree_t *root)
{
    // Initializing the left & right count.
    int l_height = -1, r_height = -1;
    
    // Condition to terminate the recursive call or return Failure when tree empty.
    if( root == NULL)
    {
        return SUCCESS;
    }

    // Finding the height of left nodes in tree
    l_height = find_height( root->left);

    // Finding the height of right nodes in tree.
    r_height = find_height(root->right);    

    // Returns the height.
    if( r_height > l_height)
    {
        return r_height += 1;
    }
    else
    {
        return l_height += 1;
    }
}
