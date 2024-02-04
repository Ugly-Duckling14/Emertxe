#ifndef DECODE_H
#define DECODE_H

#include <stdio.h>
#include "types.h"

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

typedef struct _DecodeInfo  //creating the structure to store the cla data
{
    /* Secret File Info */
    char *secret_fname;
    FILE *fptr_secret;
    char extn_secret_file[MAX_FILE_SUFFIX];
    char image_data[30];
    long size_secret_file;
    uint secret_file_extn_size;

    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;

    /* For Password Info */
    char *password;
    int opt_pos;
    long fptr_pos;

} DecodeInfo;

// Validating the command line arguments
Status read_and_validate_decode_args(int argc, char *argv[], DecodeInfo *decInfo); // Checking command line argument.

// Initiating the decode
void do_decoding(DecodeInfo *decInfo);

// Opening all the required files
Status open_files_(DecodeInfo *decInfo); 

// Decoding the "#*" to find data is encoded or not
Status decode_magic_string(DecodeInfo *decInfo);

//  Password validation
Status_pass decode_password_validation( DecodeInfo *decInfo);

// Decoding the size 
int decode_size(char *image_buffer, int len );

//collecting the values from the lsb
void decode_data_from_lsb(char *image_buffer, char *);

//decoding the extension size
void decode_extn_size(DecodeInfo *decInfo);

//decoding .txt data
void decode_extn_data(DecodeInfo *decInfo);

//decoding the secret file size
void decode_secret_file_size(DecodeInfo *decInfo);

//decoding the secret data and saving it to output file
void decode_secret_file_data(DecodeInfo *decInfo);

#endif

