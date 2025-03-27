#include<stdio.h>

int max1(int array[]) {
    int currMax = 0;

    for(int i = 0; i < 8; i++) {
        if(array[i] > currMax) {
            currMax = array[i];
        }
    }

    return currMax;
}

int max2(int array[], int maxMax) {
    int currMax = 0;
    
    for(int i = 0; i < 8; i++) {
        if(array[i] > currMax && array[i] < maxMax) {
            currMax = array[i];
        }
    }
    
    return currMax;
}

int main () {
    int inValues[8];
    int calcmax1, calcmax2;
    for(int i = 0; i < 8; i++) {
        scanf("%d ", &inValues[i]);
    }

    calcmax1 = max1(inValues);
    calcmax2 = max2(inValues, calcmax1);

    printf("%d %d", calcmax1, calcmax2);
}