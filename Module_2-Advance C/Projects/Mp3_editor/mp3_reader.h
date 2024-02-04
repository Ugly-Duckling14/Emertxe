#include <stdio.h>
#include "type.h"
#include "string.h"

typedef struct _Mp3Reader
{
   char  data[ 100];
   char *edit_type;

   FILE *fptr_mp3;
   FILE *fptr_temp_mp3;
   char *mp3_name;
}Mp3Reader;


OperaType Operation( char *argv[] );

void Display_help( void );

Status Read_Validation( int argc, char *argv[], Mp3Reader *mp3reader );


Status Open_files(int argc, Mp3Reader *reader );

Status verify_id3( Mp3Reader *mp3reader);

void Display_mp3_info( Mp3Reader *mp3reader );

void get_size( unsigned int *size, FILE *fptr_mp3);

int editing_mp3( Mp3Reader *mp3reader);

Status edit_mp3( Mp3Reader *mp3reader );

Status copy_header( Mp3Reader *mp3reader);



void version_info( Mp3Reader *mp3reader);

Status copy_remaining( Mp3Reader *mp3reader);

Status copy_to_original( Mp3Reader *mp3reader);

