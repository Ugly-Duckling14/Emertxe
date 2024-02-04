/*
Name : Munawir E
Date : 17/06/2022
Description : WAP to put the (b-a+1) lsb’s of num into val[b:a]
 Pr-requisites:-
  * Bitwise Operators
  * Functions
 Objective: -
  * Bitwise Operators
  * Functions
  
Sample I/P  :
 1) Enter the value of 'num' : 11
    Enter the value of 'a' : 3
    Enter the value of 'b' : 5
    Enter the value of 'val': 174 

Sample O/P :
 1) Result : 158
*/

#include <stdio.h>

// Function declaration.
int replace_nbits_from_pos(int, int, int, int);

int main()
{
    // Initializing the variables.
    int num, a, b, val, res = 0;

    // Reading the inputs.  
    printf("Enter the value of 'num': ");
    scanf("%d", &num);
    printf("Enter the value of 'a' : ");
    scanf("%d", &a);
    printf("Enter the value of 'b' : ");
    scanf("%d", &b);
    printf("Enter the value of 'val': ");
    scanf("%d", &val);

    // Function call.
    res = replace_nbits_from_pos(num, a, b, val);

    // Printing the output.
    printf("Result = %d\n", res);
    return 0;
}

// Function definition.
int replace_nbits_from_pos(int num, int a, int b, int val)
{
    // Getting b-a+1 bits from num and replace b-a+1 bits from b postion of val.  
    return  val & ~ ( ( 1 << ( b - a + 1 ) ) - 1 << ( b - a + 1 ) ) | ( ( num & (1 << ( b - a + 1 ) ) - 1 ) << ( b - a + 1) ) ;
}
