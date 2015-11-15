#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

#include "CipherMode.hpp"
#include "TransformChar.hpp"

#include <string>
#include <iostream>
#include <sstream>

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
};

#endif
