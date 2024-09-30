#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int size = get_int("Size: ");

    for (int counter = 0; counter < size; counter = counter + 1)
    {
        for (int i = 0; i < size + 2; i = i + 1)
        {
            printf("#");
        }
        printf("\n");
    }
}
