#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }

    for (int i = 1; i <= height; i++)
    {
        int space = height - i;
        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int h = 0; h < i; h++)
        {
            printf("#");
        }
        printf("  ");
        for (int h = 0; h < i; h++)
        {
            printf("#");
        }
        printf("\n");
    }

}