#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "decode.h"
#include "types.h"
#include "common.h"

/* Validating the command line arguments
 * Inputs: char ptr agrv[], Structure variable ptr.
 * Output: Validate decode file is bmp and stores
 * the decode file name to char ptr.
 * Return value: Returns e_success if validation is success,
 * else return e_failure.
 */
Status read_and_validate_decode_args( int argc, char *argv[], DecodeInfo *decInfo)
{
    if( !strcmp( argv[ 1 ], "-d") )
    {
	decInfo->opt_pos = 1;
    }
    else
    {
	decInfo->opt_pos = 3;
    }

    // Checking output file .bmp or not.
    if( argv[ decInfo->opt_pos + 1 ] != NULL )     
    {
	if( strstr( argv[ decInfo->opt_pos + 1 ], ".bmp" ) )
	{
	    decInfo->stego_image_fname = argv[ decInfo->opt_pos + 1 ];
	}
	else
	{
	    return e_failure;
	}
    }
    else
    {
	printf("ERROR: Operation is not specified!,\n");
	printf("./a.out: Decoding: ./a.out: Decoding: ./a.out -d <.bmp file> [output file]");
	return e_failure;
    }

    // Check if the file to be stored is passed,else default file name is passed.
    if( argv[ decInfo->opt_pos + 2 ] != NULL && ( strstr( argv[ decInfo->opt_pos + 2 ], ".txt") || strstr( argv[ decInfo->opt_pos + 2 ], ".c")))
    {
	decInfo->secret_fname = argv[ decInfo->opt_pos + 2 ];
    }
    else if( argv[ decInfo->opt_pos + 2 ] == NULL || !strcmp( argv[ decInfo->opt_pos + 2], "-p" ) )
    {
	printf("INFO: Output file not mentioned. Creating decrypted.txt as default...\n");  
	sleep(1);
	decInfo->secret_fname = "decrypted.txt";
    }
    else
    {
	printf("ERROR: Invalid Extension Please Pass .txt or .c File as Output.\n");
	return e_failure;
    }
    if( argc > 3 )
    {
	if( !strcmp( argv[ 1 ], "-p") )
	{
	    decInfo->password = argv[ 2 ];
	}
	else if( !strcmp( argv[ 3 ], "-p" ))
	{
	    decInfo->password = argv[ 4 ];
	}
	else if( !strcmp( argv[ 4 ], "-p" ))
	{
	    decInfo->password = argv[ 5 ];
	}
	else
	{
	    printf("ERROR: Password Is Not Passed After -p Or Passed Invalid Command.\n");
	    return e_failure;
	}
    }
    else
    {
	decInfo->password = NULL;
    }
    return e_success ;
}

/* Main function to start decoding process.
 * Inputs: Structure variable ptr.
 * Output: If decoding is success secret data is stored
 * in a file.
 * Description: Call all the sub function for decoding.
 */
void do_decoding(DecodeInfo *decInfo)
{
    // Opening the files for decoding, if file is not opened.
    printf("INFO: Opening required files.\n");
    sleep(1);
    if( open_files_( decInfo ) == e_success )
    {
	// Decoding the password.
	printf("INFO: Decoding Magic String Signature.\n");
	sleep(1);
	if( decode_magic_string( decInfo ) == e_success )
	{
	    printf("INFO: Done\n");
	    sleep(1);

	    // Decoding the Password.
	    decInfo->fptr_pos = ftell( decInfo->fptr_stego_image);
	    printf("INFO: Checking Password Is Available.\n");
	    int status = decode_password_validation( decInfo ) ;
	    if( status == e_neitherp )
	    {
		fseek( decInfo->fptr_stego_image, decInfo->fptr_pos, SEEK_SET);
	    }
	    else if( status == e_failurep )
	    {
		_exit(1);
	    }
	    sleep(1);
	    printf("INFO: Done.\n");
	    sleep(1);

	    // Decoding the extension size
	    printf("INFO: Decoding extension size.\n");
	    sleep(1);
	    decode_extn_size(decInfo);  
	    printf("INFO: Done\n");
	    sleep(1);

	    // Decoding the extension of secret key. 
	    printf("INFO: Decoding extension data.\n");
	    sleep(1);
	    decode_extn_data(decInfo); 
	    printf("INFO: Done\n");
	    sleep(1);

	    // Decoding the size of the secret file data
	    printf("INFO: Decoding %s File size.\n", decInfo->secret_fname); 
	    sleep(1);
	    decode_secret_file_size(decInfo); 
	    printf("INFO: Done\n");
	    sleep(1);

	    // Decoding secret file data
	    printf("INFO: Decoding %s File data.\n", decInfo->secret_fname);
	    sleep(1);
	    decode_secret_file_data(decInfo);
	    printf("INFO: Done\n");
	    sleep(1);
	    printf("INFO: Decoding Done Successfully \n");
	}
    }
}

/* Get File pointers for i/p and o/p files
 * Inputs: Structure Variable Ptr.
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files_(DecodeInfo *decInfo)
{
    decInfo->fptr_stego_image = fopen( decInfo->stego_image_fname, "r" );

    // Checking file name is empty or not
    if( decInfo->fptr_stego_image == NULL )
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->stego_image_fname);
	return e_failure; 
    }
    printf("INFO: Opened %s\n", decInfo->stego_image_fname);
    sleep(1);

    decInfo->fptr_secret = fopen(decInfo->secret_fname, "w");

    if( decInfo->fptr_secret == NULL )
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", decInfo->secret_fname);
	return e_failure;
    }
    printf("INFO: Opened %s\n", decInfo->secret_fname);
    sleep(1);
    printf("INFO: Done Opened all required files.\n");
    sleep(1);
    // No failure return e_success
    return e_success;
}

/* Decoding Magic String.
 * Inputs: structure variable ptr.
 * Output: returns success after decoding MS size and MS.
 * Description: Gets size of MS then get that
 * number of bytes from and decode MS from encrypted data.
 */
Status decode_magic_string(DecodeInfo *decInfo)
{
    int magic_len, i;
    char buffer[ 32 ];

    // Getting pass length.
    fseek( decInfo->fptr_stego_image, 54, SEEK_CUR);
    fread( buffer, sizeof(char), 32, decInfo->fptr_stego_image );
    magic_len = decode_size( buffer, 31 );

    // Getting magic string.
    char magic_string[magic_len + 1];
    for( i = 0; i < magic_len; i++ )
    {
	fread( buffer, sizeof(char), 8, decInfo->fptr_stego_image );
	decode_data_from_lsb( buffer, &magic_string[i] );
    }
    magic_string[ i] = '\0';
    printf("INFO: Done\n");
    sleep(1);

    printf("INFO: Validating The Magic String\n");
    if( strcmp( magic_string, MAGIC_STRING ) == e_failure)
    {
	printf("ERROR: Validation Of Magic String Failed.\n");
	return e_failure;
    }
    return e_success;
}

/* Decode the Password & Validation.
 * Inputs: structure variable ptr
 * Output: Return e_successp or e_failurep.
 * Description: If encoded password matches with
 * Decoding password return e_successp,
 * else return e_failurep.
 */
Status_pass decode_password_validation( DecodeInfo *decInfo)
{
    int i, pass_len = 0;
    char pass[5], buffer[32];

    for( i = 0; i < 4; i++)
    {
	fread( buffer, sizeof(char), 8, decInfo->fptr_stego_image );
	decode_data_from_lsb( buffer, &pass[i] );
    }
    pass[i] = '\0';

    if( !strcmp( pass, "pass") )
    {
	printf("INFO: Password Found. ");
	if( decInfo-> password != NULL )
	{
	    printf("Decoding password.\n");
	    fread( buffer, sizeof(char), 32, decInfo->fptr_stego_image );
	    pass_len = decode_size( buffer, 31);

	    // Getting password.
	    char passwd[ pass_len + 1 ];
	    for( i = 0; i < pass_len ; i++)
	    {
		fread( buffer, sizeof(char), 8, decInfo->fptr_stego_image );
		decode_data_from_lsb( buffer, &passwd[i] );
	    }
	    passwd[ i ] = '\0';
	    printf("INFO: Decoded Password, Validating Password.\n");

	    if( strcmp( passwd, decInfo->password) )
	    {
		printf("ERROR: Invalid Password\n");
		return e_failurep;
	    }
	}
	else
	{
	    printf("No, Input For Password From Decoder Side, Decoding Failed.\n");
	    return e_failurep;
	}
	sleep(1);
	printf("INFO: Done.\n");

    }
    else
    {
	printf("INFO: No Password is Passed Continuing Decode without Password.\n");
	return e_neitherp;
    }
    printf("INFO: Validation Of Password Is Success.\n");
    return e_successp;
}


/* Decode the size
 * Inputs: char ptr, integer len,
 * Output: size of passwd, ext, data
 * Dscription: Find the size how many bytes to fetch to 
 * decode each data. 
 */
int decode_size(char *image_buffer, int len )
{
    int i, size = 0, mask = 0x1, count = 0 ;
    for( i = len; i >= 0 ; i-- )
    {
	size += (mask << i) & ((image_buffer[ count ] & mask ) << i);
	count++;
    }
    return size;
}

/* Decode data bit by bit and converts to one byte of data.
 * Input: char ptrs
 * Output: One character.
 * Description: Decode & get 8 bit of data and converts to 1 bytes.
 */
void decode_data_from_lsb(char *image_buffer, char *magic_string)
{
    int i, count = 0, mask = 0x1;
    int magic_char = 0;
    for( i = 7; i >= 0; i-- )
    {
	magic_char += (mask << i) & ((image_buffer[ count++ ] & mask ) << i); 
    }
    *magic_string = magic_char;
}

/* Decodes extn size.
 * Inputs: Structure variable ptr.
 * Output: size if extn of encoded data.
 * Return value: Return nothing
 */
void decode_extn_size(DecodeInfo *decInfo)
{
    char buffer[32];
    fread( buffer, sizeof(char), 32, decInfo->fptr_stego_image );
    decInfo->secret_file_extn_size = decode_size( buffer, 31 );
}

/* Decode type of extn like txt,pdf etc.
 * Inputs: Structure variable ptr.
 * Output: Extn of secret data file used for encoding.
 * Return value: Return nothing.
 */
void decode_extn_data(DecodeInfo *decInfo)
{
    int i;
    char buffer[8];
    for( i = 0; i < (int) decInfo->secret_file_extn_size; i++ )
    {
	fread( buffer, sizeof(char), 8, decInfo->fptr_stego_image );
	decode_data_from_lsb( buffer, &decInfo->extn_secret_file[ i ] );
    }
}

/* Decode the size of secret data.
 * Inputs: Structure variable ptr.
 * Output: Size of secret data.
 * Return value: Return nothing.
 */
void decode_secret_file_size(DecodeInfo *decInfo)
{
    char buffer[ 32];
    fread( buffer, sizeof(char), 32, decInfo->fptr_stego_image );
    decInfo->size_secret_file = decode_size( buffer, 31);
}

/* Decode secret data. 
 * Inputs: Structure variable ptr.
 * Output: Secret data is Stored to the file.
 * Return value: return nothing.
 */
void decode_secret_file_data(DecodeInfo *decInfo)
{
    int i;
    char buffer[8];
    for( i = 0; i < decInfo->size_secret_file ; i++ )
    {
	fread( buffer, sizeof(char), 8, decInfo->fptr_stego_image );
	decode_data_from_lsb( buffer, &decInfo->image_data[i] );
    }   
    fwrite( decInfo->image_data, sizeof(char), decInfo->size_secret_file, decInfo->fptr_secret );
}
