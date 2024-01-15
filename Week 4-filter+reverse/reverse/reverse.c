#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    //accept 2 command line arguments (argc != 3 show invalid usage message and return 1)
    if (argc != 3)
    {
        printf("Error! Correct usage is: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    // TODO #2
    //open input file 'fopen in read mode'
    FILE *input = fopen(argv[1], "r");
    //check that file opened succesfully else show error and return 1
    if (input == NULL)
    {
        printf("Could not open file. Invalid file.\n");
        fclose(input);
        return 1;
    }

    // Read header
    // TODO #3
    //use the wavheader struct that stores the wav file header to
    //create a temporary buffer to store the data from header
    WAVHEADER header;
    //read header
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    //complete the check_format function.
    check_format(header);

    // Open output file for writing
    // TODO #5
    //fopen in write mode and check if the file opens succesfully
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not create new file.\n");
        fclose(output);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blocksize = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    //declare an array to store each block
    uint32_t auditdatatemp[blocksize];

    //read in each block of auditory data starting from the very end of the input file and moving backwards
    //loop from the end to the start of the audio sample
    fseek(input, -sizeof(blocksize), SEEK_END);
    while (ftell(input) > 40)   //block after header
    {
        //simultaneously writing each block to the output file so they are written in reverse order.
        fread(&auditdatatemp, sizeof(blocksize), 1, input);
        fwrite(&auditdatatemp, sizeof(blocksize), 1, output);
        fseek(input, -sizeof(blocksize) * 2, SEEK_CUR);
    }


    //close opened files and free memory
    fclose(input);
    fclose(output);
    return 0;
}

int check_format(WAVHEADER header)
{
    // TODO #4
    //if header indicates the file is a WAV file (four "W A V E" bits in .format),
    //the check_format function should return true, else it should return false.
    if (header.format[0] == 87 && header.format[1] == 65 && header.format[2]== 86 && header.format[3] == 69)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    //should return an integer representing the block size of the given WAV file, in bytes.
    //size of each block = number of channels multiplied by bytes per sample. (check in header)
    return header.numChannels * (header.bitsPerSample / 8);
}
