# - Build sub-script for the MPAGSCipher library

# - Declare the build of the status MPAGSCipher library
add_library(MPAGSCipher STATIC
  CipherFactory.hpp
  CipherFactory.cpp
  Cipher.hpp
  CaesarCipher.hpp
  CaesarCipher.cpp
  PlayfairCipher.hpp
  PlayfairCipher.cpp
  VigenereCipher.hpp
  VigenereCipher.cpp
  ProcessCommandLine.hpp
  ProcessCommandLine.cpp
  IOProcessing.hpp
  TransformChar.hpp
  TransformChar.cpp
  CipherMode.hpp
  )

target_include_directories(MPAGSCipher
  PUBLIC ${CMAKE_CURRENT_LIST_DIR}
  )

target_compile_features(MPAGSCipher
  PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization cxx_binary_literals
  )
