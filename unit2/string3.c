#include <cs50.h>
#include <stdio.h>
#include <string.h>

char changeToUpperCase(char ch);
int main(void)
{

    string name = get_string("Write some text: ");
    int length = strlen(name);
    char ch2;
    for (int i = 0; i < length; i = i + 1)
    {
        ch2 = changeToUpperCase(name[i]);
        printf("%c", ch2);
    }
    printf("\n");
}

char changeToUpperCase(char ch)
{
    if (ch <= 'z' && ch >= 'a')
    {
        ch = ch - 32;
    }
    return ch;
}
