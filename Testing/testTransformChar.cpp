//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "TransformChar.hpp"

TEST_CASE("Characters are uppercased", "[alphanumeric]"){
   REQUIRE(transformChar('a') == "A");
   REQUIRE(transformChar('b') == "B");
   REQUIRE(transformChar('c') == "C");
   REQUIRE(transformChar('d') == "D");
   REQUIRE(transformChar('e') == "E");
   REQUIRE(transformChar('f') == "F");
   REQUIRE(transformChar('g') == "G");
   REQUIRE(transformChar('h') == "H");
   REQUIRE(transformChar('i') == "I");
   REQUIRE(transformChar('j') == "J");
   REQUIRE(transformChar('k') == "K");
   REQUIRE(transformChar('l') == "L");
   REQUIRE(transformChar('m') == "M");
   REQUIRE(transformChar('n') == "N");
   REQUIRE(transformChar('o') == "O");
   REQUIRE(transformChar('p') == "P");
   REQUIRE(transformChar('q') == "Q");
   REQUIRE(transformChar('r') == "R");
   REQUIRE(transformChar('s') == "S");
   REQUIRE(transformChar('t') == "T");
   REQUIRE(transformChar('u') == "U");
   REQUIRE(transformChar('v') == "V");
   REQUIRE(transformChar('w') == "W");
   REQUIRE(transformChar('x') == "X");
   REQUIRE(transformChar('y') == "Y");
   REQUIRE(transformChar('z') == "Z");
   REQUIRE(transformString("abcdefghijklmnopqrstuvwxyz") == "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}

TEST_CASE("Digits are transliterated", "[alphanumeric]"){
   REQUIRE(transformChar('0') == "ZERO");
   REQUIRE(transformChar('1') == "ONE");
   REQUIRE(transformChar('2') == "TWO");
   REQUIRE(transformChar('3') == "THREE");
   REQUIRE(transformChar('4') == "FOUR");
   REQUIRE(transformChar('5') == "FIVE");
   REQUIRE(transformChar('6') == "SIX");
   REQUIRE(transformChar('7') == "SEVEN");
   REQUIRE(transformChar('8') == "EIGHT");
   REQUIRE(transformChar('9') == "NINE");
}

TEST_CASE("Special characters are removed", "[punctuation]"){
   REQUIRE(transformChar(',') == "");
   REQUIRE(transformChar(' ') == "");
   REQUIRE(transformString("!\"£$%^&*()_+\';:#@'~\\,.<>?/") == "");
}
