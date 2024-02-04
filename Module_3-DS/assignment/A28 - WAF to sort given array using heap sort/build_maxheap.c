#include "main.h"

/* Function to create the tree to max heapify.
 * Inputs: heap - Base address of the integer array
 *         size - Length of the array
 * Output: return void.
 * Description: To make the tree to Max heapify.
 */
void build_maxheap(int *heap, int size)
{
    // Initializing the index.
    int index = size / 2 - 1;

    // Max_heap function call till index reaches 0.
    while(index >= 0)
    {
        max_heap(heap, index, size);
        index--;
    }
}