// mpags-cipher.cpp

#include <iostream>
#include <string>
#include <cctype>

void ex2();
void ex3();
std::string transformChar(char input);

int main()
{
   ex3();

   // No requirement to return from main, but we do so for clarity and
   // consistency with other functions.
   return 0;
}

void ex2()
{
   // This is a comment
   /* This is a
    * Multiline comment */
   using namespace std;

   cout << "Hello World!\n";

   // Create, modify and output int
   int myInt1{4};
   myInt1 = 7;
   cout << myInt1 << endl;

   // Create and output a constant double
   const double myDouble1{8.4};
   cout << myDouble1 << endl;

   // Output the product of the double and int
   cout << myInt1 * myDouble1 << endl;

   // Attempt to initialise an int from a double
   int myInt2{myDouble1};

   // Create a bool variable using the auto keyword
   auto myBool = true;

   // Divide a double and an int and then two ints
   cout << "Double / Int: " << myDouble1 / myInt1 << " Int / Int: " <<
      myInt1 / myInt2 << endl;

   // Create and initialise a string variable
   string myStr{"Test string"};

   // Create a char using auto and assign a letter from the string to it
   auto myChar = myStr[2];
   cout << "The character: " << myChar << endl;
}

void ex3()
{
   char input{'\0'};
   while(std::cin >> input)
   {  // Loop until the user presses enter and Ctrl-D
      std::cout << transformChar(input);
   }
}

/*
   Takes alphanumeric characters and converts them to uppercase, with numeric
   digits replaced by their equivalent words.
*/
std::string transformChar(char input)
{
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
            if(islower(input))
               return std::string(1, char(toupper(input)));
            else
               return std::string(1, input);
         }
         else
            return "";
   }
}
