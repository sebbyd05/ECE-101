/*
Author: Sebastian Dziedzic
Date Created: 3/25/2025
Algorithm: Has two arrays, one for jersey#, one for rating, for each player it goes up one section of the array,
the section number represents one less than the player #.
*/

#include<stdio.h>

//A function that outputs the values based on what the user inputs
void outputRoster(int numberArray[], int ratingArray[]) {
    //Print the header of the roster section
    printf("ROSTER\n");

    //Loop a print statement for as long as there are players to print
    for(int i = 1; i <= 5; i++) {
        printf("Player %d -- Jersey number: %d, Rating: %d\n", i, numberArray[i-1], ratingArray[i-1]);    
    }
}

//A function that allows the user to update a player rating, only needs the rating to be pass through
void updatePlayer(int numberArray[], int *ratingArray) {
    //Variables to allow code to find what to update
    int lookNum, newRating, cellToUpdate;
    //Attain desired update`
    printf("\n");
    printf("\nEnter a jersey number:\n");
    scanf("%d ", &lookNum);
    printf("Enter a new rating for player:\n");
    scanf("%d", &newRating);
    
    //Search for the cell that has the specified jersey number
    for(int i = 0; i <= 4; i++) {
        if(numberArray[i] == lookNum) {
            cellToUpdate = i;
        }
    }

    //Once it has the cell to update, it updates the pointer
    ratingArray[cellToUpdate] = newRating; 
}

//Creating the function the user interacts with initally
int main() {
    //Declare the arrays for later
    int playerNumber[5];
    int playerRating[5];

    //Declare a variable for the user to select menu options with
    char userSelect;

    //Collect player data
    for(int i = 1; i <=5; i++) {
        printf("Enter player %d's jersey number:\n", i);
        scanf("%d", &playerNumber[i-1]);
        printf("Enter player %d's rating:\n", i);
        scanf("%d", &playerRating[i-1]);
        printf("\n");
    }

    //Call the roster output function
    outputRoster(playerNumber, playerRating);
    
    //Start an infinite loop for the menu
    while (1==1) {
        //Display the menu for the user
        printf("\nMENU\n");
        printf("u - Update player rating\n");
        printf("a - Output players above a rating\n");
        printf("r - Replace player\n");
        printf("o - Output roster\n");
        printf("q - Quit\n");
        printf("\nChoose an option:\n");
        scanf(" %c", &userSelect);
        scanf("%*c");

        //Detects what the user inputs to go to the requested function            
        if (userSelect == 'q') {
            //If the user wants to quit, exit the program
            break;
        } else if(userSelect == 'u') {
            updatePlayer(playerNumber, &playerRating[0]);
        }
    }

    //End
    return 0;
}