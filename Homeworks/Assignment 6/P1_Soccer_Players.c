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

//Creating the function the user interacts with initally
int main() {
    //Declare the arrays for later
    int playerNumber[5];
    int playerRating[5];

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
    
    //End
    return 0;
}