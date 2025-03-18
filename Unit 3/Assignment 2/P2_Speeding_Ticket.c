#include<stdio.h>
#include<math.h>

int main() {
    
    int speedLimit, speedDriving, speedDifference;

    scanf("%d", &speedLimit);
    scanf("%d", &speedDriving);

    speedDifference = speedDriving - speedLimit;

    if (speedDifference <= -10) {
        printf("50");
    } 
    else if (speedDifference >= 6 && speedDifference <= 20) {
        printf("75");
    }
    else if (speedDifference >= 21 && speedDifference <= 40) {
        printf("150");
    }
    else if (speedDifference > 40) {
        printf("300");
    }
    else {
        printf("0");
    }
}