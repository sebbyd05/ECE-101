#include <stdio.h>
#include <stdlib.h>  // for malloc() and free()
#include<string.h>
typedef struct {// Define the player struct
    char name[50];
    int level;
    int health;
} Player;
int main() {
    // Dynamically allocate memory for one Player
    Player *p;
    p = (Player *)malloc(sizeof(Player));    
    // Exit if malloc failed
    if(p == NULL) {
        printf("Failed to allocate memmory");
        return -1;
    }
    // Assign values

    p->health = 100;
    p->level = 2;
    strcpy(p->name, "Test");

// Display player info
    printf("Name: %s\n", p->name);
    printf("Level: %d\n", p->level);
    printf("Health: %d\n", p->health);
// Free the allocated memory
    free(p);

    return 0;}  
