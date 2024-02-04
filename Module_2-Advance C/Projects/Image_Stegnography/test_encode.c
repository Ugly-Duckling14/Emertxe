/*
Name : Munawir E
Date : 19/07/2022
Description : A practice of concealing a file, message, image, or video within another file, message, image, or video.
 Advantages :- 
  * Hide secret credentials
  * Detect data forgery
  * Message Passing
 Type of stegnography used in this project.
   -> In digital method the message is concealed within the lowest bits of images or sound files
   -> The current project expects us to implement LSB (Least Significant Bit) Image Steganography on a .bmp file
   -> Why BMP image?
      * Typically, BMP files are uncompressed, and therefore large and lossless, their advantage is their simple structure and wide acceptance in Windows programs.
      * No, Need to write extra code for compressing and uncompressing of Image. 

Sample I/P  : For Encoding :- ./a.out -e beautiful.bmp secret.txt 
Sample O/P  : For Encoding :-
	INFO: Output file not mentioned. Creating stego_out.bmp as default
	INFO: Validatiion Of Files Success
	INFO: Opening the required files...
	INFO: Done
	INFO: Encoding Procedure Started .
	INFO: Checking for beautiful.bmp image capacity size.
	width = 1024
	height = 768
	INFO: Checking for secret.txt file size.
	INFO: Image having enough space to store secret key.
	INFO: Copying Image Header.
	INFO: Done.
	INFO: Encoding Magic String Signature
	INFO: Done.
	INFO: Checking Password Is Passed...
	INFO: Done.
	INFO: Password is Not Passed. Encoding Without Password.
	INFO: Encoding Secret.txt File Extension.
	INFO: Done.
	INFO: Encoding Secret Data.
	INFO: Done.
	INFO: Copying Left Over Data.
	INFO: Done.
	INFO: Encoding Done Successfully .

Sample I/P : For Decoding :-  ./a.out -d stego_out.bmp 
Sample O/P : For Decoding.
	INFO: Decoding Procedure Started 
	INFO: Output file not mentioned. Creating decrypted.txt as default...
	INFO: Opening required files.
	INFO: Opened stego_out.bmp
	INFO: Opened decrypted.txt
	INFO: Done Opened all required files.
	INFO: Decoding Magic String Signature.
	INFO: Done
	INFO: Validating The Magic String
	INFO: Done
	INFO: Checking Password Is Available.
	INFO: No Password is Passed Continuing Decode without Password.
	INFO: Done.
	INFO: Decoding extension size.
	INFO: Done
	INFO: Decoding extension data.
	INFO: Done
	INFO: Decoding decrypted.txt File size.
	INFO: Done
	INFO: Decoding decrypted.txt File data.
	INFO: Done
	INFO: Decoding Done Successfully 
*/

#include <stdio.h>
#include <unistd.h>
#include "encode.h"
#include "types.h"
#include "common.h"
#include "decode.h"

int main( int argc, char *argv[] )
{
    // Checking the type of operation.
    OperationType option = check_operation_type( argv);

    // Jump to option according to user choice.
    switch( option )
    {
	case  e_encode :
	{
	    // Checking number of argument passed is greater than 3.
	    if( argc > 3 )
	    {
	    	EncodeInfo encInfo;
		if( read_and_validate_encode_args( argc, argv, &encInfo) == e_failure )
		{
		    puts("ERROR: Validation failure");
		    break ;
		}
		do_encoding( &encInfo );     // Function call for encoding.
	    }
	    else	
	    {
	    	printf("ERROR: Please pass atleast 3 arguments.\n");
		printf("%s: Encoding: %s -e <.bmp> <.txt> [output file]\n", argv[0], argv[0]);
		printf("%s: Encoding: %s -e <.bmp> <.txt> [output file] -p password\n", argv[0], argv[0]);
		printf("%s: Encoding: %s -p password -e <.bmp> <.txt> [output file]\n", argv[0], argv[0]);
	    }
	    break;
	}
	case e_decode :
	{
	    if( argc > 2)
	    {
	    	printf("INFO: Decoding Procedure Started \n");
		sleep(1);
		DecodeInfo decInfo;
		if( read_and_validate_decode_args( argc, argv, &decInfo) == e_failure )
		{
		    puts("ERROR: Validation failure");
		    break;
		}
		do_decoding( &decInfo );        // Function call for decoding.
		}
	    else
	    {
	    	printf("ERROR: Please pass atleast 2 arguments.\n");
		printf("%s: Decoding: %s -d <.bmp> [output file]\n", argv[0], argv[0]);
		printf("%s: Decoding: %s -d <.bmp> [output file] -p password\n", argv[0], argv[0]);
		printf("%s: Decoding: %s -p password -d <.bmp> [output file]\n", argv[0], argv[0]);
	    }
	    break;
	}
	default :
	{
	    printf("ERROR: Specified operation not found, Please specify any of the below operation.\n");
	    printf("./a.out: Encoding: ./a.out -e <.bmp file> <.txt file> [output file]\n./a.out: Encoding: ./a.out -e <.bmp> <.txt> [output file] -p password\n./a.out: Encoding: ./a.out -p password -e <.bmp> <.txt> [output file]\n");
	    printf("./a.out: Decoding: ./a.out -d <.bmp file> [output file]\n./a.out: Decoding: ./a.out -d <.bmp> [output file] -p password\n./a.out: Decoding: ./a.out -p password -d <.bmp> [output file]\n");
	}
    }
    return 0;
}
