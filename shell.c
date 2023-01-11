/*
Written by: Ankit Dwivedi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Signatures
int checkParamFile(char *);

int main(int argc, char * argv[])
{
    // Checking if there is a file parameter when executing the program.
    // This part of code avoids the segmentation fault due to the calling of an uninitialized pointer.
    if (!argv[1])
    {
        printf("\033[1m");
        printf("spx: ");
        printf("\033[1;31m");
        printf("fatal error: ", argv[1]);
        printf("\033[0m");
        printf("no input files\n");
        printf("interpretation terminated\n");
        return 1;
    }

    // Opening File
    FILE *fptr;
    if ((fptr = fopen(argv[1],"r")) == NULL)
    {
        printf("\033[1m");
        printf("spx: ");
        printf("\033[1;31m");
        printf("error: ", argv[1]);
        printf("\033[0m");
        printf("cannot find the specified file\n");
        printf("error: returned 1 exit status\n");
        return 1;
    }

    // This part of code checks if the specified file is a supported .spx file
    if (checkParamFile(argv[1]))
    {
        printf("\033[1m");
        printf("spx: ");
        printf("\033[1;31m");
        printf("error: ", argv[1]);
        printf("\033[0m");
        printf("cannot read the specified file\n");
        printf("error: returned 1 exit status\n");
        return 1;
    }
    
    // Reading File
    char ch = ' ';
    while ((ch = getc(fptr)) != EOF)
    {
        printf("%c", ch);
    }
    fclose(fptr);
    return 0;
}


// Functions


int checkParamFile(char * param)
{
    char str[5];
    int counter = 0;
    for(int i = strlen(param) - 1; counter < 4; i--)
    {
        str[3 - counter] = param[i];
        counter++;
    }
    return strcmp(str, ".spx");
}