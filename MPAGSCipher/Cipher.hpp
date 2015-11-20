#ifndef MPAGSCIPHER_CIPHER_HPP
#define MPAGSCIPHER_CIPHER_HPP

#include <string>

/**
	Cipher provides an interface for encoding (decoding) of plaintext
   (ciphertext).
 */
class Cipher
{
	public:
	/**
		Create a Cipher.
	 */
	Cipher() = default;

	/**
		Create a Cipher by copying an existing Cipher.
      
      \param cipher The cipher object to copy.
	 */
	Cipher(const Cipher& cipher) = default;

	/**
		Create a Cipher by moving an existing Cipher.
      
      \param cipher The cipher object to move.
	 */
	Cipher(Cipher&& cipher) = default;
   
	/**
		Create a Cipher by assigning an existing Cipher.
      
      \param cipher The cipher object to assign.
	 */
	Cipher& operator=(const Cipher& cipher) = default;

	/**
		Create a Cipher by move assigning an existing Cipher.
      
      \param cipher The cipher object to move assign.
	 */
	Cipher& operator=(Cipher&& cipher) = default;
   
	/**
		Destroy a Cipher.
	 */
	virtual ~Cipher() = default;
   	
   /**
      Sets the encryption/decryption key.

      \param kay The key to use for encryption/decryption
   */
   virtual void setKey(const std::string& key) = 0;
   
	/**
		Encodes specified plaintext.
		
		\param plaintext The plaintext to encode
		\return The encoded ciphertext
	 */
	virtual std::string encode(const std::string& plaintext) const = 0;

	/**
		Decodes specified ciphertext.
		
		\param ciphertext The ciphertext to decode
		\return The decoded plaintext
	 */
	virtual std::string decode(const std::string& ciphertext) const = 0;
};

#endif
