#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    char name[] = "Mississippi";  //A string is a list of chars
    int length = strlen(name);
    printf("%s is %i char long.\n", name, length);
    printf("%c\n", name[4]);
    return 0;
}

