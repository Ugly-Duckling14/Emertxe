/*
Name : Munawir E
Date : 01/08/2022
Description : WAP to implement fragments using Array of Pointers.
 Pr-requisites:-
  * Functions
  * Dynamic Arrays
  * Pointers
 Objective: -
  * Functions
  * Arrays
  * Pointers
 Requirements.
  * Implement fragments using array of pointers.
  * Rows are static and columns are dynamic. Fixed no.of rows and columns will vary for each row.
      Example:
        Read no.of rows from user and allocate the memory statically for rows.
        Read no.of columns for each row and allocate the memory dynamically.
        Let us Assume, Row = 3.
        Row[0] = 4 columns, Row[1] = 3 columns and Row[2] = 5 columns.
        While allocating the memory for columns you have allocate for no.of columns + 1 dynamically.
  * After that read the values from user and calculate the average for each row seperatly and store that average in that extra memory block which you added while allocating the memory.
  * Then sort the array based on the average.
  * Print the output on the screen.
Sample I/P  :
 1) Enter no.of rows : 3
    Enter no of columns in row[0] : 4
    Enter no of columns in row[1] : 3
    Enter no of columns in row[2] : 5
    Enter 4 values for row[0] : 1 2 3 4
    Enter 3 values for row[1] : 2 5 9
    Enter 5 values for row[2] : 1 3 2 4 1
Sample O/P  :
 1) Before sorting output is:
    1.000000 2.000000 3.000000 4.000000 2.500000
    2.000000 5.000000 9.000000 5.333333
    1.000000 3.000000 2.000000 4.000000 1.000000 2.200000
    After sorting output is:
    1.000000 3.000000 2.000000 4.000000 1.000000 2.200000
    1.000000 2.000000 3.000000 4.000000 2.500000
    2.000000 5.000000 9.000000 5.333333
*/

#include<stdio.h>
#include<stdlib.h>

// Function Declaration.
int fragments(int ,int *, float *[]);

int main()
{
    // Initializing local variables.
    int size, i, j;

    // Reading inputs.
    printf("Enter no.of rows : ");
    scanf("%d", &size);

    float *arr[size];
    int col[size];
    for( i =0 ; i< size; i++)       // Dynamic allocation.
    {
        printf("Enter no of columns in row[%d] : ", i);
        scanf("%d", &col[ i ]); 
        arr[ i ]= (float*)calloc( (col[ i ] + 1), sizeof(float) );
    }
    
    for( i = 0; i < size; i++ )     // Reading array elements.
    {
        printf("Enter %d values for row[%d] : ", col[i], i);
        for( j = 0; j < col[ i ]; j++)
        {
            scanf("%f", &arr[i][j]);
        }
    }

    // Function call.
    fragments(size, col, arr);

    // Deallocating dynamic array
    for( i =0 ; i< size; i++)
    {
        free(arr[i]);
    }
    return 0 ;
}

// Function definition.
int fragments(int row,int col[], float *arr[])
{
    // Initializing local variables.
    int i, j, temp;
    float *arr_temp;

    // Finding the average.
    for( i = 0; i < row; i++)
    {
        for( j = 0; j < col[ i ]; j++)
        {
            arr[i][col[i]] = (arr[i][col[i]] + arr[i][j]);
        }
        arr[i][col[i]] /= col[i];
    }

    // Printing output before sorting.
    printf("Before sorting output is:\n");
    for( i = 0; i < row; i++ )
    {
        printf("Enter %d values for row[%d] : ", col[i], i);
        for( j = 0; j < col[ i ] + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }

    // Sorting array according to the fragments.
    for( i = 0; i < row; i++)
    {
        for( j = 0; j < row; j++)
        {
            if( arr[i][col[i]] < arr[j][col[j]])
            {
                arr_temp = arr[i];
                arr[i] = arr[j];
                arr[j] = arr_temp;
                temp = col[i];
                col[i] = col[j];
                col[j] = temp;
            }
        }
    }

    // Printing output after sorting,
    printf("After sorting output is:\n");
    for( i = 0; i < row; i++ )
    {
        printf("Enter %d values for row[%d] : ", col[i], i);
        for( j = 0; j < col[ i ] + 1; j++)
        {
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}