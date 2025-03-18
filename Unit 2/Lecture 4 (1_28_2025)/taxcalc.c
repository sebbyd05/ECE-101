#include<stdio.h>

int main() {

    float price1, price2, price3;
    float finalPrice;

    printf("Item 1 Costs: ");
    scanf("%f", &price1);
    printf("\nItem 2 Costs: ");
    scanf("%f", &price2);
    printf("\nItem 3 Costs: ");
    scanf("%f", &price3);

    finalPrice = (price1 + price2 + price3) * 1.07;

    printf("\nThe final price is %.2f", finalPrice);

    return 0;
}