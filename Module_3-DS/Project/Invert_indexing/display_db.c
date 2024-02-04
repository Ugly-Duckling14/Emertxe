#include "invert_index.h"

/* Function to display the database.
 * Inputs: Structure ptr to an array.
 * Output: Return SUCCESS.
 * Description: Display the content in the database and return SUCCESS.
 */
Status Display_db(main_node **invert_arr)
{
    // Initializing the variables.
    int i, j;
    main_node *m_temp;
    sub_node *s_temp;

    // Printing the Heading / Title.
    printf(" ");
    printf("\033[36m");
    for( j = 0; j < 76; j++) printf("=");  printf(" \033[0m");
    printf("\n\033[36m| \033[34m[Index]\033[36m|\t\033[34m[ Word ]\033[36m\t|\033[34m [ File Count ] \033[36m|\033[34m[ File Name ]\t\033[36m|\033[34m[Word count]\033[36m|\n|");
    printf("\033[36m");
    for( j = 0; j < 76; j++) printf("=");//printf("\03");
    printf("\033[36m|");

    // Printing the database content.
    for( i = 0; i < ARR_SIZE; i++)
    {
	// Checking the index is empty. if Empty skip the index
	if( invert_arr[i] != NULL)
	{
	    m_temp = invert_arr[i];

	    // Printing the index values.
	    printf("\n\033[36m|\033[32m  [%d]", i);

	    // Traversing through the main_node to print the data's. 
	    while( m_temp != NULL)
	    {
		s_temp = m_temp->s_link;

		// Printing the word & file count of the data.
		printf("\t\t\033[32m[ %-7s ]\t\t%d", m_temp->word,m_temp->file_count);

		// Traversing through the sub_node.
		for( j = 1; j <= m_temp->file_count; j++)
		{
		    // Printing the file name & word count.
		    printf("\t  \033[32m[ %s ]\t  [ %d ]\t \033[36m    |", s_temp->file_name, s_temp->word_count);

		    // Moving to next sub node.
		    s_temp = s_temp->s_link;
		    if(s_temp != NULL)
		    {
			printf("\n\033[36m|\033[0m\t\t\t\t\t");
		    }	
		} 
		printf("\n\033[36m|");
		if( j-1 == m_temp->file_count && m_temp->m_link != NULL)
		{
		    //printf("\n|");
		    for( int j = 0; j < 76; j++) printf("\033[34m-");
		    printf("\033[36m|\n|");
		}  

		// Moving to next word.
		m_temp = m_temp->m_link;
	    }

	    if( i != 26 )
	    {
		//printf("|");
		for( int j = 0; j < 76; j++) printf("\033[36m=");
		printf("|\033[0m");
	    }
	}
    }

    printf(" ");    printf("\033[36m");
    for( int j = 0; j < 74; j++) printf("=");   
    printf(" |");printf("\033[0m");
    return SUCCESS;
}
