# mpags-cipher
A simple command line tool for encrypting/decrypting text using
classical ciphers  

The program will read plaintext from a keyboard or file and the encrypt
or decrypt the file based on the user's choice.  

The encryption/decryption options will include:
*	Caesar cipher
*	Vigenere cipher
*	Playfair cipher  

Ciphertext will be written to screen or file.  

# How to build

Create a directory mpags-cipher.build at the same levels as
mpags-cipher.git and cd into this directory:

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

# Authors

Andy Chappell  

# Documentation

mpags-cipher can be run as

    mpags-cipher
    Available options:
        -h | --help      Print this help message
        --version        Print version information
        -i <filename>    Read text to be processed from <filename>
                         Standard input will be used if not supplied
        -o <filename>    Write processed text to <filename>
                         Standard output will be used if not supplied
        -e <key>         Encrypt input text with key value <key>
                         Key must be in the range [0, 25]
        -d <key>         Decrypt input text with key value <key>
                         Key must be in the range [0, 25]

# Source Code Layout

Under this directory, the code and associated files are organised as
follows:  

    .  
    |-- CMakeLists.txt  
    |-- Documentation  
    |   |-- CMakeLists.txt  
    |   `-- Doxyfile.in  
    |-- LICENSE  
    |-- MPAGSCipher  
    |   |-- CMakeLists.txt  
    |   |-- TransformChar.cpp  
    |   `-- TransformChar.hpp  
    |-- README.md  
    |-- Testing  
    |   |-- CMakeLists.txt  
    |   `-- catch.hpp  
    `-- mpags-cipher.cpp  

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.

