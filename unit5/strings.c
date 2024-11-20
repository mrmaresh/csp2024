#include <cs50.h>
#include <stdio.h>

int StrLen(string string1);

int main(void){
    string string1 = get_string("String1: ");
    int length = StrLen(string1);
    printf("The length of %s is %i\n", string1, length);
    char string2[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    
}


int StrLen(string string1){
    int num = 0;
    for(int i = 0; string1[i] != '\0'; i = i + 1){
        num = num + 1;
    }
    return num;
}
