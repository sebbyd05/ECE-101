#include<stdio.h>

int main() {
    int playerMove, turn;
    char playerTurn, sq1, sq2, sq3, sq4, sq5, sq6, sq7, sq8, sq9;
    sq1 = sq2 = sq3 = sq4 = sq5 = sq6 = sq7 = sq8 = sq9 = ' ';
    playerTurn = 'x';

    // Draw the grid
    printf("|%c|%c|%c|\n", sq1, sq2, sq3);
    printf("-------\n");
    printf("|%c|%c|%c|\n", sq4, sq5, sq6);
    printf("-------\n");
    printf("|%c|%c|%c|\n", sq7, sq8, sq9);
    
    for (turn = 0; turn < 9; turn++) {
        // Have player play
        printf("Player %c please choose a square (1-9): ", playerTurn);
        scanf("%d", &playerMove);

        // Set square to be the value based on picked square
        switch (playerMove) {
        case 1:
            if (sq1 == ' ') {
                sq1 = playerTurn;
            }
            break;
        case 2:
            if (sq2 == ' ') {
                sq2 = playerTurn;
            }
            break;
        case 3:
            if (sq3 == ' ') {
                sq3 = playerTurn;
            }
            break;
        case 4:
            if (sq4 == ' ') {
                sq4 = playerTurn;
            }
            break;
        case 5:
            if (sq5 == ' ') {
                sq5 = playerTurn;
            }
            break;
        case 6:
            if (sq6 == ' ') {
                sq6 = playerTurn;
            }
            break;
        case 7:
            if (sq7 == ' ') {
                sq7 = playerTurn;
            }
            break;
        case 8:
            if (sq8 == ' ') {
                sq8 = playerTurn;
            }
            break;
        case 9:
            if (sq9 == ' ') {
                sq9 = playerTurn;
            }
            break;
        default:
            printf("That is not a valid move\n");
            turn--; // Invalid move, do not count this turn
            continue;
        }

        // Print the grid again
        printf("|%c|%c|%c|\n", sq1, sq2, sq3);
        printf("-------\n");
        printf("|%c|%c|%c|\n", sq4, sq5, sq6);
        printf("-------\n");
        printf("|%c|%c|%c|\n", sq7, sq8, sq9);

        // Change to the next player's turn
        if (playerTurn == 'x') {
            playerTurn = 'o';
        } else {
            playerTurn = 'x';
        }
    }

    return 0;
}