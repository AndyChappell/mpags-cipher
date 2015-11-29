//! \file IOProcessing.hpp
#ifndef MPAGSCIPHER_IOPROCESSING_HPP
#define MPAGSCIPHER_IOPROCESSING_HPP

#include <string>
#include <sstream>

/**
   Reads input from an arbitrary stream.

   \param inStream The input stream from which input should be read
   \return The string read from the stream
*/
template <typename T>
std::string processInput(T& inStream)
{
   char input{'\0'};
   std::ostringstream stream{""};
   while(inStream >> input)
   {
      stream << std::string{input};
   }
   
   return stream.str();
}

/**
   Writes output to an arbitrary stream.

   \param stream The output stream to which output should be written
   \param output The string to be written to the stream
*/
template <typename T>
void processOutput(T& stream, std::string& output)
{
	stream << output;
}

#endif
