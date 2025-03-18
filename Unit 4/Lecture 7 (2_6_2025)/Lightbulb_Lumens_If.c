#include<stdio.h>
#include<math.h>

int main() {
    int wattage;

    printf("Please enter the wattage of the bulb!\n");
    scanf ("%d", &wattage);

    if (wattage == 15) {
        printf("\nThe bulb's brightness is 125 Lumens");
    } else if (wattage == 25) {
        printf("\nThe bulb's brightness is 215 Lumens");
    } else if (wattage == 40) {
        printf("\nThe bulb's brightness is 500 lumens");
    } else if (wattage == 60) {
        printf("\nThe bulb's brightness is 800 lumens");
    } else {
        printf("\nThat value is not supported.");
    }
    
    return 0;

}