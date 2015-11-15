#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher()
{
}

void PlayfairCipher::setKey(const std::string& key)
{
   this->key_ = key;
}

std::string PlayfairCipher::encode(const std::string& plaintext) const
{
   std::cout << "TODO: Encode plaintext: " << plaintext << std::endl;

   return "";
}
