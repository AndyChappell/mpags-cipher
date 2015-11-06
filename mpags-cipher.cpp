// mpags-cipher.cpp
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"

int main(int argc, char* argv[])
{
   //testCipher();
   CommandLineArguments args{false, false, false, 0, "", ""};
   return processCommandLine(argc, argv, args);
}

