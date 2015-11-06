#include "CaesarCipher.hpp"

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
