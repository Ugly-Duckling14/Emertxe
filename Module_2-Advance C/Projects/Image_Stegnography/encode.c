#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "encode.h"
#include "types.h"
#include "common.h"

/* Function Definitions */

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{
    uint width, height;
    // Seek to 18th byte
    fseek(fptr_image, 18, SEEK_SET);

    // Read the width (an int)
    fread(&width, sizeof(int), 1, fptr_image);
    printf("width = %u\n", width);

    // Read the height (an int)
    fread(&height, sizeof(int), 1, fptr_image);
    printf("height = %u\n", height);

    // Return image capacity
    return width * height * 3;
}

/* Get File pointers for i/p and o/p files
 * Inputs: Structure Variable Ptr.
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files(EncodeInfo *encInfo)
{
    // Src Image file
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    // Do Error handling
    if (encInfo->fptr_src_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->src_image_fname);
	return e_failure;
    }

    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    // Do Error handling
    if (encInfo->fptr_secret == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->secret_fname);
	return e_failure;
    }

    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    // Do Error handling
    if (encInfo->fptr_stego_image == NULL)
    {
	perror("fopen");
	fprintf(stderr, "ERROR: Unable to open file %s\n", encInfo->stego_image_fname);
	return e_failure;
    }

    // No failure return e_success
    return e_success;
}

/* Checking The Type Of Operation.
 * Inputs: Command Line Arguments.
 * Output: Return 0 For Encoding, 1 For Decoding, 2 For Error.
 * Return values: e_encode, e_decode, e_unsupported
 */
OperationType check_operation_type( char * argv[] )
{    
    // Checking command line argument is passed or not.
    if( argv[ 1 ] == NULL )
    {
	printf("ERROR: Operation is not specified!,\n");
	return e_unsupported;
    }

    // Checking 1st or 3rd argument is -e for encoding.
    if( !strcmp( argv[ 1 ], "-e" )|| ( argv[ 3] != NULL && !strcmp( argv[ 3 ], "-e")) )
    {
	return e_encode;
    }
    else if( !strcmp( argv[ 1 ], "-d") || !strcmp( argv[ 3 ], "-d"))             // Checking 1st or 3rd argument is -d for decoding.
    {
	return e_decode;
    }
    else                // For othercases.
    {
	return e_unsupported;
    }
}

/* Validating The Required Files Are Passed Or Not. 
 * Inputs: Command line argument, structure variable ptr.
 * Output: Stores input file names to struct variables.
 * Description: If all arguments meets required criteria returns e_succes.  
 */
Status read_and_validate_encode_args( int argc, char * argv[], EncodeInfo *encInfo )
{
    if( !strcmp(argv[ 1 ], "-e") )
    {
	encInfo->opt_pos = 1;
    }
    else
    {
	encInfo->opt_pos = 3;
    }

    // Checking argument 2 not null, & file is bmp,if true stores to structure varible, else throws error message.
    if( argv[ encInfo->opt_pos + 1 ] != NULL )
    {
	if( strstr( argv[ encInfo->opt_pos + 1 ], ".bmp"))
	{
	    encInfo->src_image_fname = argv[ encInfo->opt_pos + 1 ];
	}
	else
	{
	    printf("ERROR: Source file extension not matched, It should be \".bmp\" \n EX:- source_image.bmp\n");
	    return e_failure;
	}
    }
    else
    {
	return e_failure;
    }

    // Checking argument is not null, if true stores to structure variable, else throw error.
    if( argv[ encInfo->opt_pos + 2 ] != NULL )
    {
	encInfo->secret_fname = argv[ encInfo->opt_pos + 2 ];
    }
    else
    {
	return e_failure;
    }

    // Checking argument 4 (optional) is present or not, if present store name, else default name used for output. 
    if( (argv[ encInfo->opt_pos + 3 ] != NULL ) && (strcmp( argv[ encInfo->opt_pos + 3], "-p" )))
    {
	if( strstr( argv[ encInfo->opt_pos + 3 ], ".bmp"))
	{
	    encInfo->stego_image_fname = argv[ encInfo->opt_pos + 3 ];
	}
	else
	{
	    printf("ERROR: Destination file extension not matched, It should be \".bmp\" \n EX:- stego_image.bmp\n");
	    return e_failure;
	}
    }
    else
    {
	printf("INFO: Output file not mentioned. Creating stego_out.bmp as default\n");        
	encInfo->stego_image_fname = "stego_out.bmp";
	sleep(1);
    }

    // Checking password passed or not
    if( argc > 5)
    {
	if( !strcmp(argv[ 1 ], "-p") )
	{
	    encInfo->password = argv[ 2 ];
	}
	else if( !strcmp(argv[ 4 ], "-p") )
	{
	    encInfo->password = argv[ 5 ];
	}
	else if( !strcmp(argv[ 5 ], "-p") && argv[ 6 ] != NULL )
	{
	    encInfo->password = argv[ 6 ];
	}
	else
	{
	    printf("ERROR: Unknown Command Or Password Not Passed with -p\n");
	    return e_failure; 	
	}
    }
    else
    {
	encInfo->password = NULL;
    }  
    printf("INFO: Validatiion Of Files Success\n");
    sleep(1);
    return e_success;
}

/* Starting The Process Of Coding.
 * Inputs: Structure variable ptr.
 * Output: If Process Is Success, An Encrypted Image Is Created With Secret Key.
 * Description: Main Function For Encoding ,
 * Which Calls All Sub Function To Complete Encodeing  
 */
Status do_encoding( EncodeInfo *encInfo )
{
    printf("INFO: Opening the required files...\n");
    sleep( 1 );

    // Function call for opening files.
    if( open_files( encInfo ) == e_success )
    {
	printf("INFO: Done\n");
	sleep(1);
	printf("INFO: Encoding Procedure Started .\n");
	sleep(1);

	// Fuction call for checking enough space for encryption.
	if( check_capacity( encInfo ) == e_success )
	{
	    printf("INFO: Copying Image Header.\n");
	    sleep(1);

	    // Function call for copy header file of image.
	    if( copy_bmp_header( encInfo-> fptr_src_image, encInfo->fptr_stego_image ) == e_success)
	    {
		printf("INFO: Done.\n");
		sleep(1);
		printf("INFO: Encoding Magic String Signature\n");
		sleep(1);

		// Function call for encode password.
		encode_magic_string( MAGIC_STRING, encInfo );

		printf("INFO: Done.\n");
		sleep(1);

		// Function call for password.
		printf("INFO: Checking Password Is Passed...\n");
		if( encInfo->password != NULL )
		{
		    printf("INFO: Done.\n");
		    sleep(1);
		    printf("INFO: Encoding The Password.\n");
		    encode_password( encInfo);
		    printf("INFO: Done.\n");
		    sleep(1);
		}
		else
		{
		    printf("INFO: Done.\n");
		    sleep(1);
		    printf("INFO: Password is Not Passed. Encoding Without Password.\n");
		}
		printf("INFO: Encoding Secret.txt File Extension.\n");
		sleep(1);
		char file_extn[30];
		strcpy( file_extn, encInfo->secret_fname);
		strtok( file_extn, ".");
		strcpy( encInfo->extn_secret_file, strtok( NULL, ".") );

		// Function call for encode secret file extension.
		encode_secret_file_extn( encInfo->extn_secret_file, encInfo );
		printf("INFO: Done.\n");
		sleep(1);
		printf("INFO: Encoding Secret Data.\n");
		sleep(1);

		// Function call for encode secret file data.
		encode_secret_file_data(encInfo );
		printf("INFO: Done.\n");
		sleep(1);
		printf("INFO: Copying Left Over Data.\n");
		sleep(1);

		// Function call to copy remaining image data.
		copy_remaining_img_data( encInfo );
		printf("INFO: Done.\n");
		sleep(1);
		printf("INFO: Encoding Done Successfully .\n");
	    }
	}
	else    // Error if image have not enough space to store the secret key.
	{
	    printf("ERROR: Image size is not enough.\n");
	    return e_failure;
	}
    }
    else        // Error message when opening of any file fails.
    {  
	printf("ERROR: Opening files failed...");
	sleep( 1 );
	return e_failure;
    }
}

/* TO Check Image Having Enough Space to Store the Key. 
 * Inputs: Structure variable ptr.
 * Output: Checks mage having enough space to store secret key.
 * Return values: e_success if image has more than
 * enough space to store secret key. 
 */
Status check_capacity( EncodeInfo *encInfo )
{
    printf("INFO: Checking for %s image capacity size.\n", encInfo->src_image_fname );
    sleep(1);
    encInfo->image_capacity = get_image_size_for_bmp( encInfo->fptr_src_image );            // Function call to get total capacity of source image. 

    printf("INFO: Checking for %s file size.\n", encInfo->secret_fname );
    sleep(1);
    encInfo->size_secret_file = get_file_size( encInfo->fptr_secret );                  // Function call to get size of secret file.

    if( 1 > encInfo->size_secret_file )                     // Checking secret fil is empty or not.
    {
	printf("ERROR: Secret code file is empty!!!....");
	sleep(1);
	return e_failure;
    }
    uint magic_len = strlen( MAGIC_STRING );
    // Getting password size.
    uint pass_length = 0;
    if( encInfo->password != NULL )
    {
	pass_length = strlen( encInfo->password ) + 64 ;
    }

    char *file_extn = strstr( encInfo->secret_fname, "." );     
    uint extn_length = strlen( file_extn ) - 1;                 // Getting extension size.
    uint total_size = ( 3 * 32 ) + ( magic_len + pass_length + extn_length + encInfo->size_secret_file ) * 8;  // Finding the required size for encoding.
    if( encInfo->image_capacity > total_size )                  // Checking image having enough spacee to add secret code.
    {
	printf("INFO: Image having enough space to store secret key.\n");
	sleep(1);
	return e_success;
    }
    else
    {
	return e_failure;
    }
}

/* Getting the size of secret code file.
 * Inputs: Secret code file.
 * Output: Size of secret code.
 * Description: Gets the file size using fseek, File size is 
 * present at the end of header file.
 */
uint get_file_size( FILE *secret )                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
{
    fseek( secret, 0L, SEEK_END );
    return ftell( secret );
}

/* Copying The Header File From the Src Image And Pasting to Output Image.
 * Inputs: File ptr of source & destination image.
 * Output: If header file is successfully copied return success.
 * Return value: e_success if header file is copied.
 */
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image )
{
    char header[54];

    // Changing file pointer position to the beginning of the file. 
    rewind( fptr_src_image );
    rewind( fptr_dest_image );

    // Copying header from source image and pasting to destination image.
    fread( header, 54, 1, fptr_src_image );
    fwrite( header, sizeof(char), 54, fptr_dest_image );
    return e_success;
}

/* Encoding MS And It's Length To Output Image.
 * Inputs: Pointer to constant & Structure ptr variable.
 * Output: First encodes MS size then it encodes
 * MS to output image at beginning of data part of image.
 * Return value: Returns e_success if MS & MS length
 * encoded to output image.  
 */
Status encode_magic_string( const char *magic_string, EncodeInfo *encInfo)
{
    char buffer[32];

    // Reading 32 bytes from source image & encode pass size to output image. 
    fread( buffer, sizeof(char), 32, encInfo->fptr_src_image );
    encode_secret_file_size( strlen( magic_string ), buffer );
    fwrite( buffer, sizeof(char), 32, encInfo->fptr_stego_image);

    // Function call for encode the magic string to output image.
    encode_data_to_image( magic_string, encInfo->fptr_src_image, encInfo->fptr_stego_image );
    return e_success;
}

/* Encoding The Password.
 * Inputs: Structure ptr variable.
 * Output: If password is passed by encoder then encode password,
 * return e_success after encoding. 
 * Return value: Return e_success after encoding th password.
 */
Status encode_password( EncodeInfo *encInfo )
{
    char buffer[32];
    encode_data_to_image( "pass", encInfo->fptr_src_image, encInfo->fptr_stego_image );

    // Reading 32 bytes from source image & encode pass size to output image. 
    fread( buffer, sizeof(char), 32, encInfo->fptr_src_image );
    encode_secret_file_size( strlen( encInfo->password ), buffer );
    fwrite( buffer, sizeof(char), 32, encInfo->fptr_stego_image);

    // Function call for encode the magic string to output image.
    encode_data_to_image( encInfo->password, encInfo->fptr_src_image, encInfo->fptr_stego_image );
    return e_success;
}

/* Encodes 1 byte of data to lsb
 * Inputs: 1 byte data & 8 bytes of source Image data.
 * Output: Stores bit by bit data to lsb of image data.
 * Description: Data is encoded and stores
 * to destination image in the ratio of 1:8 
 */
Status encode_byte_to_lsb( char data, char *image_buffer)
{
    int count = 0, i;
    for( i = 7; i >= 0; i-- )
    {
	if( ( data & (1 << i)) )
	{
	    image_buffer[ count ] |= 1;
	}
	else
	{
	    image_buffer[ count ] &= 0xFE;
	}
	count++;
    }
    return e_success;
}

/* Encodes the to image file.
 * Inputs: Data to b encoded, File ptr for source and destination img.
 * Output: Encode the data and stores to destination image.
 * Description: Data fetches byte by byte and 
 * encodes and stores to dest.
 */
Status encode_data_to_image(const char *data, FILE *fptr_src_image, FILE *fptr_dest_image)
{
    char buffer[ 8 ], i;
    // 1 byte of data fetches and send to the fuction data to lsb for encode. 
    for( i = 0; i < (int)strlen( data ); i++ )
    {
	fread( buffer, sizeof(char), 8, fptr_src_image );
	encode_byte_to_lsb( data[ i ], buffer );            // Function call for byte to lsb.
	fwrite( buffer, sizeof(char), 8, fptr_dest_image );
    }
    return e_success;
}

/* Encodes secret file extension.
 * Inputs: Pointer to constant file_extn, structure pointer variable.
 * Output: Encodes secret file extn size & extension.
 * Description: Encodes size of extension in 32 bytes,
 * Encodes extension to size * 8 bytes.
 */
Status encode_secret_file_extn(const char *file_extn, EncodeInfo *encInfo )
{
    char buffer[32];

    fread(buffer, 32, 1, encInfo->fptr_src_image);      // Taking 32 byte as integer requires 4 bytes
    encode_secret_file_size(strlen(file_extn), buffer);     // Function call encode file extn size.
    fwrite( buffer, 32, 1, encInfo->fptr_stego_image);
    encode_data_to_image( file_extn, encInfo->fptr_src_image, encInfo->fptr_stego_image);       // Function call to encod the file extension.
    return e_success;
}

/* Encodes size of extn, secret file siz and password size.
 * Inputs: long file size, char image_buffer ptr.
 * Output: Encodes size and returns e_success.
 * Description: Encodes 4 bytes size to 32 bytes buffer.
 */
Status encode_secret_file_size(long file_size, char *image_buffer)
{
    int mask = (1 << 31);

    for(int i=0; i<32; i++)
    {
	image_buffer[i] = (image_buffer[i] & 0xfe) | ((file_size & mask) >> (31 - i));  // Modifying the lsb
	mask = mask >> 1;
    }
    return e_success;
}

/* Encodes secret file data.
 * Inputs: structure pointer variable.
 * Output: Encodes data size and data
 * Description: Gets file size and data,
 * Encodes it and stores to destination
 */
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    int file_size = encInfo->size_secret_file;
    char pos[ 32 ],buffer[ file_size + 1 ];
    fread( pos, sizeof(char), 32, encInfo->fptr_src_image);
    encode_secret_file_size( file_size, pos);                   // Function call to encode data size.
    fwrite( pos, sizeof(char), 32, encInfo->fptr_stego_image );

    fseek(encInfo->fptr_secret, 0, SEEK_SET); //taking the ptr to 1st place
    fread(buffer, file_size, 1, encInfo->fptr_secret);
    encode_data_to_image( buffer, encInfo->fptr_src_image, encInfo->fptr_stego_image);      // Function call to encode the secret data.
    return e_success;
}

/* Copies the remaining img data.
 * Inputs: Structure ptr variable.
 * Output: Return e_success after copying remaining data.
 * Return value: Return e_success.
 */
Status copy_remaining_img_data( EncodeInfo *encInfo)
{
    char ch;
    while(fread(&ch, 1, 1, encInfo->fptr_src_image))
    {
	fwrite(&ch, 1, 1, encInfo->fptr_stego_image);
    }
    return e_success;
}
