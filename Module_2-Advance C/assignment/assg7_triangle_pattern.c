/*
   Documentation
Name : Munawir E
Date : /05/2022
Description :
Sample I/P  :
Sample O/P  :
*/


#include<stdio.h>
void main()
{

    int i,n,j,count=1,k;

    scanf("%d",&n);

    for ( i=n;i>=1;i--)
    {
	for ( j=1;j<=i;j++)
	{ 
	    if ( n==i || i==1)
	    {
		printf("%d ", count);
	    }
	    else
	    {
		printf("%d ",count);
		for(k=1;k<=i-2;k++)
		{
		    printf("- ");
		}
		count=count+k;	
		printf("%d ",count);
		count++;
		break;
	    }
	    count++;
	}
	printf("\n");
    }
}
