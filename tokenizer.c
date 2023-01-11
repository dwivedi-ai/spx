#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void tokenize(char * line, int readLength)
{
    char s[readLength];
    strcpy(s, line);
    char *token = strtok(s, " ");
    int tokenCount = 1;
    while (token) {
        // printf("token %d: %s\n", tokenCount, token);
        token = strtok(NULL, " ");
        tokenCount++;
    }

    FILE *writeFilePointer; 
    writeFilePointer = fopen("main.c", "a");
    fprintf(writeFilePointer, "%s", line);
    fclose(writeFilePointer);
}