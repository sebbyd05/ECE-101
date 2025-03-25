/*
Author: Sebastian Dziedzic
Date Created: 2/24/2025
You give it a number, and while the first or second digit is odd it prints the number, subtracts one, adds a number to the count, and continues to check if the digits are even. After they are both odd it prints the final number, and tells the user the average of all the numbers.
*/
#include<stdio.h>

int main() {
    //Declaring nessicary variables
    int inputNumber, tensDigit, onesDigit, count = 1;
    double sum = 0;
    //Obtaining user input
    scanf("%d", &inputNumber);

    //End program if number isn't within range
    if (inputNumber < 10 || inputNumber > 99) {
        printf("Input must be 10-99 ");
        return -1;
    }

    //Process numbers to start off the loop
    tensDigit = inputNumber / 10;
    onesDigit = inputNumber % 10;

    //Do math if the number isnt two odd digits
    while ((tensDigit % 2) == 0 || (onesDigit % 2) == 0) {
        printf("%d ", inputNumber);
        sum += inputNumber;
        count += 1;
        inputNumber -= 1;

        tensDigit = inputNumber / 10;
        onesDigit = inputNumber % 10;
    }
    
    //Print final number and do the math for the average
    printf("%d ", inputNumber);
    sum += inputNumber;
    sum /= (double)count;
    
    printf("\naverage is %.2lf", sum);

    return 0;
}