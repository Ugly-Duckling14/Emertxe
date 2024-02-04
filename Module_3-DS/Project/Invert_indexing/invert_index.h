#ifndef INVERTED
#define INVERTED

/* Header files included for the program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Declaration of macro's. */
#define FILE_SIZE 50
#define WORD_SIZE 20
#define ARR_SIZE 27

/* Defining the enum for check the status of functions. */
typedef enum status
{
    FAILURE,
    SUCCESS
     
}Status;

/* Structure definition for sub_nodes. */
typedef struct Sub_node
{
    int word_count;
    char file_name[FILE_SIZE];
    struct Sub_node *s_link;
}sub_node;

/* Structure definition for main_nodes. */
typedef struct Main_node
{
    int file_count;
    char word[WORD_SIZE];
    sub_node *s_link;
    struct Main_node *m_link;
}main_node;

/* Structure definition for SLL for store file name. */
typedef struct Sll_node
{
    char file_name[FILE_SIZE];
    struct Sll_node *link;
}sll_node;

/* Function declaration for Validating the command line arguments. */
Status Validate( int argc, char *argv[], sll_node **head, int iter );

/* Function declaration for checking the file is empty. */
Status Is_empty( FILE *fptr_name);

/* Function declaration for Creating the database. */
Status Create_db(sll_node *head, main_node **invert_arr );

/* Function declaration for Display database. */
Status Display_db(main_node **invert_arr);

/* Function declaration for Search database. */
Status Search_db( main_node **invert_arr, char *data);

/* Function declaration for Save database. */
Status Save_db( char *file_name, main_node *invert_arr[] );

/* Function declaration for Update the database. */
Status Update_db(char *file_name, main_node **invert_arr );

#endif