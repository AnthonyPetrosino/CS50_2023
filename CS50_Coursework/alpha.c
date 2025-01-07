#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string word = get_string("Word: ");
    int length = strlen(word);
    bool lowerCase = true;
    for (int i = 1; i < length; i ++)
    {
        if (word[i] < word[i - 1])
        {
            lowerCase = false;
        }
    }

    if (lowerCase)
    {
        printf("Yes!\n");
    }
    else
    {
        printf("No!\n");
    }

}