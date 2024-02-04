#include "hash.h"

/* Function to creating the hash table.
 * Inputs: arr - array for hash table,
 *         size - size of array.
 * Output: Creating the hash table. 
 */
void create_HT(hash_t *HT, int size)
{
    int i;

    // Creating an empty hash table.
    for(i = 0; i < size; i++)
    {
        HT[i].index = i;
        HT[i].value = -1;
        HT[i].link = NULL;
    }
}