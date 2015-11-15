#include "PlayfairCipher.hpp"

#include <algorithm>
#include <cctype>

PlayfairCipher::PlayfairCipher()
{
}

void PlayfairCipher::setKey(const std::string& key)
{
   // store the original key
   this->key_ = key;
   // Make sure the key is upper case
   std::transform(this->key_.begin(), this->key_.end(),
      this->key_.begin(), (int (*)(int))std::toupper);
      
   // Append the alphabet
   this->key_.append("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
   
   // Remove non-alpha characters
   this->key_.erase(std::remove_if(this->key_.begin(), this->key_.end(),
      std::not1(std::ptr_fun((int (*)(int))std::isalpha))),
      this->key_.end());
      
   // Change J -> I

   // Remove duplicated letters

   // Store the coords of each letter

   // Store the playfair cihper key map

}

std::string PlayfairCipher::encode(const std::string& plaintext) const
{
   // Make sure input is valid
   // (Upper case, only chars and J -> I)
   // Find repeated chars and add an X

   // if the size is odd, add a trailing Z

   // Loop over the input in Digraphs

   // Find the coords in the grid for each digraph
   // For each Digraph, decide how to encrypt

   // return the text

   std::cout << "TODO: Encode plaintext: " << plaintext << std::endl;

   return plaintext;
}
