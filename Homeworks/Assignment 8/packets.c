/*
Author: Sebastian Dziedzic
Date: 4/14/2025
I/O: 3 timestamp files, one ordered list
Algorithm: the merge command takes two lists, and goes through each list, storing the lowest value it sees from those two first in the combined list, it then incraments the memmory location in the one it took up by one. 
*/
#include<stdio.h>
#include<stdbool.h>
#define SIZE 9

//Read the file with the packets and stores them to the specified array
void readTimestamps(int arrayTarget[], FILE *input) {
    for(int i = 0; i < SIZE; i++) {
        //Scans file for next number and puts it in array at target location
        int currNumber;
        fscanf(input, "%d", &currNumber);
        arrayTarget[i] = currNumber;        
    }
    return;
}

//Merges two of the timestamp arrays together to create one
void mergeTimestamps(int inArray1[], int array1Size, int inArray2[], int array2Size, int outArray[], int outArraySize) {
    int a1Loc = 0;
    int a2Loc = 0;

    for(int i = 0; i < outArraySize; i++) {
        if((inArray1[a1Loc] <= inArray2[a2Loc] && inArray1[a1Loc] != '\0') || inArray2[a2Loc] == '\0') {
            outArray[i] = inArray1[a1Loc];
            a1Loc++;
        } else if((inArray2[a2Loc] <= inArray1[a1Loc] && inArray2[a2Loc] != '\0') || inArray1[a1Loc] == '\0') {
            outArray[i] = inArray2[a2Loc];
            a2Loc++;
        }
    }

    outArray[outArraySize] = '\0';

    return;
}

//Prints the timestamps in the inputted array
void printTimestamps(int array[], int size) {
    printf("%d", array[0]);
    for(int i = 1; array[i] != '\0'; i++) {
        printf(",%d", array[i]);
    }
    printf(".");
    return;
}

//Main function that reads the files
int main() {
    int timeArray1[SIZE];
    int timeArray2[SIZE];
    int timeArray3[SIZE];
    int combinedTime1[18];
    int combinedTime2[27];

    FILE *currFile = NULL;

    //Open the first file and store it in timeArray 1
    currFile = fopen("timestamp1.txt", "r");
    if(currFile == NULL) {
        return -1;
    }
    readTimestamps(timeArray1, currFile);
    fclose(currFile);

    //Repeats for timestamp file 2
    currFile = fopen("timestamp2.txt", "r");
    if(currFile == NULL) {
        return -2;
    }
    readTimestamps(timeArray2, currFile);
    fclose(currFile);

    //Repeats for timestamp file 3
    currFile = fopen("timestamp3.txt", "r");
    if(currFile == NULL) {
        return -3;
    }
    readTimestamps(timeArray3, currFile);
    fclose(currFile);

    //Perform the two merges, the first one stores to combinedTime1, which is then used to merge the next to it and is put into an array called combinedTime2
    mergeTimestamps(timeArray1, 9, timeArray2, 9, combinedTime1, 18);
    mergeTimestamps(combinedTime1, 18, timeArray3, 9, combinedTime2, 27);
    
    //Print the new array
    printTimestamps(combinedTime2, 27);
    return 0;
}