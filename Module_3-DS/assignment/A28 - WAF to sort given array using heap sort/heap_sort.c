#include "main.h"

/* Function to sort the array using heap sort
 * Inputs: heap - Base address of the integer array
 *         size - Length of the array
 * Output: return 0
 * Description: First create max heapify tree then sort the array using heap sort.
  */
int heap_sort(int *heap, int size )
{
    // Initializing the index.
    int index = size - 1;

    // Function call to built max heapify.
    build_maxheap( heap, size);

    // Loop run until index becomes 0.
    while( index >= 0)
    {
        // Function call to swap first & last element in array.
        swap( &heap[0], &heap[index]);
        
        // Function call for sort the elements in max heapify.
        max_heap( heap, 0, index);
        index--;
    }
    return 0;
}   


