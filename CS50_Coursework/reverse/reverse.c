#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "math.h"

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }

    // Open input file for reading
    FILE* readFile = fopen(argv[1], "r");

    if (readFile == NULL)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Read header
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, readFile);

    // Use check_format to ensure WAV format
    int check = check_format(header);
    if (check == 1)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }


    // Open output file for writing
    FILE* writeFile = fopen(argv[2], "w");
    if (writeFile == NULL)
    {
        printf("Could not create %s.\n", argv[2]);
        return 1;
    }

    // Write header to file
    fwrite(&header, sizeof(WAVHEADER), 1, writeFile);

    // Use get_block_size to calculate size of block
    int size = get_block_size(header);

    // Write reversed audio to file

    if (fseek(readFile, size, SEEK_END))
    {
        return 1;
    }

    BYTE b[size];
    while (ftell(readFile) - size > sizeof(header))
    {
        if(fseek(readFile, -2 * size, SEEK_CUR))
        {
            return 1;
        }
        fread(b, size, 1, readFile);
        fwrite(b, size, 1, writeFile);
    }

    fclose(readFile);
    fclose(writeFile);
}

int check_format(WAVHEADER header)
{
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int get_block_size(WAVHEADER header)
{
    // size = number of channels multiplied by bytes per sample
    int bytes = round(header.bitsPerSample / 8);
    int size = header.numChannels * bytes;
    return size;
}