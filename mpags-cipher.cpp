// mpags-cipher.cpp
#include "TransformChar.hpp"

#include <iostream>

void day2Ex1();

int main()
{
   day2Ex1();

   return 0;
}

void day2Ex1()
{
	/*
    * Solution for Exercise 1 of Day 2.
    * */
   char input{'\0'};
   while(std::cin >> input)
   {  // Loop until the user presses enter and Ctrl-D
      std::cout << transformChar(input);
   }
}
