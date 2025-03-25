#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main() {
    
    //Define Variables
    int friPeople, satPeople;
    int friWholePizza, satWholePizza;
    double friSlicePP, satSlicePP;
    double friCostPizza, satCostPizza;
    double friCost, satCost;
    double friTax, satTax;
    double friDelivery, satDelivery;
    double friPizzaQuant, satPizzaQuant;
    double friTotal, satTotal;
    double weekendTotal;

    //Aquire inputs
    scanf("%d", &friPeople);
    scanf("%lf", &friSlicePP);
    scanf("%lf", &friCostPizza);

    scanf("%d", &satPeople);
    scanf("%lf", &satSlicePP);
    scanf("%lf", &satCostPizza);
    
    //Perform Math
    friPizzaQuant = (friPeople * friSlicePP) / 8;
    friWholePizza = ceil(friPizzaQuant);
    friCost = friWholePizza * friCostPizza;
    friTax = friCost * .07;
    friDelivery = (friCost + friTax) * .2;
    friTotal = friCost + friDelivery + friTax;

    satPizzaQuant = (satPeople * satSlicePP) / 8;
    satWholePizza = ceil(satPizzaQuant);
    satCost = satWholePizza * satCostPizza;
    satTax = satCost * .07;
    satDelivery = (satCost + satTax) * .2;
    satTotal = satCost + satDelivery + satTax;

    weekendTotal = satTotal + friTotal;
    
    //Output Results
    printf("Friday Night Party\n");
    printf("%d Pizzas: $%.2lf\n", friWholePizza, friCost);
    printf("Tax: $%.2lf\n", friTax);
    printf("Delivery: $%.2lf\n", friDelivery);
    printf("Total: $%.2lf\n", friTotal);

    printf("\nSaturday Night Party\n");
    printf("%d Pizzas: $%.2lf\n", satWholePizza, satCost);
    printf("Tax: $%.2lf\n", satTax);
    printf("Delivery: $%.2lf\n", satDelivery);
    printf("Total: $%.2lf\n", satTotal);
    
    printf("\nWeekend Total: $%.2lf\n", weekendTotal);
    
    return 0;
}