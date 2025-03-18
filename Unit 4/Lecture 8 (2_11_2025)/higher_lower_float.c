//This is incomplete, my brain hurts and I don't feel like doing this tbh
//make it work with floats or something and the guess of it being within .0001

#include<stdio.h>
#include<math.h>

int main() {
    const int MAX_NUMBER = 100;
    const int LOW_NUMBER = 1;
    float playerNumber, guessNum = 0;
    
    printf("Please enter a number between %d and %d: ", LOW_NUMBER, MAX_NUMBER);
    scanf("%f", &playerNumber);

    if (playerNumber < LOW_NUMBER || playerNumber > MAX_NUMBER) {
        printf("\nPlease run again, next time enter a number between %d and %d!!", LOW_NUMBER, MAX_NUMBER);
        return 1;
    }

    while (playerNumber != guessNum) {
        printf("\nChoose a guess between %d and %d: ", LOW_NUMBER, MAX_NUMBER);
        scanf("%d", &guessNum);
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

    return 0;
    
}