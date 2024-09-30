#include <cs50.h>
#include <stdio.h>

// prompt the user for a 5 or 10.
int main(void)
{
    bool valid = false;
    int number;

    while (!valid)
    {
        number = get_int("Give me a 5 or 10: ");
        if (number == 5 || number == 10)
        {
            valid = true;
        }
    }

    printf("Valid");
}
