#include <stdio.h>
#include <stdlib.h>

typedef struct nodes // node is pre emptively called
{
    int number;
    struct nodes *next;
}
node;

int main(int argc, char *argv[])
{
    /*
    node *list = NULL;

    // makes first node
    node *n = malloc(sizeof(node));

    // Next two lines are equal in assigning node's number value
    (*n).number = 1;
    n -> number = 1;

    // Assigns node * of n to null
    n -> next = NULL;

    // makes list point to begining of list
    list = n;

    // makes second node somewhere in memory
    node *n = malloc(sizeof(node));
    // assigns values to second node
    n -> number = 2;
    n -> next = list;  // points second node to first node (making list be 2 1)
    // makes list point to 2 instead of 1 (since 2 points to 1)
    list = n;
    // as this list gets longer, it creates a stack (LIFO); puts numbers in reverse order
    */
    // linkedlist creator code:

    node *list = NULL;
    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = number; // updates n's number value to inputted number value

        // prepends to let n point to next node (where list is currently pointing) (first node points to NULL since *list = NULL from outside of loop)
        n->next = list;
        // makes list point to n (newest node)
        list = n;
    }

    node *ptr = list; // points to first node in the list
    while (ptr != NULL) // while ptr is pointing to pointer
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    // free allocated memory
    ptr = list;
    while (ptr != NULL)
    {
        node *nextnode = ptr->next;
        free(ptr);
        ptr = nextnode;
    }
}
