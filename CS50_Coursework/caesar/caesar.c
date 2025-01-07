#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool input_check(string arg, int length);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int length = strlen(argv[1]);
    bool key = input_check(argv[1], length);
    int arg = atoi(argv[1]);
    if (key)
    {
        string text = get_string("plaintext: ");
        int tlength = strlen(text);
        printf("ciphertext: ");
        for (int i = 0; i < tlength; i++)
        {
            if (isalpha(text[i]))
            {
                char t = text[i];
                if (isupper(text[i]))
                {
                    t = 65 + (((t - 65) + arg) % 26);
                }
                else if (islower(text[i]))
                {
                    t = 97 + (((t - 97) + arg) % 26);
                }
                printf("%c", t);
            }
            else
            {
                printf("%c", text[i]);
            }
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    printf("\n");
}

bool input_check(string arg, int length)
{
    bool correct = true;
    for (int i = 0; i < length; i++)
    {
        if (arg[i] < 48 || arg[i] > 57)
        {
            correct = false;
        }
    }
    if (correct)
    {
        return true;
    }
    else
    {
        return false;
    }
}