/*
Fibonacci Sequence
f(1) = 1
f(2) = 1
f(n) = f(n-1) + f(n-2)
*/

#include <stdio.h>
#include <cs50.h>

long findFibonacci(int n);

int main(void){
    int n = get_int("n: ");
    long fib = findFibonacci(n);
    printf("f(%i) = %li\n", n, fib);
}

long findFibonacci(int n){
   //Base Case
   if (n == 1 || n == 2){
    return 1;
   }

   return findFibonacci(n - 1) + findFibonacci(n - 2);
}
