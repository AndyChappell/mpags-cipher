#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

#include <algorithm>

VigenereCipher::VigenereCipher()
{
}

void VigenereCipher::setKey(const std::string& key)
{
   this->key_ = key;
   // Make sure the key is upper case
   std::transform(this->key_.begin(), this->key_.end(),
      this->key_.begin(), (int (*)(int))std::toupper);
}

std::string VigenereCipher::encode(const std::string& plaintext) const
{
   std::string oneTimeKey{};
   
   if(this->key_.size() >= plaintext.size())
   {
      oneTimeKey = this->key_.substr(0, plaintext.size());
   }
   else
   {
      int reps = plaintext.size() / this->key_.size();
      int rem = plaintext.size() % this->key_.size();
      
      for(int i = 0; i < reps; ++i)
      {
         oneTimeKey.append(this->key_);
      }
      oneTimeKey.append(this->key_.substr(0, rem));
   }
   
   std::string ciphertext{};
   CaesarCipher cipher{"0"};
   for(unsigned int i = 0; i < plaintext.size(); ++i)
   {
      cipher.setKey(std::to_string(1 + oneTimeKey[i] - 'A'));
      ciphertext.append(cipher.encode(std::string{plaintext[i]}));
   }

   return ciphertext;
}

std::string VigenereCipher::decode(const std::string& ciphertext) const
{
   std::string oneTimeKey{};
   
   if(this->key_.size() >= ciphertext.size())
   {
      oneTimeKey = this->key_.substr(0, ciphertext.size());
   }
   else
   {
      int reps = ciphertext.size() / this->key_.size();
      int rem = ciphertext.size() % this->key_.size();
      
      for(int i = 0; i < reps; ++i)
      {
         oneTimeKey.append(this->key_);
      }
      oneTimeKey.append(this->key_.substr(0, rem));
   }
   
   std::string plaintext{};
   CaesarCipher cipher{"0"};
   for(unsigned int i = 0; i < ciphertext.size(); ++i)
   {
      cipher.setKey(std::to_string(1 + oneTimeKey[i] - 'A'));
      plaintext.append(cipher.decode(std::string{ciphertext[i]}));
   }

   return plaintext;
}
