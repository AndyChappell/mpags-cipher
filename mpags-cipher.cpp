// mpags-cipher.cpp
#include "TransformChar.hpp"

#include <iostream>

void day2Ex1();
void processCommandLine(const int argc, char* argv[]);

int main(int argc, char* argv[])
{
   //day2Ex1();
   processCommandLine(argc, argv);

   return 0;
}

void processCommandLine(const int argc, char* argv[])
{
   /*
      Processes command line arguments.

      Non-flag and non-option arguments are printed to the terminal, with flags
      and options printing relevant information to the terminal.

      const int argc: A count of the number of arguments passed to the program
      char* argv[]: The list of arguments passed to the program
         Options:
            -h | --help:   Prints usage information.
            -- version:    Prints version information.
            -i <file>:     Prints input filename <file>.
            -o <file>:     Prints output filename <file>.
            <other>:       Prints <other>.
   */
   for(int i = 0; i < argc; ++i)
   {
      std::string arg = argv[i];
      if(arg == "-h" || arg == "--help")
      {
         std::cout << "Usage: mpags-cipher [arguments]" << std::endl;
         std::cout << "Please provide a list of arguments which will be printed"
            << " out by the program." << std::endl;

         continue;
      }
      else if(arg == "--version")
      {
         std::cout << "mpags-cipher Version 0.1.0" << std::endl;

         continue;
      }
      else if(arg == "-i" || arg == "-o")
      {
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            std::cout << "Filename: " << argv[i + 1] << std::endl;
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected argument after " << argv[i] <<
               ". Program exiting." << std::endl;
            return;
         }
         continue;
      }
      std::cout << arg << std::endl;
   }
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
