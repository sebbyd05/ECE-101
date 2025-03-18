#include<stdio.h>

int main() {
    int decibles;

    scanf("%d", &decibles);

    if (decibles <= 50 && decibles >= 0) {
        printf("It is quiet");
    }
    else if (decibles >= 51 && decibles <= 70) {
        printf("It is intrusive");
    }
    else if (decibles >= 71 && decibles <= 90) {
        printf("It is annoying");
    }
    else if (decibles >= 91 && decibles <= 110) {
        printf("It is very annoying");
    }
    else if (decibles > 110) {
        printf("It is uncomfotable");
    }
    else {
        printf("There's no negative sound!");
    }
    
    return 0;
}