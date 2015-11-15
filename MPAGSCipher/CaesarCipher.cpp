#include "CaesarCipher.hpp"

CaesarCipher::CaesarCipher(const std::string& key) : key_{std::atoi(key.c_str())}
{
}

std::string CaesarCipher::encode(const std::string& plaintext) const
{
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

std::string CaesarCipher::decode(const std::string& ciphertext) const
{
   const int NUM_CHAR{26};
   std::ostringstream plainStream{""};
   std::string transString{transformString(ciphertext)};
   for(char c : transString)
   {
      int plainVal{((c - 'A') - key_) % NUM_CHAR};
      if(plainVal < 0)
      {
         plainVal += NUM_CHAR;
      }
      char plainChar = 'A' + plainVal;
      plainStream << plainChar;
   }

   return plainStream.str();
}
