#include <cs50.h>
#include <stdio.h>

const int N = 20;
int values[N];

void promptUser(void);
float getAverage(void);

int main(void)
{
    promptUser();
    printf("The average is %f\n", getAverage());
}


void promptUser(void)
{
    for (int i = 0; i < N; i = i + 1)
    {
        values[i] = get_int("Value %i: ", i + 1);
    }
}


float getAverage(void)
{
    int sum = 0;
    for (int j = 0; j < N; j = j + 1)
    {
        sum = sum + values[j];
    }
    return (float) sum / N;
}
