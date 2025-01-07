#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char *name;
    char *number;
    struct node *next;
}
node;

int hashPlace(string phrase);

int main(int argc, char *argv[])
{
    node *table[26]; // empty boxes show NULL
    for (int i = 0; i < 3; i++)
    {
        string phrase = get_string("Enter phrase: ");
        int index = hashPlace(phrase);
        printf("%s hashes to %i\n", phrase, index);
    }
}

// returns an index from 0-25
int hashPlace(string phrase)
{
    return toupper(phrase[0]) - 'A';
}