#include<stdio.h>
#include<string.h>

int isPalendrome(char word[]) {
    int size, oppositeSide;
    
    size = strlen(word);
    oppositeSide = size;

    for(int i = 0; i < size; i++) {
        if(word[i] != word[(oppositeSide - 1)]) {
            return 0;
        }
        oppositeSide--;
    }

    return 1;
}

int main() {
    //Create array for charecters
    char word[50];
    char optionIn;

    while(1==1) {
        printf("\nEnter a word: ");
        scanf("%s ", word);

        if(isPalendrome(word) == 1) {
            printf("%s is a palindrome", word);
        } else {
            printf("%s is NOT a palindrome", word);
        }

        printf("\nPress q/Q to quit, others to continue: ");
        
        scanf(" %c ", &optionIn);

        if(optionIn == 'q' || optionIn == 'Q') {
            printf("Goodbye\n");
            return 0;
        }
    }
}