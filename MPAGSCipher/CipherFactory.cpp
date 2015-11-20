#include "CipherFactory.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherTypes& type)
{
   switch(type)
   {
      case CipherTypes::CAESAR:
         return std::make_unique<CaesarCipher>();
      case CipherTypes::PLAYFAIR:
         return std::make_unique<PlayfairCipher>();
      case CipherTypes::VIGENERE:
         return std::make_unique<VigenereCipher>();
      default:
         return std::make_unique<CaesarCipher>();
   }
}
