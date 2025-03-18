#include<stdio.h>

int main () {
    char letter, nextLetter;

    scanf("%c", &letter);

    if (letter >= 97 && letter <= 123) {
        nextLetter = letter - 32;
        printf("%c%c", letter, nextLetter);
    }
    else if (letter >= 65 && letter <= 91) {
        nextLetter = letter + 32;
        printf("%c%c", letter, nextLetter);
    }
    else {
        printf("%c", letter);
    }
    return 0;
}