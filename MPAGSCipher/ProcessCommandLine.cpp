#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"

#include <iostream>
#include <istream>
#include <fstream>

int processCommandLine(const int argc, char* argv[],
	CommandLineArguments& args)
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
            -i <filename>: Prints input filename <file>.
            -o <filename>: Prints output filename <file>.
            -e <key>       Encrypt input text with key value <key>
                           Key must be in the range [0, 25]
            -d <key>       Decrypt input text with key value <key>
                           Key must be in the range [0, 25]
            <other>:       Prints <other>.
   */
   args.inputFilename = "";
   args.outputFilename = "";
   args.key = 0;
   args.encrypt = true;
   args.helpRequested = false;
   args.versionRequested = false;

   for(int i = 1; i < argc; ++i)
   {
      std::string argStr{argv[i]};
      if(argStr == "-h" || argStr == "--help")
      {
         args.helpRequested = true;
      }
      else if(argStr == "--version")
      {
         args.versionRequested = true;
      }
      else if(argStr == "-i")
      {
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            args.inputFilename = argv[i + 1];
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected argument after " << argv[i] <<
               ". Program exiting." << std::endl;
            return 1;
         }
      }
      else if(argStr == "-o")
      {
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            args.outputFilename = argv[i + 1];
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected argument after " << argv[i] <<
               ". Program exiting." << std::endl;
            return 1;
         }
      }
      else if(argStr == "-e")
      {  // Encryption requested
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            args.encrypt = true;
            args.key = std::atoi(argv[i + 1]);
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected key after " << argv[i] <<
               ". Program exiting." << std::endl;
            return 1;
         }
      }
      else if(argStr == "-d")
      {  // Encryption requested
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            args.encrypt = false;
            args.key = std::atoi(argv[i + 1]);
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected key after " << argv[i] <<
               ". Program exiting." << std::endl;
            return 1;
         }
      }
      else
      {
         std::cout << "Error: Unknown argument '" << argStr << "'\n";
         return 1;
      }
   }
   
   if(args.helpRequested)
   {
      std::cout << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
         << "Encrypts/Decrypts input alphanumeric text\n\n"
         << "Available options:\n"
         << "   -h | --help      Print this help message and exit\n"
         << "   --version        Print version information and exit\n"
         << "   -i <filename>    Read text to be processed from <filename>\n"
         << "                    Standard input will be used if not supplied\n"
         << "   -o <filename>    Write processed text to <filename>\n"
         << "                    Standard output will be used if not supplied\n"
         << "   -e <key>         Encrypt input text with key value <key>\n"
         << "                    Key must be in the range [0, 25]\n"
         << "   -d <key>         Decrypt input text with key value <key>\n"
         << "                    Key must be in the range [0, 25]\n";
      return 0;
   }
   else if(args.versionRequested)
   {
      std::cout << "mpags-cipher Version 0.1.0" << std::endl;
      return 0;
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

   if(args.key < 0 || args.key > 25)
   {
      std::cout << "Error: Key must be in range [0, 25]" << std::endl;
      return 1;
   }

   CaesarCipher(args.inputFilename.empty() ? std::cin : inputStream,
      args.outputFilename.empty() ? std::cout : outputStream, args.key,
      args.encrypt);

   return 0;
}
