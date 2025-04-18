#include<stdio.h>
#include<math.h>


typedef struct cartesian_s {
    double x, y, z;
} cartesian;

typedef struct spherical_s {
    double rho;
    double theta_degree;
    double phi_degree;
} spherical;

int main(){
    cartesian userIn;
    spherical sphereOut;

    while(1==1) {
        char repeat;

        //Get user input
        printf("Enter Cartesian coordinate values for x, y and z: ");
        scanf("%lf%lf%lf", &userIn.x, &userIn.y, &userIn.z);

        //Convert to sphere
        sphereOut.rho = sqrt((pow(userIn.x, 2.0)+pow(userIn.y, 2.0)+pow(userIn.z, 2.0)));
        sphereOut.theta_degree = (atan((userIn.y/userIn.x)) * (180.0 / M_PI));
        sphereOut.phi_degree = (atan((sqrt(pow(userIn.x, 2.0)+pow(userIn.y, 2.0)))/userIn.z) * (180.0/ M_PI));

        //Output results
        printf("its spherical value: rho = %.2lf, theta (degrees) = %.2lf, phi (degrees) = %.2lf", sphereOut.rho, sphereOut.theta_degree, sphereOut.phi_degree);

        //Ask the user if they wish to continue
        printf("\nContinue (n for no)");
        scanf("%c", &repeat);
        if(repeat == 'n') {
            break;
        }
    }

    return 0;
}
