/*
Author: Sebastian Dziedzic
Date: 3/9/2025

*/
#include<stdio.h>
#include<math.h>

double find_magnitude(double Vx, double Vy, double Vz) {
    //Define function exclusive variables
    double magOut, preSQRT;

    //Do the math
    preSQRT = pow(Vx, 2.0) + pow(Vy, 2.0) + pow(Vz, 2.0);
    magOut = sqrt(preSQRT);

    return magOut;
}

void find_dotprod_angledeg(double Vx1, double Vy1, double Vz1, double Vx2, double Vy2, double Vz2, double *dotprod, double *angle_deg) {
    //Define the variables needed for just this
    double mag1, mag2;

    //Find the magnitudes of each for later
    mag1 = find_magnitude(Vx1, Vy1, Vz1);
    mag2 = find_magnitude(Vx2, Vy2, Vz2);
    
    //Output the things sense its a void
    *dotprod = (Vx1 * Vx2) + (Vy1 * Vy2) + (Vz1 * Vz2);
    *angle_deg = acos((*dotprod/(mag1 * mag2))) * (180 / 3.14159);
}

int main() {
    //Declare variables
    char userSelection;
    double inVx1, inVy1, inVz1, inVx2, inVy2, inVz2, outDotProd, outAngle;

    while(1 == 1) {
        //Ask the user for an input
        printf("3-D Vector calculation\n");
        printf("Enter M or m to find the magnitude\n");
        printf("Enter D or d to find the dot product and angle in degrees");
        printf("Enter Q or q to Quit\n");
        printf("Enter your choice: ");
        scanf("%c", &userSelection);

        //Have the user call a function based on their selection and inputs
        if(userSelection == 'm' || userSelection == 'M') {
            printf("\nEnter Vx Vy Vz (separated by spaces): ");
            scanf("%lf %lf %lf", &inVx1, &inVy1, &inVz1);
            printf("\nmagnitude of <%.2lf, %.2lf, %.2lf> is %.4lf\n", inVx1, inVy1, inVz1, find_magnitude(inVx1, inVy1, inVz1));
            printf("\n");
        } else if(userSelection == 'd' ||userSelection == 'D') {
            printf("\nEnter Vx1 Vy1 Vz1 (separated by spaces): ");
            scanf("%lf %lf %lf", &inVx1, &inVy1, &inVz1);
            printf("\nEnter Vx2 Vy2 Vz2 (separated by spaces): ");
            scanf("%lf %lf %lf", &inVx2, &inVy2, &inVz2);
            find_dotprod_angledeg(inVx1, inVy1, inVz1, inVx2, inVy2, inVz2, &outDotProd, &outAngle);
            printf("\n<%.2lf, %.2lf, %.2lf> dot <%.2lf, %.2lf, %.2lf> is %.4lf", inVx1, inVy1, inVz1, inVx2, inVy2, inVz2, outDotProd);
            printf("angle between these 2 vectors is %.4lf degrees\n\n", outAngle);
        } else if(userSelection == 'q' || userSelection == 'Q') {
            printf("\nGood Bye\n");
            return 0;
        } else {
            printf("\nwrong option entered\n\n");
        }
    }
}