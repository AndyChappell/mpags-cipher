#ifndef MPAGSCIPHER_CIPHERFACTORY_HPP
#define MPAGSCIPHER_CIPHERFACTORY_HPP

#include <memory>

#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "PlayfairCipher.hpp"
#include "VigenereCipher.hpp"

enum class CipherTypes {CAESAR, PLAYFAIR, VIGENERE};

/**
   Creates a cipher of the requested type.

   \param type The type of cipher to create
   \return The created cipher
*/
std::unique_ptr<Cipher> cipherFactory(const CipherTypes& type);

#endif
