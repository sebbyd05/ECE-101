/*
Author: Sebastian Dziedzic
Date Created: 3/1/2025
I/O: Input 1 interger, output numbers in the hailstone sequence till it's 1
Checks y -10 thru 10 before incramentig x which runs for -10 thru 10.
*/

#include<stdio.h>

int main() {
    //Defining variables
    int nXA, nYA, nXB, nYB, solutionA, solutionB, X=-10, Y=-10;

    //Getting input
    scanf("%d %d %d", &nXA, &nYA, &solutionA);
    scanf("%d %d %d", &nXB, &nYB, &solutionB);

    //Do math
    for (X = -10; X <= 10; X++) {
        for (Y = -10; Y <= 10; Y++) {
            if (((nXA * X) + (nYA * Y)) == solutionA && ((nXB * X) + (nYB * Y)) == solutionB) {
                printf("x = %d, y = %d\n", X, Y);
                return 0;
            }
        }
        Y = -10;
    }

    printf("No solution found\n");

    return 0;

}