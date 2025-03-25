#include<stdio.h>
#include<math.h>

int main() {

    //Defining Variables
    double radius, height, volume, area;

    //Accepting Input
    //printf("Radius = ");
    scanf("%lf", &radius);
    //printf("\nHeight = ", height);
    scanf("%lf", &height);

    //Perform Math
    volume = M_PI * pow(radius, 2) * height;
    area = (2 * M_PI * radius * height) + (2 * M_PI * pow(radius, 2));

    //Output Results
    printf("Volume: %.1lf cubic inches\n", volume);
    printf("Surface area: %.1lf square inches\n", area);
       
    return 0;
}