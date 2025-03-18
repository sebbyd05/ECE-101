/*
Created dirring lecture 4 by Sebastian Dziedzic as an example of how to write a basic C Program
*/

#include<stdio.h>

int main() {
//Devlare Variables
    int x;
    float y;
    float z;
//Get user input
    printf("Please declare X= ");
    scanf("%d", &x);
    printf("\nPlease declare Y= ");
    scanf("%f", &y);
//Perform math
    z = x * y;
    
//Print result    
    printf("The Result is %f", z);

    return 0;
}