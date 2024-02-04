/*
Name : Munawir E
Date : /07/2022
Description :
Sample I/P  :
Sample O/P  :
*/

#include<stdio.h>
#include<stdlib.h>

#define Swap( T, X, Y)  \
	{                   \
	   T temp = X;  	\
	    X = Y;	    	\
	    Y = temp;	    \
	}

int main()
{
    int choice;

    printf("1. Int\n2. char\n3. short\n4. float\n5. double\n6. string\nEnter you choice : "); 
    scanf("%d", &choice);

    if( choice == 1)
    {
    	int num1, num2;

    	printf("Enter the num1 : ");
    	scanf("%d", &num1);
    	printf("Enter the num2 : ");
    	scanf("%d", &num2);

    	Swap( int, num1, num2);

    	printf("After Swapping :\nnum1 : %d\nnum2 : %d\n", num1, num2);
    }
    else if( choice == 2)
    {
    	char char1, char2;

	printf("Enter the char1 : ");
        scanf(" %c", &char1);
        printf("Enter the char2 : ");
        scanf("\n%c", &char2);

        Swap( char, char1, char2);

        printf("After Swapping :\nchar1 : %c\nchar2 : %c\n", char1, char2);
    }
    else if( choice == 3)
    {
    	short short1, short2;
	printf("Enter the short1 : ");
        scanf("%hd", &short1);
        printf("Enter the short2 : ");
        scanf("%hd", &short2);

        Swap( short, short1, short2);

        printf("After Swapping :\nshort1 : %hd\nshort2 : %hd\n", short1, short2);
    }
    else if( choice == 4)
    {
    	float float1, float2;
	printf("Enter the float1 : ");
        scanf("%f", &float1);
        printf("Enter the float2 : ");
        scanf("%f", &float2);

        Swap( float, float1, float2);

        printf("After Swapping :\nfloat1 : %f\nfloat2 : %f\n", float1, float2);
    }
    else if( choice == 5)
    {
    	double double1, double2;
	printf("Enter the double1 : ");
        scanf("%lf", &double1);
        printf("Enter the double2 : ");
        scanf("%lf", &double2);

        Swap( double, double1, double2);

        printf("After Swapping :\ndouble1 : %lf\ndouble2 : %lf\n", double1, double2);
    }
    else if( choice == 6)
    {
    	char *str1 = malloc(sizeof(char)* 30) , *str2 = malloc(sizeof(char)* 30);
	    
        printf("Enter the str1 : ");
        scanf(" %[^\n]", str1);
      //  __fpurge();
        
        printf("Enter the str2 : ");
        scanf(" %[^\n]", str2);
      //   __fpurge();
      //  fflush(stdin);
        
        Swap( char *, str1, str2);

        printf("After Swapping :\nstr1 : %s\nstr2 : %s\n", str1, str2);
    }
    else
    {
    	printf("Invalid choice");
    }
    return 0 ;
}

