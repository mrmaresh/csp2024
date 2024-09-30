#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    printf("%i %i %i\n", c1, c2, c3);

    int scores[3];
    scores[0] = 72;
    scores[1] = 73;
    scores[2] = 33;
    printf("%i %i %i\n", scores[0], scores[1], scores[2]);

    int values[] = {72, 73, 33};
    printf("%i\n", values[2]);
}
