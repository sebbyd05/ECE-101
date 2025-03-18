#include<stdio.h>
#include<math.h>

int main() {
    int wattage;

    printf("Please enter the wattage of the bulb!\n");
    scanf ("%d", &wattage);

    switch (wattage) {
        case 15:
            printf("\nThe bulb's brightness is 125 Lumens");
            break;
        case 25:
            printf("\nThe bulb's brightness is 215 Lumens");
            break;
        case 40 ... 43:
            printf("\nThe bulb's brightness is 500 lumens");
            break;
        case 60:
        case 61:
        case 62:
            printf("\nThe bulb's brightness is 800 lumens");
            break;
        default:
            printf("\nThat value is not supported.");
    }
}