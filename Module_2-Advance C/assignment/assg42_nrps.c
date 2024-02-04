/*
Name : Munawir E
Date : 25/07/2022
Description : Generate consecutive NRPS of length n using k distinct character
 Pr-requisites:-
  * Strings
  * Pointers
  * Arrays
 Objective: -
  * To understand the concept of string manipulation.
Sample I/P  :
 1) Enter the number characters C : 3
    Enter the Length of the string N : 6
    Enter 3 distinct characters : a b c
 2) Enter the number characters C : 3
    Enter the Length of the string N : 7
    Enter 3 distinct characters : a b a

Sample O/P  :
 1) Possible NRPS is abcbca
 2) Error : Enter distinct characters
*/

#include <stdio.h>
#include <stdlib.h>

// Function declaration.
void nrps(char *, int, int);

int main()
{
    // Initializing the variables.
    int c_len, s_len;
    
    // Reading the inputs.
    printf("Enter the number characters C : ");
    scanf("%d", &c_len);

    if( c_len > 1 )      // Checking character length is positive. 
    {
        printf("Enter the Length of the string N : ");
        scanf("%d", &s_len);

        if( s_len > 0)      // Checking string length is positive
        {
            int i;
            char str[ c_len];
            printf("Enter 3 distinct characters : ");
            for( i = 0; i < c_len; i++ )
            {
                scanf(" %c", &str[ i]);
            }

            // Function call for finding nrps.
            nrps( str, c_len, s_len);
        }
        else
        {
            printf("Enter a positive number.\n");
        }
    }
    else
    {
        printf("Enter a positive number greater than 1.\n");
    }
}

void nrps(char *str, int c_len, int s_len)
{
    // Initializing the local variables.
    int i = 0, j;
    char *str1 = (char*)calloc( s_len+1, 1);

    // Checking characters are distinct or not.
    while( str[ i ] != '\0')
    {
        j = 0;
        while( str[ j ] != '\0' )
        {
            if( str[ i ] == str[ j ] && i != j)
            {
                printf("Error : Enter distinct characters");
                return;
            }
            j++;
        }
        i++;
    }
    
    // Finding the nrps combinations.
    j = 0; 
    for( i = 0; i < s_len; i++)
    {
        if( c_len > 2 )
        {
            if( i % c_len == 0 && i != 0)
            {
                j++;
            }
        }
        str1[ i ] = *(str+((i+j)%c_len));
    }
    str1[s_len] = '\0';
    
    // Printing the output.
    printf("Possible NRPS is  %s\n", str1);
}