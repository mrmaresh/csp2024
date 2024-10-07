#include <stdio.h>

int main(void)
{
    int j = 1;
    goto skip_this;
    j = 10;
    j = 20;
    j = 50;
    skip_this:
    printf("j = %i\n", j);
}
