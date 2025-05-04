#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Step 1: Player Struct node
typedef struct Player {
    char name[30];
    int level;
    struct Player* next;
} Player;

int main() {
    // Step 2: Initialize the head of the list
    Player* head = NULL;

    // Step 3: Create first player 
    Player* player1 = (Player*)malloc(sizeof(Player));

    player1->level = 1;
    strcpy(player1->name, "George");
    player1->next = NULL;

    head = player1;

    // Step 4:Add players
    //Create second player 
    Player* player2 = (Player*)malloc(sizeof(Player));

    player2->level = 3;
    strcpy(player2->name, "Bill");
    player2->next = NULL;
    
    player1->next=player2;

    //Create a third player

    Player* player3 = (Player*)malloc(sizeof(Player));

    player3->level = 7;
    strcpy(player3->name, "Rick");
    player3->next = NULL;
    
    player2->next=player3;
    
    // Step 5: Traverse and print the list
    printf("Player roster: ");
    
    Player* temp = head;
    
    while(temp != NULL) {
        printf("\nLevel: %d", temp->level);
        printf("\nName: %s", temp->name);

        temp = temp->next;
    }
    
    //Add a block
    Player* insertedPlayer = (Player*)malloc(sizeof(Player));
    
    insertedPlayer->level = 3;
    strcpy(insertedPlayer->name, "Rob");

    insertedPlayer->next = player2->next;
    player2->next = insertedPlayer;

    // Step 6: Free the list
    Player *temp2 = head;
    Player *freeP = temp2;
    while (freeP != NULL) {
        temp2 = freeP->next;
        free(freeP);
        freeP = temp2;
    }
    

    return 0;
}
