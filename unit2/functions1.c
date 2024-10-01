#include <string.h> //lets me use strlen
#include <cs50.h> //lets me use bool


bool my_isdigit(char ch);
bool my_islower(char ch);
bool my_isupper(char ch);  // These are function declarations.
bool my_isalpha(char ch);  // They let the compiler know that there
char my_tolower(char ch);  // are user made functions below.
char my_toupper(char ch);  // The ctype library already has these functions.


int main(void)
{

}



// Takes a character, checks if it is a digit, returns true or false
bool my_isdigit(char ch)
{
    string digits = "0123456789";  //all the digits.  A string is a list of chars.
    int num_of_digits = strlen(digits); // the number of digits
    for(int i = 0; i < num_of_digits; i = i + 1)
    {
        if (digits[i] == ch)
        {
            return true;
        }
    }
    return false;
}


// Takes a character, checks if it is a lower case, returns true or false
bool my_islower(char ch)
{
    string lower_case = "abcdefghijklmnopqrstuvwxyz"; //all lower case letters
    int num_lower_case = strlen(lower_case); //number of lower case letters
    for(int i = 0; i < num_lower_case; i = i + 1)
    {
        if (lower_case[i] == ch)
        {
            return true;
        }
    }
    return false;
}


// Takes a character, checks if it is an upper case, returns true or false
bool my_isupper(char ch)
{
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //all upper case letters
    int num_upper_case = strlen(upper_case); //number of upper case letters
        for(int i = 0; i < num_upper_case; i = i + 1)
    {
        if (upper_case[i] == ch)
        {
            return true;
        }
    }
    return false;
}


// Takes a character, checks if it is alphabetical, returns true or false
bool my_isalpha(char ch)
{
    return my_isupper(ch) || my_islower(ch);
}


// Takes a character, returns lower case alphabetical or the origonal char
char my_tolower(char ch)
{
    if (!my_isupper(ch))
    {
        return ch;
    }
    string lower_case = "abcdefghijklmnopqrstuvwxyz"; //all lower case letters
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //all upper case letters
    int num_letters = strlen(upper_case);
    int index;
    for (int i = 0; i < num_letters; i = i + 1)
    {
        if (ch == upper_case[i])
        {
            index = i;
        }
    }
    return lower_case[index];
}



// Takes a character, returns lower case alphabetical or the origonal char
char my_toupper(char ch)
{
    if (!my_islower(ch))
    {
        return ch;
    }
    string lower_case = "abcdefghijklmnopqrstuvwxyz"; //all lower case letters
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //all upper case letters
    int num_letters = strlen(upper_case);
    int index;
    for (int i = 0; i < num_letters; i = i + 1)
    {
        if (ch == lower_case[i])
        {
            index = i;
        }
    }
    return upper_case[index];
}

