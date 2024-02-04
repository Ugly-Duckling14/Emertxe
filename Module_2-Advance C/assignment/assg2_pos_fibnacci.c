/*
   Documentation
Name : Munawir E
Date : /05/2022
Description :
Sample I/P  :
Sample O/P  :
*/

#include<stdio.h>
int main() {

    int fib=1,n,num1=1,num2=1,i;
    printf("Enter the values : ");
    scanf("%d",&n);

    if (n > 0 )
    {
	if ( n == 1)
	{
	    printf("0 1 ");
	}
	else 
	{ 
	    printf("0 1 ");
	    for(i=0;i<=n;i++)
	    {
		printf("%d ",fib);
		fib=num1+num2;
		num1=num2;
		num2=fib;
		if (fib > n) break;
	    }
	    printf("\n");
	}
    }
    else 
    { 
	printf("Invalid input\n");
    }
    return 0;
}
