/*
Name : Munawir E
Date : 07/07/2022
Description : WAP to find the product of given matrix.
 Pr-requisites:
  * 2D – Arrays / Pointers.
  * DMA.
 Objective:
  * 2D – Arrays / Pointers.
  * DMA.
 Matrix multiplication in mathematically.
                __       __ 
               |           |
               |  1  2  3  |   
  Matrix A =   |  1  2  3  |
               |  1  2  3  |
               |__       __|
                __       __ 
               |           |
               |  1  1  1  |   
  Matrix b =   |  2  2  2  |
               |  3  3  3  |
               |__       __|

  Final Result :     A          *         B         =           R
                __       __          __       __         __          __ 
               |           |        |           |       |              |
               |  1  2  3  |        |  1  1  1  |       |  14  14  14  |
  Result R =   |  1  2  3  |    x   |  2  2  2  |   =   |  14  14  14  |
               |  1  2  3  |        |  1  2  3  |       |  14  14  14  |
               |__       __|        |__       __|       |__          __|
Sample I/P  : 
 1) Enter number of rows : 3
    Enter number of columns : 3
    Enter values for 3 x 3 matrix :
    1      2      3
    1      2      3
    1      2      3
    Enter number of rows : 3
    Enter number of columns : 3
    Enter values for 3 x 3 matrix :
    1      1     1
    2      2     2
    3      3     3
 2) Enter number of rows : 3
    Enter number of columns : 3
    Enter values for 3 x 3 matrix :
    1      2      3
    1      2      3
    1      2      3
    Enter number of rows : 2
    Enter number of columns : 3

Sample O/P  :
 1) Product of two matrix :
    14      14      14
    14      14      14
    14      14      14
 2) Matrix multiplication is not possible
*/

#include <stdio.h>
#include <stdlib.h>

// Function declaration.
int matrix_mul(int **, int, int, int **, int, int, int **);
void scan_matrix( int **, int, int );

int main()
{
    // Initializing the variables.
    int m, n, p, q, i, j;
    int **mat_a, **mat_b, **result;

    // Reading inputs.
    // Matrix A.
    printf("Enter number of rows : ");
    scanf("%d", &m);
    printf("Enter number of columns : ");
    scanf("%d", &n);

    mat_a = malloc( m * sizeof( int ) );            // Row initialization for matrix A.
    for( i = 0 ; i < m ; i++ )
    {
	mat_a[ i ] = malloc( n * sizeof( int ) );   // Column initialization for matrix A.
    }

    scan_matrix( mat_a, m, n );                     // Function call reading input matrix a.

    // Matrix B
    printf("Enter number of rows : ");              
    scanf("%d", &p);
    printf("Enter number of columns : ");
    scanf("%d", &q);

    // Reading input.
    if( n == p )
    {
	mat_b = malloc( p * sizeof( int ) );            // Row initialization for matrix B.
	for( i = 0 ; i < p ; i++ )
	{
	    mat_b[ i ] = malloc( q * sizeof( int ) );   // Column initialization for matrix B.

	}

	scan_matrix( mat_b, p, q) ;                       // Function call reading input matrix B.

	// Memory allocation for result matrix.
	result = malloc( m * sizeof( int ) );		// Row initialization for result matrix
	for( i = 0 ; i < m ; i++ )
	{
	    result[ i ] = calloc( q,  sizeof( int ) );  // Column initialization for result matrix.
	}

	// function call for matrix multiplication.
	matrix_mul( mat_a, m, n, mat_b, p, q, result );

	// Printing the output.
	for( i = 0 ; i < m ; i++ )
	{
	    for( j = 0 ; j < q ; j++ )
	    {
		printf(" %d ", result[ i ][ j ]);
	    }
	    printf("\n");
	}

	// Deallocation of dynamic memory.
	for( i = 0 ; i < m ; i++ )
	{
	    free( mat_a[ i ] );
	}
	free( mat_a );

	for( i = 0 ; i < p ; i++ )
	{
	    free( mat_b[ i ] );
	}
	free( mat_b );
	
	for( i = 0 ; i < m ; i++ )
	{
	    free( result[ i ] );
	}
	free( result );
    }  
    else      // Display error message if column of mat A not equal to row of mat B.
    {
	printf("Matrix multiplication is not possible");  
    }
}

// Function definition for matrix multiplication.
int matrix_mul(int **mat_a, int m, int n, int **mat_b, int p, int q, int **result)
{
    // Initializing local variables.
    int i, j, k;

    //  Matrix multiplication.
    for( i = 0 ; i < m ; i++ )
    {
	for( j = 0 ; j < q ; j++ )
	{
	    for( k = 0 ; k < n ; k++ )
	    {       

		result[ i ][ j ] += mat_a[ i ][ k ] * mat_b[ k ][ j ];

	    }
	}
    }
}

// Function definition for Reading the matrix values.
void scan_matrix( int **array, int row, int col)
{
    // Initializing local variables.
    int i, j;

    // Reading the input.
    printf("Enter values for %d x %d matrix :\n", row, col );
    for( i = 0 ; i < row ; i++ )
    {
	for( j = 0 ; j < col ; j++ )
	{
	    scanf("%d", &array[ i ][ j ] );
	}
    }
}

