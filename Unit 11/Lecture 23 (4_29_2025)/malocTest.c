#include<stdio.h>
#include<stdlib.h>

int main() {
    int *pointer;
    pointer = (int *)malloc(sizeof(int));

    *pointer = 5;

    printf("%d", *pointer);

    free(pointer); //If you forgot this it will still run but it's incorrect

    //free(pointer); //This will make the program crash because it frees someting that's already freed

    return 0;
}