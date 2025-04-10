/*
Name: Sebastian Dziedzic
Date: 4/7/2025
Algorithm:
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//Function that prints the menu
void PrintMenu() {
    printf("\nMENU\n");
    printf("c - Number of non-whitespace characters\n");
    printf("w - Number of words\n");
    printf("f - Fix capitalization\n");
    printf("r - Replace all !'s\n");
    printf("q - Quit\n");
}

//Function that takes user input to call other functions
void ExecuteMenu(char choice, char string[512]) {
    if (choice == 'c') {
        printf("Number of non-whitespace characters: %d\n", GetNumOfNonWSCharacters(string));
    } else if (choice == 'w') {
        printf("Number of words: %d\n", GetNumOfWords(string));
    }
}

//Function that counts number of non whitespace charecters in a string
int GetNumOfNonWSCharacters(char string[512]) {
    int count = 0;
    for(int i = 0; string[i] != '\n'; i++) {
        if(string[i] != ' ') {
            count++;
        }
    }
    
    return count;
}

//Function that finds the number of words in a string
int GetNumOfWords(char string[512]) {
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        if((string[i] == ' ' && string[(i+1)] != ' ') || (string[i] == '.' && (string[(i+1)] == ' ' || string[(i+1)] == '\0' || string[(i+1)] == '\n'))) {
            count++;
        } 
    }

    return count;
}

int main() {
    //Define the string
    char userString[512];
    char userOption;

    //Ask the user for a string
    printf("Enter a sample text:\n");
    fgets(userString, 512, stdin);
    printf("\nYou entered: %s", userString);
    
    while(1==1) {
        PrintMenu();
        printf("\nChoose an option:\n");
        scanf(" %c ", &userOption);
        if(userOption == 'q') {
            return 0;
        } else if(userOption == 'c' || userOption == 'w' || userOption == 'f' || userOption == 'r') {
            ExecuteMenu(userOption, userString);
        }
    }
}