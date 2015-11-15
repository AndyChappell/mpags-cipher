#include "ProcessCommandLine.hpp"

#include <cstdlib>
#include <iostream>

int processCommandLine(const int argc, char* argv[],
   CommandLineArguments& args)
{
   /*
      Processes command line arguments.

      Non-flag and non-option arguments are printed to the terminal, with flags
      and options printing relevant information to the terminal.

      const int argc:            A count of the number of arguments
                                 passed to the program
      char* argv[]:              The list of arguments passed to the
                                 program
      CommandLineArguments args: A structure to store the commandline
                                 arguments
         Options:
            -h | --help:         Prints usage information.
            -- version:          Prints version information.
            -i <filename>:       Prints input filename <file>.
            -o <filename>:       Prints output filename <file>.
            -e <key>             Encrypt input text with key value <key>
                                 Key must be in the range [0, 25].
            -d <key>             Decrypt input text with key value <key>
                                 Key must be in the range [0, 25].
            --cipher <cipher>    Sets the encryption/decryption cipher
                                 Key must take one of the values:
                                 (caesar, playfair)
   */
   args.inputFilename = "";
   args.outputFilename = "";
   args.key = "";
   args.encrypt = true;
   args.helpRequested = false;
   args.versionRequested = false;
   args.cipher = "";

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
            return 2;
         }
      }
      else if(argStr == "-e")
      {  // Encryption requested
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            args.encrypt = true;
            args.key = argv[i + 1];
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected key after " << argv[i] <<
               ". Program exiting." << std::endl;
            return 3;
         }
      }
      else if(argStr == "-d")
      {  // Encryption requested
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            args.encrypt = false;
            args.key = argv[i + 1];
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected key after " << argv[i] <<
               ". Program exiting." << std::endl;
            return 4;
         }
      }
      else if(argStr == "--cipher")
      {  // Cipher specified
         if(i + 1 < argc && (std::string(argv[i + 1]) == "caesar" ||
            std::string(argv[i + 1]) == "playfair"))
         {  // Check that the next argument exists and is not a flag or option
            args.cipher = std::string(argv[i + 1]);
            ++i;
         }
         else
         {  // Missing argument
            std::cout << "Error: Expected cipher name after "
               << argv[i] << ".\n\n"
               << "Available options:\n"
               << "   caesar\n"
               << "   playfair\n" << std::endl;
            return 6;
         }
      }
      else
      {
         std::cout << "Error: Unknown argument '" << argStr << "'\n";
         return 5;
      }
   }

   if(args.helpRequested)
   {
      std::cout << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
         << "Encrypts/Decrypts input alphanumeric text\n\n"
         << "Available options:\n"
         << "   -h | --help         Print this help message and exit\n"
         << "   --version           Print version information and exit\n"
         << "   -i <filename>       Read text to be processed from <filename>\n"
         << "                       Standard input will be used if not supplied\n"
         << "   -o <filename>       Write processed text to <filename>\n"
         << "                       Standard output will be used if not supplied\n"
         << "   -e <key>            Encrypt input text with key value <key>\n"
         << "                       Options:\n"
         << "                          Range [1, 25] for Caesar cipher\n"
         << "                          Upto 25 alphabetic character string for Playfair cipher\n"
         << "   -d <key>            Decrypt input text with key value <key>\n"
         << "                       Options:\n"
         << "                          Range [1, 25] for Caesar cipher\n"
         << "                          Upto 25 alphabetic character string for Playfair cipher\n"
         << "   --cipher <cipher>   Sets the encryption/decryption cipher\n"
         << "                       Key must take one of the values:\n"
         << "                       (caesar, playfair)\n";
      return 0;
   }
   else if(args.versionRequested)
   {
      std::cout << "mpags-cipher Version 0.1.0" << std::endl;
      return 0;
   }

   if(args.cipher == "caesar")
   {
      for(auto c : args.key)
      {
         if(!std::isdigit(c))
         {
            std::cout << "Error: Key must be in range [1, 25]" << std::endl;
            return 2;
         }
      }
      int key = std::atoi(args.key.c_str());
      if(key < 1 || key > 25)
      {
         std::cout << "Error: Key must be in range [1, 25]" << std::endl;
         return 2;
      }
   }
   else if(args.cipher == "playfair")
   {
      if(args.key.length() > 25)
      {
         std::cout << "Error: Maximum key length is 25 characters" << std::endl;
         return 7;
      }
   }

   return 0;
}
