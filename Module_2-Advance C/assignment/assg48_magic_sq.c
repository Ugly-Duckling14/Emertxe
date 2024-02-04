/*
Name : Munawir E
Date : 16/07/2022
Description : WAP to generate a n*n magic square
 Pr-requisites:-
  * Loops
  * Arrays
  * Pointers
  * DMA
  * Functions
 Objective: -
  * Pointers on 2d arrays.
 Steps :- 
  * Read an odd number n from user.
    -> Do error checking.
    -> Check the number is odd or not.
  * If not, continue step a.
  * Create an n X n matrix.
  * Insert 1 to (n * n) numbers into matrix.
  * Arrange the numbers in such a way that, adding the numbers in any direction, either row wise column wise or diagonal wise, should result in same answer.
  * Allocate the memory dynamically using calloc.

Sample I/P  :
 1) Enter a number: 3
 2) Enter a number: 6

Sample O/P  :
 1) 8      1      6
    3      5      7
    4      9      2
 2) Error : Please enter only positive values
*/

#include<stdio.h>
#include<stdlib.h>

// Function definition.
void magic_square(int **, int);

int main()
{
    // Initializing the variables.
    int n, i, j, **array;

    // Reading the input.
    printf("Enter a number: ");
    scanf("%d", &n );

    // Checking number is positive & odd number.
    if( n > 0 && n % 2 != 0 )
    {
    	// Initializing dynamic array.
        array = calloc( n, sizeof( int* ) );
        for( i = 0 ; i < n ; i++ )
        {
            array[ i ] = calloc( n , sizeof( int ) );
        }

	// Function call.
        magic_square( array, n);

	// Printing the the output.
        for( i =0 ; i < n ; i++ )
        {
            for( j = 0 ; j < n ; j++ )
            {
                printf("%d ", array[ i ][  j ]);
            }
            printf("\n");
        }

	// Deallocation of dynamic memory.
        for( i = 0 ; i < n ; i++ )
        {
            free( array[i]);
        }
        free(array);
    }
    else
    {
        printf("Error : Please enter only positive values\n");
    }
    return 0 ;
}

// Function definition.
void magic_square(int **array, int n)
{
    // Initializing the local variables.
    int i, j, num = 0, k = 0, l = 0, temp_k, temp_l ;

    // Finding the magic square values.
    for( i = 0 ; i < n; i++ )
    {
        for( j = 0 ; j < n ; j++ )
        {
            // Storing the 1st value.
            if(  i == 0 && j == 0 )
            {
                 num++;  
                array[ k ][ l = n / 2 ] = num;
                
            }
            else
            {
                --k;				// One row up.
                ++l;				// One col towards right.
                num++;
                if(  k  == -1 )		// Checking row is underflow,if true then giving row value to last row 
                {
                    k = n - 1;   
                }
                if( l == n )    	// Checking col is overflow, if true then set col to 0.
                {
                    l = 0;
                }
                if( array[ k ][ l ] == 0 )		// Checking array value is zero then stores the value.
                {
                    array[ k ][ l ] = num;
                    temp_k = k;
                    temp_l = l;      
                }
                else				//  If array value is not zero then increament row and store the value.
                {
                    k= temp_k;
                    l = temp_l;
                    
                    array[ ++k ][ l ] = num;
                }
            }
        }
    }
    printf("\n");
}
