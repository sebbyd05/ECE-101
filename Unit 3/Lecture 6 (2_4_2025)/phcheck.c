#include<stdio.h>

int main() {
    int ph;

    scanf("%d", &ph);

    if (ph <= 7) {
        if (ph == 7) {
            printf("Neutral");
        }
        else if (ph > 2) {
            printf("Acidic");
        }
        else {
            printf("Very Acidic");
        }
    } 
    else if (ph > 7) {
        if (ph < 12) {
            printf("Alkaline");
        }
        else {
            printf("Very Alkaline");
        }
    }
    
    return 0;
}