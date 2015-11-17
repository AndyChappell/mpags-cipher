#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include "CipherMode.hpp"
#include "TransformChar.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <utility>
#include <map>

/**
	PlayfairCipher provides encoding (decoding) of plaintext (ciphertext)
	using the Playfair Cipher.
 */
 
class PlayfairCipher
{
	public:
	/**
		Create a PlayfairCipher.
	 */
	PlayfairCipher();

	/**
		Sets the encryption/decryption key.
		
		\param kay The key to use for encryption/decryption
	 */
	void setKey(const std::string& key);
	
	/**
		Encodes specified plaintext.
		
		\param plaintext The plaintext to encode
		\return The encoded ciphertext
	 */
	std::string encode(const std::string& plaintext) const;
	
	private:
	std::string key_; ///< The key to use for encoding/decoding
   std::map<std::pair<int, int>, char> chars_;
   std::map<char, std::pair<int, int>> coords_;
   
   static const int NumRows = 5;
   static const int NumColumns = 5;
};

#endif
