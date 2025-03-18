#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main() {
    
    //Define Variables
    int friPeople;
    int friWholePizza;
    double friSlicePP;
    double friCostPizza;
    double friCost;
    double friTax;
    double friDelivery;
    double friPizzaQuant;
    double friTotal;

    //Aquire inputs
    scanf("%d", &friPeople);
    scanf("%lf", &friSlicePP);
    scanf("%lf", &friCostPizza);

    //Perform Math
    friPizzaQuant = (friPeople * friSlicePP) / 8;
    friWholePizza = ceil(friPizzaQuant);
    friCost = friWholePizza * friCostPizza;
    friTax = friCost * .07;
    friDelivery = (friCost + friTax) * .2;
    friTotal = friCost + friDelivery + friTax;

    //Output Results
    printf("Friday Night Party\n");
    printf("%d Pizzas: $%.2lf\n", friWholePizza, friCost);
    printf("Tax: $%.2lf\n", friTax);
    printf("Delivery: $%.2lf\n", friDelivery);
    printf("Total: $%.2lf\n", friTotal);

    return 0;
}