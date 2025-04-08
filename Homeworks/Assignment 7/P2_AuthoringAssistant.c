/*
Name: Sebastian Dziedzic
Date: 4/7/2025
Algorithm:
*/
#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {
    //Define the string
    char userString[512];

    //Ask the user for a string
    printf("Enter a sample text:\n");
    fgets(userString, 512, stdin);
    printf("\nYou entered: %s", userString);

    return 0;
}