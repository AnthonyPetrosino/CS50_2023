#include <stdio.h>
#include <stdlib.h>

// how to use valgrind to debug memory usage bugs

int main(void)
{
    int *x = malloc(3 * sizeof(int));  // int size is 4, makes 12 bytes of memory
    x[0] = 72;
    x[1] = 73;
    x[2] = 74;
    free(x);
}