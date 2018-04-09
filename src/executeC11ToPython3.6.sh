#!/bin/bash

loc=C11ToPython3.6

##Navigate to location of files so that all executables are contained
cd $loc

##location of files
cFile=cFile.c 

##c will view Python as a module
pyMod=pythonMod
pyFunc=translate
firstNum=4
secondNum=5

## Setup
## This will embedded Python in C
##
## src => https://docs.python.org/3/extending/embedding.html

gcc -std=c11 `python3.6-config --cflags` $cFile `python3.6-config --ldflags`
PYTHONPATH=. ./a.out $pyMod $pyFunc $firstNum $secondNum

