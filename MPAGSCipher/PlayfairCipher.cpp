#include "PlayfairCipher.hpp"

#include <algorithm>
#include <cctype>
#include <map>

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
   std::transform(this->key_.begin(), this->key_.end(),
      this->key_.begin(), [](int c){ return c == 'J' ? 'I' : c; });

   // Remove duplicated letters
   std::map<int, bool> charsUsed{};
   auto func = [&](int c)
   {
      auto iter = charsUsed.find(c);
      if(iter == charsUsed.end())
      {
         charsUsed[c] = true;
         return false;
      }
      return true;
   };
   this->key_.erase(std::remove_if(this->key_.begin(), this->key_.end(),
      func), this->key_.end());

   // Store the coords of each letter and the letter at each coord
   this->chars_ = std::map<std::pair<int, int>, char>();
   this->coords_ = std::map<char, std::pair<int, int>>();
   for(int r = 0; r < NumRows; ++r)
   {
      int base = r * NumColumns;
      for(int c = 0; c < NumColumns; ++c)
      {
         int index = base + c;
         char letter = this->key_[index];
         std::pair<int, int> coords{r, c};
         this->chars_[coords] = letter;
         this->coords_[letter] = coords;
      }
   }
}

std::string PlayfairCipher::encode(const std::string& plaintext) const
{
   std::cout << "Plain: " << plaintext << std::endl;
   
   // Make sure input is valid
   // (Upper case, only chars and J -> I)
   std::string input{plaintext};
   std::transform(input.begin(), input.end(),
      input.begin(), (int (*)(int))std::toupper);
   std::transform(input.begin(), input.end(),
      input.begin(), [](int c){ return c == 'J' ? 'I' : c; });
      
   std::cout << "J -> I: " << input << std::endl;
   
   // Find repeated chars and add an X
   for(unsigned int i = 0; i < input.size() - 1; ++i)
   {
      if(input[i] == input[i + 1])
      {
         input = input.insert(i + 1, "X");
         ++i;
      }
   }
   
   std::cout << "Repeats: " << input << std::endl;
   
   // if the size is odd, add a trailing Z
   if(input.size() % 2)
   {
      input = input.append("Z");
   }
   
   std::cout << "Z?: " << input << std::endl;

   // Loop over the input in Digraphs

   // Find the coords in the grid for each digraph
   // For each Digraph, decide how to encrypt
   std::string ciphertext{""};
   for(unsigned int i = 0; i < input.size(); i += 2)
   {
      char letter1 = input[i];
      char letter2 = input[i + 1];
      auto coords1 = this->coords_.at(letter1);
      auto coords2 = this->coords_.at(letter2);
      
      if(coords1.first == coords2.first)
      {  // Same row
         std::pair<int, int> cipherCoord1{coords1.first,
            (coords1.second + 1) % NumColumns};
         std::pair<int, int> cipherCoord2{coords2.first,
            (coords2.second + 1) % NumColumns};
         
         std::string cipherChar1 = std::string{
            this->chars_.at(cipherCoord1)};
         std::string cipherChar2 = std::string{
            this->chars_.at(cipherCoord2)};
         ciphertext = ciphertext.append(cipherChar1 + cipherChar2);
      }
      else if(coords1.second == coords2.second)
      {  // Same column
         std::pair<int, int> cipherCoord1{(coords1.first + 1) % NumRows,
            coords1.second};
         std::pair<int, int> cipherCoord2{(coords2.first + 1) % NumRows,
            coords2.second};
                  
         std::string cipherChar1 = std::string{
            this->chars_.at(cipherCoord1)};
         std::string cipherChar2 = std::string{
            this->chars_.at(cipherCoord2)};
         ciphertext = ciphertext.append(cipherChar1 + cipherChar2);
      }
      else
      {  // Coords form a rectangle
         std::pair<int, int> cipherCoord1{coords1.first, coords2.second};
         std::pair<int, int> cipherCoord2{coords2.first, coords1.second};
                 
         std::string cipherChar1 = std::string{
            this->chars_.at(cipherCoord1)};
         std::string cipherChar2 = std::string{
            this->chars_.at(cipherCoord2)};
         ciphertext = ciphertext.append(cipherChar1 + cipherChar2);
      }
   }
   
   std::cout << "Cipher: " << ciphertext << std::endl;

   return ciphertext;
}
