#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "TransformChar.hpp"

#include <string>
#include <iostream>
#include <sstream>

/**
	CaesarCipher provides encoding (decoding) of plaintext (ciphertext)
	using the Caesar Cipher.
 */
class CaesarCipher
{
	public:
	/**
		Create a CaesarCipher with a specified key.

		\param key The key to use for encoding/decoding
	 */
	CaesarCipher(int key);
	
	/**
		Encodes specified plaintext.
		
		\param plaintext The plaintext to encode
		\return The encoded ciphertext
	 */
	std::string encode(const std::string& plaintext) const;
	
	private:
	int key_;	///< The key to use for encoding/decoding
};

template <typename T, typename U>
void caesarCipher(T& inStream, U& outStream, const int k,
	const bool encrypt = true)
{
   /*
      Applies Caesar Cipher encryption and decryption.

      T& inStream:   The input stream from which input should be read
      U& outStream:  The output stream to which output should be written
      const int k:   The key for the cipher ([0, 25]).
      const bool encrypt:  The mode of execution for the cipher:
         Options:
            true  Encryption
            false Decryption
   */
   const int NUM_CHAR{26};
   char input{'\0'};
   int shift = encrypt ? k : -k;
   while(inStream >> input)
   {
      std::string transStr{transformChar(input)};
      for(char c : transStr)
      {
         int cipherVal{((c - 'A') + shift) % NUM_CHAR};
         if(cipherVal < 0)
         {
            cipherVal += NUM_CHAR;
         }
         char cipherChar = 'A' + cipherVal;
         outStream << cipherChar;
      }
   }
   outStream << std::endl;
}

void testCipher();

#endif
