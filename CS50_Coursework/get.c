#include <stdio.h>
 int main(void)
 {
    int x;  // how to get an int without cs50
    printf("x: ");
    scanf("%i", &x);  // checks what user types??
    printf("x: %i\n", x);

    // need malloc ?
    char s[4];  // allocates 5 chars and one \0 for users input
    printf("s: ");
    scanf("%s", s);  // since s is already an address, no need for &
    printf("s: %s\n", s);
 }