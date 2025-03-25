/*
Author: Sebastian Dziedzic
Date Created: 2/24/2025
It counts the number of digits by dividing by ten, and outputs the digits as words by caculating the leftmost digit and printing it as a word
*/
#include<stdio.h>
#include<math.h>

int main() {
    //Create variables
    int input, digitCount = 0, countInput, outputDivisor, outputDigit;

    //Asks user for input
    inputStage:
    printf("Enter a 5-digit area code:");
    scanf("%d", &input);

    //Determine the number of digits entered
    countInput = input;
    digitCount = 0;
    while (countInput != 0) {
        digitCount += 1;
        countInput /= 10;
    }

    //Check to make sure the user input 5 digits
    if (digitCount != 5) {
        printf("\nyou entered %d digits.\n", digitCount);
        //Goes back up to the point where it asks for an input
        goto inputStage;
    }
    
    //Print out the actual digits
    while (digitCount > 0) {
        //Divides the input by whatever it needs to get the first number
        outputDivisor = pow(10.0, ((double)digitCount - 1.0));
        outputDigit = input / outputDivisor;
        
        //Prints the resulting number
        switch(outputDigit) {
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
            case 0:
                printf("zero ");
        }

        //Removes the first digit of the number and decreases the number of digits left
        input = input - (outputDigit * outputDivisor);
        digitCount -= 1;
    }

}
