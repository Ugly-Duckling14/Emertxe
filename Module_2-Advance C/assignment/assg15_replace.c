/*
Name : Munawir E
Date : 26/05/2022
Description : WAP to replace 'n' bits of a given number.
a. Read number num from user.
b. Read number n from user.
c. Read number val from user
d. Fetch n number of bits from LSB end of val and replace in the last n bits of num.
e. Return new value of num. If num is 10 and n is 3 and val is 12
10 -> 0 0 0 0 1 0 1 0 
12 -> 0 0 0 0 1 1 0 0 
The program should print result as 12 (1 1 0 0)
Pre-requisites.
 * Bitwise operators
 * Functions

 Sample I/P  :
 1) Enter the number: 10
 Enter number of bits: 3
 Enter the value: 12
 2) Enter the number: 15
 Enter number of bits: 2
 Enter the value: 1

 Sample O/P  :
 1) Result = 12
 2) Result =  13
 */

#include<stdio.h>

int replace_nbits(int num, int n, int val);  // function declaration.

int main()
{ 
    // Initializing the variables.
    int num, n, val, res = 0;

    // Reading the input. 
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter number of bits: ");
    scanf("%d", &n);
    printf("Enter the value: ");
    scanf("%d", &val);

    // Function call.
    res = replace_nbits( num, n, val);

    // Printing the output.
    printf("Result =  %d\n", res);

    return 0 ;
}

// Function definition.
int replace_nbits(int num, int n, int val)
{ 
    // Replacing N bits
    return  num & (~ (( 1 << n ) - 1 ) ) | ( val &  ( 1 << n ) - 1 )   ;
}
