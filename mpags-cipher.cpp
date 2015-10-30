// mpags-cipher.cpp

#include <iostream>
#include <string>
#include <cctype>

void day2Ex1();
std::string transformChar(char input);

int main()
{
   day2Ex1();

   return 0;
}

void day2Ex1()
{
	/*
    * Solution for Exercise 1 of Day 2.
    * */
   char input{'\0'};
   while(std::cin >> input)
   {  // Loop until the user presses enter and Ctrl-D
      std::cout << transformChar(input);
   }
}

std::string transformChar(char input)
{
   /*
    * Transliterates an input character into a purely alphabetical
    * string.
    * 
    * Alpha characters are converted to uppercase, numeric
    * characters are replaced by their equivalent words and other
    * characters are omitted.
    * 
    * char input: The character to be transliterated
    * 
    * return: The transliterated string
   */
   switch(input)
   {
      case '1':
         return "ONE";
      case '2':
         return "TWO";
      case '3':
         return "THREE";
      case '4':
         return "FOUR";
      case '5':
         return "FIVE";
      case '6':
         return "SIX";
      case '7':
         return "SEVEN";
      case '8':
         return "EIGHT";
      case '9':
         return "NINE";
      case '0':
         return "ZERO";
      default:
         if(isalpha(input))
         {
            std::string s{""};
            return std::string(1, char(toupper(input)));
         }
         else
         {
            return "";
         }
   }
}
