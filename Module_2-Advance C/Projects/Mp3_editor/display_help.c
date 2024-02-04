#include "mp3_reader.h"

void Display_help( void )
{
    int i;

    for( i = 0; i < DEC; i++) printf("-");
    printf("\n\t  USAGE: mp3tag -[tTaAycg] \"value\" file1 \n");
    for( i = 0; i < DEC; i++) printf("-");

    printf("\n\t\t\tmp3tag -V\n-t \tModifies a Title tag\n-T \tModifies a Track tag\n");
    printf("-a \tModifies an Artist tag\n-A \tModifies an Album tag\n");
    printf("-y \tModifies a Year tag\n-c \tModifies a Comment tag\n");
    printf("-g \tModifies a Genre tag\n-h \tDisplays this help info\n-v \tPrints version info\n\n");
    for( i = 0; i < DEC; i++) printf("-");
    printf("\n");

}