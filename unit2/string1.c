#include <stdio.h>
#include <cs50.h>


int findStringLength(string name);
int main(void)
{
    char name[] = "Mississippi";  //A string is a list of chars
    int length = findStringLength(name);
    printf("%s is %i char long.\n", name, length);
    printf("%c\n", name[4]);
    return 0;
}


int findStringLength(string name)
{
    int length = 0;
    while (name[length] != '\0')
    {
        length = length + 1;
    }
    return length;
}
