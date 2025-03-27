#include<stdio.h>

int main() {
    //Arrays can have both rows and collums
    int array[/*# of rows*/3][/*# of collums*/2]={{10,20},{30,40},{50,60}};
    //So it's more like a table

    for(int row = 0; row < 3; row++) {
        for(int col = 0; col < 2; col++){
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }
}