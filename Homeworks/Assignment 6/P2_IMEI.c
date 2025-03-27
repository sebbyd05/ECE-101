/*
Author: Sebastian Dziedzic
Date: 3/27/2025
I/O: IMEI / Validity, Luhn digit, Check digit
Algorithm:
*/

#include<stdio.h>

//Print IMEI function
void print_IMEI(int IMEI[], int size) {
    //Do this untill the IMEI is printed
    for(int i = 0; i < size; i++) {
        printf("%d", IMEI[i]);
    }
    printf("\n");
}

//Sum function for the IMEI
int calc_sum(int IMEI[], int size) {
    //Declare a variable for the sum to go into
    int sum;

    //Add odd digits
    for(int i = 0; i < size; i += 2) {
        sum += IMEI[i];
    }

    //Add even digits
    for(int i = 1; i < size; i += 2) {
        sum += (IMEI[i] * 2);
    }

    //Return the sum
    return sum;
}

//Creating a function that turns a string into the array for the IMEI.
void programArray(int *IMEI, int imeiPreArray) {
    for(int i = 15; i >= 0; i--) {
        IMEI[i] = imeiPreArray % 10;
        imeiPreArray /= 10;
    }
}

//Make the main section of the program
int main() {
    //Declaring the variables
    int IMEI[15], checkDigit, imeiPreArray;
    FILE *inFile = NULL;

    //Begin opening file
    inFile = fopen("list_IMEI.txt", "r");
    if(inFile == NULL) {
        printf("File failed to open");
        return -1;
    }

    //Start the loop that runs for the entirety of the program from here on out, and closes when there are no more IMEIs to read
    while(fscanf(inFile, "%d", &imeiPreArray) != EOF) {
        programArray(&IMEI[0], imeiPreArray);
        print_IMEI(IMEI, 15);
    }
}

