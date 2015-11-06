#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>

struct CommandLineArguments
{
	bool helpRequested;
	bool versionRequested;
	bool encrypt;
	int key;
	std::string inputFilename;
	std::string outputFilename;
};

int processCommandLine(const int argc, char* argv[],
	CommandLineArguments& args);

#endif
