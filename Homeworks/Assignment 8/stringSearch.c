/*
Author: Sebastian Dziedzic
Date: 4/15/2025
I/O: A file, the name of a file to open, the string that you want to search for
Algorithm: We only need to check if something in the string has the letter thats the same as the first letter in the search string, so if it does we count how many letters match up and return true if the same ammount match up as the amount being searched for.
*/
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool lineSearch(char original[], char searchingFor[]) {
    int numberNeeded = 0;
    int numberFound = 0;

    //Calculate how many charecters in a row need to match for it to return true.
    for(int i = 0; searchingFor[i] != '\0'; i++) {
        numberNeeded++;
    }

    //Goes one by one, and if the charecter seen matches the first charecter of the search string, it enters a new for loop
    for(int i = 0; original[i] != '\0'; i++) {
        if(original[i] == searchingFor[0]) {
            for(int j = 0; j < numberNeeded; j++) {
                //This for loop goes one by one comparing the original string to the string being searched for untill the number of charecters that are being searched for have been compared
                if(original[(i+j)] == searchingFor[j]) {
                    numberFound++;
                }
            }
            //If every charecter searched matches the charecter being searched for, these two will be equal and this will return true
            if(numberNeeded == numberFound) {
                return true;
            }
            numberFound = 0;
        }
    }
    
    //Return false if the number found does not match the number needed
    return false;

}

int main() {
    //Ask the user for the name of the file to open
    char fileName[30];
    FILE* currentFile = NULL;
    printf("File input:");
    scanf("%s", fileName);
    
    //Open the file the user asked for, return an error if that file can't be opened
    currentFile = fopen(fileName, "r");
    if(currentFile == NULL) {
        printf("\nCouldn't open that file.");
        return -1;
    }

    //Store the file into the string
    char currentChar;
    char stringFromFile[10][300];
    int currLoc = 0, lineCount = 0;
    for(int i = 0; i < 10; i++) {
        currLoc = 0;
        while(fscanf(currentFile, "%c", &currentChar) != EOF) {
            if (currentChar == '\n') {
                break;
            }
            stringFromFile[i][currLoc] = currentChar;
            currLoc++;
        }
        stringFromFile[i][currLoc] = '\0';
        lineCount++;
        if(currentChar == EOF) {
            break;
        }
    }

    //Print the string for the user including newlines
    for(int i = 0; i < lineCount; i++) {
        printf("%s\n", stringFromFile[i]);
    }
    
    //Get the string that the user wants to search for
    char searchString[100];

    printf("\nEnter the string you are searching for: ");
    //An fgets that eats up the starting newline
    getchar();
    //The fgets that actually wants the string
    fgets(searchString, 100, stdin);
    
    //Find the newline charecter and replace it with an end string terminator, makes it easier later
    for(int i = 0; searchString[i] != '\0'; i++) {
        if(searchString[i] == '\n') {
            searchString[i] = '\0';
            break;
        }
    }

    //Print any line that has what is being searched for
    printf("Output:\n");
    for(int i = 0; i < lineCount; i++) {
        if(lineSearch(stringFromFile[i], searchString) == true) {
            printf("%d %s\n",(i+1), stringFromFile[i]);
        }
    }

    return 0;
}