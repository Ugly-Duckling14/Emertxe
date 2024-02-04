#include "invert_index.h"

/* Function to search the word in database.
 * Inputs: Structure ptr to an array, character pointer.
 * Output: Return SUCCESS / FAILURE.
 * Description: Search the given word in database if found return SUCCESS,
 *      else return FAILURE.
 */
Status Search_db( main_node **invert_arr, char *data)
{
    char letter = data[0];
    int index, j;

    // Finding the index value if given word's starting index is alphabet,
    if( isalpha(letter))
    {
	index = toupper(letter) % 65;
    }
    else        // Assigning index value if given input is not an alphabet
    {
	index = 26;
    }

    if( invert_arr[index] == NULL )
    {
	return FAILURE;
    }
    else
    {
	main_node *m_temp = invert_arr[index];

	while( m_temp != NULL)
	{
	    // If the word found in database.
	    if( !strcmp(m_temp->word, data ))
	    {
		// Printing the Heading / Title.
		printf(" \033[36m");
		for( j = 0; j < 65; j++) printf("=");
		printf(" \n\033[36m|\033[34m   [ Word ]\033[36m    | \033[34m[ File Count ]\033[36m|\033[34m  [File Name ]  \033[36m| \033[34m[ Word Count ]\033[36m |\n|\033[36m");
		for( j = 0; j < 65; j++) printf("=");
		printf("\033[36m|\033[0m\n");

		// Printing the word & file count
		printf("\033[36m| [ %-8s ]  \033[36m|   [ %d ]  \t", m_temp->word, m_temp->file_count);

		sub_node *s_temp = m_temp->s_link;

		while( s_temp != NULL)
		{
		    // Printing the word.
		    printf("\033[36m|  [ %s ] \033[36m|    [ %d ]\t\033[36m  |\n", s_temp->file_name, s_temp->word_count);

		    s_temp = s_temp->s_link;
		    if(s_temp != NULL)
		    {
			printf("\033[36m|\t\t|\t\t");
		    }
		}
		printf("\033[36m|");
		for( j = 0; j < 65; j++) printf("=");
		printf("|\033[36m");
		if(s_temp == NULL)
		{
		    return SUCCESS;
		}
	    }
	    m_temp = m_temp->m_link;
	}

	// If data not found in database
	return FAILURE;;
    }    
}
