//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Caesar Cipher encoding", "[cipher]"){
   std::string plaintext{"HELLOWORLD"};

   CaesarCipher cipher{"5"};
	REQUIRE(cipher.encode(plaintext) == "MJQQTBTWQI");
}

TEST_CASE("Caesar Cipher decoding", "[cipher]"){
   std::string ciphertext{"MJQQTBTWQI"};

   CaesarCipher cipher{"5"};
	REQUIRE(cipher.decode(ciphertext) == "HELLOWORLD");
}
