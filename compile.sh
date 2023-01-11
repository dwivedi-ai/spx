#! /bin/bash
touch main.c
gcc shell.c -o spx
./spx $1
gcc main.c
./a.out
sleep 0.0001
rm main.c
rm a.out