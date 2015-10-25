// mpags-cipher.cpp

#include <iostream>
#include <string>

int main()
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

  // No requirement to return from main, but we do so for clarity and
  // consistency with other functions.
  return 0;
}
