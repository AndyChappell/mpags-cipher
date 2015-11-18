#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "CipherMode.hpp"

#include <string>
#include <iostream>
#include <sstream>

/**
	VigenereCipher provides encoding (decoding) of plaintext (ciphertext)
	using the Vigenere Cipher.
 */
class VigenereCipher
{
	public:
	/**
		Create a VigenereCipher with a specified key.

		\param key The key to use for encoding/decoding
	 */
	VigenereCipher();
	
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

	/**
		Decodes specified ciphertext.
		
		\param ciphertext The ciphertext to decode
		\return The decoded plaintext
	 */
	std::string decode(const std::string& ciphertext) const;
	
	private:
	std::string key_;	///< The key to use for encoding/decoding
};

#endif
