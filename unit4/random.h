#include <stdlib.h>
#include <time.h>


#define RANDOM_SEED srand(time(NULL)) //Call RANDOM_SEED once in the main program in order to use the functions below.


// This function will select a random integer between min and max
int get_random_integer_between(int min, int max){
    int range = max - min + 1;
    return min + rand() % range;
}


// This function will select a random float between min and max
float get_random_float_between(float min, float max){
    float range = max - min;
    float percent_range_traveled = ((double)rand()) / RAND_MAX;
    return min + range * percent_range_traveled;
}
