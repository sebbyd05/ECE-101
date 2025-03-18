#include<stdio.h>

int main() {
    //Declare the variables
    float price1;
    int quantity;
    float finalPrice;

    //Ask the user for inputs
    printf("The item costs: ");
    scanf("%f", &price1);
    printf("\nI have this many of these items: ");
    scanf("%d", &quantity);

    //Do the math
    finalPrice = (price1 * quantity) * 1.07;

    //Tell the user the results
    printf("\nThe final price is %.2f", finalPrice);

    return 0;
}