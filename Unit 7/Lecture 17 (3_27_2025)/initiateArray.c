#include <stdio.h>
#define row_size  2
#define col_size  2

void initiate(int arr[][col_size], int inInt) {
    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++){
            arr[row][col] = inInt;
        }
        printf("\n");
    }
}

int main()
{
    // Define variables
    int input;
    int array[row_size][col_size];    
    // call function
    initiate(array, 3);

    for(int row = 0; row < 5; row++) {
        for(int col = 0; col < 5; col++){
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }

    return 0;
}
