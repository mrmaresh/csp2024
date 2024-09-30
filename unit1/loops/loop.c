#include <stdio.h>

int main (void)
{
    int counter = 2;
    while (counter < 40)
    {
        printf("%i\n", counter);
        counter = counter * counter;
    }

    // for (initialize counter; boolean statement; how to change counter)
    for (int i = 0; i < 5; i = i + 1)
    {
        printf("Hello ");
    }
    printf("\n");
}
