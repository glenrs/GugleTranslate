#!/bin/bash

loc=Python3.6ToC11

##Navigate to location of files so that all executables are contained
cd $loc

##location of files
cMod=cmod.c

##c will view Python as a module
pyScript=pythonScript.py

## Setup
## This will extend embedded Python. Extended embedded Python allows us to 
## choose which versions of Python and c to compile. 
##
## src = https://docs.python.org/3/extending/embedding.html
## This source talks about why we call the c file to call the original python script
##
gcc -std=c11 `python3.6-config --cflags` $cMod `python3.6-config --ldflags`
PYTHONPATH=. ./a.out $pyScript 

