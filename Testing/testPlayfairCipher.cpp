//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlayfairCipher.hpp"

TEST_CASE("Playfair Cipher encoding", "[cipher]"){
   std::string plaintext{"TESTCIPHERREPEATLETTERSEXAMPLEWITHITEST"};

   PlayfairCipher cipher{};
   cipher.setKey("playfairexample");
	REQUIRE(cipher.encode(plaintext) == "VIKZBRFBXEMEIADEUPIVIWXEOMEYIFARTXZBBPMOUT");
}

TEST_CASE("Playfair Cipher decoding", "[cipher]"){
   std::string ciphertext{"VIKZBRFBXEMEIADEUPIVIWXEOMEYIFARTXZBBPMOUT"};

   PlayfairCipher cipher{};
   cipher.setKey("playfairexample");
	REQUIRE(cipher.decode(ciphertext) == "TESTCIPHERREPEATLETTERSEXAMPLEWITHITEST");
}
