#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // int values[4];
    // values[0] = get_int("Value 1: ");
    // values[1] = get_int("Value 2: ");
    // values[2] = get_int("Value 3: ");
    // values[3] = get_int("Value 4: ");

    // float average = (float)(values[0] + values[1] + values[2] + values[3]) / 4;
    // printf("Average is %f\n", average);



    int values[4];
    //Example of using a loop to populate a list
    for (int i = 0; i < 4; i = i + 1)
    {
        values[i] = get_int("Value %i: ", i + 1);
    }

    int sum = 0;
    for (int j = 0; j < 4; j = j + 1)
    {
        sum = sum + values[j];
    }
    float average = (float) sum / 4;
    printf("The average is %f\n", average);
}
