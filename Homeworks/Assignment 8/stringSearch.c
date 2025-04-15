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

    for(int i = 0; original[i] != '\0'; i++) {
        if(original[i] == searchingFor[0]) {
            for(int j = 0; j < numberNeeded; j++) {
                if(original[(i+j)] == searchingFor[j]) {
                    numberFound++;
                }
            }
            if(numberNeeded == numberFound) {
                return true;
            }
            numberFound = 0;
        }
    }
    
    //Return false if the number found matches the number needed
    return false;

}

int main() {
    //Ask the user for the name of the file to open
    char fileName[30];
    FILE* currentFile = NULL;
    printf("File input:");
    scanf("%s", &fileName);
    
    //Open the file the user asked for
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

    printf("You are searching for: %s", searchString);

    //Print any line that has what is being searched for
    for(int i = 0; i < lineCount; i++) {
        if(lineSearch(stringFromFile[i], searchString) == true) {
            printf("%s", stringFromFile[i]);
        }
    }

    return 0;
}