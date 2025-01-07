#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n = 50;
    int *p = &n;  // sets p to the address of n (* makes p a "pointer")

    printf("%p\n", &n);  // prints hexidecimal address (%p means "pointer")
    printf("%p\n", p);  // prints pointer p (which is hexidecimal address)
    printf("%i\n", *p);  // prints address that pointer p is pointing at (50)

    char *s = "HI!";  /* string's data type
    (strings point to address of first char in sequence of chars and reads until it sees \0) */
    printf("%s\n", s);  // prints string s by doing above
    printf("%p\n", s);  // prints address that s containts/points to
    printf("%p\n", &s[0]);  // prints address of first char of s (same as previous)
    printf("%p\n", &s[1]);  // prints address of second char of s (=previous++)

    printf("%c\n", *s);  // prints char at s
    printf("%c\n", *(s + 1));  // prints char at s++ (gets what is at s++)
    printf("%c\n", *(s + 2));  // prints char at s + 2 (gets what is at s + 2)

    printf("%s\n", s);  // prints string at s
    printf("%s\n", s + 1);  // prints string begining at s++ (gets what is at s++ and follows until \0)
    
}