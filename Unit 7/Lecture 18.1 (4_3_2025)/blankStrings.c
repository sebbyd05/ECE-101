#include<stdio.h>
#include<string.h>

int main() {
    char x[] = "";
    //Print it
    printf("The string is: %s", x);
    int y = strlen(x);
    int z = sizeof(x);

    printf("%d %d", y, z);
    
}