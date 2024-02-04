#include <stdio.h>
#include <string.h>
#include "mp3_reader.h"
#include "type.h"

int main( int argc, char *argv[] )
{
    if( argc > 1)
    {
        if( Operation( argv ) == e_help )
        {
            Display_help();
        }
        else if( Operation( argv) == e_view )
        {
            Mp3Reader mp3reader;
            if( Read_Validation( argc, argv, &mp3reader ) == e_success)
            {
                
                if( Open_files(argc, &mp3reader ) == e_success )
                {    
                    if( verify_id3( &mp3reader) == e_failure )
                    {
                       printf("ERROR: The File is not ID3 V3\n");
                       return 0;
                    }
                    Display_mp3_info( &mp3reader );
                }
                else
                {
                    printf("ERROR: Opening files failed.\n");
                }
                
            }
            else
            {
                printf("ERROR: Validation failed.\n");
            }
        }
        else if( Operation( argv ) == e_edit )
        {
            Mp3Reader mp3reader;
            if( Read_Validation( argc, argv, &mp3reader ) == e_success)
            {
                if( Open_files( argc, &mp3reader ) == e_success )
                {
                    if( verify_id3( &mp3reader) == e_failure )
                    {
                       printf("ERROR: The File is not ID3 V3");
                    }
                    editing_mp3( &mp3reader);
                }
            }

        }
        else if( Operation( argv ) == e_version)
        {
            Mp3Reader mp3reader;
            if( Read_Validation( argc, argv, &mp3reader ) == e_success)
            {
                if( Open_files( argc, &mp3reader ) == e_success )
                {
                    version_info(&mp3reader);
                }
            }
        }
        else
        {
            printf("ERROR: No argument present\n");
        }
    }
    else
    {
        printf("ERROR: Please pass arguments.\n");
    }
    return 0;
}