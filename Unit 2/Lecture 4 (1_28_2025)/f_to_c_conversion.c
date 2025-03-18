#include<stdio.h>

int main(){

    float fer, cel;

    printf("Temperature in F is: ");
    scanf("%f", &fer);

    cel = (5.0/9.0)*(fer - 32.0);

    printf("\n%.2f degrees F is %.2f degrees C", fer, cel);

    return 0;

}