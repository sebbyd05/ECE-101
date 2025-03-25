/*
Author: Sebastian Dziedzic
Date Created: 2/24/2025
It continuously asks the user for a number, checks if its the biggest, stores it if it is and ends if the user enters a negative.
*/
#include <stdio.h>
int main() {
    //Declaring variables
    int max = 0, input;

    //Entering an infinite loop
    while (1 == 1) {
        //Asks for input
        scanf("%d", &input);
        //If the input is less than 0 it can tell the user the max and end the program.
        if (input < 0) {
            printf("%d", max);
            return 0;
        }
        //If the input is the largest it should set it to be the max
        if (input > max) {
            max = input;
        }
    }
}