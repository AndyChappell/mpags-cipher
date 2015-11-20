# - Build sub-script for the MPAGSCipher library unit tests

# Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# TransformChar test
add_executable(testTransformChar testTransformChar.cpp)
target_link_libraries(testTransformChar MPAGSCipher Catch)
add_test(NAME test-transformchar COMMAND testTransformChar -s)

# ProcessCommandLine test
add_executable(testProcessCommandLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCommandLine MPAGSCipher Catch)
add_test(NAME test-processcommandline COMMAND testProcessCommandLine -s)

# CaesarCipher test
add_executable(testCaesarCipher testCaesarCipher.cpp)
target_link_libraries(testCaesarCipher MPAGSCipher Catch)
add_test(NAME test-caesarcipher COMMAND testCaesarCipher -s)

# PlayfairCipher test
add_executable(testPlayfairCipher testPlayfairCipher.cpp)
target_link_libraries(testPlayfairCipher MPAGSCipher Catch)
add_test(NAME test-playfaircipher COMMAND testPlayfairCipher -s)

# Ciphers test
add_executable(testCiphers testCiphers.cpp)
target_link_libraries(testCiphers MPAGSCipher Catch)
add_test(NAME test-ciphers COMMAND testCiphers -s)
