#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //create a list (or array)
    char char_list[9]; //This would create space for 9 characters
    char char_list2[] = {'c','y','8','*','!'}; //read or write mode
    char char_list3[] = "Hello my name is Mr. Maresh" //read only mode
    int n = 50;
    char char_list4[n];


    //using loops to populate lists
    int num = 6;
    char char_list5[num];
    for (int i = 0; i < num; i = i + 1)
    {
        // i = 0, 1, 2, 3, 4, 5
        // index = 0, 1, 2, 3, 4, 5
        char_list5[i] = get_char("Char: ");
    }

    // char_list5 = {'H', 'K', '8', '!', '*', 'j'}
    //Example of using a loop to access each char to print out
    for (int j = 0; j < num; j = j + 1)
    {
        //char ch = 'J'
        printf("%c  ", char_list5[j]);
    }


    string text = "Hello! It is a nice day!"
    //text[0] = 'H'

}
