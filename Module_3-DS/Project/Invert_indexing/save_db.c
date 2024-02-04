#include "invert_index.h"

/* Function to save the databas to an file.
 * Inputs: Character pointer, Structur ptr to an array.
 * Output: Return SUCCESS / FAILURE.
 * Description: If the file contents in database successfully stored in database return SUCCESS,
 *      else return FAILURE
 */
Status Save_db( char *file_name, main_node *invert_arr[] )
{
    int i;

    // Checking the given file is txt
    if( strstr( file_name, ".txt"))
    {
	FILE *fptr_save = fopen(file_name , "w");
	if( fptr_save == NULL)
	{
	    return FAILURE;
	}

	// Saving the contents to database.
	printf("\033[32mINFO: Saving the database\n"); 
	for( i = 0; i < ARR_SIZE; i++)
	{
	    if( invert_arr[i] != NULL)
	    {
		main_node *m_temp = invert_arr[i];

		// Saving the index value to the file.
		fprintf(fptr_save, "#%d;\n", i);
		while( m_temp != NULL)
		{
		    sub_node *s_temp = m_temp->s_link;

		    // Storing the word to the file & file count.
		    fprintf(fptr_save, "%s;%d;", m_temp->word,m_temp->file_count );
		    while( s_temp != NULL)
		    {
			// Saving the filename and word count to the file.
			fprintf(fptr_save, "%s;%d;", s_temp->file_name, s_temp->word_count);
			s_temp = s_temp->s_link; 
		    }
		    fprintf(fptr_save, "\n");
		    m_temp = m_temp->m_link;
		}
		fprintf(fptr_save, "#\n");
	    }
	}
	fclose(fptr_save);
	return SUCCESS;
    }
    else            // Returns error message when extension is not passed.
    {
	printf("\033[31mERROR: File extension is not matching please pass txt file.\n\033[0m");
	return FAILURE;
    }
}
