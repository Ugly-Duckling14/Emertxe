/*
Name : Munawir E
Date : 13/07/2022
Description :WAP to Implement the student record using array of structures
 Pr-requisites:-
  * Structures.
 Objective:
  * Structures
  * Pointers
 
Sample I/P  :
 1) Enter no.of students : 2
    Enter no.of subjects : 2
    Enter the name of subject 1 : Maths
    Enter the name of subject 2 : Science
    ----------Enter the student datails-------------
    Enter the student Roll no. : 1
    Enter the student 1 name : Nandhu
    Enter Maths mark : 99
    Enter Science mark : 91
    ----------Enter the student datails-------------
    Enter the student Roll no. : 2
    Enter the student 2 name : Bindhu
    Enter Maths mark : 88
    Enter Science mark : 78

Sample O/P  :
 1) ----Display Menu----
    1. All student details
    2. Particular student details
    Enter your choice : 2

    ----Menu for Particular student----
    1. Name.
    2. Roll no.
    Enter you choice : 1
    Enter the name of the student : Nandhu
    Roll No.   Name           Maths         Science       Average       Grade
    1              Nandhu        99               91                95                  A
    Do you want to continue to display(Y/y) : n
*/

#include<stdio.h>
#include<stdlib.h>

// Structure declaration.
struct student_data
{
    char name[ 30 ];
    int roll_no, mark[30];
    float avg;
};

// Function declaration.
void student_entry( struct student_data *stu_detail, int stu_no, int sub_no, char **subject );
int display_menu(int sub_no, int stu_no, struct student_data *stu_detail, char **subject );
int my_strcmp( int, struct student_data *, char *);
int my_strlen(const char *str);

int main()
{
    // Initializing the variables.
    int stu_no, sub_no, i;
    char option;

    do{
	// Reading the input.
	printf("Enter no.of students : ");
	scanf("%d", &stu_no);
	printf("Enter no.of subjects : ");
	scanf("%d", &sub_no);

	char **subject = malloc( sub_no * sizeof(char));
	for(i = 0; i < sub_no; i++ )
	{
	    subject[ i ] = calloc( 15, 1 );

	    printf("Enter the name of subject %d : ", i +1 );
	    scanf(" %[^\n]", subject[ i ] );
	}

	struct student_data data[ stu_no ];			// Structure initialization.

	// Function call Input student details.
	student_entry( data, stu_no, sub_no, subject );

	// Function call for display students contents.
	display_menu( sub_no, stu_no, data, subject );

	// Deallocating dynamic memory.
	for( i = 0 ; i< sub_no; i++ )
	{
	    free( subject[ i ]);
	}
	free( subject );

	// Restart the code from beginning
	printf("Do you want to continue to display(Y/y) : ");
	scanf(" %c", &option );
    } while( option == 'Y' || option == 'y' );
    return 0;
}

// Function definition for reading the student details.
void student_entry( struct student_data *stu_detail, int stu_no, int sub_no, char **subject )
{
    // Initializing the local variables
    int i, j, total;

    // Reading students details from user.
    for( i = 0; i < stu_no; i++ )
    {
	total = 0;
	printf("Enter the student Roll no. : ");
	scanf("%d", &stu_detail[ i ].roll_no );
	printf("Enter the student %d name : ", stu_detail[ i ].roll_no);
	scanf("%s", stu_detail[ i ].name);

	for( j = 0; j < sub_no; j++ )
	{
	    printf("Enter %s mark : ", subject[ j ] );
	    scanf("%d", &stu_detail[ i ].mark[ j ] );
	    total = total + stu_detail[ i ].mark[ j ];
	}
	stu_detail[ i ].avg = (float) total / sub_no;
    }
}

// Function definition to display student details
int display_menu(int sub_no, int stu_no, struct student_data *stu_detail, char **subject )
{
    // Initializing the local variables.
    int choice1, i, j, choice2, roll;
    char option, name_opt[20] ;

    do			
    {
	// Displays the menu.
	printf("\n\n----Display Menu----\n1. All student details\n2. Particular student details\nEnter your choice : ");
	scanf("%d", &choice1 );
	if( choice1 == 1 )
	{
	    printf("Roll No.\tName\t");
	    for( j = 0 ; j < sub_no; j++)
	    {
		printf("%s\t", subject[ j ]);
	    }
	    printf("Average\tGrade\n");

	    for( i = 0; i < stu_no; i++ )
	    {
		printf("%4d\t%0.10s\t", stu_detail[ i ].roll_no, stu_detail[ i ].name );
		for( j = 0 ; j < sub_no; j++ )
		{
		    printf("%3d\t", stu_detail[ i ].mark[j ]);
		}
		printf("%0.3f\t", stu_detail[ i ].avg );

		if( stu_detail[ i ].avg > 90 && stu_detail[ i ].avg <= 100 )
		{
		    printf("A");
		}
		else if( stu_detail[ i ].avg > 80 &&  stu_detail[ i ].avg <= 90 )
		{
		    printf("B");
		}
		else if( stu_detail[ i ].avg > 70 &&  stu_detail[ i ].avg <= 80 )
		{
		    printf("C");
		}
		else if( stu_detail[ i ].avg > 60 &&  stu_detail[ i ].avg <= 70 )
		{
		    printf("D");
		}
		else
		{
		    printf("Fail");
		}
		printf("\n");
	    }  
	} 
	else if( choice1 == 2 )      // To display details of particular student when name is passed.
	{
	    printf("----Menu for Particular student----\n1. Name.\n2. Roll no.\nEnter you choice : ");
	    scanf("%d", &choice2 );

	    if( choice2 == 1 )
	    {
		printf("Enter the name of the student : ");
		scanf("%s", name_opt );
		// name compare
		i = my_strcmp( stu_no, stu_detail, name_opt);
		if( i > -1 )
		{
		    printf("Roll No.\tName\t");
		    for( j = 0 ; j < sub_no; j++)
		    {
			printf("%s\t", subject[ j ]);
		    }
		    printf("Average\tGrade\n");
		    printf("%4d\t%0.10s\t", stu_detail[ i ].roll_no, stu_detail[ i ].name );
		    for( j = 0 ; j < sub_no; j++ )
		    {
			printf("%3d\t", stu_detail[ i ].mark[j ]);
		    }
		    printf("%0.3f\t", stu_detail[ i ].avg );

		    if( stu_detail[ i ].avg > 90 && stu_detail[ i ].avg <= 100 )
		    {
			printf("A");
		    }
		    else if( stu_detail[ i ].avg > 80 &&  stu_detail[ i ].avg <= 90 )
		    {
			printf("B");
		    }
		    else if( stu_detail[ i ].avg > 70 &&  stu_detail[ i ].avg <= 80 )
		    {
			printf("C");
		    }
		    else if( stu_detail[ i ].avg > 60 &&  stu_detail[ i ].avg <= 70 )
		    {
			printf("D");
		    }
		    else
		    {
			printf("Fail");
		    }
		    printf("\n");
		}  
		else
		{
		    printf("Studnt details not found \n");
		}
	    }
	    else if( choice2 == 2)		// Display details of particular student when rollno is passed
	    {
		printf("Enter the Roll No of the student : ");
		scanf("%d", &roll );

		printf("Roll No.\tName\t");
		for( j = 0 ; j < sub_no; j++)
		{
		    printf("%s\t", subject[ j ]);
		}
		printf("Average\tGrade\n");

		for( i = 0; i < stu_no; i++ )
		{
		    if( roll == stu_detail[ i ].roll_no )
		    {
			printf("%4d\t%0.18s\t", stu_detail[ i ].roll_no, stu_detail[ i ].name );
			for( j = 0 ; j < sub_no; j++ )
			{
			    printf("%3d\t", stu_detail[ i ].mark[j ]);
			}
			printf("%0.3f\t", stu_detail[ i ].avg );

			if( stu_detail[ i ].avg > 90 && stu_detail[ i ].avg <= 100 )
			{
			    printf("A");
			}
			else if( stu_detail[ i ].avg > 80 &&  stu_detail[ i ].avg <= 90 )
			{
			    printf("B");
			}
			else if( stu_detail[ i ].avg > 70 &&  stu_detail[ i ].avg <= 80 )
			{
			    printf("C");
			}
			else if( stu_detail[ i ].avg > 60 &&  stu_detail[ i ].avg <= 70 )
			{
			    printf("D");
			}
			else
			{
			    printf("Fail");
			}
			printf("\n");
			break;
		    }
		}
	    }
	}
	else
	{
	    printf("You Entered a wrong choice!\n");
	}
	// To restart from display menu.
	printf("Do you want to continue to display(Y/y) : ");
	scanf(" %c", &option );
    } while( option == 'Y' || option == 'y' );
    return 0;
}

// Function definition for comparing the strings
int my_strcmp(int stu_no,  struct student_data *stu_detail, char *name_opt )
{
    int i, j,  count, strlen;

    for( i = 0 ; i < stu_no; i++ )
    {
	strlen = my_strlen( stu_detail[i].name );
	count = 0;
	for( j = 0; stu_detail[ i ].name[ j ] == name_opt[ j ] && stu_detail[ i ].name[ j ] != '\0' ; j++ )
	{
	    count++;
	}
	if( count == strlen && name_opt[ j ] == '\0' )
	{
	    return i;
	}
    }
    return -1;
}

// Function definition for finding string length.
int my_strlen(const char *str)
{
    int strlen = 0;
    while( *str++ != '\0' )
    {
	strlen++;
    }
    return strlen;
}
