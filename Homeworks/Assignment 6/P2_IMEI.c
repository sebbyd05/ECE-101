/*
Author: Sebastian Dziedzic
Date: 3/27/2025
I/O: IMEI / Validity, check digit, Check digit
Algorithm: Opens file, then stores IMEI to an array, then calculates the sum and check digit, then prints what the results are while checking validity at the very end
*/

#include<stdio.h>

//Print IMEI function
void print_IMEI(int IMEI[], int size) {
    //Do this untill the IMEI is printed
    for(int i = 0; i < size; i++) {
        printf("%d", IMEI[i]);
    }
}

//Sum function for the IMEI
int calc_sum(int IMEI[], int size) {
    //Declare a variable for the sum to go into
    int sum = 0;
    
    //Add odd digits
    for(int i = 0; i < 14; i += 2) {
        sum += IMEI[i];
    }

    //Add even digits
    for(int i = 1; i < size; i += 2) {
        sum += (((IMEI[i] * 2)/10) + ((IMEI[i] * 2) %10) );
    }

    //Return the sum
    return sum;
}

//Int function for finding the check digit
int findCheck(int sumIn) {
    if((sumIn % 10) == 0) {
        //The check digit is zero if the sum ends in zero
        return 0;
    } else {
        //Returns 10 - the last digit
        return (10 - (sumIn % 10));
    }
}


//Creating a function that turns a string into the array for the IMEI.
void programArray(int *IMEI, FILE* IMEIfile, int *aliveAfter) {
    int tempDigit;
    for(int i = 0; i < 15; i++) {
        //If statement that ensures not at the end of file
        if(fscanf(IMEIfile, "%d", &tempDigit) != EOF) {
            IMEI[i] = tempDigit;
        } else {
            *aliveAfter = 0;
            return;
        }
    }
}

//Make the main section of the program
int main() {
    //Declaring the variables
    int IMEI[15], checkDigit, calculatedSum, aliveAfter = 1;
    FILE *inFile = NULL;

    //Begin opening file
    inFile = fopen("List_IMEI.txt", "r");
    if(inFile == NULL) {
        printf("File failed to open");
        return -1;
    }

    //Start the loop that runs for the entirety of the program from here on out, and closes when there are no more IMEIs to read
    while(1 == 1) {
        //Program the array to the scanned in IMEI
        programArray(&IMEI[0], inFile, &aliveAfter);
        //Check if the function reached the end of file, and quit if it did.
        if(aliveAfter == 0) {
            break;
        }

        //Calculate the sum for the later printing
        calculatedSum = calc_sum(IMEI, 15);
        //Find what the check digit needs to be
        checkDigit = findCheck(calculatedSum); 
        
        //Print the output
        printf("IMEI: ");
        print_IMEI(IMEI, 15);
        printf("\ntotal sum of 14 digits = %d", calculatedSum);
        printf("\nLuhn digit = %d", IMEI[14]);
        printf("\ncheck digit = %d", checkDigit);
        //If statement to determine if the IMEI is valid, and print if it is or not
        if(IMEI[14] == checkDigit) {
            printf("\nIMEI is valid\n");
        } else {
            printf("\nIMEI is invalid\n");
        }

        printf("\n");
    
    }

    return 0;
}