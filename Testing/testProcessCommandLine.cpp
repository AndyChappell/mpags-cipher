//! Test that Catch works
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <string>
#include "ProcessCommandLine.hpp"

TEST_CASE("Help flag is processed", "[flag]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("-h");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 0);
   REQUIRE(args.helpRequested == true);
   
   str2 = std::string("--help");
   arg2 = const_cast<char*>(str2.c_str());
   char* strArgs2[] = {arg1, arg2};
	CommandLineArguments args2{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs2, args2) == 0);
   REQUIRE(args.helpRequested == true);
}

TEST_CASE("Version flag is processed", "[flag]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("--version");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 0);
   REQUIRE(args.versionRequested == true);
}

TEST_CASE("Input option is processed", "[option]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("-i");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 1);
      
   std::string str3 = std::string("input.txt");
   char* arg3 = const_cast<char*>(str3.c_str());
   char* strArgs2[] = {arg1, arg2, arg3};
	CommandLineArguments args2{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(3, strArgs2, args2) == 0);
   REQUIRE(args2.inputFilename == "input.txt");
}

TEST_CASE("Output option is processed", "[option]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("-o");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 2);
      
   std::string str3 = std::string("output.txt");
   char* arg3 = const_cast<char*>(str3.c_str());
   char* strArgs2[] = {arg1, arg2, arg3};
	CommandLineArguments args2{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(3, strArgs2, args2) == 0);
   REQUIRE(args2.outputFilename == "output.txt");
}

TEST_CASE("Encryption option is processed", "[key]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("-e");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 3);
      
   std::string str3 = std::string("5");
   char* arg3 = const_cast<char*>(str3.c_str());
   char* strArgs2[] = {arg1, arg2, arg3};
	CommandLineArguments args2{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(3, strArgs2, args2) == 0);
   REQUIRE(args2.key == 5);
}

TEST_CASE("Decryption option is processed", "[key]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("-d");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 4);
      
   std::string str3 = std::string("5");
   char* arg3 = const_cast<char*>(str3.c_str());
   char* strArgs2[] = {arg1, arg2, arg3};
	CommandLineArguments args2{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(3, strArgs2, args2) == 0);
   REQUIRE(args2.key == 5);
}

TEST_CASE("Unrecognised argument processed", "[flag]"){
   std::string str1 = std::string("mpags-cipher");
   char* arg1 = const_cast<char*>(str1.c_str());
   std::string str2 = std::string("invalid");
   char* arg2 = const_cast<char*>(str2.c_str());
	char* strArgs[] = {arg1, arg2};
	CommandLineArguments args{false, false, false, 0, "", ""};
	REQUIRE(processCommandLine(2, strArgs, args) == 5);
}
