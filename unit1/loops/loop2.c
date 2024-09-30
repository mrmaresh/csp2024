// Use loops to print "Red Red Green Red Red Green Red Red Green"
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m = get_int("m: ");
    int k = get_int("k: ");
    int sum = 0;
    for (int counter = 0; counter < m; counter = counter + 1)
    {
        for (int j = 0; j < k; j = j + 1)
        
        {
            sum = sum + 1;
        }
    }
    printf("%i\n", sum);
}
