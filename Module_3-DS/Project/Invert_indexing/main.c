/*
Name : Munawir E
Date : 05/09/2022
Description : Project for Invert indexing
*/


#include "invert_index.h"

int main(int argc, char *argv[])
{
    // Checking command line argument is greater than 1.
    if(argc > 1)
    {
	// Initializing the variables.
	char option;
	char choice = 'Y';
	main_node *invert_arr[ARR_SIZE]= {NULL};        // Initializing the memory for database.

	// Creatinng SLL.
	sll_node *head = NULL;

	// Validating the files having duplicate files.
	printf("\033[0;32m");
	printf("INFO: Validating The Files\n");
	//  printf("\033[0m");
	if( Validate( argc, argv, &head, 1) == SUCCESS)
	{
	    printf("\033[0;32m");
	    printf("INFO: Validation completed successfully.\n");
	    printf("\033[0m");
	    do
	    {
		// Displaying the menu.
		printf("\n\033[0;36mSelect your choice among the following options :\n\n1. Create DATABASE\n2. Display DATABASE\n3. Search\n4. Save DATABASE\n5. Update DATABASE\n\nEnter your choice\n");
		scanf(" %c", &option);
		printf("\033[0m");
		switch( option)
		{
		    case '1' :
		    {
			    // Function call for create database.
			    printf("\033[0;32m");
			    printf("\nINFO: Creation Of Database Processing....\n");
			    printf("\033[0m");
			    if(Create_db( head, invert_arr ) == FAILURE)
			    {
				printf("\033[0;31m");
				printf("ERROR: Creation of Database Failed\n\n");
				printf("\033[0m");
			    }
			    else
			    {
				printf("\033[0;32m");
				printf("INFO: DONE\n\n");
				printf("\033[0m");
			    }
			    break;
		    }
		    case '2':
		    {
			    // Function call for displaying the contents in database.
			    printf("\033[0;32m");
			    printf("INFO: Displaying The Database....\n\n");
			    printf("\033[0m");
			    if( Display_db( invert_arr) == FAILURE)
			    {
				printf("\033[0;31m");
				printf("ERROR: DISPLAY FAILED\n\n");
				printf("\033[0m");
			    }
			    else
			    {
				printf("\033[0;32m");
				printf("\n\nINFO: DONE\n");
				printf("\033[0m");
			    }
			    break;
		    }
		    case '3':
		    {
			    char data[WORD_SIZE];

			    printf("\n\033[0;33mEnter the data to be Searched : ");                            scanf("%s", data);
			    printf("\033[0m");
			    // Function call for searching the words in database.
			    if( Search_db( invert_arr, data) == FAILURE)
			    {
				printf("\n\033[0;31mERROR: Data not present\033[0m\n");
			    }
			    else
			    {
				printf("\033[0;32m");
				printf("\n\nINFO: DONE\n");
				printf("\033[0m");
			    }
			    break;
	 	    }
		    case '4':
		    {
			    char fname_backup[FILE_SIZE];
			    printf("\033[0;33mEnter the backup file name : ");
			    scanf("%s", fname_backup);
			    printf("\033[0m");

			    // Function call for saving the database.
			    if( Save_db( fname_backup, invert_arr ) == SUCCESS)
			    {
				printf("\033[0;32m");
				printf("INFO: DONE\n");
				printf("\033[0m");
			    }
			    else
			    {
				printf("\033[0;31m");
				printf("ERROR: Save the database is failed\n");
				printf("\033[0m");
			    }
			    return SUCCESS;
		    }
		    case '5':
		    {
			    char f_update[FILE_SIZE];

			    printf("\033[0;33mEnter the Filename to update database : ");
			    scanf("%s", f_update);
			    printf("\033[0m");

			    // Function call to update database.
			    if( Update_db( f_update, invert_arr) == SUCCESS)
			    {
				printf("\033[0;32m");
				printf("INFO: DONE\n");
				printf("\033[0m");
			    }
			    else
			    {
				printf("\033[0;31m");
				printf("ERROR: Updating database is failed\n");
				printf("\033[0m");

			    }
			    break;
		    }
		    default:
		    {
			    printf("\033[0;31m");
			    printf("ERROR: please pass an valid opton\n");
			    printf("\033[0m");
		    }
		}

		// Display option for continue.
		printf("\033[0;33mDo you want to continue(Y / N).\n");
		scanf(" %c", &choice);
	    }while( toupper(choice) == 'Y');
	}
	else        // If validation is Failed.
	{
	    printf("\033[0;31m");
	    printf("ERROR: Vaildation Failed\033[0m\n");

	}
    }
    else        // If theirs no files passed / command line arguments.
    {
	printf("\033[0;31mERROR: Please Pass The Command Line Argument\n./a.out <file> <file2> ....... <filen>\n");
	printf("\033[0m");
    }
}
