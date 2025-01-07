#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int length = 0;
    do
    {
        length = get_int("Length of array: ");
    }
    while (length < 1);

    int array[length];
    array[0] = 1;
    printf("%i ", array[0]);
    for (int i = 1; i < length; i++)
    {
        array[i] = array[i - 1] * 2;
        printf("%i ", array[i]);
    }
    printf("\n");
}