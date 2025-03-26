#include<stdio.h>

int codeFinder(int codes[], int code, int size) {
    for(int i = 0; i < size; i++) {
        if(codes[i] == code) {
            return 1;
        }
    }

    return 0;
}


int main() {
    //Creating the array and variables
    int list[50];
    int currSize;
    int currPos = 0;
    int currNum;
    FILE *inCodes = NULL;

    inCodes = fopen("codes.txt", "r");

    if(inCodes == NULL) {
        printf("File failed to open");
        return -1;
    }

    while(fscanf(inCodes, "%d", &currNum) != EOF) {
        if(codeFinder(list, currNum, currPos) == 0) {
            list[currPos] = currNum;
        }
        currPos++;
    }

    for(int i=0; i <= currPos; i++) {
        printf("%d ", list[i]);
    }

    return 0;
}