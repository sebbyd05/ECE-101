#include<stdio.h>
#include<math.h>

int main() {
    double sideA, sideB, sideC;

    //Ask user for input
    printf("Enter in three sides of a triangle A,B,C: ");
    scanf("%lf", &sideA);
    scanf("%lf", &sideB);
    scanf("%lf", &sideC);

    //Determine what kind of triangle and report to user
    if ((sideA + sideB) > sideC && (sideB + sideC) > sideA && (sideC + sideA) > sideB) {
        if (sideA == sideB || sideA == sideC || sideB == sideC) {
            printf("\nSides A = %.2lf, B = %.2lf, C = %.2lf will form an isosceles triangle\n", sideA, sideB, sideC);
        } else if ((pow(sideA, 2) + pow(sideB, 2)) == pow(sideC, 2) || (pow(sideB, 2) + pow(sideC, 2)) == pow(sideA, 2) || (pow(sideC, 2) + pow(sideA, 2)) == pow(sideB, 2)) {
            printf("\nSides A = %.2lf, B = %.2lf, C = %.2lf will form a right triangle\n", sideA, sideB, sideC);
        } else {
            printf("\nSides A = %.2lf, B = %.2lf, C = %.2lf can be formed into a triangle\n", sideA, sideB, sideC);
        }
    } else {
        printf("\nSides A = %.2lf, B = %.2lf, C = %.2lf cannot be formed into a triangle\n", sideA, sideB, sideC);
    }

    return 0;
}