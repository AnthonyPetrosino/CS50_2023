#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // LOOK AT TRIE DIRECTORY!!!!!!!!!!!!!!
    // Big O of 1!
    // Arrays that point to other arrays
    // At 2:00:00 on video
    typedef struct node
    {
        char *number;
        struct node *children[26];
    }
    node;

    node *trie;
}
