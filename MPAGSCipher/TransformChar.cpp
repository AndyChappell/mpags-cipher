#include "TransformChar.hpp"

#include <iostream>
#include <cctype>
#include <sstream>

std::string transformChar(const char input)
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

std::string transformString(const std::string& input)
{
   /*
    * Transliterates an input string into a purely alphabetical
    * string.
    *
    * Alpha characters are converted to uppercase, numeric
    * characters are replaced by their equivalent words and other
    * characters are omitted.
    *
    * std::string input: The string to be transliterated
    *
    * return: The transliterated string
   */
   std::ostringstream transliterationStream{""};
   for(char c : input)
   {
	   std::string transString = transformChar(c);
	   transliterationStream << transString;
   }
   
   return transliterationStream.str();
}
