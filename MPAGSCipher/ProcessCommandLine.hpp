//! \file ProcessCommandLine.hpp
#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

/**
   A structure containing the values that can be read from the command
   line.
*/
struct CommandLineArguments
{
	bool helpRequested;
	bool versionRequested;
	bool encrypt;
	std::string key;
	std::string inputFilename;
	std::string outputFilename;
	std::string cipher;
};

/**
   Populates a CommandLineArguments structure with command line input.
   
   \param argc The number of command line arguments
   \param argv The command line arguments
   \param args A CommandLineArguments structure to populate
   \return Returns zero if the command line was processed without error, non-zero otherwise
 */
int processCommandLine(const int argc, char* argv[],
	CommandLineArguments& args);

#endif
