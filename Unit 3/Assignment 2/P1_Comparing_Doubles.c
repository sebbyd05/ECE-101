#include<stdio.h>
#include<math.h>

int main() {
    double comp1, comp2, difference;

    scanf("%lf", &comp1);
    scanf("%lf", &comp2);
    scanf("%lf", &difference);

    if (fabs((comp1 - comp2)) <= 0.001) {
        printf("equal\n");
    }
    else if (fabs((comp1 - comp2)) <= difference) {
        printf("close enough\n");
    }
    else {
        printf("not close\n");
    }
    
    return 0;
}