#include "tree.h"

/* Function to find total number of nodes.
 * Inputs: root - pointer to th root node.
 * Outputs: Return SUCCESS / total no of nodes.
 */
int total_nodes(Tree_t *root)
{
    int no_nodes = -1;

    // Condition to terminate recursive call / To return tree empty.
    if(root == NULL)
    {
        return SUCCESS;
    }

    // Traversing to the left nodes 
    no_nodes = total_nodes( root->left);

    // Traversing to the right nodes
    no_nodes += total_nodes( root->right);

    // returns total number of nodes.
    return no_nodes + 1;
}
