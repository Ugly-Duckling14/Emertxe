/*
Name : Munawir E
Date : 29/06/2022
Description : Squeeze the character in s1 that matches any character in the string s2.
 Pr-requisites:-
  * Functions
  * Pointers
  * Arrays
 Objective: -
  * Functions
  * Pointers
  * strings
  * Arrays
 
Sample I/P  :
 1) Enter s1 : Dennis Ritchie
 2) Enter s1 : Welcome

Sample O/P  :
 1) After squeeze s1 : Des Rtche
 2) After squeeze s1 : Wlco
*/

#include <stdio.h>

// Function declaration.
void squeeze(char*, char*);

int main()
{
    // Initializing the variables.
    char str1[ 30 ], str2[ 30 ];
    
    // Reading the input.
    printf("Enter string1 : ");
    scanf("%[^\n]", str1);

    printf("Enter string2 : ");
    scanf(" %[^\n]", str2);
    
    // Function call.
    squeeze(str1, str2);
    
    // Printing the output.
    printf("After squeeze s1 : %s\n", str1);
    
}

// Function definition.
void squeeze(char *str1, char *str2)
{
    // Initializing local variables.
    int i = 0, k = 0, j;

    // Squeezing string1 that matches with characters inside string2.
    while( str1[i] != '\0')
    {
    	for( j = 0; str2[j] != '\0' &&  str2[ j ] != str1[ i ] ; j++ );
	    if( str2[j] == '\0' )
	    { 
            str1[ k++ ] = str1[ i ];
	    }
	i++;
    }
    str1[ k ] = '\0';         // Assigning null character at the end of string1.
}
