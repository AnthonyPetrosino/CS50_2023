#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
      // comparing int
    int x = get_int("Define x: ");
    int y = get_int("Define y: ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }

      // comparing strings
    char *s = get_string("Define s: ");
    char *t = get_string("Define t: ");

    if (strcmp(s, t) == 0)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }

      // gets what is at both s and t pointer but doesn't follow until the \0 (first char in string)
    if (*s == *t)
    {
        printf("Same first char!");
    }
}