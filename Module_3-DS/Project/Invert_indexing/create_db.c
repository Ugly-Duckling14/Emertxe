#include "invert_index.h"

/* Function definition to create database.
 * Inputs: head - pointer to first node of SLL.
 *         invert_arr - Structure ptr to an array, to store database.
 * Output: Return SUCCESS / FAILURE.
 * Description: If database is succesfully created thn return SUCCESS else return FAILURE.
 */
Status Create_db(sll_node *head, main_node **invert_arr )
{
    // Initializing the local variables.
    int index;
    FILE *fptr;
    char word[WORD_SIZE], letter;

    // Checking the list is not empty.
    if( head != NULL)
    {
	// Opening the files.
	fptr = fopen( head->file_name, "r");

	// Checking the file is empty then skip it else store the words to database.
	if( Is_empty( fptr) == SUCCESS)
	{
	    // Making the file pointer to begining. 
	    rewind(fptr);

	    // Reading the input from the file till EOF.
	    while( fscanf(fptr, "%s", word) != EOF)
	    {
		letter = toupper(word[0]);

		// Checking the input is alphabetic words.
		if( isalpha(letter))
		{    
		    index = letter % 65;    // Stroing the index for alphabets.
		}
		else
		{
		    index = 26;     // For digits & special characters
		}

		// Checking given index having any values..
		if(invert_arr[index] == NULL)
		{
		    // Initializing the main node.
		    main_node *m_new = (main_node*) malloc(sizeof(main_node));
		    if( m_new == NULL)
		    {
			return FAILURE;
		    }

		    // Assigning the values to main node.
		    m_new->file_count = 1;
		    strcpy(m_new->word, word);
		    m_new->m_link = NULL;

		    invert_arr[index] = m_new;

		    // Creating the subnode.
		    sub_node *s_new = (sub_node*) malloc(sizeof(sub_node));
		    if(s_new == NULL)
		    {
			return FAILURE;
		    }

		    // Assigning the values to sub node.
		    s_new->word_count = 1;
		    strcpy(s_new->file_name, head->file_name);
		    s_new->s_link = NULL;
		    m_new->s_link =s_new;
		}
		else            // If index having values.
		{
		    main_node *m_temp = invert_arr[index], *m_cur;

		    // Traversing through the main node.
		    while(m_temp != NULL)
		    {
			// Checking word is already present of not.
			if(!strcmp( m_temp->word, word))
			{
			    sub_node *s_temp = m_temp->s_link, *s_cur;

			    // Traversing through the sub node 
			    while( s_temp != NULL)
			    {
				// Checking the word is in same file.
				if( !strcmp( s_temp->file_name,head->file_name))
				{
				    s_temp->word_count++;
				    break;
				    break;
				}
				s_cur = s_temp;
				s_temp = s_temp->s_link;
			    }

			    // If word is not in same file, then store the file name in new node.
			    if(s_temp == NULL)
			    {
				sub_node *s_new = (sub_node*) malloc(sizeof(sub_node));
				if(s_new == NULL)
				{
				    return FAILURE;
				}

				s_new->word_count = 1;
				m_temp->file_count++;
				strcpy(s_new->file_name, head->file_name);
				s_new->s_link = NULL;
				s_cur->s_link = s_new;
				break;

			    }
			    break;
			}
			m_cur = m_temp;
			m_temp = m_temp->m_link;
		    }

		    // If word is not present in database.
		    if( m_temp == NULL && strcmp( m_cur->word, word))
		    {
			main_node *m_new = (main_node*) malloc(sizeof(main_node));
			if( m_new == NULL)
			{
			    return FAILURE;
			}

			m_new->file_count = 1;
			strcpy(m_new->word, word);
			m_new->m_link = NULL;

			m_cur->m_link = m_new;

			sub_node *s_new = (sub_node*) malloc(sizeof(sub_node));
			if(s_new == NULL)
			{
			    return FAILURE;
			}

			s_new->word_count = 1;
			strcpy(s_new->file_name, head->file_name);
			s_new->s_link = NULL;
			m_new->s_link =s_new;
		    }
		}  
	    }
	    printf("\033[0;32m");
	    printf("INFO: Creation of %s database is success\n", head->file_name); 
	    printf("\033[0m");
	}
	else            // Error message if file is empty.
	{
	    printf("\033[0;33m");
	    printf("INFO: File %s is empty\n", head->file_name); printf("\033[0m");
	}
	fclose(fptr);

	// Recursive call for create db.
	Create_db( head->link, invert_arr);           
    }
    return SUCCESS;
}
