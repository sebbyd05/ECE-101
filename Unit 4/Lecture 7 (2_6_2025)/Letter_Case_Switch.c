#include<stdio.h>

int main () {
    char letter, nextLetter;

    scanf("%c", &letter);

    switch(letter) {
        case 97 ... 123:
            nextLetter = letter - 32;
            printf("%c%c", letter, nextLetter);
            break;
        case 65 ... 91:
            nextLetter = letter + 32;
            printf("%c%c", letter, nextLetter);
            break;
        default:
            printf("%c", letter);
    }

    return 0;
}