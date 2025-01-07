#include <cs50.h>
#include <stdio.h>
#include <stdint.h>  //  Allows for pdf conversion/buffers

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Improper usage.\n");
        return 1;
    }

    //  Open file
    string filename = argv[1];
    FILE *file = fopen(filename, "r");  //  Opens file in "read" mode and creates file pointer
    if (file == NULL)  //  Checks if file exists
    {
        printf("No such file found.\n");
        return 1;
    }

    uint8_t buffer [4];  //  u- means unsigned/only positive ints, -int- means type int, -8- means 8 bits (one byte), -t means new type
    uint8_t signature [4] = {37, 80, 68, 70};  // what every pdf starts with

    fread(buffer, 1, 4, file);  //  defines buffer by reading in data through file 4 times in increments of 1 byte
    fclose(file);  //  closes file (valgrind) to prevent leaks
    for (int i = 0; i < 4; i++)  //  checks if buffer matches signature
    {
        if (buffer[i] != signature[i])
        {
            printf("Likely not a pdf.\n");
            return 0;
        }
        printf("%i", buffer[i]);
    }
    printf("Likely a pdf.\n");
    return 0;
}