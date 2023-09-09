#include <stdio.h>
#include <string.h>

int main(){
    FILE *inputFile;
    inputFile = fopen("empInput.txt", "r");
    char inputFileName[] = "empInput.txt";
    char buffer[256];
    int i = 0;
    int n = 5;

    if (inputFile == NULL){
        printf ("Error: The file %s was not found", inputFileName);
        return 1;
    }
    else{
        while (i < n){
            fgets(buffer, 256, inputFile);
            buffer[strlen(buffer) - 1] = 0;
            printf ("%s", buffer);
            i++;
        }
    }

    fclose(inputFile);
    return 0;
}