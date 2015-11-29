//! \file VigenereCipher.hpp
#ifndef MPAGSCIPHER_VIGENERECIPHER_HPP
#define MPAGSCIPHER_VIGENERECIPHER_HPP

#include "Cipher.hpp"
#include "CipherMode.hpp"

#include <string>
#include <iostream>
#include <sstream>

/**
	VigenereCipher provides encoding (decoding) of plaintext (ciphertext)
	using the Vigenere Cipher.
 */
class VigenereCipher : public Cipher
{
   public:  
   /**
      Sets the encryption/decryption key.

      \param kay The key to use for encryption/decryption
   */
   virtual void setKey(const std::string& key) override;
   
	/**
		Encodes specified plaintext.
		
		\param plaintext The plaintext to encode
		\return The encoded ciphertext
	 */
	virtual std::string encode(const std::string& plaintext) const override;

	/**
		Decodes specified ciphertext.
		
		\param ciphertext The ciphertext to decode
		\return The decoded plaintext
	 */
	virtual std::string decode(const std::string& ciphertext) const override;
	
	private:
	std::string key_;	///< The key to use for encoding/decoding
};

#endif
