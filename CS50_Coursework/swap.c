#include <cs50.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;
    printf("%i and %i\n", x, y);
    swap(&x, &y);  // & means address of __
    printf("%i and %i\n", x, y);
}

void swap(int *a, int *b)  // * means what is at the address of __
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}