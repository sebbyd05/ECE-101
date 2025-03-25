#include<stdio.h>

void printArray(int array[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d", array[i]); //Keeps printing the next value of the array
    }
} 

int main() {
    
    int x[4]= {1, 2, 3, 4}; //Declaring the array

    printArray(x, 4); //Telling the function that there is an array

    return 0;
}