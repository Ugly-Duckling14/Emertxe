#include "mp3_reader.h"

void Display_mp3_info( Mp3Reader *mp3reader )
{
    char buffer[ 5 ];
    unsigned int size;
    int i;
    rewind(mp3reader->fptr_mp3);
    fseek( mp3reader->fptr_mp3, 10, SEEK_CUR);
    
    //Display output

    for( i = 0; i < DEC; i++ ) printf("-");

    printf("\n\tMP3 Tag Reader and Editor for ID3v2\n");
    for( i = 0; i < DEC; i++ ) printf("-");
    printf("\n");
    for( i = 0; i< 6; i++)
    {
       fread( buffer, sizeof(char), 4, mp3reader->fptr_mp3 );
       buffer[ 4 ] = '\0';
       size = 0;
       get_size( &size, mp3reader->fptr_mp3);
       fseek( mp3reader->fptr_mp3, 3, SEEK_CUR);
           
       fread( mp3reader->data, 1, size - 1, mp3reader->fptr_mp3);
       mp3reader->data[ size-1] = '\0';

       if( !strcmp(buffer, "TIT2"))
       {
           printf("\n Title\t  :\t");
       }
       else if( !strcmp( buffer, "TPE1"))
       {
           printf(" Artist\t  :\t");
       }
       else if( !strcmp( buffer, "TALB"))
       {
           printf(" Album\t  :\t");
       }
       else if( !strcmp( buffer, "TYER"))
       {
           printf(" Year\t  :\t");
       }
       else if( !strcmp( buffer, "TCON"))
       {
           printf(" Music\t  :\t");   
        }
       else if( !strcmp( buffer, "COMM"))
       {
           printf(" Comment  :\t");
       }
       printf("%s\n",mp3reader->data);
    }
     
       for( i = 0; i < DEC; i++ ) printf("-");
       printf("\n");  
       fclose(mp3reader->fptr_mp3);

}