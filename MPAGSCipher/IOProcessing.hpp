#ifndef MPAGSCIPHER_IOPROCESSING_HPP
#define MPAGSCIPHER_IOPROCESSING_HPP

#include <string>
#include <sstream>

template <typename T>
std::string processInput(T& inStream)
{
   /*
      Processes input from an arbitrary stream.

      T& inStream:   The input stream from which input should be read
   */
   char input{'\0'};
   std::ostringstream stream{""};
   while(inStream >> input)
   {
      stream << std::string{input};
   }
   
   return stream.str();
}

template <typename T>
void processOutput(T& stream, std::string& output)
{
	stream << output;
}

#endif
