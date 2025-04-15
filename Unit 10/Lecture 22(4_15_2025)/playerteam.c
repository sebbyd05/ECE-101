#include <stdio.h>
#include <string.h>

// Define the Player struct
typedef struct playerInfo {
    char name[20];
    char class[20];
    int level;
    int health;
    int attack;
    int defense;
} playerInfo;

void displayPlayer (playerInfo player) {
    printf("---------------\n");
    printf("Name: %s\n", player.name);
    printf("Class: %s\n", player.class);
    printf("Level: %d\n", player.level);
    printf("Health: %d\n", player.health);
    printf("Attack: %d\n", player.attack);
    printf("Defense: %d\n", player.defense);
    printf("---------------\n");
    
    return;
}

//print function desplay()
int main() {
    // Create and initialize three players
    playerInfo player1 = {"John", "Mage", 10, 100, 23, 1000}, player2 = {"Bob", "Wizard", 1000, 100, 22, 10}, player3 = {"Ronald", "God", 10000, 100000, 10000,10000};

    // print elements for player 1
    printf("Name:%s\nClass:%s\nLevel:%d\nHealth:%d\nAttack:%d\nDefense:%d\n", player1.name, player1.class, player1.level, player1.health, player1.attack, player1.defense);
    // use a print function desplay()
    displayPlayer(player1);
    displayPlayer(player2);
    displayPlayer(player3);

    return 0;
}
