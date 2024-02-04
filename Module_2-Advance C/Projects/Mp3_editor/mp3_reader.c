#include <stdio.h>
#include <unistd.h>
#include "string.h"
#include "type.h"
#include "mp3_reader.h"

OperaType Operation( char *argv[] )
{
    if( argv[ 1 ] ==  NULL )
    {
        return e_unsupported;
    }

    if( !strcmp( argv[ 1 ] , "-h") )
    {
        return e_help;
    }
    else if( !strcmp( argv[ 1 ], "-V" ) )
    {
        return e_view;
    }else if( !strcmp( argv[ 1 ], "-e"))
    {
        return e_edit;
    }
    else if( !strcmp( argv[ 1 ], "-v"))
    {
        return e_version;
    }

    return e_unsupported;
} 

Status Read_Validation( int argc, char *argv[], Mp3Reader *mp3reader )
{
    if( argv[ 2 ] == NULL )
    {
        printf("ERROR: No file name is passed\n");
        return e_failure;
    }   

    if( strstr( argv[2], ".mp3") )
    {
        mp3reader->mp3_name = argv[ 2 ];
        return e_success;
    }

    if( argc > 3)
    {
        if( !strcmp( argv[ 2 ], "-t"))
        {
            mp3reader->edit_type = (char*) "TIT2";
        }
        else if( !strcmp( argv[ 2 ], "-a"))
        {
            mp3reader->edit_type = (char*) "TPE1";
        }
        else if( !strcmp( argv[ 2 ], "-A"))
        {
            mp3reader->edit_type = (char*) "TALB";
        }
        else if( !strcmp( argv[ 2 ], "-y"))
        {
            mp3reader->edit_type = (char*) "TYER";
        }
        else if( !strcmp( argv[ 2 ], "-m"))
        {
            mp3reader->edit_type = (char*) "TCON";
        }
        else if( !strcmp( argv[ 2 ], "-c"))
        {
            mp3reader->edit_type = (char*) "COMM";
        }
        else
        {
            printf("ERROR: Invalid command.\n");
            return e_failure;
        }
    
        if( argv[3] == NULL)
        {
            printf("ERROR: Please Pass the content for editing in argv 3.\n");
            return e_failure;
        }
        else
        {
           strcpy( mp3reader->data, argv[ 3 ]);
        }
        if( argv[4] == NULL )
        {
            printf("ERROR: Pleas pass file name.\n");
            return e_failure;
        }
        if( strstr( argv[4], ".mp3"))
        {
            mp3reader->mp3_name = argv[ 4 ];
        }
        return e_success;
    }
    return e_failure;
}

Status Open_files(int argc, Mp3Reader *mp3reader)
{
    mp3reader->fptr_mp3 = fopen( mp3reader->mp3_name, "r+");
    if( mp3reader->fptr_mp3 == NULL )
    {
        printf("ERROR: Opening %s file failed\n", mp3reader->mp3_name);
        return e_failure;
    }
    if( argc > 3 )
    {
        mp3reader->fptr_temp_mp3 = fopen( "temp.mp3", "w+");
        if( mp3reader->fptr_temp_mp3 == NULL)
        {
            printf("ERROR: Opening temp.mp3 file failed\n");
            return e_failure;
        }
    }
    return e_success;    
}

Status verify_id3( Mp3Reader *mp3reader)
{
    char buffer[4];
    short int version;
    rewind( mp3reader->fptr_mp3);
    fread(buffer, 1, 3, mp3reader->fptr_mp3);
    buffer[3] = '\0';
    
    if( !strcmp( buffer, "ID3"))
    {
        fread( &version, 2, 1, mp3reader->fptr_mp3);
       
        if( version == 3 )
        {
            rewind( mp3reader->fptr_mp3 );
            return e_success;
        }
    }
    return e_failure;
}



void get_size( unsigned int *size, FILE *fptr_mp3)
{
    char temp[ 4 ];
    int i;
    
    *size = 0;
    fread( temp, 4, 1, fptr_mp3);
    for( i = 0; i <= 3; i++ )
    {
       *size += (temp[ 3 - i ]  << ( 8 * i)); 
    } 
}

Status copy_header( Mp3Reader *mp3reader)
{
    char buffer[10];
    rewind( mp3reader->fptr_mp3);
    rewind( mp3reader->fptr_temp_mp3);
    fread(buffer, 1, 10, mp3reader->fptr_mp3);
    fwrite( buffer, 1, 10, mp3reader->fptr_temp_mp3);
    return e_success;
}

Status copy_remaining( Mp3Reader *mp3reader)
{
    char remain;

    while( fread( &remain, 1, 1, mp3reader->fptr_mp3))
    {
        fwrite( &remain, 1, 1, mp3reader->fptr_temp_mp3);
    }
    return e_success;
}

Status copy_to_original( Mp3Reader *mp3reader)
{
    char temp;
    rewind( mp3reader->fptr_mp3);
    rewind( mp3reader->fptr_temp_mp3);

    while( fread( &temp, 1, 1, mp3reader->fptr_temp_mp3))
    {
        fwrite( &temp, 1, 1, mp3reader->fptr_mp3);
    }

    fclose(mp3reader->fptr_mp3);
    fclose(mp3reader->fptr_temp_mp3);
    remove("temp.mp3");
    return e_success;
}

void version_info( Mp3Reader *mp3reader)
{
    char tag[4];
    short int version;
    
    rewind(mp3reader->fptr_mp3);

    fread(tag, 1, 3, mp3reader->fptr_mp3);
    tag[3] = '\0';

    fread( &version, 2, 1, mp3reader->fptr_mp3);

    printf("The tag & version of %s file is %s & %d\n", mp3reader->mp3_name, tag, version);
}