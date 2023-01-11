# This speeds up dev time.
# Whenever we make changes to shell.c we have to recompile and run the executable again. 
#! /bin/bash
touch main.c
gcc shell.c -o spx
./spx $1
gcc main.c
./a.out
sleep 0.0001
rm main.c
rm a.out