// mpags-cipher.cpp
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"
#include "IOProcessing.hpp"

#include <iostream>
#include <istream>
#include <fstream>

int main(int argc, char* argv[])
{
   //testCipher();
   CommandLineArguments args{false, false, false, "", "", "", ""};
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
     
   std::string text = processInput(
      args.inputFilename.empty() ? std::cin : inputStream);

   std::string input{};
   for(char c : text)
   {
	   input.append(transformChar(c));
   }

   if(args.cipher == "caesar")
   {
      CaesarCipher cipher{};
      cipher.setKey(args.key);
      if(args.encrypt)
      {
         std::string ciphertext = cipher.encode(input);
         processOutput(
            args.outputFilename.empty() ? std::cout : outputStream,
            ciphertext);
      }
      else
      {
         std::string plaintext = cipher.decode(input);
         processOutput(
            args.outputFilename.empty() ? std::cout : outputStream,
            plaintext);      
      }
   }
   else if(args.cipher == "playfair")
   {
      PlayfairCipher cipher{};
      cipher.setKey(args.key);
      if(args.encrypt)
      {
         std::string ciphertext = cipher.encode(input);
         processOutput(
            args.outputFilename.empty() ? std::cout : outputStream,
            ciphertext);
      }
      else
      {
         std::string plaintext = cipher.decode(input);
         processOutput(
            args.outputFilename.empty() ? std::cout : outputStream,
            plaintext);
      }
   }
   else if(args.cipher == "vigenere")
   {
      VigenereCipher cipher{};
      cipher.setKey(args.key);
      if(args.encrypt)
      {
         std::string ciphertext = cipher.encode(input);
         processOutput(
            args.outputFilename.empty() ? std::cout : outputStream,
            ciphertext);
      }
      else
      {
         std::string plaintext = cipher.decode(input);
         processOutput(
            args.outputFilename.empty() ? std::cout : outputStream,
            plaintext);
      }
   }
  
   return 0;
}

