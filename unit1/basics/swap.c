#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    int temp;
    temp = x;
    x = y;
    y = temp;
    bool m = true;
    char c = '#';
    double d = 98749780872043875.739582740952;
    float f = 35435.322;
    int i = 5;
    long l = 7488838383838838;
    string s = "Hello, I am a string!!!";

    printf("x is %i\n", x);
    printf("y is %i\n", y);
}
