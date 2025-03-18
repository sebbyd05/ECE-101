#include<stdio.h>

int main() {
    int inputNumber;
    int sum = 1;

    printf("Number to calculate = ");
    scanf("%d", &inputNumber);

    while (inputNumber > 1) {
        sum = sum * inputNumber;
        inputNumber -= 1;
    }

    printf("\nThe factorial value is: %d", sum);

    return 0;
}