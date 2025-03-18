#include<stdio.h>

int main() {
    int inputNum = 0, calcNum, i;
    char cont;

    for (i = 0; cont = 'n'; i++) {
        printf("Enter a number");
        scanf("%d", &inputNum);
        calcNum += inputNum;
        printf("The current number is %d would you like to continue (y/n)", calcNum);
        scanf("%c", cont);
    }
    printf("The final sum was %d", calcNum);
}