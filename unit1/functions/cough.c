#include <stdio.h>

void cough (int num);
int main(void)
{
    cough(6);
}


void cough (int num)
{
    for (int counter = 0; counter < num; counter = counter + 1)
    {
        printf("cough\n");
    }
}
