#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user x
    int x = get_int("x: ");

    // Promt user y
    int y = get_int("y: ");

    //Divide x by y
    float z = (float)x/(float)y;

    printf("%.13f\n", z);
}
