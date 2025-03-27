#include<stdio.h>
#define SIZE 3

int main() {
    int maxRow = 0, rowSize[3] = {0,0,0};
    int array[SIZE][SIZE];
    
    for(int row = 0; row < SIZE; row++) {
        printf("Row %d:", row);
        for(int col = 0; col < SIZE; col++) {
            scanf("%d", &array[row][col]);
        }
    }

    for(int row = 0; row < SIZE; row++) {
        for(int col = 0; col < SIZE; col++) {
            rowSize[row] += array[row][col];
        }
        printf("Row %d total: %d\n", row, rowSize[row]);
    }
    for(int row = 0; row < SIZE; row++) {
        if(rowSize[row] > rowSize[maxRow]) {
            maxRow = row;
        }
    }

    printf("\nRow %d has the highest total", maxRow);

    return 0;
}