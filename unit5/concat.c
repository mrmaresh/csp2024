#include <cs50.h>
#include <stdio.h>
#include <string.h>

void concat(char newString[], string string1, string string2);

int main(void){
    string string1 = get_string("String 1: ");  //good
    string string2 = get_string("String 2: ");  //bye
    int len1 = strlen(string1);
    int len2 = strlen(string2);
    char newString[len1 + len2 + 1];
    concat(newString, string1, string2);
    printf("The concatinated string is %s\n", newString);
}

void concat(char newString[], string string1, string string2){
    // newString[] = {g, o, o, d, b, y, e, \0}
    int len1 = strlen(string1);
    for (int i = 0; i < len1; i = i + 1) {
        newString[i] = string1[i]; //good
    }

    int len2 = strlen(string2);
    for (int j = 0; j < len2; j = j + 1) {
        newString[j + len1] = string2[j];
    }

    newString[len1 + len2] = '\0';
}
