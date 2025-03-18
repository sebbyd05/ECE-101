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
    double friPizzaQuant;

    //Aquire inputs
    scanf("%d", &friPeople);
    scanf("%lf", &friSlicePP);
    scanf("%lf", &friCostPizza);

    //Perform Math
    friPizzaQuant = (friPeople * friSlicePP) / 8;
    friWholePizza = ceil(friPizzaQuant);
    friCost = friWholePizza * friCostPizza;

    //Output Results
    printf("Friday Night Party\n");
    printf("%d Pizzas: $%.2lf\n", friWholePizza, friCost);


}