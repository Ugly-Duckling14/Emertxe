#include "mp3_reader.h"

int editing_mp3( Mp3Reader *mp3reader )
{
    int i;

    for( i = 0; i < DEC + 7; i++)  printf("-");
    printf(" Select Edit Option");
    for( i = 0; i < DEC + 7; i++)  printf("-");
    printf("\n");
    copy_header( mp3reader);
    
    if( !strcmp( mp3reader->edit_type, "TIT2"))
    {
        for( i = 0; i < DEC; i++)  printf("-");
        printf("Selected Title Changing Option");
        for( i = 0; i < DEC; i++)  printf("-");
        printf("\n\t\t Title changed to %s\n", mp3reader->data);

    }
    else if( !strcmp( mp3reader->edit_type, "TPE1"))
    {
        for( i = 0; i < DEC; i++)  printf("-");
        printf("Selected Artist Changing Option");
        for( i = 0; i < DEC; i++)  printf("-");
        printf("\n\t\t Artist changed to %s\n", mp3reader->data);

    }
    else if( !strcmp( mp3reader->edit_type, "TALB"))
    {
        for( i = 0; i < DEC; i++)  printf("-");
        printf("Selected Album Changing Option");
        for( i = 0; i < DEC; i++)  printf("-");
        printf("\n\t\t Album changed to %s\n", mp3reader->data);

    }
    else if( !strcmp( mp3reader->edit_type, "TYER"))
    {
        for( i = 0; i < DEC; i++)  printf("-");
        printf("Selected Year Changing Option");
        for( i = 0; i < DEC; i++)  printf("-");
        printf("\n\t\t Year changed to %s\n", mp3reader->data);

    }
    else if( !strcmp( mp3reader->edit_type, "TCON"))
    {
        for( i = 0; i < DEC; i++)  printf("-");
        printf("Selected Music Changing Option");
        for( i = 0; i < DEC; i++)  printf("-");
        printf("\n\t\t Music changed to %s\n", mp3reader->data);
  
    }
    else if( !strcmp( mp3reader->edit_type, "COMM"))
    {
        for( i = 0; i < DEC; i++)  printf("-");
        printf("Selected Comments Changing Option");
        for( i = 0; i < DEC; i++)  printf("-");
        printf("\n\t\t Comment changed to %s\n", mp3reader->data);
    }
    
    edit_mp3(mp3reader);
    copy_remaining( mp3reader );
    
    copy_to_original( mp3reader);
    for( i = 0; i < DEC; i++)  printf("-");
    printf("Editing is success");
    for( i = 0; i < DEC; i++)  printf("-");
    printf("\n");
   
    
    return e_success;
}

Status edit_mp3( Mp3Reader *mp3reader)
{
    int i;
    unsigned int size = 0;
    char buffer[5], temp[ 4 ];
    fread( buffer, sizeof(char), 4, mp3reader->fptr_mp3 );
    buffer[ 4 ] = '\0';
         
    if( !strcmp( buffer, mp3reader->edit_type ))
    {
        fwrite(buffer, 1, 4, mp3reader->fptr_temp_mp3);
        
        get_size( &size, mp3reader->fptr_mp3 );

        fread( buffer, sizeof(char), 3, mp3reader->fptr_mp3 );
        buffer[ 3 ] = '\0';

       fseek( mp3reader->fptr_mp3, size -1, SEEK_CUR);
        size = strlen( mp3reader->data)+1;
        
            for( i = 3; i >= 0; i--)
            {
                temp[ 3 - i ] = ( size >> ( 7 * i));

            }

        fwrite( temp, 4, 1, mp3reader->fptr_temp_mp3);
        fwrite(buffer, 1, 3, mp3reader->fptr_temp_mp3);
        fwrite( mp3reader->data, 1, size-1, mp3reader->fptr_temp_mp3);
        
        return e_success;
    }
    else
    {
        fwrite(buffer, 1, 4, mp3reader->fptr_temp_mp3);

        get_size( &size, mp3reader->fptr_mp3 );
        for( int i = 3; i >= 0; i--)
        {
            temp[ 3 - i ] = ( size >> ( 7 * i));
        }
        fwrite( temp, 1, 4, mp3reader->fptr_temp_mp3);

        fread(buffer, 1, 3, mp3reader->fptr_mp3);
        buffer[ 3] = '\0';
        fwrite( buffer, 1, 3, mp3reader->fptr_temp_mp3);
           
        char title[ size];
        fread( title, 1, size-1, mp3reader->fptr_mp3);
        fwrite( title, 1, size -1, mp3reader->fptr_temp_mp3); 
        
        edit_mp3(mp3reader);
    }

    return e_success;

}