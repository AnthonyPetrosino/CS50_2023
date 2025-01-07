#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <stdlib.h>  // allows for malloc and free

int main(void)
{
    char *s = get_string("s: ");  // can return NULL if string is too big to be contained in memory

    if (s == NULL) // NULL is a pointer to an empty piece of memory, NUL is \0
    {
        return 1;
    }

    string t = s;  // only assigns t to pointer value s

    t = malloc(strlen(s) + 1);  // gets pointer for bytes for all chars of s + \0 (REMEMBER FREE)

    if (t == NULL) // this prevents the program from continuing if malloc allocates too much memory for t and returns NULL
    {
        return 2;
    }

    for (int i = 0, n = strlen(s) + 1; i < n; i++)  // assigns chars of s to bytes contained in t including \0
    {
        t[i] = s[i];
    }

    // this takes the place of the loop above
    strcpy(t, s);

    if (strlen(s) > 0)
        t[0] = toupper(t[0]);  // provided by <ctype.h>, could result in seg fault if t[0] DNE

    printf("s = %s\n", s);
    printf("t = %s\n", t);

    free(t);  // frees/returns the memory allocated for t by malloc

    return 0;
}
