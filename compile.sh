#this speeds up dev time.
#Whenever we make changes to shell.c we have to recompile and
#run the executable again. 

#This script saves that time.
gcc shell.c -o spx
./spx $1