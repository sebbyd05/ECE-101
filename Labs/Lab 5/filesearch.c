#include<stdio.h>

int CountInts(FILE *inp, int target) {
    int currentVal, trueCount = 0;
    //Reads intergers till end of file, increments if the value is >= to the target
    while(fscanf(inp, "%d", &currentVal) != EOF) {
        if(currentVal >= target){
            trueCount++;
        }
    }
    return trueCount;
}

int main() {
    //Define Variables
    FILE* inFile = NULL;
    int userTarget;

    //Open File
    inFile = fopen("MyData.dat", "r");

    //Notify user if file fails to open
    if(inFile == NULL) {
        printf("The file failed to open, goodbye!");
        return -1;
    }

    //Ask user for input
    printf("Count the number of integers above what threshold? ");
    scanf("%d", &userTarget);

    //Print the result while calling the function and passing the function to it
    printf("The number of integers >= %d was found to be %d\n", userTarget, CountInts(inFile, userTarget));
    return 0;
}