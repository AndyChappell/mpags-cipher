#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include "CipherMode.hpp"
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
	CaesarCipher(const std::string& key);
	
	/**
		Encodes specified plaintext.
		
		\param plaintext The plaintext to encode
		\return The encoded ciphertext
	 */
	std::string encode(const std::string& plaintext) const;

	/**
		Decodes specified ciphertext.
		
		\param ciphertext The ciphertext to decode
		\return The decoded plaintext
	 */
	std::string decode(const std::string& ciphertext) const;
	
	private:
	int key_;	///< The key to use for encoding/decoding
};

#endif
