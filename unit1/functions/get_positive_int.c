#include <cs50.h>
#include <stdio.h>

int get_positive_int (void);
int main(void)
{
    int i = get_positive_int();
    printf("%i\n", i);
}


int get_positive_int (void)
{
    int n = -3;

    while (n < 1)
    {
        n = get_int("Positive Integer: ");
    }
    return n;
}
