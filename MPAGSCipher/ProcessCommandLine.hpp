#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

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

int processCommandLine(const int argc, char* argv[],
	CommandLineArguments& args);

#endif
