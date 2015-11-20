//! Test that Catch works
#define CATCH_CONFIG_MAIN

#include <vector>

#include "catch.hpp"

#include <memory>

#include "Cipher.hpp"
#include "CipherFactory.hpp"

TEST_CASE("Cipher encoding", "[cipher]"){
   std::string plaintext{"PLAINTEXT"};
   
   std::string keys[] = {"5", "key", "key"};
   std::string ciphertexts[] = {"UQFNSYJCY", "AQZTSSPCS", "QIKNOSAVZB"};

   std::vector<std::unique_ptr<Cipher>> ciphers;
   ciphers.push_back(cipherFactory(CipherTypes::CAESAR));
   ciphers.push_back(cipherFactory(CipherTypes::VIGENERE));
   ciphers.push_back(cipherFactory(CipherTypes::PLAYFAIR));

   for(unsigned int i = 0; i < ciphers.size(); ++i)
   {
      const auto& cipher = ciphers[i];
      cipher->setKey(keys[i]);
      REQUIRE(cipher->encode(plaintext) == ciphertexts[i]);
   }
}

TEST_CASE("Cipher decoding", "[cipher]"){
   std::string plaintext{"PLAINTEXT"};
   std::string ciphertexts[] = {"UQFNSYJCY", "AQZTSSPCS", "QIKNOSAVZB"};
   
   std::string keys[] = {"5", "key", "key"};

   std::vector<std::unique_ptr<Cipher>> ciphers;
   ciphers.push_back(cipherFactory(CipherTypes::CAESAR));
   ciphers.push_back(cipherFactory(CipherTypes::VIGENERE));
   ciphers.push_back(cipherFactory(CipherTypes::PLAYFAIR));

   for(unsigned int i = 0; i < ciphers.size(); ++i)
   {
      const auto& cipher = ciphers[i];
      cipher->setKey(keys[i]);
      REQUIRE(cipher->decode(ciphertexts[i]) == plaintext);
   }
}
