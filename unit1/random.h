#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int random(void)
{
    // set max for random number from 1 to max.
    int max = 100;
    time_t t;
    // Seed the random function with the current time.
    srand(time(&t));
    // Calculate a random value between 1 and max.
    int random_value = rand() % max + 1;
    return random_value;
}
