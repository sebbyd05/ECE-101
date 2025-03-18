#include<stdio.h>

int main() {
    //Create a variable for the file
    FILE *inFile = NULL;
    //Open a file with that vatiable
    inFile = fopen("myfile.txt", "w");

    //Give an error if the file didn't open properly
    if (inFile == NULL) {
        printf("File failed to load");
        return -1;
    }

    fprintf(inFile, "Hello");
    fclose(inFile);
    return 0;

}