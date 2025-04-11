/*
Name: Sebastian Dziedzic
Date: 4/7/2025
Algorithm: A writing assistant program that calls various functions to change the writing
PLEASE NOTE: I tried and tried for quite a while trying to get it to accept my menu function and it simply wouldn't, sorry!
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
    return;
}

//Function that counts number of non whitespace charecters in a string
int GetNumOfNonWSCharacters(char string[512]) {
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        //Counts any charecter that's not a space or a newline
        if(string[i] != ' ' && string[i] != '\n') {
            count++;
        }
    }
    
    return count;
}

//Function that finds the number of words in a string
int GetNumOfWords(char string[512]) {
    int count = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        //Counts spaces with letters after them, or punctuation right before the newline at the end
        if((string[i] == ' ' && string[(i+1)] != ' ') || ((string[i] == '.' || string[i] == '!' || string[i] == '?') && (string[(i+1)] == '\0' || string[(i+1)] == '\n'))) {
            count++;
        } 
    }

    return count;
}

//Fixes the capitalization of a string
void FixCapitalization(char string[512]) {
    int nextNeedsCapitalized = 0;
    for(int i = 0; string[i] != '\0'; i++) {
        if (i == 0) {
            //Ensures the first letter of the string is capitalized
            if(string[i] >= 'a' && string[i] <= 'z') {
                string[i] = (string[i] - 32);
            }
        }
        //Checks to see if the charecter being scanned is a punctuation mark
        if(string[i] == '.' || string[i] == '!' || string[i] == '?') {
                nextNeedsCapitalized = 1;
            }
        //Once it continues, see if the next charecter needs to be capitalized, but it only needs to be called if the previous charecter isn't seen as a punctuation mark
        else if(nextNeedsCapitalized == 1) {
            if(string[i] >= 'a' && string[i] <= 'z') {
                //Capitalizes next charecter then sets the caller to zero
                string[i] = (string[i] - 32);
                nextNeedsCapitalized = 0;
            } else if(string[i] >= 'A' && string[i] <= 'Z') {
                //Sets the variable back to zero because the charecter is already capitalized
                nextNeedsCapitalized = 0;
            }
        }
    }
    return;
}

//Function that replaces exclamation points with periods
void ReplaceExclamation(char string[512]) {
    for(int i = 0; string[i] != '\0'; i++) {
        if(string[i] == '!') {
            string[i] = '.';
        }
    }
}

//Function that takes user input to call other functions
void ExecuteMenu(char choice, char string[512]) {
    if (choice == 'c') {
        printf("Number of non-whitespace characters: %d\n", GetNumOfNonWSCharacters(string));
    } else if (choice == 'w') {
        printf("Number of words: %d\n", GetNumOfWords(string));
    } else if (choice == 'f') {
        FixCapitalization(string);
        printf("Edited text: %s", string);
    } else if (choice == 'r') {
        ReplaceExclamation(string);
        printf("Edited text: %s", string);
    }
    return;
}

int main() {
    //Define the string
    char userString[512];
    char userOption;

    //Ask the user for a string
    printf("Enter a sample text:\n");
    fgets(userString, 512, stdin);
    printf("\nYou entered: %s", userString);
    
    //Loop that constantly prompts the user to enter their input
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

    return 0;
}