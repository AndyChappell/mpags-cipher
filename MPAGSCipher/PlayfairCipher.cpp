#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher()
{
}

void PlayfairCipher::setKey(const std::string& key)
{
   // store the original key
   this->key_ = key;
   // Append the alphabet

   // Make sure the key is upper case
   // Remove non-alpha characters
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
