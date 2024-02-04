/*
Name : Munawir E
Date : 07/07/2022
Description : Variance calculation with dynamic arrays.
 Pr-requisites:-
  * Functions
  * Pointers
  * DMA
 Objective: -
  * Functions
  * Pointers
  * DMA
  Example: to find variance.
 _________________________________________________________________________
|    x(input)          |      D = X - Mean           |             D^2    |
|______________________|_____________________________|____________________|   
|       9              |           -11               |             121    |
|       12             |           -8                |             64     |
|       15             |           -5                |             25     |
|       18             |           -2                |             4      |
|       20             |            0                |             0      |
|       22             |            2                |             4      |
|       23             |            3                |             9      |
|       24             |            4                |             16     |
|       26             |            6                |             36     |
|       31             |            11               |             121    |
|______________________|_____________________________|____________________|
| Sum = 200            |                             |       Sum = 400    |
|______________________|_____________________________|____________________|
Mean = (sum of x) / size
where : size = Number of items in the input
Formula to calculate the variance:
sigma = (sum of D2 ) / size

Sample I/P  :
 1) Enter the no.of elements : 10

Enter the 10 elements:
[0] -> 9
[1] -> 12
[2] -> 15
[3] -> 18
[4] -> 20
[5] -> 22
[6] -> 23
[7] -> 24
[8] -> 26
[9] -> 31

Sample O/P  :
 1) Variance is 40.000000
*/

#include<stdio.h>
#include<stdlib.h>

// Function declaration.
float variance(int *, int);

int main()
{
    // Initializing the variables.
    int size, i;
    float result;

    // Reading the input
    printf("Enter the no.of elements : ");
    scanf("%d", &size);

    // Initializing the dynamic array and reading the array elements.
    int *array = malloc( size * sizeof( int ) );

    printf("Enter the %d elements:\n",size);
    for( i = 0 ; i < size; i++ )
    {
        printf("[%d] -> ", i);
        scanf("%d", &array[i]);
    }

    // Function call for finding the variance.
    result = variance( array, size);
    
    // Printing the output.
    printf("Variance is %f\n", result );        
    return 0;
}

// Function definition.
float variance(int *array, int size)
{
    // Initializing the local variables.
    int x = 0, i;
    float mean, dev = 0;

    // Finding the sum of X
    for( i = 0; i < size ; i++ )
    {
        x += array[ i ];
    }

    mean = x / size;                // Finding the mean.

    // Finding the sum of D^2
    for( i = 0; i < size; i++ )
    {
        dev += (array[ i] - mean) * (array[ i] - mean); 
    }

    // Returning the variance.
    return dev / size ;
}