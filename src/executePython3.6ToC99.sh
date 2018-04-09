#!/bin/bash

loc=Python3.6ToC99

##Navigate to location of files so that all executables are contained
cd $loc

##location of files
cMod=cmod.c

##c will view Python as a module
pyScript=pythonScript.py

##loc of setupfile
pySetup=setup.py

## Setup
## This sets builds the extended C modules so that they can be called in Python
## This has a limitation. There are only certain compilers that can compile the c code. It compiles in C99, not C11.
##

## This compiles the c code in C99 and builds and installs the module so that it can be executed in python
python3.6 $pySetup build
python3.6 $pySetup install 

## The execution script
python3.6 $pyScript


