#include<stdio.h>

int main() {
    //Declare variabled
    int n = 0, nSpaces, nChar, g, i, s, c;
    
    //Ask for user input and validate input
    for (g = 0; g < 100; g++) {
        if (n < 1 || n > 9) {
            printf("Enter only integer 1-9: ");
            scanf("%d", &n);
        } else {
            break;
        }
    }

    //Print the thing
    nSpaces = n - 1;
    nChar = 1;
    for (i=1; i <= n; i++) {
        for (s=1; s <= nSpaces; s++) {
            printf(" ");
        }
        for (c=1; c <= nChar; c++) {
            printf("%d", i);
        }
        nSpaces -=1;
        nChar += 2;
        printf("\n");
    }

    return 0;
}