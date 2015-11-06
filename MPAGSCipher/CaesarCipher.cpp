#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(int key) : key_{key}
{
}

std::string CaesarCipher::encode(const std::string& plaintext) const
{
   /*
      Encodes the string provided.

      const std::string& plaintext:	The plaintext to encode
      return std:string				The ciphertext
   */
   const int NUM_CHAR{26};
   std::ostringstream cipherStream{""};
   std::string transString{transformString(plaintext)};
   for(char c : transString)
   {
      int cipherVal{((c - 'A') + key_) % NUM_CHAR};
      if(cipherVal < 0)
      {
         cipherVal += NUM_CHAR;
      }
      char cipherChar = 'A' + cipherVal;
      cipherStream << cipherChar;
   }

   return cipherStream.str();
}

void testCipher()
{
   std::istringstream plainstream("HELLOWORLD");
   std::ostringstream cipherstream{""};

   caesarCipher(plainstream, cipherstream, 5, true);

   std::istringstream codestream{cipherstream.str()};
   std::ostringstream outputstream{""};

   caesarCipher(codestream, outputstream, 5, false);

   std::string originalText{plainstream.str()};
   std::string decodedText{outputstream.str()};
   std::cout << "Original and encrypt-decrypt text equal: " <<
      ((originalText == decodedText) == 1 ? "True" : "False") << std::endl;
}
