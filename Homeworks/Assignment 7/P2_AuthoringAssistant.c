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

int main() {
    //Define the string
    char userString[512];
    char userOption;

    //Ask the user for a string
    printf("Enter a sample text:\n");
    fgets(userString, 512, stdin);
    printf("\nYou entered: %s", userString);
    
    PrintMenu();

    return 0;
}