#include "invert_index.h"

/* Function definition used to update database. 
 * Inputs: filename - character ptr for passing the filename.
 *         invert_arr - Structure ptr to an array.
 * Output: Return SUCCESS / FAILURE.
 * Description: If creation of any ptr Fails return FAILURE.
 *     Else update the database return SUCCESS.  
 */ 
Status Update_db(char *file_name, main_node **invert_arr )
{
    // Initializing the local variables. 
    FILE *f_update = fopen( file_name, "r");        // Opening the file in read mode.
    char word[200], *token, t_word[WORD_SIZE];
    int index;

    // Checking the file pointer is created or not.
    if( f_update == NULL)
    {
	printf("\033[31mERROR: File not found.\n");
	return FAILURE;
    }

    if( Is_empty( f_update) == SUCCESS)
    {
	printf("\033[32mINFO: Updating the database.......\n");

	// Reading the data line by line from file till EOF.
	while( fscanf( f_update, "%s", word) != EOF)
	{
	    // Checking the data is index.
	    if( word[0] == '#')
	    {
		// Storing the index value.
		if( word[1] != '\0')
		{
		    strcpy( word, strtok( word, "#;"));
		    index = atoi(word);
		}
		continue;
	    }

	    // Creating the main node.
	    main_node *m_new = (main_node*) malloc(sizeof(main_node));
	    if( m_new == NULL)
	    {
		return FAILURE;
	    }

	    // Assigning the values to main node.
	    strcpy( m_new->word, strtok( word, ";"));		// Updating the word to database.

	    // Updating file count value to database.
	    strcpy( t_word, strtok( NULL, ";"));
	    m_new->file_count = atoi( t_word);
	    m_new->m_link = NULL;		// Assigning the link to NULL for new main node.

	    // Creating the 1st subnode.
	    sub_node *s_temp = (sub_node*) malloc(sizeof(sub_node));
	    if(s_temp == NULL)
	    {
		return FAILURE;
	    }

	    // Linking the subnodes to main node.
	    m_new->s_link = s_temp;

	    // Updating the filename.
	    strcpy( s_temp->file_name, strtok( NULL, ";"));

	    // Updating word count to database.
	    token = strtok( NULL, ";");
	    strcpy( t_word, token);
	    s_temp->word_count = atoi( t_word);

	    // Traversing through the sub nodes.
	    while( token != NULL)
	    {
		// Creating the subnodes from 2nd  onwards    
		sub_node *s_new = (sub_node*) malloc(sizeof(sub_node));
		if(s_new == NULL)
		{
		    return FAILURE;
		}

		token = strtok( NULL, ";");
		// Checking for termination
		if(token == NULL)
		{
		    break;
		}

		// Updating the filenam to database.
		strcpy( s_new->file_name,token);

		// Updating the word count to database.
		strcpy( t_word, token = strtok( NULL, ";"));
		s_new->word_count = atoi( t_word);

		// Updating the links.
		s_temp->s_link = s_new;
		s_temp = s_new;                    
	    }
	    s_temp->s_link = NULL;		// Assigning NULL to last subnode.

	    // If database given index is empty, update main node at first.
	    if( invert_arr[index] == NULL)
	    {
		invert_arr[index] = m_new;

	    }
	    else		// Update main node at last of index.
	    {
		main_node *m_temp = invert_arr[index];

		while( m_temp->m_link != NULL )
		{
		    m_temp = m_temp->m_link;
		}

		m_temp->m_link = m_new;
	    }
	}
	return SUCCESS;
    }
    else
    {
	printf("\033[31mERROR: Updating file is empty.\n");
    }
}
