/*
Name : Munawir E
Date : 25/07/2022
Description : WAP to print all possible combinations of given string.
 Pr-requisites:-
  * Strings
  * Pointers
  * Arrays
 Objective: -
  * Strings

Sample I/P  :
 1) Enter a string: abc
 2) Enter a string: abb

Sample O/P  :
 1) All possible combinations of given string :
    abc
    acb
    bca
    bac
    cab
    cba
 2) Error: please enter distinct characters.
*/

#include<stdio.h> 

// Function declaration.
void combination(char *,int ,int );
void swapping(char *, char *);
int my_strlen(char*);

int main()
{
    // Initializing the variables.
    char str[100];
    int n;

    // Reading the input,
    printf("Enter a string: ");
    scanf("%100[^\n]", str);    
    
    n = my_strlen(str);         // Function call to find string length.

    combination(str,0,n-1);     // Function call for finding combintions.                     
    return 0;
}

// Function definition to find combinations. 
void combination(char *str,int ind,int str_len)
{
    // Initializing local variables. 
    int i = 0, j;
    static int flag = 0;
    
    // checking is their any distinct character is present or not.
    if( flag == 0 )
    {
        while( str[ i ] != '\0' )
        {
            j = 1;
            while( str[ j ] != '\0' )
            {
                if( str[ i ] == str[ j ] && i != j )
                {
                    printf("Error: please enter distinct characters.\n");
                    return;
                }
                j++;
            }
            i++;
        }
        printf("All possible combinations of given string :\n");
        flag = 1;
    }

    // Checking the index reached to the end string. 
	if ( ind == str_len )                   
	{
		printf("%s\n", str);
	}
	else
	{
		i = ind;
        // Loop runs until i is lessthan string length.
		while ( i <= str_len )            
		{
			swapping((str + ind), (str + i));       // Function call to swap values.
			combination(str, ind + 1, str_len);     // Recursive call for swap the values.
			swapping((str + ind), (str + i));       // Function call to swap the values.
			i++;
		}
	}
}

// Function definition for swapping the values.
void swapping(char *char1, char *char2)
{
    // Initializing local variables.
	char temp;

    // Swaping the values.   
	temp = *char1;    
	*char1 = *char2;
	*char2 = temp;
}

// Function definition for finding string length.
int my_strlen(char *str)
{
    int len=0;
    while( *str++ != '\0')
    {
        len++;
    }
    return len;
}