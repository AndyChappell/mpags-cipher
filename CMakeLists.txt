# - Main CMake buildscript for mpags-cipher
# Comments in a CMake Script are lines beginning with a '#'

# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.2.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler commands/flags
#   are used. This can also be done by removing the 'set' command and
#   running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)

# - Don't allow C++ Compiler Vendor Extension
set(CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags if the GNU/Clang compilers
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
  set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wfatal-errors -Wshadow -pedantic")
endif()

# - Add the MPAGSCipher subdirectory to the build
add_subdirectory(MPAGSCipher)

# - Declare the build of mpags-cipher main program
add_executable(mpags-cipher mpags-cipher.cpp)
target_link_libraries(mpags-cipher PRIVATE MPAGSCipher)

# - Install mpags-cipher using UNIX/GNU directory structure
include(GNUInstallDirs)
install(TARGETS mpags-cipher DESTINATION ${CMAKE_INSTALL_BINDIR})

# - Package mpags-cipher binaries and sources
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
include(CPack)
