/*
Name : Munawir E
Date : /07/2022
Description : Read n & n person names of maxlen 32. Sort and print the names.
 Pr-requisites:-
  * Functions
  * Dynamic Arrays
  * Pointers
 Objective: -
  * Functions
  * Dynamic Arrays
  * Pointers
 Requirements:-
  * Read the N name from the user
  * Sort it in alphabetical order
  * Use 1st dynamic and 2nd static. Char (*name)[32]
  * No.of names should be dynamic and no.of characters should be static.
  * Allocate the memory dynamically for no.of names.
Sample I/P  :
 1) Enter the size: 5
    Enter the 5 names of length max 32 characters in each
    [0] -> Delhi
    [1] -> Agra
    [2] -> Kolkata
    [3] -> Bengaluru
    [4] -> Chennai
Sample O/P  :
 1) The sorted names are:
    Agra
    Bengaluru
    Chennai
    Delhi
    Kolkata
*/

#include <stdio.h>
#include <stdlib.h>

void sort_names(char (*)[20], int);

int main()
{
    int num, i, j;

    printf("Enter the size: ");
    scanf("%d", &num);

    char (*array)[20];
    array  = malloc( num * sizeof(char[20]));

    for( i = 0; i < num; i++)
    {
        printf("[%d] -> ", i);
        scanf(" %[^\n]s", array[i]);
    }

    sort_names( array, num);
for( i = 0; i < num; i++)
    {
        printf("%s \n", array[i]);
    }




}

void sort_names(char (*arr)[20], int row)
{
    int i, j;
    char *ptr;

    for( i = 0; i < row; i++)
    {
        for( j = 0; j < arr[i][j] != '\0'; j++)
        {
            if( arr[i][j] < arr[i+1][j])
            {
                ptr = arr[i];
                arr = arr[i+1];
                arr[i+1] = ptr;
            }
        }
    }


}
