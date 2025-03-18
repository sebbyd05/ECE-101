#include<stdio.h>

int main() {
    //Define variables
    double inRad, halfLife, hoursCalc = 0.0;

    //Ask user for input
    printf("Enter initial amount of radiation: ");
    scanf("%lf", &inRad);
    printf("Enter half-life in hours: ");
    scanf("%lf", &halfLife);

    //Process and return data
    if (inRad < .5) {
        printf("the radiation is already below safe level of 0.50\n");
        return 1;
    }
    
    printf("Hours \tRadiation\n");
    printf("%.2lf\t%.4lf\n", hoursCalc, inRad);
    
    while (inRad >= .5) {
        inRad /= 2.0;
        hoursCalc += halfLife;
        printf("%.2lf\t%.4lf\n", hoursCalc, inRad);
    }
    
    printf("After %.2lf hours, the radiation level is %.4lf (below 0.50)\n", hoursCalc, inRad);
    
}