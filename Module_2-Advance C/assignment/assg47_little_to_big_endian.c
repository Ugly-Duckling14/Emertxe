/*
Name : Munawir E
Date : 07/07/2022
Description : WAP to convert Little Endian data to Big Endian.
 Pr-requisites:
  * Pointers
 Objective: -
  * Big Endian and Little Endian representation
  * Pointers

Sample I/P  : 
 1) Enter the size: 2
    Enter any number in Hexadecimal: ABCD
 2) Enter the size: 4
    Enter any number in Hexadecimal: 12345678

Sample O/P  :
 1) After conversion CDAB
 2) After conversion 78563412
*/

#include<stdio.h>

int main()
{
    // Initializing the variables.
    int size;

    // Reading the input.
    printf("Enter the size: ");
    scanf("%d", &size);

    printf("Enter any number in Hexadecimal: ");
    switch ( size )             // Jump to case according size value.
    {
        // if size is 2, find the big endian for short DT.
        case 2:
        {
            // Initializing the variables.
            short int number;  
            int temp, i;
            char *ptr;

            scanf("%hX", &number);   // Reading the value for short.
            ptr = (char*) &number;

            // Converting little endian to big endian  for short variables. 
            for( i = 0 ; i < ( size / 2 ) ; i++ )
            {
                temp = ptr[ i ];
                ptr[ i ] = ptr[ size - 1 - i ];
                ptr[ size - 1 - i ] = temp;
            }

            // Printing the output.
            printf("After conversion %hX\n", number);
            break;
        }
        // if size is 4, find the big endian for int DT.
        case 4:
        {
            // Initializing the variables.
            int number, temp, i;
            char *ptr;

             scanf("%X", &number);      // Reading the value for integer.
             ptr = (char*) &number;
 
            // Converting littl endian to to big endian for integer variables.
            for( i = 0 ; i < ( size / 2 ) ; i++ )
            {
                temp = ptr[ i ];
                ptr[ i ] = ptr[ size - 1 - i ];
                ptr[ size - 1 - i ] = temp;
            }

            // Printing the output.
            printf("After conversion %X\n", number); 
            break;
        }
        default : printf("Invalid input");      // Error message other than short and integer values.
    }
    return 0;
}