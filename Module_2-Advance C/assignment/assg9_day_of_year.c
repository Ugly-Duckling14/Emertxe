/*
   Documentation
Name : Munawir E
Date : 17/05/2022
Description : WAP to find which day of the year.
Pre-requisites.
 * Arithmetic operator.
 * Switch case.
 Objective.
 * To understand the concept of Switch Case.

 Sample I/P  :
 1) Enter the value of 'n' : 9
 Choose First Day :
 1. Sunday
 2. Monday
 3. Tuesday
 4. Wednesday
 5. Thursday
 6. Friday
 7. Saturday
 Enter the option to set the first day : 2
 2) Enter the value of 'n' : 9
 Choose First Day :
 1. Sunday
 2. Monday
 3. Tuesday
 4. Wednesday
 5. Thursday
 6. Friday
 7. Saturday
 Enter the option to set the first day : 3
 3) Enter the value of 'n' : 9
 Choose First Day :
 1. Sunday
 2. Monday
 3. Tuesday
 4. Wednesday
 5. Thursday
 6. Friday
 7. Saturday
 Enter the option to set the first day : 8
 4) Enter the value of 'n' : 0
 5) Enter the value of 'n' : 366

 Sample O/P  :
 1) The day is Tuesday
 2) The day is Wednesday
 3) Error: Invalid input, first day should be > 0 and <= 7
 4) Error: Invalid Input, n value should be > 0 and <= 365
 5) Error: Invalid Input, n value should be > 0 and <= 365
 */

#include<stdio.h>
int main()
{   // Initializing the variables.
    int N,first_day,option;
    // Reading the values for variables.
    printf("Enter the value of 'n' : ");
    scanf("%d",&N);
    // Checking the user input is between 1 and 365, for the entered day is belongs in year. 
    if ( N >= 1 && N <= 365 )
    {   // Displaying the options to the user and reading the option.
	printf("Choose First Day :\n\n1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n\nEnter the option to set the first day : ");
	scanf("%d",&first_day);
	if ( first_day >= 1 && first_day <= 7 )	// Checking the option between 1 to 7 (week).
	{
	    option = ( ( N + first_day - 2 ) % 7 )  ;	// calculating which day of the year using user input values.
	    switch (option) 			// It will display which day of the year according to user input.
	    {
		case 0 : 
		    {	printf("The day is Sunday\n");
			break ;
		    }

		case 1 : 
		    {
			printf("The day is Monday\n");
			break ;
		    }
		case 2 : {
			     printf("The day is Tuesday\n");
			     break ;
			 }
		case 3 : 
			 {  
			     printf("The day is Wedday\n");
			     break ;
			 }
		case 4 : 
			 {
			     printf("The day is Thursday\n");
			     break ;
			 }
		case 5 : 
			 {
			     printf("The day is Friday\n");
			     break ;
			 }
		case 6 : 
			 {
			     printf("The day is Saturday\n");
			     break ;
			 }
	    }
	}
	else
	{ // Printing error message if the day value is not present in week ( 1 to 7 ).
	    printf("Error: Invalid input, first day should be > 0 and <= 7");
	}
    }
    else
    {	// Printing error message if the value is not belongs to the day of year ( 1 to 365 )
	printf("Error: Invalid Input, n value should be > 0 and <= 365\n");
    }
    return 0 ;
}

