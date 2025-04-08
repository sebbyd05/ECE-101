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
    printf("\n\nMENU\n");
    printf("c - Number of non-whitespace characters\n");
    printf("w - Number of words\n");
    printf("f - Fix capitalization\n");
    printf("r - Replace all !'s\n");
    printf("q - Quit\n");
}

//Function that takes user input to call other functions
void ExecuteMenu(char choice, char string[512]) {
    if (choice = 'c') {
        printf("Number of non-whitespace characters %d", GetNumOfNonWSCharacters(string));
    }
}

//Function that counts number of non whitespace charecters in a string
int GetNumOfNonWSCharacters(char string[512]) {
    int count = 0;
    for(int i = 0; string[i] != '\n'; i++) {
        if((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) {
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
        fscanf("%c ", &userOption);
        if(userOption == 'q') {
            return 0;
        } else if(userOption == 'c' || userOption == 'w' || userOption == 'f' || userOption == 'r') {
            ExecuteMenu(userOption, userString);
        }
    }
}