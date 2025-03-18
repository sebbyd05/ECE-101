#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>

int main() {
    
    //Define Variables
    int friPeople, satPeople, sunPeople;
    int friWholePizza, satWholePizza, sunWholePizza;
    double friSlicePP, satSlicePP, sunSlicePP;
    double friCostPizza, satCostPizza, sunCostPizza;
    double friCost, satCost, sunCost;
    double friTax, satTax, sunTax;
    double friDelivery, satDelivery, sunDelivery;
    double friPizzaQuant, satPizzaQuant, sunPizzaQuant;
    double friTotal, satTotal, sunTotal;
    double weekendTotal;

    //Aquire inputs
    scanf("%d", &friPeople);
    scanf("%lf", &friSlicePP);
    scanf("%lf", &friCostPizza);

    scanf("%d", &satPeople);
    scanf("%lf", &satSlicePP);
    scanf("%lf", &satCostPizza);
    
    scanf("%d", &sunPeople);
    scanf("%lf", &sunSlicePP);
    scanf("%lf", &sunCostPizza);

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

    sunPizzaQuant = (sunPeople * sunSlicePP) / 8;
    sunWholePizza = ceil(sunPizzaQuant);
    sunCost = sunWholePizza * sunCostPizza;
    sunTax = sunCost * .07;
    sunDelivery = (sunCost + sunTax) * .2;
    sunTotal = sunCost + sunDelivery + sunTax;

    weekendTotal = satTotal + friTotal + sunTotal;
    
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

    printf("\nSunday Night Party\n");
    printf("%d Pizzas: $%.2lf\n", sunWholePizza, sunCost);
    printf("Tax: $%.2lf\n", sunTax);
    printf("Delivery: $%.2lf\n", sunDelivery);
    printf("Total: $%.2lf\n", sunTotal);

    printf("\nWeekend Total: $%.2lf\n", weekendTotal);
    
    return 0;
}