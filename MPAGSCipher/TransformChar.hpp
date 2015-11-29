//! \file TransformChar.hpp
#ifndef MPAGSCIPHER_TRANSFORMCHAR_HPP
#define MPAGSCIPHER_TRANSFORMCHAR_HPP

#include <string>

/**
   Transliterates characters to make them suitable for encryption.
   
   \param input The character to transliterate
   \return A transliterated string
 */
std::string transformChar(const char input);

/**
   Transliterates strings to make them suitable for encryption.
   
   \param input The string to transliterate
   \return A transliterated string
 */
std::string transformString(const std::string& input);

#endif
