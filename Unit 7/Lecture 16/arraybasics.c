#include<stdio.h>

void printArray(int *array2, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d", array2[i]); //Keeps printing the next value of the array
    }
    printf("\n");
} 

void initiateArray(int *array1, int size, int n) {
    for(int i = 0; i < size; i++) {
        array1[i] = array1[i] + n;
    }
}

int main() {
    
    int x[4]= {1, 2, 3, 4}; //Declaring the array

    printArray(&x[0], 4); //Telling the function that there is an array
    initiateArray(&x[0], 4, 2);
    printArray(&x[0], 4);

    return 0;
}