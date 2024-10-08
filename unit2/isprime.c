/*
The user will run the program like ...    ./isprime 5
we want to return ... true (if prime) or false (otherwise)

If they give us n, we would want to loop n - 2 times checking
if n is divisible by 2,3,4,..., n-1
*/

#include <stdio.h> // printf
#include <cs50.h> // string, bool
#include <stdlib.h> //atoi

bool isprime(int number_to_check);

int main(int argc, string argv[])
{
    int number_to_check = atoi(argv[1]);   // argv[] = {"./isprime", "5"}
    if (isprime(number_to_check))
    {
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}


//return_type  function_name (parameter_type parameter_name, ...)
bool isprime(int number_to_check)
{
    for(int divisor = 2; divisor < number_to_check; divisor = divisor + 1)
    {
        if (number_to_check % divisor == 0)
        {
            printf("A divisor of %i is %i\n", number_to_check, divisor);
            return false;
        }
    }
    return true;
}
