// mpags-cipher.cpp
#include "TransformChar.hpp"

#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include <sstream>

template <typename T, typename U>
void transliterate(T& inStream, U& outStream);
int processCommandLine(const int argc, char* argv[]);
template <typename T, typename U>
void CaesarCipher(T& inStream, U& outStream, const int k, const bool encrypt = true);
void testCipher();

int main(int argc, char* argv[])
{
   //testCipher();
   return processCommandLine(argc, argv);
}

int processCommandLine(const int argc, char* argv[])
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
   std::string inputFilename{""};
   std::string outputFilename{""};
   int key{0};
   bool encrypt{true};

   for(int i = 1; i < argc; ++i)
   {
      std::string argStr{argv[i]};
      if(argStr == "-h" || argStr == "--help")
      {
         std::cout << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
            << "Encrypts/Decrypts input alphanumeric text\n\n"
            << "Available options:\n"
            << "   -h | --help      Print this help message and exit\n"
            << "   --version        Print version information\n"
            << "   -i <filename>    Read text to be processed from <filename>\n"
            << "                    Standard input will be used if not supplied\n"
            << "   -o <filename>    Write processed text to <filename>\n"
            << "                    Standard output will be used if not supplied\n"
            << "   -e <key>         Encrypt input text with key value <key>\n"
            << "                    Key must be in the range [0, 25]\n"
            << "   -d <key>         Decrypt input text with key value <key>\n"
            << "                    Key must be in the range [0, 25]\n";
      }
      else if(argStr == "--version")
      {
         std::cout << "mpags-cipher Version 0.1.0" << std::endl;
      }
      else if(argStr == "-i")
      {
         if(i + 1 < argc && argv[i + 1][0] != '-')
         {  // Check that the next argument exists and is not a flag or option
            inputFilename = argv[i + 1];
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
            outputFilename = argv[i + 1];
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
            encrypt = true;
            key = std::atoi(argv[i + 1]);
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
            encrypt = false;
            key = std::atoi(argv[i + 1]);
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

   // Use standard input by default
   std::ifstream inputStream{};
   if(!inputFilename.empty())
   {  // Try to use the input file
      inputStream.open(inputFilename);
      if(!inputStream.good())
      {
         std::cout << "Error: Could not open " << inputFilename << std::endl;
         return 1;
      }
   }

   std::ofstream outputStream{};
   if(!outputFilename.empty())
   {  // Try to use the output file
      outputStream.open(outputFilename);
      if(!outputStream.good())
      {
         std::cout << "Error: Could not open " << outputFilename << std::endl;
         return 1;
      }
   }

   if(key < 0 || key > 25)
   {
      std::cout << "Error: Key must be in range [0, 25]" << std::endl;
      return 1;
   }

   //transliterate(inputFilename.empty() ? std::cin : inputStream, outputFilename.empty() ? std::cout : outputStream);
   CaesarCipher(inputFilename.empty() ? std::cin : inputStream,
      outputFilename.empty() ? std::cout : outputStream, key, encrypt);

   return 0;
}


template <typename T, typename U>
void transliterate(T& inStream, U& outStream)
{
   /*
      Applies transliteration.

      Lowercase characters are converted to uppercase. Digits are converted to
      alphabetical equivalents and all other symbols are ignored.

      T& inStream:   The input stream from which input should be read
      U& outStream:  The output stream to which output should be written
   */
   char input{'\0'};
   while(inStream >> input)
   {  // Loop until the user presses enter and Ctrl-D
      outStream << transformChar(input);
   }
}

template <typename T, typename U>
void CaesarCipher(T& inStream, U& outStream, const int k, const bool encrypt)
{
   /*
      Applies Caesar Cipher encryption and decryption.

      T& inStream:   The input stream from which input should be read
      U& outStream:  The output stream to which output should be written
      const int k:   The key for the cipher ([0, 25]).
      const bool encrypt:  The mode of execution for the cipher:
         Options:
            true  Encryption
            false Decryption
   */
   const int NUM_CHAR{26};
   char input{'\0'};
   int shift = encrypt ? k : -k;
   while(inStream >> input)
   {
      std::string transStr{transformChar(input)};
      for(char c : transStr)
      {
         int cipherVal{((c - 'A') + shift) % NUM_CHAR};
         if(cipherVal < 0)
         {
            cipherVal += NUM_CHAR;
         }
         char cipherChar = 'A' + cipherVal;
         outStream << cipherChar;
      }
   }
}

void testCipher()
{
   std::istringstream plainstream("HELLOWORLD");
   std::ostringstream cipherstream{""};

   CaesarCipher(plainstream, cipherstream, 5, true);

   std::istringstream codestream{cipherstream.str()};
   std::ostringstream outputstream{""};

   CaesarCipher(codestream, outputstream, 5, false);

   std::string originalText{plainstream.str()};
   std::string decodedText{outputstream.str()};
   std::cout << "Original and encrypt-decrypt text equal: " <<
      ((originalText == decodedText) == 1 ? "True" : "False") << std::endl;
}