#include<stdio.h>

int main() {
    //Initialize variables
    int userN, i, totalSum = 0, numDivisible = 0, maxDivisible = 0;

    //Request input from user
    printf("Enter a value for N: ");
    scanf("%d", &userN);

    //Perform math
    for (i=100; i<=499; i++) {
        if ((i % userN) == 0) {
            numDivisible += 1;
            totalSum += i;
            if (i > maxDivisible) {
                maxDivisible = i;
            }
        }
    }

    //Display results
    printf("There are %d values between 100-499 that are divisible by %d", numDivisible, userN);
    printf("\nSum of numbers between 100-499 that are divisible by %d is %d", userN, totalSum);
    if (numDivisible == 0) {
        printf("\nNo Maximum number betweeen 100-499 that are divisible by %d\n", userN);
    } else {
        printf("\nMaximum number between 100-499 that are divisible by %d is %d\n", userN, maxDivisible);
    }
    return 0;

}