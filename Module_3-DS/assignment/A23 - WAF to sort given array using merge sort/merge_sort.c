#include "main.h"

/* Function to split the elements
 * Inputs: array - Base address of the integer array.
 *         narray - Length of the array
 * Output: split the array sort the elements in the array.
 * 
 */
int merge_sort(int *array, int narray)
{
    // Initializing the variables.
    int mid, i;

    // Condition to terminate recursive function.
    if( narray == 1)
    {
        return 0;
    }
    
    mid = narray / 2;

    // Initializing sub arrays.
    int *lsa = (int*) malloc(sizeof(int) * mid);
    int *rsa = (int*) malloc(sizeof(int) * (narray - mid));

    // Storing of left sub array elements.
    for( i = 0; i < mid; i++)
    {
        lsa[i] = array[i];
    }

    // Storing the right sub array elements.
    for( i = mid; i < narray; i++)
    {
        rsa[ i - mid] = array[i];
    }

    // Recursive call for split the array elements.
    merge_sort(lsa, mid);
    merge_sort(rsa, narray - mid);

    // Function to merge array in sorted format.
    merge( array, narray, lsa, mid, rsa, narray-mid);

    // Deallocating the sub arrays.
    free(lsa);
    free(rsa);

    return 0;

}
