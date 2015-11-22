# mpags-cipher
A simple command line tool for encrypting/decrypting text using
classical ciphers  

The program will read plaintext from a keyboard or file and the encrypt
or decrypt the file based on the user's choice.  

The encryption/decryption options will include:
*	Caesar cipher
*	Vigenere cipher
*	Playfair cipher  

# Building mpags-cipher

Compilation of `mpags-cipher` requires [CMake] (http://www.cmake.org) build
tool, a C++14 compatible compiler and `make`.

To build from a clone of this repository, open a terminal window and change
directory into that holding this README.

Create a directory mpags-cipher.build in this directory and change directory
into it:

    mkdir mpags-cipher.build
    cd mpags-cipher.build

Now run cmake, passing the mpags-cipher.git directory as an
argument:

    cmake ../mpags-cipher.git

This will produce a Makefile in the mpags-cipher.build directory, which
can be run as:

    make -j2

# How to install

cd to the mpags-cipher.build directory:

    cd mpags-cipher.build

Now run the installation with the following command:

    make install

This should add the mpags-cipher executable to the directory
~/Software/

# How to package

cd to the mpags-cipher.build directory:

    cd mpags-cipher.build

Now run the following make command:

    make package package_source

This should create a set of tar and tar bundles in the
mpags-cipher.build directory

# Running 'mpags-cipher'

mpags-cipher can be run as

    mpags-cipher
    Available options:
        -h | --help          Print this help message
        --version            Print version information
        -i <filename>        Read text to be processed from <filename>
                             Standard input will be used if not supplied
        -o <filename>        Write processed text to <filename>
                             Standard output will be used if not supplied
        --cipher <cipher>    Sets the encryption/decryption cipher
                             Key must take one of the values:
                             (caesar, playfair, vigenere)
        -e <key>             Encrypt input text with key value <key>
                             Key must be in the range [0, 25]
        -d <key>             Decrypt input text with key value <key>
                             Key must be in the range [0, 25]

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed. It will then
echo the output to standard output or write it to the file specified by the
`-o` option.

# Source Code Layout

Under this directory, the code and associated files are organised as
follows:  

```
.                                                                                       
|-- CMakeLists.txt                                                                      
|-- Documentation                                                                       
|   |-- CMakeLists.txt                                                                  
|   `-- Doxyfile.in                                                                     
|-- LICENSE                                                                             
|-- MPAGSCipher                                                                         
|   |-- CMakeFiles                                                                      
|   |-- CMakeLists.txt                                                                  
|   |-- CaesarCipher.cpp                                                                
|   |-- CaesarCipher.hpp                                                                
|   |-- Cipher.hpp                                                                      
|   |-- CipherFactory.cpp                                                               
|   |-- CipherFactory.hpp                                                               
|   |-- CipherMode.hpp                                                                  
|   |-- IOProcessing.hpp                                                                
|   |-- PlayfairCipher.cpp
|   |-- PlayfairCipher.hpp
|   |-- ProcessCommandLine.cpp
|   |-- ProcessCommandLine.hpp
|   |-- TransformChar.cpp
|   |-- TransformChar.hpp
|   |-- VigenereCipher.cpp
|   `-- VigenereCipher.hpp
|-- README.md
|-- Testing
|   |-- CMakeFiles
|   |-- CMakeLists.txt
|   |-- catch.hpp
|   |-- testCaesarCipher.cpp
|   |-- testCiphers.cpp
|   |-- testPlayfairCipher.cpp
|   |-- testProcessCommandLine.cpp
|   `-- testTransformChar.cpp
`-- mpags-cipher.cpp
```

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.

