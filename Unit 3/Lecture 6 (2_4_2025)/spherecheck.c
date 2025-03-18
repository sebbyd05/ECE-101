#include<stdio.h>
#include<math.h>

int main() {
    double r_sphere, side_cube, vol_Sphere, vol_Cube;

    scanf("%lf", &r_sphere);
    scanf("%lf", &side_cube);

    vol_Cube = pow(side_cube, 3.0);

    vol_Sphere = (4.0/3.0) * M_PI * pow(r_sphere, 3.0);

    if (vol_Cube > vol_Sphere) {
        printf("The cube is larger, with a volume of %lf compared to a volume of %lf", vol_Cube, vol_Sphere);
    }
    else if (vol_Sphere > vol_Cube) {
        printf("The sphere is larger, with a volume of %lf compared to a volume of %lf", vol_Sphere, vol_Cube);
    }
    return 0;
}