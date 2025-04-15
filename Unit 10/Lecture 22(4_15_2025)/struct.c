#include<stdio.h>
#include<stdbool.h>


//Structs group properties together
typedef struct thing_struct {
    char name[20];
    int length;
    bool isBig;
} thing;

int main() {
    thing thing1;
    thing1.name = {'The Big Ragu'};
    thing1.length = 100;

    thing thingList[2];

    for (int i = 0; i < 2; i++) {
        printf("Enter a name for thing %d:", (i+1));
        scanf("%s", thingList[i].name);
        printf("\nEnter thing %d length", (i+1));
        scanf("%d", thingList[i].length);
        printf("\nIs thing %d big?", (i+1));
        scanf("%d", thingList[i].isBig);
    }

}