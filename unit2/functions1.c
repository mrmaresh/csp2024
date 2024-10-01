#include <stdio.h>
#include <string.h> //lets me use strlen
#include <cs50.h> //lets me use bool


bool my_isdigit(char ch);
bool my_islower(char ch);
bool my_isupper(char ch);  //These are function declarations.
bool my_isalpha(char ch);  //They let the compiler know that there
char my_tolower(char ch);  //are user made functions below.
char my_toupper(char ch);


int main(void)
{
    
}



//Takes a character, checks if it is a digit, returns true or false
bool my_isdigit(char ch)
{
    string digits = "0123456789";  //all the digits.  A string is a list of chars.
    int num_of_digits = strlen(digits); // the number of digits
}


//Takes a character, checks if it is a lower case, returns true or false
bool my_islower(char ch)
{
    string lower_case = "abcdefghijklmnopqrstuvwxyz"; //all lower case letters
    int num_lower_case = strlen(lower_case); //number of lower case letters
}


//Takes a character, checks if it is an upper case, returns true or false
bool my_isupper(char ch)
{
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //all upper case letters
    int num_upper_case = strlen(upper_case); //number of upper case letters
}


//Takes a character, checks if it is alphabetical, returns true or false
bool my_isalpha(char ch)
{

}


//Takes a character, returns lower case alphabetical or the origonal char
char my_tolower(char ch)
{

}



//Takes a character, returns lower case alphabetical or the origonal char
char my_toupper(char ch)
{

}

