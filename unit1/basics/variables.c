#include <stdio.h>

int main (void)
{
    int a = 5;
    int b = 3;
    int c = 10;
    int d = 2;
    a = a + b;
    b = c - d;
    c = a * d;
    d = c / b;
    a = a - d;
    b = b + d;
    c = c + 5;
    printf("a = %i\n", a);
    printf("b = %i\n", b);
    printf("c = %i\n", c);
    printf("d = %i\n", d);
}
