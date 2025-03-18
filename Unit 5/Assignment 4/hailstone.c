/*
Author: Sebastian Dziedzic
Date Created: 3/1/2025
I/O: Input 1 interger, output numbers in the hailstone sequence till it's 1
The program keeps performing the sequence and making a new line after printing 10 lines untill the result is 1
*/

#include<stdio.h>

int main() {
    //Declaring Variables
    int n, i = 1;

    //Obtain Input
    scanf("%i", &n);
    
    //Perform and print math
    printf("%d",n);
    while (n != 1) {
        printf("\t");
        if(i == 10) {
            printf("\n");
            i = 0;
        }

        if(n %2 == 0) {
            n /= 2;
        } else {
            n = (n * 3) + 1;
        }

        printf("%d", n);

        i++;


    }
    printf("\n");
    return 0;
}