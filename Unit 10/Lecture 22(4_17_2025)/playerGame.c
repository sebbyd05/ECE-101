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

//print function desplay()
void printPlayer(playerInfo player) {
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

//Level up function LevelUp()
void levelUp(playerInfo *p) {
    p->level += 1;
    p->health += 10;
    p->attack += 5;
    p->defense += 3;

    return;
}

//Copys a player's class and health stat to another
void copyPlayer(playerInfo toCopy, playerInfo *toPaste) {
    strcpy(toPaste->class, toCopy.class);
    toPaste->health = toCopy.health;

    return;
}

//Does a specified amount of damage to player, but health can't drop below zero
void damage(playerInfo *player, int damageAmmount) {
    if(player->health > damageAmmount) {
        player->health -= damageAmmount;
    } else {
        player->health = 0;
    }

    return;
}

//Heals a player by a certain amount
void heal(playerInfo *player, int healAmmount) {
    if((player->health + healAmmount) < 100) {
        player->health += healAmmount;
    } else {
        player->health = 100;
    }

    return;
}

//One player attacks another
void attack(playerInfo *attacker, playerInfo *defender) {
    int damageDealt;
    damageDealt = attacker->attack - defender->defense;
    if(damageDealt > 0) {
        if(defender->health > damageDealt) {
            defender->health -= damageDealt;
        } else {
            defender->health = 0;
        }
    } else {
        if(attacker->health > (damageDealt * (-1))) {
            attacker->health += damageDealt;
        } else {
            attacker->health = 0;
        }
    }
}

int main() {
    // Create and initialize three players
    playerInfo player1 = {"Bob", "Warrior", 10, 120, 30, 20};
    playerInfo player2 = {"Joe", "Gleem", 70, 20, 35, 28};
    playerInfo player3 = {"Ron", "Fleem", 10, 120, 30, 20};
    
    // Desplay Player 2 updated stats
    printPlayer(player2);
    //Level Up player 2
    levelUp(&player2);
    // Desplay Player 2 updated stats
    printPlayer(player2);

    //Copys the class and health of platyer 1 to player 2
    copyPlayer(player1, &player2);
    
    //Prints the new player 2
    printPlayer(player2);
    
    return 0;
}
