#include<stdio.h>

int main() {
    const int MAX_NUMBER = 100;
    const int LOW_NUMBER = 1;
    int playerNumber, numAttempts = 0, guessNum = 0;
    
    printf("Please enter a number between %d and %d: ", LOW_NUMBER, MAX_NUMBER);
    scanf("%d", &playerNumber);

    if (playerNumber < LOW_NUMBER || playerNumber > MAX_NUMBER) {
        printf("\nPlease run again, next time enter a number between %d and %d!!", LOW_NUMBER, MAX_NUMBER);
        return 1;
    }

    while (playerNumber != guessNum) {
        printf("\nChoose a guess between %d and %d: ", LOW_NUMBER, MAX_NUMBER);
        scanf("%d", &guessNum);
        numAttempts += 1;
        if (guessNum < LOW_NUMBER || guessNum > MAX_NUMBER) {
            printf("\nYour guess must be between %d and %d!", LOW_NUMBER, MAX_NUMBER);
        } else if (guessNum == playerNumber) {
            printf("\nCorrect, %d was the answer", playerNumber);
        } else if (guessNum > playerNumber) {
            printf("\n%d is too high!", guessNum);
        } else if (guessNum < playerNumber) {
            printf("\n%d is too low!", guessNum);
        }
    }

    printf("\nIt took you %d attempts to guess the #!", numAttempts);
    return 0;
    
}