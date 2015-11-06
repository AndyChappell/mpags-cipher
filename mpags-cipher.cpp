// mpags-cipher.cpp
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"

#include <iostream>
#include <istream>
#include <fstream>

int main(int argc, char* argv[])
{
   //testCipher();
   CommandLineArguments args{false, false, false, 0, "", ""};
   int retCode = processCommandLine(argc, argv, args);
   
   if(retCode != 0)
   {
	   return retCode;
   }
   
   // Use standard input by default
   std::ifstream inputStream{};
   if(!args.inputFilename.empty())
   {  // Try to use the input file
      inputStream.open(args.inputFilename);
      if(!inputStream.good())
      {
         std::cout << "Error: Could not open " << args.inputFilename << std::endl;
         return 1;
      }
   }

   std::ofstream outputStream{};
   if(!args.outputFilename.empty())
   {  // Try to use the output file
      outputStream.open(args.outputFilename);
      if(!outputStream.good())
      {
         std::cout << "Error: Could not open " << args.outputFilename << std::endl;
         return 1;
      }
   }
   
   caesarCipher(args.inputFilename.empty() ? std::cin : inputStream,
      args.outputFilename.empty() ? std::cout : outputStream, args.key,
      args.encrypt);
   
   return 0;
}

