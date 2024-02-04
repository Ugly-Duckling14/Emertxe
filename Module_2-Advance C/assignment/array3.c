#include <stdio.h>

int sec_largest(int *ptr, int size);

int main()
{
	int i,size, ret;

	//Read size from the user
	printf("Enter the size of the array : ");
	scanf("%d", &size);

	int arr[size];                                         // declare array

	printf("Enter the elements into the array: ");
	
	for(i=0; i<size; i++)                             //loop to get the array elements
	{
		scanf("%d",&arr[i]);                         //read array elements
	}
	//funtion call
	ret = sec_largest(arr, size);

	printf("Second largest element of the array is %d\n", ret);
}

int sec_largest(int *ptr, int size)                                    //function definition

{	
   int first_largest, second_largest, i;                    // variable declaration

	first_largest = ptr[0];                                              //assigned 0 index array element as first largest number
	second_largest = ptr[1],t_lar=ptr[1];                               //assigned second array element to array index 1 element
   
	for (i=1 ; i<size; i++)                                           // for loop. This loop will rum on the basic of i value
	{
		if(ptr[i] > first_largest)                                      //check array element according to the in value with first largest array element value
		{
t_lar= second_largest;
			second_largest = first_largest;                               //update the second largest element
			first_largest = ptr[i];                                      //update the first largest value when if condition is true

		}
		else if((ptr[i] > second_largest) && (ptr[i] < first_largest))        //check for second largest element
		{
t_lar=second_largest;
			second_largest = ptr[i];                                        //update the second largest element
		}
else if(ptr[i]>t_lar && ptr[i] <second_largest && ptr[i] < first_largest )
{
t_lar =ptr[i];
}
	}

	return second_largest;                                   //return second largest element to main funcion call
}