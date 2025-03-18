#include<stdio.h>

int main() {

    int n, i, sum = 0;

    //Get input
    printf("Enter n value: ");
    scanf("%d", &n);

    //Do math
    for (i = 0; i <= n; ++i) {
        sum += i;
    }

    //Return result
    printf("Sum of 1 to %d is %d\n", n, sum);

    return 0;
}