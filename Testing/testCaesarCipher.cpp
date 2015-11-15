//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"

TEST_CASE("Caesar Cipher encoding", "[cipher]"){
   std::string plaintext{"Hello world!"};

   CaesarCipher caesar{"5"};
	REQUIRE(caesar.encode(plaintext) == "MJQQTBTWQI");
}

TEST_CASE("Caesar Cipher decoding", "[cipher]"){
   std::string ciphertext{"MJQQTBTWQI"};

   CaesarCipher caesar{"5"};
	REQUIRE(caesar.decode(ciphertext) == "HELLOWORLD");
}
