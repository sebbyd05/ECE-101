#include<stdio.h>
// Example of printing variables with the printf function

int main(void)
{
    int x; // declaration of an integer
    float y; // declaration of a float
    char c; 	
    x = 125; // initialization
    y = 3.14159; // initialization
    c = 'a'; // initialization
// print	
    printf("Display x %d\n", x); // integer
    printf("Display y %f\n", y); // real
    printf("Display c %c\n", c); // char
    printf("You can also print message prompts\n"); 
    printf("Display x and y %d %f\n", x, y); // printing tabs
    printf("y with two decimals:%2.2f, y with three decimals:%0.3f", y, y); 
	// decimals
	
    return(0);
} 