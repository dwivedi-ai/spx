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
    if (checkParamFile(argv[1]))
    {
        printf("\033[1;31m");
        printf("cannot find %s: No such file or directory\n", argv[1]);
        printf("\033[0m");
        printf("error: returned 1 exit status\n");
        return 1;
    }
    
    FILE *fptr;
    fptr = fopen(argv[1],"r");
    
    if ((fptr = fopen(argv[1], "r")) == NULL){
       printf("An Error Occured!");
       exit(1);
    }
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